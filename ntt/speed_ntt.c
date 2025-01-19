#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpucycles.h"

#ifdef RVV
#    include "ntt_rvv_vlen128.h"
#elif defined(RV32)
#    include "ntt_rv32im.h"
#elif defined(RV64)
#    include "ntt_rv64im.h"
#endif
#include "speed_print.h"

#define NTESTS 10000

uint64_t t[NTESTS];

int main()
{
#ifdef DILITHIUM_NTT_RV32_H
    int32_t a[256], b[256], c[256], zetas[256 * 2];
    int64_t tmp[256];
    printf(
        "Dilithium 8-layer NTT & Montgomery based & 3+3+2 layers "
        "merging & RV32IM\n");
    PERF(ntt_rv32im(a, zetas), ntt);
    PERF(poly_basemul_8l_init_rv32im(tmp, a, b), poly_basemul_init);
    PERF(poly_basemul_8l_acc_rv32im(tmp, a, b), poly_basemul_acc);
    PERF(poly_basemul_8l_acc_end_rv32im(c, a, b, tmp),
         poly_basemul_acc_end);
    PERF(poly_basemul_8l_rv32im(c, a, b), poly_basemul);
    PERF(poly_reduce_rv32im(a), poly_reduce);
    PERF(intt_rv32im(a, zetas), intt);
#elif defined(DILITHIUM_NTT_RV64_H)
    int32_t a[256], b[256], c[256];
    int64_t zetas[256 * 2];
    int64_t tmp[256];
    printf(
        "Dilithium 8-layer NTT & Plantard based & 4+4 layers "
        "merging & RV64IM\n");
    PERF(ntt_rv64im(a, zetas), ntt);
    PERF(poly_basemul_8l_init_rv64im(tmp, a, b), poly_basemul_init);
    PERF(poly_basemul_8l_acc_rv64im(tmp, a, b), poly_basemul_acc);
    PERF(poly_basemul_8l_acc_end_rv64im(c, a, b, tmp),
         poly_basemul_acc_end);
    PERF(poly_basemul_8l_rv64im(c, a, b), poly_basemul);
    PERF(poly_reduce_rv64im(a), poly_reduce);
    PERF(intt_rv64im(a, zetas), intt);
#elif defined(KYBER_RV32_MONT)
    int16_t r[256];
    uint32_t zetas[128];
    printf(
        "Kyber 7-layer NTT & Mont based & 1+3+3 layers merging & "
        "RV32IM\n");
    PERF(ntt_rv32im(r, zetas), ntt);
    PERF(intt_rv32im(r, zetas), intt);
#elif defined(KYBER_NTT_RV32_H)
    int16_t r[256], a[256], b[256], b_cache[256];
    int32_t r_double[256];
    uint32_t zetas[128];
    printf(
        "Kyber 7-layer NTT & Plantard based & 4+3 layers merging & "
        "RV32IM\n");
    PERF(ntt_rv32im(r, zetas), ntt);
    PERF(intt_rv32im(r, zetas), intt);
    PERF(poly_basemul_acc_rv32im(r_double, a, b, zetas), basemul_acc);
    PERF(poly_basemul_acc_end_rv32im(r, a, b, zetas, r_double),
         basemul_acc_end);
    PERF(poly_basemul_cache_init_rv32im(r_double, a, b, b_cache, zetas),
         basemul_cache_init);
    PERF(
        poly_basemul_acc_cache_init_rv32im(r_double, a, b, b_cache, zetas),
        basemul_acc_cache_init);
    PERF(poly_basemul_acc_cache_init_end_rv32im(r, a, b, b_cache, zetas,
                                                r_double),
         basemul_acc_cache_init_end);
    PERF(poly_basemul_acc_cached_rv32im(r_double, a, b, b_cache),
         basemul_acc_cached);
    PERF(poly_basemul_acc_cache_end_rv32im(r, a, b, b_cache, r_double),
         basemul_acc_cache_end);
    PERF(poly_plantard_rdc_rv32im(r), plantard_rdc);
    PERF(poly_toplant_rv32im(r), toplant);
#elif defined(KYBER_NTT_RV64_H)
    int16_t r[256], a[256], b[256], b_cache[256];
    int32_t r_double[256];
    uint32_t zetas[128];
    printf(
        "Kyber 7-layer NTT & Plantard based & 4+3 layers merging & "
        "RV64IM\n");
    PERF(ntt_rv64im(r, zetas), ntt);
    PERF(intt_rv64im(r, zetas), intt);
    PERF(poly_basemul_acc_rv64im(r_double, a, b, zetas), basemul_acc);
    PERF(poly_basemul_acc_end_rv64im(r, a, b, zetas, r_double),
         basemul_acc_end);
    PERF(poly_basemul_cache_init_rv64im(r_double, a, b, b_cache, zetas),
         basemul_cache_init);
    PERF(
        poly_basemul_acc_cache_init_rv64im(r_double, a, b, b_cache, zetas),
        basemul_acc_cache_init);
    PERF(poly_basemul_acc_cache_init_end_rv64im(r, a, b, b_cache, zetas,
                                                r_double),
         basemul_acc_cache_init_end);
    PERF(poly_basemul_acc_cached_rv64im(r_double, a, b, b_cache),
         basemul_acc_cached);
    PERF(poly_basemul_acc_cache_end_rv64im(r, a, b, b_cache, r_double),
         basemul_acc_cache_end);
    PERF(poly_plantard_rdc_rv64im(r), plantard_rdc);
    PERF(poly_toplant_rv64im(r), toplant);
#elif defined(KYBER_NTT_RVV_VLEN128_H)
    int16_t r[256], a[256], b[256], b_cache[256];
    printf(
        "Kyber 7-layer NTT & Montgomery based & 1+6 layers merging & "
        "RV32IMV\n");
    PERF(ntt_rvv_vlen128(r, qdata_vlen128), ntt);
    PERF(intt_rvv_vlen128(r, qdata_vlen128), intt);
    PERF(poly_basemul_rvv_vlen128(r, a, b, qdata_vlen128),
         poly_basemul_rvv_vlen128);
    PERF(poly_basemul_acc_rvv_vlen128(r, a, b, qdata_vlen128),
         poly_basemul_acc_rvv_vlen128);
    PERF(poly_basemul_cache_init_rvv_vlen128(r, a, b, qdata_vlen128,
                                             b_cache),
         poly_basemul_cache_init_rvv_vlen128);
    PERF(poly_basemul_acc_cache_init_rvv_vlen128(r, a, b, qdata_vlen128,
                                                 b_cache),
         poly_basemul_acc_cache_init_rvv_vlen128);
    PERF(poly_basemul_cached_rvv_vlen128(r, a, b, qdata_vlen128, b_cache),
         poly_basemul_cached_rvv_vlen128);
    PERF(poly_basemul_acc_cached_rvv_vlen128(r, a, b, qdata_vlen128,
                                             b_cache),
         poly_basemul_acc_cached_rvv_vlen128);
    PERF(poly_reduce_rvv_vlen128(r), poly_reduce_rvv_vlen128);
    PERF(poly_tomont_rvv_vlen128(r), poly_tomont_rvv_vlen128);
    PERF(ntt2normal_order_rvv_vlen128(r, qdata_vlen128),
         ntt2normal_order_rvv_vlen128);
    PERF(normal2ntt_order_rvv_vlen128(r, qdata_vlen128),
         normal2ntt_order_rvv_vlen128);
#elif defined(DILITHIUM_NTT_RVV_VLEN128_H)
    int32_t r[256], a[256], b[256];
    printf(
        "Dilithium 8-layer NTT & Montgomery based & 3+3+2 layers merging "
        "& "
        "RV32IMV\n");
    PERF(ntt_rvv_vlen128(r, qdata_vlen128), ntt_rvv_vlen128);
    PERF(intt_rvv_vlen128(r, qdata_vlen128), intt_rvv_vlen128);
    PERF(poly_basemul_rvv_vlen128(r, a, b), poly_basemul_rvv_vlen128);
    PERF(poly_basemul_acc_rvv_vlen128(r, a, b),
         poly_basemul_acc_rvv_vlen128);
    PERF(ntt2normal_order_rvv_vlen128(r, qdata_vlen128),
         ntt2normal_order_rvv_vlen128);
    PERF(normal2ntt_order_rvv_vlen128(r, qdata_vlen128),
         normal2ntt_order_rvv_vlen128);
    PERF(poly_reduce_rvv_vlen128(r), poly_reduce_rvv_vlen128);
#endif

    return 0;
}