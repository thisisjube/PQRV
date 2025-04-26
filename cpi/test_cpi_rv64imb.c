#include <stdint.h>
#include <stdio.h>

#include "cpucycles.h"
#include "speed_print.h"

#define NTESTS 10000

uint64_t t[NTESTS];

extern void cpi_add();
extern void cpi_addi();
extern void cpi_addi_x1();
extern void cpi_xor();
extern void cpi_xori();
extern void cpi_mul();
extern void cpi_mulh();
extern void cpi_mulw();
extern void cpi_mulw_x1();
extern void cpi_mul_x1();
extern void cpi_mulh_x1();

extern void cpi_lh(int8_t *);
extern void cpi_lh_addi(int8_t *);
extern void cpi_lw(int8_t *);
extern void cpi_lw_addi(int8_t *);
extern void cpi_ld(int8_t *);
extern void cpi_ld_addi(int8_t *);
extern void cpi_sh(int8_t *);
extern void cpi_sw(int8_t *);
extern void cpi_addi_sw_v2(int8_t *);
extern void cpi_sd(int8_t *);

extern void cpi_rori();
extern void cpi_rori_x1();
extern void cpi_andn();
extern void cpi_andn_x1();

int main(void)
{
    int64_t buf[128];
    PERF(cpi_add(), cpi_add);
    PERF(cpi_addi(), cpi_addi);
    PERF(cpi_addi_x1(), cpi_addi_x1);
    PERF(cpi_xor(), cpi_xor);
    PERF(cpi_xori(), cpi_xori);
    PERF(cpi_mul(), cpi_mul);
    PERF(cpi_mulh(), cpi_mulh);
    PERF(cpi_mul_x1(), cpi_mul_x1);
    PERF(cpi_mulh_x1(), cpi_mulh_x1);
#    ifdef RV64
    PERF(cpi_mulw(), cpi_mulw);
    PERF(cpi_mulw_x1(), cpi_mulw_x1);
#    endif
    PERF(cpi_lh((int8_t *)buf), cpi_lh);
    PERF(cpi_lh_addi((int8_t *)buf), cpi_lh_addi);
    PERF(cpi_lw((int8_t *)buf), cpi_lw);
    PERF(cpi_lw_addi((int8_t *)buf), cpi_lw_addi);
#    ifdef RV64
    PERF(cpi_ld((int8_t *)buf), cpi_ld);
    PERF(cpi_ld_addi((int8_t *)buf), cpi_ld_addi);
#    endif
    PERF(cpi_sh((int8_t *)buf), cpi_sh);
    PERF(cpi_sw((int8_t *)buf), cpi_sw);
    PERF(cpi_addi_sw_v2((int8_t *)buf), cpi_addi_sw_v2);
#    ifdef RV64
    PERF(cpi_sd((int8_t *)buf), cpi_sd);
#    endif
    PERF(cpi_rori(), cpi_rori);
    PERF(cpi_rori_x1(), cpi_rori_x1);
    PERF(cpi_andn(), cpi_andn);
    PERF(cpi_andn_x1(), cpi_andn_x1);
    return 0;
}