#include <stdint.h>
#include <stdio.h>

#include "cpucycles.h"
#include "speed_print.h"

#define NTESTS 10000

uint64_t t[NTESTS];

extern int init_vector_e8();
extern int init_vector_e16();
extern int init_vector_e32();
extern int init_vector_e64();
// Vector unit-stride loads and stores
extern void cpi_vle8(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                     int8_t *buf3);
extern void cpi_vle8_add(int8_t *buf);
extern void cpi_vse8(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                     int8_t *buf3);
extern void cpi_vle16(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                      int8_t *buf3);
extern void cpi_vle16_add(int8_t *buf);
extern void cpi_vse16(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                      int8_t *buf3);
extern void cpi_vle32(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                      int8_t *buf3);
extern void cpi_vle32_add(int8_t *buf);
extern void cpi_vse32(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                      int8_t *buf3);
extern void cpi_vle64(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                      int8_t *buf3);
extern void cpi_vle64_add(int8_t *buf);
extern void cpi_vse64(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                      int8_t *buf3);
//   Vector strided loads and stores
extern void cpi_vlse8(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                      int8_t *buf3, size_t byte_stride);
extern void cpi_vlse16(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                       int8_t *buf3, size_t byte_stride);
extern void cpi_vlse32(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                       int8_t *buf3, size_t byte_stride);
extern void cpi_vlse64(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                       int8_t *buf3, size_t byte_stride);
extern void cpi_vsse8(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                      int8_t *buf3, size_t byte_stride);
extern void cpi_vsse16(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                       int8_t *buf3, size_t byte_stride);
extern void cpi_vsse32(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                       int8_t *buf3, size_t byte_stride);
extern void cpi_vsse64(int8_t *buf0, int8_t *buf1, int8_t *buf2,
                       int8_t *buf3, size_t byte_stride);

extern void cpi_vaddvv();
extern void cpi_vaddvx();
extern void cpi_vaddvx_x1();
extern void cpi_vaddvx_x2();
extern void cpi_vaddvx_x4();
extern void cpi_vadcvvm();
extern void cpi_vadcvvm_x1();
extern void cpi_vadcvvm_x2();
extern void cpi_vadcvvm_x4();
extern void cpi_vmadcvvm();
extern void cpi_vmadcvvm_x1();
extern void cpi_vmadcvvm_x2();
extern void cpi_vmadcvvm_x4();
extern void cpi_vmadcvv();
extern void cpi_vmadcvv_x1();
extern void cpi_vmadcvv_x2();
extern void cpi_vmadcvv_x4();
extern void cpi_vmsltuvv();
extern void cpi_vmsltuvv_x1();
extern void cpi_vmsltuvv_x2();
extern void cpi_vmsltuvv_x4();
extern void cpi_vmsbc_vmslt();
extern void cpi_vmsbc_vsub();
extern void cpi_vmsbc_2_vsub_4();
extern void cpi_vsrl_vmsltu();
extern void cpi_vsrl_vadd_2_2();
extern void cpi_vand_vadd_2_2();
extern void cpi_vsrl_vadd_2_3();
extern void cpi_vand_vadd_2_3();
extern void cpi_vsrl_vadd_2_4();
extern void cpi_vand_vadd_2_4();
extern void cpi_vsrl_vadd_2_6();
extern void cpi_vand_vadd_2_6();
extern void cpi_vsrl_vadd_1_1();
extern void cpi_vand_vadd_1_1();
extern void cpi_vsrl_vadd_1_2();
extern void cpi_vand_vadd_1_2();
extern void cpi_vsrl_vadd_1_3();
extern void cpi_vand_vadd_1_3();
extern void cpi_vmvvv();
extern void cpi_vmvvv_x1();
extern void cpi_vandvv();
extern void cpi_vandvx();
extern void cpi_vandvx_and_hybrid_v1();
extern void cpi_vandvx_and_hybrid_v2();
extern void cpi_vandvx_and_hybrid_v3();
extern void cpi_vandvx_and_hybrid_v4();
extern void cpi_vandvx_and_hybrid_v4_1();
extern void cpi_vandvx_and_hybrid_v5();
extern void cpi_vandvx_and_hybrid_v6();
extern void cpi_vandvv_x1();
extern void cpi_vandvv_x2();
extern void cpi_vandvv_x4();
extern void cpi_vnotv();
extern void cpi_vnotv_x1();
extern void cpi_vnotv_x2();
extern void cpi_vnotv_x4();
extern void cpi_vxorvv();
extern void cpi_vxorvv_x1();
extern void cpi_vxorvv_x2();
extern void cpi_vxorvv_x4();
extern void cpi_vsllvi();
extern void cpi_vsllvi_x1();
extern void cpi_vsllvi_x2();
extern void cpi_vsllvi_x4();
extern void cpi_vssrlvi();
extern void cpi_vssrlvi_x1();
extern void cpi_vssrlvi_x2();
extern void cpi_vssrlvi_x4();
extern void cpi_vsrlvx();
extern void cpi_vsrlvx_x1();
extern void cpi_vsrlvx_x2();
extern void cpi_vsrlvx_x4();
extern void cpi_vsravi();
extern void cpi_vsravi_x1();
extern void cpi_vsravi_x2();
extern void cpi_vsravi_x4();
extern void cpi_vmulvx();
extern void cpi_vmulvx_x1();
extern void cpi_vmulvx_x2();
extern void cpi_vmulvx_x4();
extern void cpi_vmulvv();
extern void cpi_vmulvv_x1();
extern void cpi_vmulvv_x2();
extern void cpi_vmulvv_x4();
extern void cpi_vmaccvv();
extern void cpi_vmaccvv_x1();
extern void cpi_vmaccvv_x2();
extern void cpi_vmaccvv_x4();
extern void cpi_vmulhvv();
extern void cpi_vmulhvv_x1();
extern void cpi_vmulhvv_x2();
extern void cpi_vmulhvv_x4();
extern void cpi_vrgathervv();
extern void cpi_vrgathervv_x1();
extern void cpi_vrgathervv_x2();
extern void cpi_vrgathervv_x4();
extern void cpi_vmergevvm();
extern void cpi_vmergevvm_x1();
extern void cpi_vmergevvm_x2();
extern void cpi_vmergevvm_x4();

extern void init_vector_double_reg(double *);
extern void cpi_vfaddvv();
extern void cpi_vfaddvv_x1();
extern void cpi_vfmulvv();
extern void cpi_vfmulvv_x1();
extern void cpi_vfmaccvv();
extern void cpi_vfmaccvv_x1();
extern void cpi_vfminvv();
extern void cpi_vfminvv_x1();
extern void cpi_vfsgnjvv();
extern void cpi_vfsgnjvv_x1();
extern void pre_v0v1(double *, double *);
extern void cpi_vfdivvv();
extern void cpi_vfdivvv_x1();
extern void cpi_vfsqrtv();
extern void cpi_vfsqrtv_x1();

int main(void)
{
    int64_t buf[1024];
    int vec_len;
    int8_t *buf_ptr = (int8_t *)buf;
    int8_t *buf_ptr0 = buf_ptr, *buf_ptr1 = buf_ptr + 32,
           *buf_ptr2 = buf_ptr + 64, *buf_ptr3 = buf_ptr + 96;

    printf("Vector unit-stride loads and stores\n");
    init_vector_e8();
    PERF(cpi_vle8(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3), cpi_vle8);
    PERF(cpi_vle8_add((int8_t *)buf), cpi_vle8_add);
    PERF(cpi_vse8(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3), cpi_vse8);
    init_vector_e16();
    PERF(cpi_vle16(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3), cpi_vle16);
    PERF(cpi_vle16_add((int8_t *)buf), cpi_vle16_add);
    PERF(cpi_vse16(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3), cpi_vse16);
    init_vector_e32();
    PERF(cpi_vle32(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3), cpi_vle32);
    PERF(cpi_vle32_add((int8_t *)buf), cpi_vle32_add);
    PERF(cpi_vse32(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3), cpi_vse32);
    init_vector_e64();
    PERF(cpi_vle64(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3), cpi_vle64);
    PERF(cpi_vle64_add((int8_t *)buf), cpi_vle64_add);
    PERF(cpi_vse64(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3), cpi_vse64);
    printf("Vector strided loads and stores\n");
    init_vector_e8();
    PERF(cpi_vlse8(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 1),
         cpi_vlse8 with stride = 1);
    PERF(cpi_vlse8(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 2),
         cpi_vlse8 with stride = 2);
    PERF(cpi_vlse8(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 4),
         cpi_vlse8 with stride = 4);
    PERF(cpi_vlse8(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 8),
         cpi_vlse8 with stride = 8);
    PERF(cpi_vsse8(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 1),
         cpi_vsse8 with stride = 1);
    PERF(cpi_vsse8(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 2),
         cpi_vsse8 with stride = 2);
    PERF(cpi_vsse8(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 4),
         cpi_vsse8 with stride = 4);
    PERF(cpi_vsse8(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 8),
         cpi_vsse8 with stride = 8);
    init_vector_e16();
    PERF(cpi_vlse16(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 2),
         cpi_vlse16 with stride = 2);
    PERF(cpi_vlse16(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 4),
         cpi_vlse16 with stride = 4);
    PERF(cpi_vlse16(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 8),
         cpi_vlse16 with stride = 8);
    PERF(cpi_vlse16(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 16),
         cpi_vlse16 with stride = 16);
    PERF(cpi_vsse16(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 2),
         cpi_vsse16 with stride = 2);
    PERF(cpi_vsse16(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 4),
         cpi_vsse16 with stride = 4);
    PERF(cpi_vsse16(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 8),
         cpi_vsse16 with stride = 8);
    PERF(cpi_vsse16(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 16),
         cpi_vsse16 with stride = 16);
    init_vector_e32();
    PERF(cpi_vlse32(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 4),
         cpi_vlse32 with stride = 4);
    PERF(cpi_vlse32(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 8),
         cpi_vlse32 with stride = 8);
    PERF(cpi_vlse32(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 16),
         cpi_vlse32 with stride = 16);
    PERF(cpi_vlse32(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 32),
         cpi_vlse32 with stride = 32);
    PERF(cpi_vsse32(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 4),
         cpi_vsse32 with stride = 4);
    PERF(cpi_vsse32(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 8),
         cpi_vsse32 with stride = 8);
    PERF(cpi_vsse32(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 16),
         cpi_vsse32 with stride = 16);
    PERF(cpi_vsse32(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 32),
         cpi_vsse32 with stride = 32);
    init_vector_e64();
    PERF(cpi_vlse64(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 8),
         cpi_vlse64 with stride = 8);
    PERF(cpi_vlse64(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 16),
         cpi_vlse64 with stride = 16);
    PERF(cpi_vlse64(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 32),
         cpi_vlse64 with stride = 32);
    PERF(cpi_vlse64(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 64),
         cpi_vlse64 with stride = 64);
    PERF(cpi_vsse64(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 8),
         cpi_vsse64 with stride = 8);
    PERF(cpi_vsse64(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 16),
         cpi_vsse64 with stride = 16);
    PERF(cpi_vsse64(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 32),
         cpi_vsse64 with stride = 32);
    PERF(cpi_vsse64(buf_ptr0, buf_ptr1, buf_ptr2, buf_ptr3, 64),
         cpi_vsse64 with stride = 64);
    vec_len = init_vector_e16();
    printf("init_vector_e16, the length of vector is %d bits\n",
           vec_len * 16);
    cpi_vmvvv();
    PERF(cpi_vmvvv(), cpi_vmvvv);
    PERF(cpi_vmvvv_x1(), cpi_vmvvv_x1);
    PERF(cpi_vaddvv(), cpi_vaddvv);
    PERF(cpi_vaddvx(), cpi_vaddvx);
    PERF(cpi_vaddvx_x1(), cpi_vaddvx_x1);
    PERF(cpi_vaddvx_x2(), cpi_vaddvx_x2);
    PERF(cpi_vaddvx_x4(), cpi_vaddvx_x4);
    PERF(cpi_vadcvvm(), cpi_vadcvvm);
    PERF(cpi_vadcvvm_x1(), cpi_vadcvvm_x1);
    PERF(cpi_vadcvvm_x2(), cpi_vadcvvm_x2);
    PERF(cpi_vadcvvm_x4(), cpi_vadcvvm_x4);
    PERF(cpi_vmadcvvm(), cpi_vmadcvvm);
    PERF(cpi_vmadcvvm_x1(), cpi_vmadcvvm_x1);
    PERF(cpi_vmadcvvm_x2(), cpi_vmadcvvm_x2);
    PERF(cpi_vmadcvvm_x4(), cpi_vmadcvvm_x4);
    PERF(cpi_vmadcvv(), cpi_vmadcvv);
    PERF(cpi_vmadcvv_x1(), cpi_vmadcvv_x1);
    PERF(cpi_vmadcvv_x2(), cpi_vmadcvv_x2);
    PERF(cpi_vmadcvv_x4(), cpi_vmadcvv_x4);
    PERF(cpi_vmsltuvv(), cpi_vmsltuvv);
    PERF(cpi_vmsltuvv_x1(), cpi_vmsltuvv_x1);
    PERF(cpi_vmsltuvv_x2(), cpi_vmsltuvv_x2);
    PERF(cpi_vmsltuvv_x4(), cpi_vmsltuvv_x4);
    PERF(cpi_vmsbc_vmslt(), cpi_vmsbc_vmslt);
    PERF(cpi_vmsbc_vsub(), cpi_vmsbc_vsub);
    PERF(cpi_vmsbc_2_vsub_4(), cpi_vmsbc_2_vsub_4);
    PERF(cpi_vsrl_vmsltu(), cpi_vsrl_vmsltu);
    PERF(cpi_vsrl_vadd_2_2(), cpi_vsrl_vadd_2_2);
    PERF(cpi_vand_vadd_2_2(), cpi_vand_vadd_2_2);
    PERF(cpi_vsrl_vadd_2_3(), cpi_vsrl_vadd_2_3);
    PERF(cpi_vand_vadd_2_3(), cpi_vand_vadd_2_3);
    PERF(cpi_vsrl_vadd_2_4(), cpi_vsrl_vadd_2_4);
    PERF(cpi_vand_vadd_2_4(), cpi_vand_vadd_2_4);
    PERF(cpi_vsrl_vadd_2_6(), cpi_vsrl_vadd_2_6);
    PERF(cpi_vand_vadd_2_6(), cpi_vand_vadd_2_6);
    PERF(cpi_vsrl_vadd_1_1(), cpi_vsrl_vadd_1_1);
    PERF(cpi_vand_vadd_1_1(), cpi_vand_vadd_1_1);
    PERF(cpi_vsrl_vadd_1_2(), cpi_vsrl_vadd_1_2);
    PERF(cpi_vand_vadd_1_2(), cpi_vand_vadd_1_2);
    PERF(cpi_vsrl_vadd_1_3(), cpi_vsrl_vadd_1_3);
    PERF(cpi_vand_vadd_1_3(), cpi_vand_vadd_1_3);
    PERF(cpi_vandvv(), cpi_vandvv);
    PERF(cpi_vandvx(), cpi_vandvx);
    PERF(cpi_vandvv_x1(), cpi_vandvv_x1);
    PERF(cpi_vandvv_x2(), cpi_vandvv_x2);
    PERF(cpi_vandvv_x4(), cpi_vandvv_x4);
    PERF(cpi_vandvx_and_hybrid_v1(), cpi_vandvx_and_hybrid_v1);
    PERF(cpi_vandvx_and_hybrid_v2(), cpi_vandvx_and_hybrid_v2);
    PERF(cpi_vandvx_and_hybrid_v3(), cpi_vandvx_and_hybrid_v3);
    PERF(cpi_vandvx_and_hybrid_v4(), cpi_vandvx_and_hybrid_v4);
    PERF(cpi_vandvx_and_hybrid_v4_1(), cpi_vandvx_and_hybrid_v4_1);
    PERF(cpi_vandvx_and_hybrid_v5(), cpi_vandvx_and_hybrid_v5);
    PERF(cpi_vandvx_and_hybrid_v6(), cpi_vandvx_and_hybrid_v6);
    // PERF(cpi_vnotv(), cpi_vnotv);
    // PERF(cpi_vnotv_x1(), cpi_vnotv_x1);
    // PERF(cpi_vnotv_x2(), cpi_vnotv_x2);
    // PERF(cpi_vnotv_x4(), cpi_vnotv_x4);
    // PERF(cpi_vxorvv(), cpi_vxorvv);
    // PERF(cpi_vxorvv_x1(), cpi_vxorvv_x1);
    // PERF(cpi_vxorvv_x2(), cpi_vxorvv_x2);
    // PERF(cpi_vxorvv_x4(), cpi_vxorvv_x4);
    PERF(cpi_vsllvi(), cpi_vsllvi);
    PERF(cpi_vsllvi_x1(), cpi_vsllvi_x1);
    PERF(cpi_vsllvi_x2(), cpi_vsllvi_x2);
    PERF(cpi_vsllvi_x4(), cpi_vsllvi_x4);
    // PERF(cpi_vssrlvi(), cpi_vssrlvi);
    // PERF(cpi_vssrlvi_x1(), cpi_vssrlvi_x1);
    // PERF(cpi_vssrlvi_x2(), cpi_vssrlvi_x2);
    // PERF(cpi_vssrlvi_x4(), cpi_vssrlvi_x4);
    // PERF(cpi_vsrlvx(), cpi_vsrlvx);
    // PERF(cpi_vsrlvx_x1(), cpi_vsrlvx_x1);
    // PERF(cpi_vsrlvx_x2(), cpi_vsrlvx_x2);
    // PERF(cpi_vsrlvx_x4(), cpi_vsrlvx_x4);
    // PERF(cpi_vsravi(), cpi_vsravi);
    // PERF(cpi_vsravi_x1(), cpi_vsravi_x1);
    // PERF(cpi_vsravi_x2(), cpi_vsravi_x2);
    // PERF(cpi_vsravi_x4(), cpi_vsravi_x4);
    PERF(cpi_vmulvx(), cpi_vmulvx);
    PERF(cpi_vmulvx_x1(), cpi_vmulvx_x1);
    PERF(cpi_vmulvx_x2(), cpi_vmulvx_x2);
    PERF(cpi_vmulvx_x4(), cpi_vmulvx_x4);
    PERF(cpi_vmulvv(), cpi_vmulvv);
    PERF(cpi_vmulvv_x1(), cpi_vmulvv_x1);
    PERF(cpi_vmulvv_x2(), cpi_vmulvv_x2);
    PERF(cpi_vmulvv_x4(), cpi_vmulvv_x4);
    PERF(cpi_vmaccvv(), cpi_vmaccvv);
    PERF(cpi_vmaccvv_x1(), cpi_vmaccvv_x1);
    PERF(cpi_vmaccvv_x2(), cpi_vmaccvv_x2);
    PERF(cpi_vmaccvv_x4(), cpi_vmaccvv_x4);
    PERF(cpi_vmulhvv(), cpi_vmulhvv);
    PERF(cpi_vmulhvv_x1(), cpi_vmulhvv_x1);
    PERF(cpi_vmulhvv_x2(), cpi_vmulhvv_x2);
    PERF(cpi_vmulhvv_x4(), cpi_vmulhvv_x4);
    PERF(cpi_vrgathervv(), cpi_vrgathervv);
    PERF(cpi_vrgathervv_x1(), cpi_vrgathervv_x1);
    PERF(cpi_vrgathervv_x2(), cpi_vrgathervv_x2);
    PERF(cpi_vrgathervv_x4(), cpi_vrgathervv_x4);
    PERF(cpi_vmergevvm(), cpi_vmergevvm);
    PERF(cpi_vmergevvm_x1(), cpi_vmergevvm_x1);
    PERF(cpi_vmergevvm_x2(), cpi_vmergevvm_x2);
    PERF(cpi_vmergevvm_x4(), cpi_vmergevvm_x4);
    vec_len = init_vector_e32();
    printf("\ninit_vector_e32, the length of vector is %d bits\n",
           vec_len * 32);
    PERF(cpi_vaddvv(), cpi_vaddvv);
    PERF(cpi_vaddvx(), cpi_vaddvx);
    PERF(cpi_vaddvx_x1(), cpi_vaddvx_x1);
    PERF(cpi_vaddvx_x2(), cpi_vaddvx_x2);
    PERF(cpi_vaddvx_x4(), cpi_vaddvx_x4);
    PERF(cpi_vadcvvm(), cpi_vadcvvm);
    PERF(cpi_vadcvvm_x1(), cpi_vadcvvm_x1);
    PERF(cpi_vadcvvm_x2(), cpi_vadcvvm_x2);
    PERF(cpi_vadcvvm_x4(), cpi_vadcvvm_x4);
    PERF(cpi_vmadcvvm(), cpi_vmadcvvm);
    PERF(cpi_vmadcvvm_x1(), cpi_vmadcvvm_x1);
    PERF(cpi_vmadcvvm_x2(), cpi_vmadcvvm_x2);
    PERF(cpi_vmadcvvm_x4(), cpi_vmadcvvm_x4);
    PERF(cpi_vmadcvv(), cpi_vmadcvv);
    PERF(cpi_vmadcvv_x1(), cpi_vmadcvv_x1);
    PERF(cpi_vmadcvv_x2(), cpi_vmadcvv_x2);
    PERF(cpi_vmadcvv_x4(), cpi_vmadcvv_x4);
    PERF(cpi_vmsltuvv(), cpi_vmsltuvv);
    PERF(cpi_vmsltuvv_x1(), cpi_vmsltuvv_x1);
    PERF(cpi_vmsltuvv_x2(), cpi_vmsltuvv_x2);
    PERF(cpi_vmsltuvv_x4(), cpi_vmsltuvv_x4);
    PERF(cpi_vmsbc_vmslt(), cpi_vmsbc_vmslt);
    PERF(cpi_vmsbc_vsub(), cpi_vmsbc_vsub);
    PERF(cpi_vmsbc_2_vsub_4(), cpi_vmsbc_2_vsub_4);
    PERF(cpi_vsrl_vmsltu(), cpi_vsrl_vmsltu);
    PERF(cpi_vmulvx(), cpi_vmulvx);
    PERF(cpi_vmulvx_x1(), cpi_vmulvx_x1);
    PERF(cpi_vmulvx_x2(), cpi_vmulvx_x2);
    PERF(cpi_vmulvx_x4(), cpi_vmulvx_x4);
    PERF(cpi_vmulvv(), cpi_vmulvv);
    PERF(cpi_vmulvv_x1(), cpi_vmulvv_x1);
    PERF(cpi_vmulvv_x2(), cpi_vmulvv_x2);
    PERF(cpi_vmulvv_x4(), cpi_vmulvv_x4);
    PERF(cpi_vmaccvv(), cpi_vmaccvv);
    PERF(cpi_vmaccvv_x1(), cpi_vmaccvv_x1);
    PERF(cpi_vmaccvv_x2(), cpi_vmaccvv_x2);
    PERF(cpi_vmaccvv_x4(), cpi_vmaccvv_x4);
    PERF(cpi_vmulhvv(), cpi_vmulhvv);
    PERF(cpi_vmulhvv_x1(), cpi_vmulhvv_x1);
    PERF(cpi_vmulhvv_x2(), cpi_vmulhvv_x2);
    PERF(cpi_vmulhvv_x4(), cpi_vmulhvv_x4);
    vec_len = init_vector_e64();
    printf("\ninit_vector_e64, the length of vector is %d bits\n",
           vec_len * 64);
    PERF(cpi_vaddvv(), cpi_vaddvv);
    PERF(cpi_vaddvx(), cpi_vaddvx);
    PERF(cpi_vaddvx_x1(), cpi_vaddvx_x1);
    PERF(cpi_vaddvx_x2(), cpi_vaddvx_x2);
    PERF(cpi_vaddvx_x4(), cpi_vaddvx_x4);
    PERF(cpi_vadcvvm(), cpi_vadcvvm);
    PERF(cpi_vadcvvm_x1(), cpi_vadcvvm_x1);
    PERF(cpi_vadcvvm_x2(), cpi_vadcvvm_x2);
    PERF(cpi_vadcvvm_x4(), cpi_vadcvvm_x4);
    PERF(cpi_vmadcvvm(), cpi_vmadcvvm);
    PERF(cpi_vmadcvvm_x1(), cpi_vmadcvvm_x1);
    PERF(cpi_vmadcvvm_x2(), cpi_vmadcvvm_x2);
    PERF(cpi_vmadcvvm_x4(), cpi_vmadcvvm_x4);
    PERF(cpi_vmadcvv(), cpi_vmadcvv);
    PERF(cpi_vmadcvv_x1(), cpi_vmadcvv_x1);
    PERF(cpi_vmadcvv_x2(), cpi_vmadcvv_x2);
    PERF(cpi_vmadcvv_x4(), cpi_vmadcvv_x4);
    PERF(cpi_vmsltuvv(), cpi_vmsltuvv);
    PERF(cpi_vmsltuvv_x1(), cpi_vmsltuvv_x1);
    PERF(cpi_vmsltuvv_x2(), cpi_vmsltuvv_x2);
    PERF(cpi_vmsltuvv_x4(), cpi_vmsltuvv_x4);
    PERF(cpi_vmsbc_vmslt(), cpi_vmsbc_vmslt);
    PERF(cpi_vmsbc_vsub(), cpi_vmsbc_vsub);
    PERF(cpi_vmsbc_2_vsub_4(), cpi_vmsbc_2_vsub_4);
    PERF(cpi_vsrl_vmsltu(), cpi_vsrl_vmsltu);
    PERF(cpi_vmulvx(), cpi_vmulvx);
    PERF(cpi_vmulvx_x1(), cpi_vmulvx_x1);
    PERF(cpi_vmulvx_x2(), cpi_vmulvx_x2);
    PERF(cpi_vmulvx_x4(), cpi_vmulvx_x4);
    PERF(cpi_vmulvv(), cpi_vmulvv);
    PERF(cpi_vmulvv_x1(), cpi_vmulvv_x1);
    PERF(cpi_vmulvv_x2(), cpi_vmulvv_x2);
    PERF(cpi_vmulvv_x4(), cpi_vmulvv_x4);
    PERF(cpi_vmaccvv(), cpi_vmaccvv);
    PERF(cpi_vmaccvv_x1(), cpi_vmaccvv_x1);
    PERF(cpi_vmaccvv_x2(), cpi_vmaccvv_x2);
    PERF(cpi_vmaccvv_x4(), cpi_vmaccvv_x4);
    PERF(cpi_vmulhvv(), cpi_vmulhvv);
    PERF(cpi_vmulhvv_x1(), cpi_vmulhvv_x1);
    PERF(cpi_vmulhvv_x2(), cpi_vmulhvv_x2);
    PERF(cpi_vmulhvv_x4(), cpi_vmulhvv_x4);

    vec_len = init_vector_e64();
    printf("\ninit_vector_e64, the length of vector is %d bits\n",
           vec_len * 64);
    double f0[4] = {1.141592653589793, 1.141592653589793,
                    1.141592653589793, 1.141592653589793};
    double f1[4] = {1.0e308, 1.0e308, 1.0e308, 1.0e308};
    init_vector_double_reg(f1);
    PERF(cpi_vfaddvv(), cpi_vfaddvv);
    PERF(cpi_vfaddvv_x1(), cpi_vfaddvv_x1);
    PERF(cpi_vfminvv(), cpi_vfminvv);
    PERF(cpi_vfminvv_x1(), cpi_vfminvv_x1);
    PERF(cpi_vfsgnjvv(), cpi_vfsgnjvv);
    PERF(cpi_vfsgnjvv_x1(), cpi_vfsgnjvv_x1);

    for (int i = 0; i < 4; i++)
        f0[i] = 1.141592653589793;
    for (int i = 0; i < 4; i++)
        f1[i] = 2.141592653589793;
    pre_v0v1(f0, f1);
    printf("v0 = %g, v1 = %g:\n", f0[0], f1[0]);
    PERF(cpi_vfmulvv(), cpi_vfmulvv);
    PERF(cpi_vfmaccvv(), cpi_vfmaccvv);
    PERF(cpi_vfdivvv(), cpi_vfdivvv);
    PERF(cpi_vfsqrtv(), cpi_vfsqrtv);

    for (int i = 0; i < 4; i++)
        f0[i] = 1.0e308;
    for (int i = 0; i < 4; i++)
        f1[i] = 1.0e-308;
    pre_v0v1(f0, f1);
    printf("v0 = %g, v1 = %g:\n", f0[0], f1[0]);
    PERF(cpi_vfmulvv(), cpi_vfmulvv);
    PERF(cpi_vfmaccvv(), cpi_vfmaccvv);
    PERF(cpi_vfdivvv(), cpi_vfdivvv);
    PERF(cpi_vfsqrtv(), cpi_vfsqrtv);

    for (int i = 0; i < 4; i++)
        f0[i] = 1.0e-308;
    for (int i = 0; i < 4; i++)
        f1[i] = 1.0e308;
    pre_v0v1(f0, f1);
    printf("v0 = %g, v1 = %g:\n", f0[0], f1[0]);
    PERF(cpi_vfmulvv(), cpi_vfmulvv);
    PERF(cpi_vfmaccvv(), cpi_vfmaccvv);
    PERF(cpi_vfdivvv(), cpi_vfdivvv);
    PERF(cpi_vfsqrtv(), cpi_vfsqrtv);

    for (int i = 0; i < 4; i++)
        f0[i] = 1.0e308;
    for (int i = 0; i < 4; i++)
        f1[i] = 1.141592653589793;
    pre_v0v1(f0, f1);
    printf("v0 = %g, v1 = %g:\n", f0[0], f1[0]);
    PERF(cpi_vfmulvv(), cpi_vfmulvv);
    PERF(cpi_vfmaccvv(), cpi_vfmaccvv);
    PERF(cpi_vfdivvv(), cpi_vfdivvv);
    PERF(cpi_vfsqrtv(), cpi_vfsqrtv);
    pre_v0v1(f0, f1);
    PERF(cpi_vfmulvv_x1(), cpi_vfmulvv_x1);
    pre_v0v1(f0, f1);
    PERF(cpi_vfmaccvv_x1(), cpi_vfmaccvv_x1);
    pre_v0v1(f0, f1);
    PERF(cpi_vfdivvv_x1(), cpi_vfdivvv_x1);
    pre_v0v1(f0, f1);
    PERF(cpi_vfsqrtv_x1(), cpi_vfsqrtv_x1);
    return 0;
}