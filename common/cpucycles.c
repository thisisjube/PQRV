#include "cpucycles.h"

#include <stdint.h>

#ifdef __linux__
#include <linux/perf_event.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

/*
 * Kernels that drive the PMU through SBI (mainline 6.x, as opposed to the
 * 5.10.4 vendor kernel this project was originally measured on) leave the
 * cycle and instret counters inhibited until perf schedules an event onto
 * them. rdcycle/rdinstret then read a frozen value instead of trapping, so
 * every measurement silently comes out as 0. Holding one hardware event open
 * per counter keeps them running for the lifetime of the process.
 *
 * The CSRs must also be readable from user mode, which is a boot-time setting:
 *     sysctl -w kernel.perf_user_access=2
 * Without it rdcycle raises SIGILL. This is a no-op on the vendor kernel,
 * where the counters already run free.
 */
static void cpucycles_open_counter(unsigned long long config)
{
    struct perf_event_attr attr;

    memset(&attr, 0, sizeof(attr));
    attr.type = PERF_TYPE_HARDWARE;
    attr.size = sizeof(attr);
    attr.config = config;

    /* Intentionally leaked: the counters must stay armed until the process
     * exits, and nothing else ever refers to the descriptor. */
    (void)syscall(__NR_perf_event_open, &attr, 0, -1, -1, 0);
}

__attribute__((constructor)) static void cpucycles_init(void)
{
    cpucycles_open_counter(PERF_COUNT_HW_CPU_CYCLES);
    cpucycles_open_counter(PERF_COUNT_HW_INSTRUCTIONS);
}
#endif /* __linux__ */

uint64_t cpucycles_overhead(void)
{
    uint64_t t0, t1, overhead = -1LL;
    unsigned int i;

    for (i = 0; i < 100000; i++) {
        t0 = cpucycles();
        __asm__ volatile("");
        t1 = cpucycles();
        if (t1 - t0 < overhead)
            overhead = t1 - t0;
    }

    return overhead;
}
