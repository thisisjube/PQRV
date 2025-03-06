.text

.macro fld_m n
    fld f\n, (a0)
.endm

.globl init_f_registers
.align 2
init_f_registers:
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
ret

.globl cpi_fadd
.align 2
cpi_fadd:
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
ret

.globl cpi_fadd_x1
.align 2
cpi_fadd_x1:
.rep 1600
    fadd.d f0, f0, f0
.endr
ret

.globl cpi_fmul
.align 2
cpi_fmul:
.rep 200
    fmul.d f8,  f0, f0
    fmul.d f9,  f1, f1
    fmul.d f10, f2, f2
    fmul.d f11, f3, f3
    fmul.d f12, f4, f4
    fmul.d f13, f5, f5
    fmul.d f14, f6, f6
    fmul.d f15, f7, f7
.endr
ret

.globl cpi_fmul_x1
.align 2
cpi_fmul_x1:
.rep 1600
    fmul.d f0, f0, f0
.endr
ret

.globl cpi_fmin
.align 2
cpi_fmin:
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
ret

.globl cpi_fmin_x1
.align 2
cpi_fmin_x1:
.rep 1600
    fmin.d f0, f0, f0
.endr
ret

.globl cpi_fmadd
.align 2
cpi_fmadd:
.rep 200
    fmadd.d f0, f0, f0, f0
    fmadd.d f1, f1, f1, f1
    fmadd.d f2, f2, f2, f2
    fmadd.d f3, f3, f3, f3
    fmadd.d f4, f4, f4, f4
    fmadd.d f5, f5, f5, f5
    fmadd.d f6, f6, f6, f6
    fmadd.d f7, f7, f7, f7
.endr
ret

.globl cpi_fmadd_x1
.align 2
cpi_fmadd_x1:
.rep 1600
    fmadd.d f0, f0, f0, f0
.endr
ret

.globl cpi_fsgnj
.align 2
cpi_fsgnj:
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
ret

.globl cpi_fsgnj_x1
.align 2
cpi_fsgnj_x1:
.rep 1600
    fsgnj.d f0, f0, f0
.endr
ret

.globl pre_div
.align 2
pre_div:
    fld f0, (a0)
    fld f1, (a1)
ret

.globl cpi_fdiv
.align 2
cpi_fdiv:
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
ret

.globl cpi_fdiv_x1
.align 2
cpi_fdiv_x1:
.rep 1600
    fdiv.d f0, f0, f1
.endr
ret

.globl cpi_fsqrt
.align 2
cpi_fsqrt:
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
ret

.globl cpi_fsqrt_x1
.align 2
cpi_fsqrt_x1:
.rep 1600
    fsqrt.d f0, f0
.endr
ret