.text

.macro fld_m n
    fld f\n, (a0)
.endm

.macro FUNC name
    .global \name
    .align 2
    \name:
.endm

.macro FUNC_END name
    ret
    .type \name, %function
    .size \name, .-\name
.endm

FUNC init_f_registers
    fld_m 0
    fld_m 1
    fld_m 2
    fld_m 3
    fld_m 4
    fld_m 5
    fld_m 6
    fld_m 7
    fld_m 8
    fld_m 9
    fld_m 10
    fld_m 11
    fld_m 12
    fld_m 13
    fld_m 14
    fld_m 15
FUNC_END init_f_registers

FUNC cpi_fld
.rep 200
    fld f0, 8*0(a0)
    fld f1, 8*1(a0)
    fld f2, 8*2(a0)
    fld f3, 8*3(a0)
    fld f4, 8*4(a0)
    fld f5, 8*5(a0)
    fld f6, 8*6(a0)
    fld f7, 8*7(a0)
.endr
FUNC_END cpi_fld

FUNC cpi_fld_fadd
.rep 200
    fld f0, 8*0(a0)
    fld f1, 8*1(a0)
    fadd.d f2, f0, f1
    fadd.d f3, f0, f1
    fadd.d f4, f0, f1
    fadd.d f5, f0, f1
    fadd.d f6, f0, f1
    fadd.d f7, f0, f1
    fadd.d f8, f0, f1
    fadd.d f9, f0, f1
.endr
FUNC_END cpi_fld_fadd

FUNC cpi_fadd
.rep 200
    fadd.d f0, f0, f0
    fadd.d f1, f1, f1
    fadd.d f2, f2, f2
    fadd.d f3, f3, f3
    fadd.d f4, f4, f4
    fadd.d f5, f5, f5
    fadd.d f6, f6, f6
    fadd.d f7, f7, f7
.endr
FUNC_END cpi_fadd

FUNC cpi_fadd_x1
.rep 1600
    fadd.d f0, f0, f0
.endr
FUNC_END cpi_fadd_x1

FUNC cpi_fmin
.rep 200
    fmin.d f0, f0, f0
    fmin.d f1, f1, f1
    fmin.d f2, f2, f2
    fmin.d f3, f3, f3
    fmin.d f4, f4, f4
    fmin.d f5, f5, f5
    fmin.d f6, f6, f6
    fmin.d f7, f7, f7
.endr
FUNC_END cpi_fmin

FUNC cpi_fmin_x1
.rep 1600
    fmin.d f0, f0, f0
.endr
FUNC_END cpi_fmin_x1

FUNC cpi_fsgnj
.rep 200
    fsgnj.d f0, f0, f0
    fsgnj.d f1, f1, f1
    fsgnj.d f2, f2, f2
    fsgnj.d f3, f3, f3
    fsgnj.d f4, f4, f4
    fsgnj.d f5, f5, f5
    fsgnj.d f6, f6, f6
    fsgnj.d f7, f7, f7
.endr
FUNC_END cpi_fsgnj

FUNC cpi_fsgnj_x1
.rep 1600
    fsgnj.d f0, f0, f0
.endr
FUNC_END cpi_fsgnj_x1

FUNC pre_f0f1
    fld f0, (a0)
    fld f1, (a1)
FUNC_END pre_f0f1

FUNC cpi_fmul
.rep 200
    fmul.d f8,  f0, f1
    fmul.d f9,  f0, f1
    fmul.d f10, f0, f1
    fmul.d f11, f0, f1
    fmul.d f12, f0, f1
    fmul.d f13, f0, f1
    fmul.d f14, f0, f1
    fmul.d f15, f0, f1
.endr
FUNC_END cpi_fmul

FUNC cpi_fmul_x1
.rep 1600
    fmul.d f0, f0, f1
.endr
FUNC_END cpi_fmul_x1

FUNC cpi_fmadd
.rep 200
    fmadd.d f10, f0, f1, f1
    fmadd.d f11, f0, f1, f1
    fmadd.d f12, f0, f1, f1
    fmadd.d f13, f0, f1, f1
    fmadd.d f14, f0, f1, f1
    fmadd.d f15, f0, f1, f1
    fmadd.d f16, f0, f1, f1
    fmadd.d f17, f0, f1, f1
.endr
FUNC_END cpi_fmadd

FUNC cpi_fmadd_x1
.rep 1600
    fmadd.d f0, f0, f1, f1
.endr
FUNC_END cpi_fmadd_x1

FUNC cpi_fdiv
.rep 200
    fdiv.d f8,  f0, f1
    fdiv.d f9,  f0, f1
    fdiv.d f10, f0, f1
    fdiv.d f11, f0, f1
    fdiv.d f12, f0, f1
    fdiv.d f13, f0, f1
    fdiv.d f14, f0, f1
    fdiv.d f15, f0, f1
.endr
FUNC_END cpi_fdiv

FUNC cpi_fdiv_x1
.rep 1600
    fdiv.d f0, f0, f1
.endr
FUNC_END cpi_fdiv_x1

FUNC cpi_fsqrt
.rep 200
    fsqrt.d f8,  f0
    fsqrt.d f9,  f0
    fsqrt.d f10, f0
    fsqrt.d f11, f0
    fsqrt.d f12, f0
    fsqrt.d f13, f0
    fsqrt.d f14, f0
    fsqrt.d f15, f0
.endr
FUNC_END cpi_fsqrt

FUNC cpi_fsqrt_x1
.rep 1600
    fsqrt.d f0, f0
.endr
FUNC_END cpi_fsqrt_x1