#include "speed_print.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "cpucycles.h"

static int cmp_uint64(const void *a, const void *b)
{
    if (*(uint64_t *)a < *(uint64_t *)b)
        return -1;
    if (*(uint64_t *)a > *(uint64_t *)b)
        return 1;
    return 0;
}

uint64_t median(uint64_t *l, size_t llen)
{
    qsort(l, llen, sizeof(uint64_t), cmp_uint64);

    if (llen % 2)
        return l[llen / 2];
    else
        return (l[llen / 2 - 1] + l[llen / 2]) / 2;
}

static uint64_t average(uint64_t *t, size_t tlen)
{
    size_t i;
    uint64_t acc = 0;

    for (i = 0; i < tlen; i++)
        acc += t[i];
    return acc / tlen;
}

void print_results(const char *s, uint64_t *t, size_t tlen)
{
    size_t i;
    static uint64_t overhead = -1;

    if (tlen < 2) {
        fprintf(stderr, "ERROR: Need a least two cycle counts!\n");
        return;
    }

    //if (overhead == (uint64_t)-1)
    //    overhead = cpucycles_overhead();

    tlen--;
    for (i = 0; i < tlen; ++i)
        t[i] = t[i + 1] - t[i] - overhead;

    printf("%-30s", s);
    printf("%7llu cycles\n", (unsigned long long)median(t, tlen));
}

void print_results_average(const char *s, uint64_t *t, size_t tlen)
{
    size_t i;
    static uint64_t overhead = -1;

    if (tlen < 2) {
        fprintf(stderr, "ERROR: Need a least two cycle counts!\n");
        return;
    }

    //if (overhead == (uint64_t)-1)
    //   overhead = cpucycles_overhead();

    tlen--;
    for (i = 0; i < tlen; ++i)
        t[i] = t[i + 1] - t[i] - overhead;

    printf("%-30s", s);
    printf("%7llu cycles\n", (unsigned long long)average(t, tlen));
}

uint64_t get_average(uint64_t *t, size_t tlen)
{
    size_t i;
    static uint64_t overhead = -1;

    if (tlen < 2) {
        fprintf(stderr, "ERROR: Need a least two cycle counts!\n");
        return 0;
    }

    //if (overhead == (uint64_t)-1)
    //    overhead = cpucycles_overhead();

    tlen--;
    for (i = 0; i < tlen; ++i)
        t[i] = t[i + 1] - t[i] - overhead;

    return average(t, tlen);
}

uint64_t get_median(uint64_t *t, size_t tlen)
{
    size_t i;
    static uint64_t overhead = -1;

    if (tlen < 2) {
        fprintf(stderr, "ERROR: Need a least two cycle counts!\n");
        return 0;
    }

    //if (overhead == (uint64_t)-1)
    //    overhead = cpucycles_overhead();

    tlen--;
    for (i = 0; i < tlen; ++i)
        t[i] = t[i + 1] - t[i] - overhead;

    return median(t, tlen);
}

uint64_t cycles_overhead() {
    uint64_t overhead_total = 0, overhead_avg = 0;
    int N = 1000;
    init_perf_events();
    for(int i=0; i < N; i++) {
        start_counting_events();
        __asm__ volatile("");
        stop_and_read_events();
        overhead_total += get_total_cycles();
    }
    cleanup_perf_events();
    overhead_avg = overhead_total / N;
    return overhead_avg;
}