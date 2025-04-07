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

.macro OP_VX op
.rep 200
    \op v0, v0, t0
    \op v1, v1, t0
    \op v2, v2, t0
    \op v3, v3, t0
    \op v4, v4, t0
    \op v5, v5, t0
    \op v6, v6, t0
    \op v7, v7, t0
    \op v8, v8, t0
    \op v9, v9, t0
.endr
.endm

.macro OP_VX_x1 op
.rep 2000
    \op v0, v0, t0
.endr
.endm

.macro OP_VX_x2 op
.rep 1000
    \op v0, v0, t0
    \op v1, v1, t0
.endr
.endm

.macro OP_VX_x4 op
.rep 500
    \op v0, v0, t0
    \op v1, v1, t0
    \op v2, v2, t0
    \op v3, v3, t0
.endr
.endm

.macro OP_VV op
.rep 200
    \op v10, v0, v1
    \op v11, v0, v1
    \op v12, v0, v1
    \op v13, v0, v1
    \op v14, v0, v1
    \op v15, v0, v1
    \op v16, v0, v1
    \op v17, v0, v1
    \op v18, v0, v1
    \op v19, v0, v1
.endr
.endm

.macro OP_VV_x1 op
.rep 2000
    \op v0, v0, v1
.endr
.endm

.macro OP_VV_x2 op
.rep 1000
    \op v10, v10, v5
    \op v11, v11, v5
.endr
.endm

.macro OP_VV_x4 op
.rep 500
    \op v10, v10, v5
    \op v11, v11, v5
    \op v12, v12, v5
    \op v13, v13, v5
.endr
.endm

.macro OP_VI op
.rep 200
    \op v0, v0, 10
    \op v1, v1, 10
    \op v2, v2, 10
    \op v3, v3, 10
    \op v4, v4, 10
    \op v5, v5, 10
    \op v6, v6, 10
    \op v7, v7, 10
    \op v8, v8, 10
    \op v9, v9, 10
.endr
.endm

.macro OP_VI_x1 op
.rep 2000
    \op v0, v0, 10
.endr
.endm

.macro OP_VI_x2 op
.rep 1000
    \op v0, v0, 10
    \op v1, v1, 10
.endr
.endm

.macro OP_VI_x4 op
.rep 500
    \op v0, v0, 10
    \op v1, v1, 10
    \op v2, v2, 10
    \op v3, v3, 10
.endr
.endm

.macro OP_V op
.rep 200
    \op v10, v0
    \op v11, v1
    \op v12, v2
    \op v13, v3
    \op v14, v4
    \op v15, v5
    \op v16, v6
    \op v17, v7
    \op v18, v8
    \op v19, v9
.endr
.endm

.macro OP_V_x1 op
.rep 2000
    \op v0, v0
.endr
.endm

.macro OP_V_x2 op
.rep 1000
    \op v0, v0
    \op v1, v1
.endr
.endm

.macro OP_V_x4 op
.rep 500
    \op v0, v0
    \op v1, v1
    \op v2, v2
    \op v3, v3
.endr
.endm

.macro OP_VVM op
.rep 200
    \op v11, v1,  v1,  v0
    \op v12, v2,  v2,  v0
    \op v13, v3,  v3,  v0
    \op v14, v4,  v4,  v0
    \op v15, v5,  v5,  v0
    \op v16, v6,  v6,  v0
    \op v17, v7,  v7,  v0
    \op v18, v8,  v8,  v0
    \op v19, v9,  v9,  v0
    \op v20, v10, v10, v0
.endr
.endm

.macro OP_VVM_x1 op
.rep 2000
    \op v1, v1,  v1,  v0
.endr
.endm

.macro OP_VVM_x2 op
.rep 1000
    \op v1, v1,  v1,  v0
    \op v2, v2,  v2,  v0
.endr
.endm

.macro OP_VVM_x4 op
.rep 500
    \op v1, v1,  v1,  v0
    \op v2, v2,  v2,  v0
    \op v3, v3,  v3,  v0
    \op v4, v4,  v4,  v0
.endr
.endm

.macro F_OP_VX op
FUNC cpi_\()\op\()vx
    OP_VX \op\().vx
FUNC_END cpi_\()\op\()vx
.endm

.macro F_OP_VX_x1 op
FUNC cpi_\()\op\()vx_x1
    OP_VX_x1 \op\().vx
FUNC_END cpi_\()\op\()vx_x1
.endm

.macro F_OP_VX_x2 op
FUNC cpi_\()\op\()vx_x2
    OP_VX_x2 \op\().vx
FUNC_END cpi_\()\op\()vx_x2
.endm

.macro F_OP_VX_x4 op
FUNC cpi_\()\op\()vx_x4
    OP_VX_x4 \op\().vx
FUNC_END cpi_\()\op\()vx_x4
.endm

.macro F_OP_VI op
FUNC cpi_\()\op\()vi
    OP_VI \op\().vi
FUNC_END cpi_\()\op\()vi
.endm

.macro F_OP_VI_x1 op
FUNC cpi_\()\op\()vi_x1
    OP_VI_x1 \op\().vi
FUNC_END cpi_\()\op\()vi_x1
.endm

.macro F_OP_VI_x2 op
FUNC cpi_\()\op\()vi_x2
    OP_VI_x2 \op\().vi
FUNC_END cpi_\()\op\()vi_x2
.endm

.macro F_OP_VI_x4 op
FUNC cpi_\()\op\()vi_x4
    OP_VI_x4 \op\().vi
FUNC_END cpi_\()\op\()vi_x4
.endm

.macro F_OP_VV op
FUNC cpi_\()\op\()vv
    OP_VV \op\().vv
FUNC_END cpi_\()\op\()vv
.endm

.macro F_OP_VV_x1 op
FUNC cpi_\()\op\()vv_x1
    OP_VV_x1 \op\().vv
FUNC_END cpi_\()\op\()vv_x1
.endm

.macro F_OP_VV_x2 op
FUNC cpi_\()\op\()vv_x2
    OP_VV_x2 \op\().vv
FUNC_END cpi_\()\op\()vv_x2
.endm

.macro F_OP_VV_x4 op
FUNC cpi_\()\op\()vv_x4
    OP_VV_x4 \op\().vv
FUNC_END cpi_\()\op\()vv_x4
.endm

.macro F_OP_V op
FUNC cpi_\()\op\()v
    OP_V \op\().v
FUNC_END cpi_\()\op\()v
.endm

.macro F_OP_V_x1 op
FUNC cpi_\()\op\()v_x1
    OP_V_x1 \op\().v
FUNC_END cpi_\()\op\()v_x1
.endm

.macro F_OP_V_x2 op
FUNC cpi_\()\op\()v_x2
    OP_V_x2 \op\().v
FUNC_END cpi_\()\op\()v_x2
.endm

.macro F_OP_V_x4 op
FUNC cpi_\()\op\()v_x4
    OP_V_x4 \op\().v
FUNC_END cpi_\()\op\()v_x4
.endm

.macro F_OP_VVM op
FUNC cpi_\()\op\()vvm
    OP_VVM \op\().vvm
FUNC_END cpi_\()\op\()vvm
.endm

.macro F_OP_VVM_x1 op
FUNC cpi_\()\op\()vvm_x1
    OP_VVM_x1 \op\().vvm
FUNC_END cpi_\()\op\()vvm_x1
.endm

.macro F_OP_VVM_x2 op
FUNC cpi_\()\op\()vvm_x2
    OP_VVM_x2 \op\().vvm
FUNC_END cpi_\()\op\()vvm_x2
.endm

.macro F_OP_VVM_x4 op
FUNC cpi_\()\op\()vvm_x4
    OP_VVM_x4 \op\().vvm
FUNC_END cpi_\()\op\()vvm_x4
.endm


FUNC init_vector_e16
    vsetivli a0, 16, e16, m1, tu, mu
ret

FUNC init_vector_e32
    vsetivli a0, 8, e32, m1, tu, mu
ret

FUNC init_vector_e64
    vsetivli a0, 4, e64, m1, tu, mu
ret

FUNC cpi_vle16
.rep 200
    vle16.v v0, (a0)
    vle16.v v1, (a0)
    vle16.v v2, (a0)
    vle16.v v3, (a0)
    vle16.v v4, (a0)
    vle16.v v5, (a0)
    vle16.v v6, (a0)
    vle16.v v7, (a0)
    vle16.v v8, (a0)
    vle16.v v9, (a0)
.endr
ret

FUNC cpi_vle16_add
.rep 200
    vle16.v v0, (a0)
    vadd.vv v10, v0, v0
    vadd.vv v11, v0, v0
    vadd.vv v12, v0, v0
    vadd.vv v13, v0, v0
.endr
ret

FUNC cpi_vse16
.rep 200
    vse16.v v0, (a0)
    vse16.v v1, (a1)
    vse16.v v2, (a2)
    vse16.v v3, (a3)
.endr
ret

# Since there is no data dependency between vse and vadd instructions, the actual latency of vse instruction cannot be reflected.
FUNC cpi_vse16_add
.rep 200
    vse16.v v0, (a0)
    vadd.vv v10, v0, v0
    vadd.vv v11, v0, v0
    vadd.vv v12, v0, v0
    vadd.vv v13, v0, v0
.endr
ret

F_OP_VX vmul
F_OP_VX_x1 vmul
F_OP_VX_x2 vmul
F_OP_VX_x4 vmul

F_OP_VV vmul
F_OP_VV_x1 vmul
F_OP_VV_x2 vmul
F_OP_VV_x4 vmul

F_OP_VV vmacc
F_OP_VV_x1 vmacc
F_OP_VV_x2 vmacc
F_OP_VV_x4 vmacc

F_OP_VV vmulh
F_OP_VV_x1 vmulh
F_OP_VV_x2 vmulh
F_OP_VV_x4 vmulh

F_OP_VV vadd
F_OP_VX vadd
F_OP_VX_x1 vadd
F_OP_VX_x2 vadd
F_OP_VX_x4 vadd

F_OP_VVM vadc
F_OP_VVM_x1 vadc
F_OP_VVM_x2 vadc
F_OP_VVM_x4 vadc
F_OP_VVM vmadc
F_OP_VVM_x1 vmadc
F_OP_VVM_x2 vmadc
F_OP_VVM_x4 vmadc
F_OP_VV  vmadc
F_OP_VV_x1 vmadc
F_OP_VV_x2 vmadc
F_OP_VV_x4 vmadc

F_OP_VV vand
F_OP_VV_x1 vand
F_OP_VV_x2 vand
F_OP_VV_x4 vand
F_OP_VV vxor
F_OP_VV_x1 vxor
F_OP_VV_x2 vxor
F_OP_VV_x4 vxor

F_OP_VX vand

F_OP_V vnot
F_OP_V_x1 vnot
F_OP_V_x2 vnot
F_OP_V_x4 vnot

F_OP_VI vsll
F_OP_VI_x1 vsll
F_OP_VI_x2 vsll
F_OP_VI_x4 vsll

FUNC cpi_vssrlvi
    # vxrm[1:0]=0b00 for round-to-nearest-up; =0b10 for round-down
    csrwi vxrm, 0
    OP_VI vssrl.vi
ret

F_OP_VI_x1 vssrl
F_OP_VI_x2 vssrl
F_OP_VI_x4 vssrl

F_OP_VX vsrl
F_OP_VX_x1 vsrl
F_OP_VX_x2 vsrl
F_OP_VX_x4 vsrl

F_OP_VI vsra
F_OP_VI_x1 vsra
F_OP_VI_x2 vsra
F_OP_VI_x4 vsra

F_OP_VV vrgather

FUNC cpi_vrgathervv_x1
.rep 200
    vrgather.vv v1, v0, v20
    vrgather.vv v2, v1, v20
    vrgather.vv v3, v2, v20
    vrgather.vv v4, v3, v20
    vrgather.vv v5, v4, v20
    vrgather.vv v6, v5, v20
    vrgather.vv v7, v6, v20
    vrgather.vv v8, v7, v20
    vrgather.vv v9, v8, v20
    vrgather.vv v10, v9, v20
    vrgather.vv v11, v10, v20
    vrgather.vv v12, v11, v20
    vrgather.vv v13, v12, v20
    vrgather.vv v14, v13, v20
    vrgather.vv v15, v14, v20
    vrgather.vv v16, v15, v20
    vrgather.vv v17, v16, v20
    vrgather.vv v18, v17, v20
    vrgather.vv v0, v18, v20
.endr
ret

FUNC cpi_vrgathervv_x2
.rep 1000
    vrgather.vv v1, v0, v20
    vrgather.vv v3, v2, v20
.endr
ret

FUNC cpi_vrgathervv_x4
.rep 500
    vrgather.vv v1, v0, v20
    vrgather.vv v3, v2, v20
    vrgather.vv v5, v4, v20
    vrgather.vv v7, v6, v20
.endr
ret

FUNC cpi_vmergevvm
.rep 200
    vmerge.vvm v1, v1, v2, v0
    vmerge.vvm v3, v3, v4, v0
    vmerge.vvm v5, v5, v6, v0
    vmerge.vvm v7, v7, v8, v0
    vmerge.vvm v9, v9, v10,v0
    vmerge.vvm v11,v11,v12,v0
    vmerge.vvm v13,v13,v14,v0
    vmerge.vvm v15,v15,v16,v0
    vmerge.vvm v17,v17,v18,v0
    vmerge.vvm v19,v19,v20,v0
.endr
ret

FUNC cpi_vmergevvm_x1
.rep 2000
    vmerge.vvm v1, v1, v2, v0
.endr
ret

FUNC cpi_vmergevvm_x2
.rep 1000
    vmerge.vvm v1, v1, v2, v0
    vmerge.vvm v3, v3, v4, v0
.endr
ret

FUNC cpi_vmergevvm_x4
.rep 500
    vmerge.vvm v1, v1, v2, v0
    vmerge.vvm v3, v3, v4, v0
    vmerge.vvm v5, v5, v6, v0
    vmerge.vvm v7, v7, v8, v0
.endr
ret

FUNC init_vector_double_reg
    vle64.v v0, (a0); vle64.v v1, (a0)
    vle64.v v2, (a0); vle64.v v3, (a0)
    vle64.v v4, (a0); vle64.v v5, (a0)
    vle64.v v6, (a0); vle64.v v7, (a0)
    vle64.v v8, (a0); vle64.v v9, (a0)
ret

FUNC pre_v0v1
    vle64.v v0, (a0)
    vle64.v v1, (a1)
ret

F_OP_VV vfadd
F_OP_VV_x1 vfadd

F_OP_VV vfmin
F_OP_VV_x1 vfmin

F_OP_VV vfsgnj
F_OP_VV_x1 vfsgnj

F_OP_VV vfmul
F_OP_VV_x1 vfmul

F_OP_VV vfmacc
F_OP_VV_x1 vfmacc

F_OP_VV vfdiv
F_OP_VV_x1 vfdiv

F_OP_V vfsqrt
F_OP_V_x1 vfsqrt

FUNC cpi_vandvx_and_hybrid_v1
.rep 200
    vand.vx v0, v0, t0
    vand.vx v1, v1, t0
    and t1, t1, t1
    vand.vx v2, v2, t0
    vand.vx v3, v3, t0
    and t2, t2, t2
    vand.vx v4, v4, t0
    vand.vx v5, v5, t0
    and t3, t3, t3
    vand.vx v6, v6, t0
    vand.vx v7, v7, t0
    and t4, t4, t4
    vand.vx v8, v8, t0
    vand.vx v9, v9, t0
    and t5, t5, t5
.endr
ret

FUNC cpi_vandvx_and_hybrid_v2
.rep 200
    vand.vx v0, v0, t0
    vand.vx v1, v1, t0
    and t1, t1, t1
    and a1, a1, a1
    vand.vx v2, v2, t0
    vand.vx v3, v3, t0
    and t2, t2, t2
    and a2, t1, a2
    vand.vx v4, v4, t0
    vand.vx v5, v5, t0
    and t3, t3, t3
    and a3, a3, a3
    vand.vx v6, v6, t0
    vand.vx v7, v7, t0
    and t4, t4, t4
    and a4, a4, a4
    vand.vx v8, v8, t0
    vand.vx v9, v9, t0
    and t5, t5, t5
    and a5, a5, a5
.endr
ret

FUNC cpi_vandvx_and_hybrid_v3
.rep 200
    vand.vx v0, v0, t0
    vand.vx v1, v1, t0
    and t1, t1, t1
    and a1, a1, a1
    and t1, t1, t1
    vand.vx v2, v2, t0
    vand.vx v3, v3, t0
    and t2, t2, t2
    and a2, t1, a2
    and t2, t2, t2
    vand.vx v4, v4, t0
    vand.vx v5, v5, t0
    and t3, t3, t3
    and a3, a3, a3
    and t3, t3, t3
    vand.vx v6, v6, t0
    vand.vx v7, v7, t0
    and t4, t4, t4
    and a4, a4, a4
    and t4, t4, t4
    vand.vx v8, v8, t0
    vand.vx v9, v9, t0
    and t5, t5, t5
    and a5, a5, a5
    and t5, t5, t5
.endr
ret

FUNC cpi_vandvx_and_hybrid_v4
.rep 200
    vand.vx v0, v0, t0
    vand.vx v1, v1, t0
    and t1, t1, t1
    and a1, a1, a1
    and t1, t1, t1
    and a1, a1, a1
    vand.vx v2, v2, t0
    vand.vx v3, v3, t0
    and t2, t2, t2
    and a2, t1, a2
    and t2, t2, t2
    and a2, t1, a2
    vand.vx v4, v4, t0
    vand.vx v5, v5, t0
    and t3, t3, t3
    and a3, a3, a3
    and t3, t3, t3
    and a3, a3, a3
    vand.vx v6, v6, t0
    vand.vx v7, v7, t0
    and t4, t4, t4
    and a4, a4, a4
    and t4, t4, t4
    and a4, a4, a4
    vand.vx v8, v8, t0
    vand.vx v9, v9, t0
    and t5, t5, t5
    and a5, a5, a5
    and t5, t5, t5
    and a5, a5, a5
.endr
ret

FUNC cpi_vandvx_and_hybrid_v4_1
.rep 200
    vand.vx v0, v0, t0
    and t1, t1, t1
    and a1, a1, a1
    vand.vx v1, v1, t0
    and t1, t1, t1
    and a1, a1, a1
    vand.vx v2, v2, t0
    and t2, t2, t2
    and a2, t1, a2
    vand.vx v3, v3, t0
    and t2, t2, t2
    and a2, t1, a2
    vand.vx v4, v4, t0
    and t3, t3, t3
    and a3, a3, a3
    vand.vx v5, v5, t0
    and t3, t3, t3
    and a3, a3, a3
    vand.vx v6, v6, t0
    and t4, t4, t4
    and a4, a4, a4
    vand.vx v7, v7, t0
    and t4, t4, t4
    and a4, a4, a4
    vand.vx v8, v8, t0
    and t5, t5, t5
    and a5, a5, a5
    vand.vx v9, v9, t0
    and t5, t5, t5
    and a5, a5, a5
.endr
ret

FUNC cpi_vandvx_and_hybrid_v5
.rep 200
    vand.vx v0, v0, t0
    vand.vx v1, v1, t0
    and t1, t1, t1
    and a1, a1, a1
    and t1, t1, t1
    and a1, a1, a1
    and t1, t1, t1
    vand.vx v2, v2, t0
    vand.vx v3, v3, t0
    and t2, t2, t2
    and a2, t1, a2
    and t2, t2, t2
    and a2, t1, a2
    and t2, t2, t2
    vand.vx v4, v4, t0
    vand.vx v5, v5, t0
    and t3, t3, t3
    and a3, a3, a3
    and t3, t3, t3
    and a3, a3, a3
    and t3, t3, t3
    vand.vx v6, v6, t0
    vand.vx v7, v7, t0
    and t4, t4, t4
    and a4, a4, a4
    and t4, t4, t4
    and a4, a4, a4
    and t4, t4, t4
    vand.vx v8, v8, t0
    vand.vx v9, v9, t0
    and t5, t5, t5
    and a5, a5, a5
    and t5, t5, t5
    and a5, a5, a5
    and t5, t5, t5
.endr
ret

FUNC cpi_vandvx_and_hybrid_v6
.rep 200
    vand.vx v0, v0, t0
    vand.vx v1, v1, t0
    and t1, t1, t1
    and a1, a1, a1
    and t1, t1, t1
    and a1, a1, a1
    and t1, t1, t1
    and a1, a1, a1
    vand.vx v2, v2, t0
    vand.vx v3, v3, t0
    and t2, t2, t2
    and a2, t1, a2
    and t2, t2, t2
    and a2, t1, a2
    and t2, t2, t2
    and a2, t1, a2
    vand.vx v4, v4, t0
    vand.vx v5, v5, t0
    and t3, t3, t3
    and a3, a3, a3
    and t3, t3, t3
    and a3, a3, a3
    and t3, t3, t3
    and a3, a3, a3
    vand.vx v6, v6, t0
    vand.vx v7, v7, t0
    and t4, t4, t4
    and a4, a4, a4
    and t4, t4, t4
    and a4, a4, a4
    and t4, t4, t4
    and a4, a4, a4
    vand.vx v8, v8, t0
    vand.vx v9, v9, t0
    and t5, t5, t5
    and a5, a5, a5
    and t5, t5, t5
    and a5, a5, a5
    and t5, t5, t5
    and a5, a5, a5
.endr
ret
