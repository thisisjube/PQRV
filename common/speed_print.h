#ifndef PRINT_SPEED_H
#define PRINT_SPEED_H

#include <stddef.h>
#include <stdint.h>
#include "perf.h"

void print_results(const char *s, uint64_t *t, size_t tlen);
void print_results_average(const char *s, uint64_t *t, size_t tlen);
uint64_t cycles_overhead();
uint64_t get_average(uint64_t *t, size_t tlen);
uint64_t get_median(uint64_t *t, size_t tlen);
uint64_t median(uint64_t *l, size_t llen);

#define PERF(FUNC, LABEL)                                                                 \
    do {                                                                                  \
        uint64_t cycles_total, instr_total;                                               \
        uint64_t cc_average, instr_average, overhead;                                     \
        init_perf_events();                                                               \
        start_counting_events();                                                          \
        for (int ii = 0; ii < NTESTS; ii++) {                                             \
            FUNC;                                                                         \
        }                                                                                 \
        stop_and_read_events();                                                           \
        cleanup_perf_events();                                                            \
        cycles_total = get_total_cycles();                                                \
        instr_total = get_total_instr();                                                  \
        overhead = cycles_overhead();                                                     \
        cc_average = (cycles_total-overhead) / NTESTS;                                    \
        instr_average = instr_total / NTESTS;                                             \
        printf("%-30s cycles/insts/CPI=%llu/%llu/%.2f\n", #LABEL,                         \
               (unsigned long long)cc_average,                                            \
               (unsigned long long)instr_average,                                         \
               (float)cc_average / instr_average);                                        \
    } while (0)

#define PERF_N(FUNC, LABEL, N)                                                            \
    do {                                                                                  \
        uint64_t cycles_total, instr_total;                                               \
        uint64_t cc_average, oneway_cc, instr_average, overhead;                          \
        init_perf_events();                                                               \
        start_counting_events();                                                          \
        for (int ii = 0; ii < NTESTS; ii++) {                                             \
            FUNC;                                                                         \
        }                                                                                 \
        stop_and_read_events();                                                           \
        cleanup_perf_events();                                                            \
        cycles_total = get_total_cycles();                                                \
        instr_total = get_total_instr();                                                  \
        overhead = cycles_overhead();                                                     \
        cc_average = (cycles_total-overhead) / NTESTS;                                    \
        instr_average = instr_total / NTESTS;                                             \
        oneway_cc = cc_average / N;                                                       \
        printf("%-20s cycles/insts/CPI/1-wayCC=%llu/%llu/%.2f/%llu\n", #LABEL,            \
               (unsigned long long)cc_average,                                            \
               (unsigned long long)instr_average,                                         \
               (float)cc_average / instr_average,                                         \
               (unsigned long long)oneway_cc);                                            \
    } while (0)
#endif
