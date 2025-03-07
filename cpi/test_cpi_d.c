#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cpucycles.h"
#include "speed_print.h"

#define NTESTS 10000

uint64_t t[NTESTS];

extern void init_f_registers(double *);
extern void cpi_fadd();
extern void cpi_fadd_x1();
extern void cpi_fmul();
extern void cpi_fmul_x1();
extern void cpi_fmin();
extern void cpi_fmin_x1();
extern void cpi_fmadd();
extern void cpi_fmadd_x1();
extern void cpi_fsgnj();
extern void cpi_fsgnj_x1();
extern void pre_f0f1(double *, double *);
extern void cpi_fdiv();
extern void cpi_fdiv_x1();
extern void cpi_fsqrt();
extern void cpi_fsqrt_x1();

static double get_random_float_in_range(double a, double b)
{
    srand(time(NULL));
    return a + (b - a) * ((double)rand() / (double)RAND_MAX);
}

int main(void)
{
    double f0, f1;
    f0 = get_random_float_in_range(1.0, 2.0);
    init_f_registers(&f0);
    PERF(cpi_fadd(), cpi_fadd);
    PERF(cpi_fadd_x1(), cpi_fadd_x1);
    init_f_registers(&f0);
    PERF(cpi_fmin(), cpi_fmin);
    PERF(cpi_fmin_x1(), cpi_fmin_x1);
    PERF(cpi_fsgnj(), cpi_fsgnj);
    PERF(cpi_fsgnj_x1(), cpi_fsgnj_x1);

    f0 = 1.141592653589793, f1 = 2.141592653589793;
    printf("f0 = %g, f1 = %g:\n", f0, f1);
    pre_f0f1(&f0, &f1);
    PERF(cpi_fmul(), cpi_fmul);
    PERF(cpi_fmadd(), cpi_fmadd);
    PERF(cpi_fdiv(), cpi_fdiv);
    PERF(cpi_fsqrt(), cpi_fsqrt);

    f0 = 1.0e308, f1 = 1.0e-308;
    printf("f0 = %g, f1 = %g:\n", f0, f1);
    pre_f0f1(&f0, &f1);
    PERF(cpi_fmul(), cpi_fmul);
    PERF(cpi_fmadd(), cpi_fmadd);
    PERF(cpi_fdiv(), cpi_fdiv);
    PERF(cpi_fsqrt(), cpi_fsqrt);

    f0 = 1.0e-308, f1 = 1.0e308;
    printf("f0 = %g, f1 = %g:\n", f0, f1);
    pre_f0f1(&f0, &f1);
    PERF(cpi_fmul(), cpi_fmul);
    PERF(cpi_fmadd(), cpi_fmadd);
    PERF(cpi_fdiv(), cpi_fdiv);
    PERF(cpi_fsqrt(), cpi_fsqrt);

    f0 = 1.0e308, f1 = 1.141592653589793;
    printf("f0 = %g, f1 = %g:\n", f0, f1);
    pre_f0f1(&f0, &f1);
    PERF(cpi_fmul(), cpi_fmul);
    PERF(cpi_fmadd(), cpi_fmadd);
    PERF(cpi_fdiv(), cpi_fdiv);
    PERF(cpi_fsqrt(), cpi_fsqrt);
    pre_f0f1(&f0, &f1);
    PERF(cpi_fmul_x1(), cpi_fmul_x1);
    pre_f0f1(&f0, &f1);
    PERF(cpi_fmadd_x1(), cpi_fmadd_x1);
    pre_f0f1(&f0, &f1);
    PERF(cpi_fdiv_x1(), cpi_fdiv_x1);
    pre_f0f1(&f0, &f1);
    PERF(cpi_fsqrt_x1(), cpi_fsqrt_x1);

    return 0;
}