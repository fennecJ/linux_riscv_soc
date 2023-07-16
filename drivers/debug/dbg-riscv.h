#define RV_OP_LOAD 0x0
#define RV_OP_LOAD_FP 0x1
#define RV_OP_CUST_0 0x2
#define RV_OP_MISC_MEM 0x3
#define RV_OP_OP_IMM 0x4
#define RV_OP_AUIPC 0x5
#define RV_OP_OP_IMM_32 0x6
#define RV_OP_STORE 0x8
#define RV_OP_STORE_FP 0x9
#define RV_OP_CUST_1 0xa
#define RV_OP_AMO 0xb
#define RV_OP_OP 0xc
#define RV_OP_LUI 0xd
#define RV_OP_OP_32 0xe
#define RV_OP_MADD 0x10
#define RV_OP_MSUB 0x11
#define RV_OP_NMSUB 0x12
#define RV_OP_NMADD 0x13
#define RV_OP_OP_FP 0x14
#define RV_OP_RSV_0 0x15
#define RV_OP_CUST_2 0x16
#define RV_OP_BRANCH 0x18
#define RV_OP_JALR 0x19
#define RV_OP_RSV_1 0x1a
#define RV_OP_JAL 0x1b
#define RV_OP_SYSTEM 0x1c
#define RV_OP_RSV_2 0x1d
#define RV_OP_CUST_3 0x1e

#define RV_OP16_C0 0
#define RV_OP16_C1 1
#define RV_OP16_C2 2

#define RV_FUNCT3_JALR 0x0
#define RV_FUNCT3_BEQ 0x0
#define RV_FUNCT3_BNE 0x1
#define RV_FUNCT3_BLT 0x4
#define RV_FUNCT3_BGE 0x5
#define RV_FUNCT3_BLTU 0x6
#define RV_FUNCT3_BGEU 0x7
#define RV_FUNCT3_LB 0x0
#define RV_FUNCT3_LH 0x1
#define RV_FUNCT3_LW 0x2
#define RV_FUNCT3_LD 0x3
#define RV_FUNCT3_LBU 0x4
#define RV_FUNCT3_LHU 0x5
#define RV_FUNCT3_LWU 0x6
#define RV_FUNCT3_SB 0x0
#define RV_FUNCT3_SH 0x1
#define RV_FUNCT3_SW 0x2
#define RV_FUNCT3_SD 0x3
#define RV_FUNCT3_ADDI 0x0
#define RV_FUNCT3_SLTI 0x2
#define RV_FUNCT3_SLTIU 0x3
#define RV_FUNCT3_XORI 0x4
#define RV_FUNCT3_ORI 0x6
#define RV_FUNCT3_ANDI 0x7
#define RV_FUNCT3_SLLI 0x1
#define RV_FUNCT3_SRLI 0x5
#define RV_FUNCT3_SRAI 0x5
#define RV_FUNCT3_ADD 0x0
#define RV_FUNCT3_SUB 0x0
#define RV_FUNCT3_SLL 0x1
#define RV_FUNCT3_SLT 0x2
#define RV_FUNCT3_SLTU 0x3
#define RV_FUNCT3_XOR 0x4
#define RV_FUNCT3_SRL 0x5
#define RV_FUNCT3_SRA 0x5
#define RV_FUNCT3_OR 0x6
#define RV_FUNCT3_AND 0x7
#define RV_FUNCT3_FENCE 0x0
#define RV_FUNCT3_FENCE_I 0x1
#define RV_FUNCT3_PRIV 0x0
#define RV_FUNCT3_CSRRW 0x1
#define RV_FUNCT3_CSRRS 0x2
#define RV_FUNCT3_CSRRC 0x3
#define RV_FUNCT3_CSRRWI 0x5
#define RV_FUNCT3_CSRRSI 0x6
#define RV_FUNCT3_CSRRCI 0x7
#define RV_FUNCT3_MUL 0x0
#define RV_FUNCT3_MULH 0x1
#define RV_FUNCT3_MULHSU 0x2
#define RV_FUNCT3_MULHU 0x3
#define RV_FUNCT3_DIV 0x4
#define RV_FUNCT3_DIVU 0x5
#define RV_FUNCT3_REM 0x6
#define RV_FUNCT3_REMU 0x7

#define RV_FUNCT5_LR 0x02
#define RV_FUNCT5_SC 0x03
#define RV_FUNCT5_AMOSWAP 0x01
#define RV_FUNCT5_AMOADD 0x00
#define RV_FUNCT5_AMOXOR 0x04
#define RV_FUNCT5_AMOAND 0x0c
#define RV_FUNCT5_AMOOR 0x08
#define RV_FUNCT5_AMOMIN 0x10
#define RV_FUNCT5_AMOMAX 0x14
#define RV_FUNCT5_AMOMINU 0x18
#define RV_FUNCT5_AMOMAXU 0x1c

#define RV_FUNCT7_SLLI 0x00
#define RV_FUNCT7_SRLI 0x00
#define RV_FUNCT7_SRAI 0x20
#define RV_FUNCT7_OP0 0x00
#define RV_FUNCT7_OP1 0x20
#define RV_FUNCT7_SFENCE_VMA 0x09
#define RV_FUNCT7_MULDIV 0x01

#define RV_FUNCT12_ECALL 0x000
#define RV_FUNCT12_EBREAK 0x001
#define RV_FUNCT12_WFI 0x105
#define RV_FUNCT12_SRET 0x102
#define RV_FUNCT12_MRET 0x302

#define RV_FUNCT3_C0_ADDI4SPN 0x0
#define RV_FUNCT3_C0_FLD 0x1
#define RV_FUNCT3_C0_LW 0x2
#define RV_FUNCT3_C0_FLW 0x3
#define RV_FUNCT3_C0_FSD 0x5
#define RV_FUNCT3_C0_SW 0x6
#define RV_FUNCT3_C0_FSW 0x7

#define RV_FUNCT3_C1_ADDI 0x0
#define RV_FUNCT3_C1_JAL 0x1
#define RV_FUNCT3_C1_LI 0x2
#define RV_FUNCT3_C1_LUI 0x3
#define RV_FUNCT3_C1_OP 0x4
#define RV_FUNCT3_C1_J 0x5
#define RV_FUNCT3_C1_BEQZ 0x6
#define RV_FUNCT3_C1_BNEZ 0x7

#define RV_FUNCT3_C2_SLLI 0x0
#define RV_FUNCT3_C2_FLDSP 0x1
#define RV_FUNCT3_C2_LWSP 0x2
#define RV_FUNCT3_C2_FLWSP 0x3
#define RV_FUNCT3_C2_OP 0x4
#define RV_FUNCT3_C2_FSDSP 0x5
#define RV_FUNCT3_C2_SWSP 0x6
#define RV_FUNCT3_C2_FSWSP 0x7

#define RV_FUNCT2_OP_IMM_C_SRLI 0x0
#define RV_FUNCT2_OP_IMM_C_SRAI 0x1
#define RV_FUNCT2_OP_IMM_C_ANDI 0x2
#define RV_FUNCT2_OP_IMM_C_OP 0x3

#define RV_FUNCT2_OP_C_SUB 0x0
#define RV_FUNCT2_OP_C_XOR 0x1
#define RV_FUNCT2_OP_C_OR 0x2
#define RV_FUNCT2_OP_C_AND 0x3
#define RV_FUNCT2_OP_C_SUBW 0x0
#define RV_FUNCT2_OP_C_ADDW 0x1

#define RV_REG_ZERO 0
#define RV_REG_RA 1
#define RV_REG_SP 2
#define RV_REG_GP 3
#define RV_REG_TP 4
#define RV_REG_T0 5
#define RV_REG_T1 6
#define RV_REG_T2 7
#define RV_REG_S0 8
#define RV_REG_FP 8
#define RV_REG_S1 9
#define RV_REG_A0 10
#define RV_REG_A1 11
#define RV_REG_A2 12
#define RV_REG_A3 13
#define RV_REG_A4 14
#define RV_REG_A5 15
#define RV_REG_A6 16
#define RV_REG_A7 17
#define RV_REG_S2 18
#define RV_REG_S3 19
#define RV_REG_S4 20
#define RV_REG_S5 21
#define RV_REG_S6 22
#define RV_REG_S7 23
#define RV_REG_S8 24
#define RV_REG_S9 25
#define RV_REG_S10 26
#define RV_REG_S11 27
#define RV_REG_T3 28
#define RV_REG_T4 29
#define RV_REG_T5 30
#define RV_REG_T6 31

#define CSR_USTATUS 0x000
#define CSR_UIE 0x004
#define CSR_UTVEC 0x005
#define CSR_USCRATCH 0x040
#define CSR_UEPC 0x041
#define CSR_UCAUSE 0x042
#define CSR_UTVAL 0x043
#define CSR_UIP 0x044
#define CSR_FFLAGS 0x001
#define CSR_FRM 0x002
#define CSR_FCSR 0x003
#define CSR_CYCLE 0xc00
#define CSR_TIME 0xc01
#define CSR_INSTRET 0xc02
#define CSR_HPMCOUNTER3 0xc03
#define CSR_HPMCOUNTER4 0xc04
#define CSR_HPMCOUNTER5 0xc05
#define CSR_HPMCOUNTER6 0xc06
#define CSR_HPMCOUNTER7 0xc07
#define CSR_HPMCOUNTER8 0xc08
#define CSR_HPMCOUNTER9 0xc09
#define CSR_HPMCOUNTER10 0xc0a
#define CSR_HPMCOUNTER11 0xc0b
#define CSR_HPMCOUNTER12 0xc0c
#define CSR_HPMCOUNTER13 0xc0d
#define CSR_HPMCOUNTER14 0xc0e
#define CSR_HPMCOUNTER15 0xc0f
#define CSR_HPMCOUNTER16 0xc10
#define CSR_HPMCOUNTER17 0xc11
#define CSR_HPMCOUNTER18 0xc12
#define CSR_HPMCOUNTER19 0xc13
#define CSR_HPMCOUNTER20 0xc14
#define CSR_HPMCOUNTER21 0xc15
#define CSR_HPMCOUNTER22 0xc16
#define CSR_HPMCOUNTER23 0xc17
#define CSR_HPMCOUNTER24 0xc18
#define CSR_HPMCOUNTER25 0xc19
#define CSR_HPMCOUNTER26 0xc1a
#define CSR_HPMCOUNTER27 0xc1b
#define CSR_HPMCOUNTER28 0xc1c
#define CSR_HPMCOUNTER29 0xc1d
#define CSR_HPMCOUNTER30 0xc1e
#define CSR_HPMCOUNTER31 0xc1f
#define CSR_CYCLEH 0xc80
#define CSR_TIMEH 0xc81
#define CSR_INSTRETH 0xc82
#define CSR_HPMCOUNTER3H 0xc83
#define CSR_HPMCOUNTER4H 0xc84
#define CSR_HPMCOUNTER5H 0xc85
#define CSR_HPMCOUNTER6H 0xc86
#define CSR_HPMCOUNTER7H 0xc87
#define CSR_HPMCOUNTER8H 0xc88
#define CSR_HPMCOUNTER9H 0xc89
#define CSR_HPMCOUNTER10H 0xc8a
#define CSR_HPMCOUNTER11H 0xc8b
#define CSR_HPMCOUNTER12H 0xc8c
#define CSR_HPMCOUNTER13H 0xc8d
#define CSR_HPMCOUNTER14H 0xc8e
#define CSR_HPMCOUNTER15H 0xc8f
#define CSR_HPMCOUNTER16H 0xc90
#define CSR_HPMCOUNTER17H 0xc91
#define CSR_HPMCOUNTER18H 0xc92
#define CSR_HPMCOUNTER19H 0xc93
#define CSR_HPMCOUNTER20H 0xc94
#define CSR_HPMCOUNTER21H 0xc95
#define CSR_HPMCOUNTER22H 0xc96
#define CSR_HPMCOUNTER23H 0xc97
#define CSR_HPMCOUNTER24H 0xc98
#define CSR_HPMCOUNTER25H 0xc99
#define CSR_HPMCOUNTER26H 0xc9a
#define CSR_HPMCOUNTER27H 0xc9b
#define CSR_HPMCOUNTER28H 0xc9c
#define CSR_HPMCOUNTER29H 0xc9d
#define CSR_HPMCOUNTER30H 0xc9e
#define CSR_HPMCOUNTER31H 0xc9f
#define CSR_SSTATUS 0x100
#define CSR_SEDELEG 0x102
#define CSR_SIDELEG 0x103
#define CSR_SIE 0x104
#define CSR_STVEC 0x105
#define CSR_SCOUNTEREN 0x106
#define CSR_SSCRATCH 0x140
#define CSR_SEPC 0x141
#define CSR_SCAUSE 0x142
#define CSR_STVAL 0x143
#define CSR_SIP 0x144
#define CSR_SATP 0x180
#define CSR_MVENDORID 0xf11
#define CSR_MARCHID 0xf12
#define CSR_MIMPID 0xf13
#define CSR_MHARTID 0xf14
#define CSR_MSTATUS 0x300
#define CSR_MISA 0x301
#define CSR_MEDELEG 0x302
#define CSR_MIDELEG 0x303
#define CSR_MIE 0x304
#define CSR_MTVEC 0x305
#define CSR_MCOUNTEREN 0x306
#define CSR_MSCRATCH 0x340
#define CSR_MEPC 0x341
#define CSR_MCAUSE 0x342
#define CSR_MTVAL 0x343
#define CSR_MIP 0x344
#define CSR_PMPCFG0 0x3a0
#define CSR_PMPCFG1 0x3a1
#define CSR_PMPCFG2 0x3a2
#define CSR_PMPCFG3 0x3a3
#define CSR_PMPADDR0 0x3b0
#define CSR_PMPADDR1 0x3b1
#define CSR_PMPADDR2 0x3b2
#define CSR_PMPADDR3 0x3b3
#define CSR_PMPADDR4 0x3b4
#define CSR_PMPADDR5 0x3b5
#define CSR_PMPADDR6 0x3b6
#define CSR_PMPADDR7 0x3b7
#define CSR_PMPADDR8 0x3b8
#define CSR_PMPADDR9 0x3b9
#define CSR_PMPADDR10 0x3ba
#define CSR_PMPADDR11 0x3bb
#define CSR_PMPADDR12 0x3bc
#define CSR_PMPADDR13 0x3bd
#define CSR_PMPADDR14 0x3be
#define CSR_PMPADDR15 0x3bf
#define CSR_PMACFG0 0x3c0
#define CSR_PMACFG1 0x3c1
#define CSR_PMACFG2 0x3c2
#define CSR_PMACFG3 0x3c3
#define CSR_PMAADDR0 0x3d0
#define CSR_PMAADDR1 0x3d1
#define CSR_PMAADDR2 0x3d2
#define CSR_PMAADDR3 0x3d3
#define CSR_PMAADDR4 0x3d4
#define CSR_PMAADDR5 0x3d5
#define CSR_PMAADDR6 0x3d6
#define CSR_PMAADDR7 0x3d7
#define CSR_PMAADDR8 0x3d8
#define CSR_PMAADDR9 0x3d9
#define CSR_PMAADDR10 0x3da
#define CSR_PMAADDR11 0x3db
#define CSR_PMAADDR12 0x3dc
#define CSR_PMAADDR13 0x3dd
#define CSR_PMAADDR14 0x3de
#define CSR_PMAADDR15 0x3df
#define CSR_MCYCLE 0xb00
#define CSR_MINSTRET 0xb02
#define CSR_MHPMCOUNTER3 0xb03
#define CSR_MHPMCOUNTER4 0xb04
#define CSR_MHPMCOUNTER5 0xb05
#define CSR_MHPMCOUNTER6 0xb06
#define CSR_MHPMCOUNTER7 0xb07
#define CSR_MHPMCOUNTER8 0xb08
#define CSR_MHPMCOUNTER9 0xb09
#define CSR_MHPMCOUNTER10 0xb0a
#define CSR_MHPMCOUNTER11 0xb0b
#define CSR_MHPMCOUNTER12 0xb0c
#define CSR_MHPMCOUNTER13 0xb0d
#define CSR_MHPMCOUNTER14 0xb0e
#define CSR_MHPMCOUNTER15 0xb0f
#define CSR_MHPMCOUNTER16 0xb10
#define CSR_MHPMCOUNTER17 0xb11
#define CSR_MHPMCOUNTER18 0xb12
#define CSR_MHPMCOUNTER19 0xb13
#define CSR_MHPMCOUNTER20 0xb14
#define CSR_MHPMCOUNTER21 0xb15
#define CSR_MHPMCOUNTER22 0xb16
#define CSR_MHPMCOUNTER23 0xb17
#define CSR_MHPMCOUNTER24 0xb18
#define CSR_MHPMCOUNTER25 0xb19
#define CSR_MHPMCOUNTER26 0xb1a
#define CSR_MHPMCOUNTER27 0xb1b
#define CSR_MHPMCOUNTER28 0xb1c
#define CSR_MHPMCOUNTER29 0xb1d
#define CSR_MHPMCOUNTER30 0xb1e
#define CSR_MHPMCOUNTER31 0xb1f
#define CSR_MCYCLEH 0xb80
#define CSR_MINSTRETH 0xb82
#define CSR_MHPMCOUNTER3H 0xb83
#define CSR_MHPMCOUNTER4H 0xb84
#define CSR_MHPMCOUNTER5H 0xb85
#define CSR_MHPMCOUNTER6H 0xb86
#define CSR_MHPMCOUNTER7H 0xb87
#define CSR_MHPMCOUNTER8H 0xb88
#define CSR_MHPMCOUNTER9H 0xb89
#define CSR_MHPMCOUNTER10H 0xb8a
#define CSR_MHPMCOUNTER11H 0xb8b
#define CSR_MHPMCOUNTER12H 0xb8c
#define CSR_MHPMCOUNTER13H 0xb8d
#define CSR_MHPMCOUNTER14H 0xb8e
#define CSR_MHPMCOUNTER15H 0xb8f
#define CSR_MHPMCOUNTER16H 0xb90
#define CSR_MHPMCOUNTER17H 0xb91
#define CSR_MHPMCOUNTER18H 0xb92
#define CSR_MHPMCOUNTER19H 0xb93
#define CSR_MHPMCOUNTER20H 0xb94
#define CSR_MHPMCOUNTER21H 0xb95
#define CSR_MHPMCOUNTER22H 0xb96
#define CSR_MHPMCOUNTER23H 0xb97
#define CSR_MHPMCOUNTER24H 0xb98
#define CSR_MHPMCOUNTER25H 0xb99
#define CSR_MHPMCOUNTER26H 0xb9a
#define CSR_MHPMCOUNTER27H 0xb9b
#define CSR_MHPMCOUNTER28H 0xb9c
#define CSR_MHPMCOUNTER29H 0xb9d
#define CSR_MHPMCOUNTER30H 0xb9e
#define CSR_MHPMCOUNTER31H 0xb9f
#define CSR_MHPMEVENT3 0x323
#define CSR_MHPMEVENT4 0x324
#define CSR_MHPMEVENT5 0x325
#define CSR_MHPMEVENT6 0x326
#define CSR_MHPMEVENT7 0x327
#define CSR_MHPMEVENT8 0x328
#define CSR_MHPMEVENT9 0x329
#define CSR_MHPMEVENT10 0x32a
#define CSR_MHPMEVENT11 0x32b
#define CSR_MHPMEVENT12 0x32c
#define CSR_MHPMEVENT13 0x32d
#define CSR_MHPMEVENT14 0x32e
#define CSR_MHPMEVENT15 0x32f
#define CSR_MHPMEVENT16 0x330
#define CSR_MHPMEVENT17 0x331
#define CSR_MHPMEVENT18 0x332
#define CSR_MHPMEVENT19 0x333
#define CSR_MHPMEVENT20 0x334
#define CSR_MHPMEVENT21 0x335
#define CSR_MHPMEVENT22 0x336
#define CSR_MHPMEVENT23 0x337
#define CSR_MHPMEVENT24 0x338
#define CSR_MHPMEVENT25 0x339
#define CSR_MHPMEVENT26 0x33a
#define CSR_MHPMEVENT27 0x33b
#define CSR_MHPMEVENT28 0x33c
#define CSR_MHPMEVENT29 0x33d
#define CSR_MHPMEVENT30 0x33e
#define CSR_MHPMEVENT31 0x33f
#define CSR_TSELECT 0x7a0
#define CSR_TDATA1 0x7a1
#define CSR_TDATA2 0x7a2
#define CSR_TDATA3 0x7a3
#define CSR_DCSR 0x7b0
#define CSR_DPC 0x7b1
#define CSR_DSCRATCH 0x7b2

#define RV_GET_CSR_ADDR(INSN) ((INSN) >> 20 & 0xfff)
#define RV_GET_CSR_NAME(INSN) (csr_name(RV_GET_CSR_ADDR(INSN)))

#define RV_IMM_I(INSN) (   (INSN) >> 20                  )
#define RV_IMM_S(INSN) ( (((INSN) >> 20) &  ~0x1f)       | \
                         (((INSN) >>  7) &   0x1f)       )
#define RV_IMM_B(INSN) ( (((INSN) >> 20) & ~0x81f)       | \
                         (((INSN) >>  7) &   0x1e)       | \
                         (((INSN) <<  4) &  0x800)       )
#define RV_IMM_U(INSN) (  ((INSN) >> 12)           << 12 )
#define RV_IMM_J(INSN) (( ((INSN) >> 31)           << 20)| \
                        ((((INSN) >> 12) &   0xff) << 12)| \
                        ((((INSN) >> 20) &    0x1) << 11)| \
                        ((((INSN) >> 21) &  0x3ff) <<  1))

#define RV_IMM_CI_LWSP(INSN)     (((((INSN) >>  2) &  0x3) <<  6)| \
                                  ((((INSN) >> 12) &  0x1) <<  5)| \
                                  ((((INSN) >>  4) &  0x7) <<  2))
#define RV_IMM_CI_LDSP(INSN)     (((((INSN) >>  2) &  0x7) <<  6)| \
                                  ((((INSN) >> 12) &  0x1) <<  5)| \
                                  ((((INSN) >>  5) &  0x3) <<  3))
#define RV_IMM_CI_LI(INSN)       (((((INSN) << 19) >>  31) <<  5)| \
                                   (((INSN) >>  2) & 0x1f)       )
#define RV_IMM_CI_LUI(INSN)      (((((INSN) << 19) >>  31) << 17)| \
                                  ((((INSN) >>  2) & 0x1f) << 12))
#define RV_IMM_CI_ADDI16SP(INSN) (((((INSN) << 19) >>  31) <<  9)| \
                                  ((((INSN) >>  3) &  0x3) <<  7)| \
                                  ((((INSN) >>  5) &  0x1) <<  6)| \
                                  ((((INSN) >>  2) &  0x1) <<  5)| \
                                  ((((INSN) >>  6) &  0x1) <<  4))
#define RV_IMM_CSS(INSN)         (((((INSN) >>  7) &  0x3) <<  6)| \
                                  ((((INSN) >>  9) &  0xf) <<  2))
#define RV_IMM_CSS64(INSN)       (((((INSN) >>  7) &  0x7) <<  6)| \
                                  ((((INSN) >> 10) &  0x7) <<  3))
#define RV_IMM_CIW(INSN)         (((((INSN) >>  7) &  0xf) <<  6)| \
                                  ((((INSN) >> 11) &  0x3) <<  4)| \
                                  ((((INSN) >>  5) &  0x1) <<  3)| \
                                  ((((INSN) >>  6) &  0x1) <<  2))
#define RV_IMM_CL(INSN)          (((((INSN) >>  5) &  0x1) <<  6)| \
                                  ((((INSN) >> 10) &  0x7) <<  3)| \
                                  ((((INSN) >>  6) &  0x1) <<  2))
#define RV_IMM_CL64(INSN)        (((((INSN) >>  6) &  0x1) <<  7)| \
                                  ((((INSN) >>  5) &  0x1) <<  6)| \
                                  ((((INSN) >> 10) &  0x7) <<  3))
#define RV_IMM_CS(INSN)          (((((INSN) >>  5) &  0x1) <<  6)| \
                                  ((((INSN) >> 10) &  0x7) <<  3)| \
                                  ((((INSN) >>  6) &  0x1) <<  2))
#define RV_IMM_CB(INSN)          (((((INSN) << 19) >>  31) <<  8)| \
                                  ((((INSN) >>  5) &  0x3) <<  6)| \
                                  ((((INSN) >>  2) &  0x1) <<  5)| \
                                  ((((INSN) >> 10) &  0x3) <<  3)| \
                                  ((((INSN) >>  3) &  0x3) <<  1))
#define RV_IMM_CJ(INSN)          (((((INSN) << 19) >>  31) << 11)| \
                                  ((((INSN) >>  8) &  0x1) << 10)| \
                                  ((((INSN) >>  9) &  0x3) <<  8)| \
                                  ((((INSN) >>  6) &  0x1) <<  7)| \
                                  ((((INSN) >>  7) &  0x1) <<  6)| \
                                  ((((INSN) >>  2) &  0x1) <<  5)| \
                                  ((((INSN) >> 11) &  0x1) <<  4)| \
                                  ((((INSN) >>  3) &  0x7) <<  1))

#define RV_FUNCT3(INSN) (((INSN) >> 12) &  0x7)
#define RV_FUNCT5(INSN) (((INSN) >> 27) & 0x1f)
#define RV_FUNCT7(INSN) (((INSN) >> 25) & 0x7f)

#define RV_FUNCT3_16(INSN)        (((INSN) >> 13) & 0x7)
#define RV_FUNCT2_16_OP_IMM(INSN) (((INSN) >> 10) & 0x3)
#define RV_FUNCT2_16_OP(INSN)     (((INSN) >>  5) & 0x3)

#define RV_OPCODE_16(INSN) ( (INSN)       &  0x3)
#define RV_OPCODE_32(INSN) (((INSN) >> 2) & 0x1f)

#define RV_AQ(INSN) (((INSN) & (1 << 26)) ? ".aq" : "")
#define RV_RL(INSN) (((INSN) & (1 << 25)) ? ".rl" : "")

#define RV_SHAMT(INSN) (((INSN) >> 20) & 0x3f)

#define RV_PRED(INSN)  (((INSN) >> 24) &  0xf)
#define RV_SUCC(INSN)  (((INSN) >> 20) &  0xf)
#define RV_FENCE_FLAG(ARG) \
    ((ARG) & 0x8) ? "i" : "", ((ARG) & 0x4) ? "o" : "", \
    ((ARG) & 0x2) ? "r" : "", ((ARG) & 0x1) ? "w" : ""

#define RV_CAUSE_MISALIGNED_FETCH 0x0
#define RV_CAUSE_INSTRUCTION_ACCESS 0x1
#define RV_CAUSE_ILLEGAL_INSTRUCTION 0x2
#define RV_CAUSE_BREAKPOINT 0x3
#define RV_CAUSE_MISALIGNED_LOAD 0x4
#define RV_CAUSE_LOAD_ACCESS 0x5
#define RV_CAUSE_MISALIGNED_STORE 0x6
#define RV_CAUSE_STORE_ACCESS 0x7
#define RV_CAUSE_USER_ECALL 0x8
#define RV_CAUSE_SUPERVISOR_ECALL 0x9
#define RV_CAUSE_HYPERVISOR_ECALL 0xa
#define RV_CAUSE_MACHINE_ECALL 0xb
#define RV_CAUSE_INSTRUCTION_PAGE_FAULT 0xc
#define RV_CAUSE_LOAD_PAGE_FAULT 0xd
#define RV_CAUSE_STORE_PAGE_FAULT 0xf

struct __attribute__((__packed__)) trace_package {
    union {
        uint64_t mem_data;
        uint64_t rd_data;
        uint64_t mtval;
    } d1;
    union {
        uint64_t mem_addr;
        uint64_t csr_wdata;
        uint64_t mcause;
    } d2;
    int32_t insn;
    uint64_t pc;
    uint32_t cycle:27;
    uint32_t misa_mxl:1;
    uint32_t prv:2;
    uint32_t type:2;
};

struct trace_decode {
    uint16_t rd_wr:1;
    uint16_t rd:5;
    uint16_t csr_wr:1;
    uint16_t mem_rd:1;
    uint16_t mem_wr:1;
};

static const char *regs_name(uint16_t addr) {
    switch (addr) {
        case RV_REG_ZERO: return "zero";
        case RV_REG_RA  : return "ra";
        case RV_REG_SP  : return "sp";
        case RV_REG_GP  : return "gp";
        case RV_REG_TP  : return "tp";
        case RV_REG_T0  : return "t0";
        case RV_REG_T1  : return "t1";
        case RV_REG_T2  : return "t2";
        case RV_REG_S0  : return "s0";
        case RV_REG_S1  : return "s1";
        case RV_REG_A0  : return "a0";
        case RV_REG_A1  : return "a1";
        case RV_REG_A2  : return "a2";
        case RV_REG_A3  : return "a3";
        case RV_REG_A4  : return "a4";
        case RV_REG_A5  : return "a5";
        case RV_REG_A6  : return "a6";
        case RV_REG_A7  : return "a7";
        case RV_REG_S2  : return "s2";
        case RV_REG_S3  : return "s3";
        case RV_REG_S4  : return "s4";
        case RV_REG_S5  : return "s5";
        case RV_REG_S6  : return "s6";
        case RV_REG_S7  : return "s7";
        case RV_REG_S8  : return "s8";
        case RV_REG_S9  : return "s9";
        case RV_REG_S10 : return "s10";
        case RV_REG_S11 : return "s11";
        case RV_REG_T3  : return "t3";
        case RV_REG_T4  : return "t4";
        case RV_REG_T5  : return "t5";
        case RV_REG_T6  : return "t6";
    }
    return "unknown";
}

static const char *csr_name(uint16_t addr) {
    switch (addr) {
        case CSR_USTATUS       : return "ustatus";
        case CSR_UIE           : return "uie";
        case CSR_UTVEC         : return "utvec";
        case CSR_USCRATCH      : return "uscratch";
        case CSR_UEPC          : return "uepc";
        case CSR_UCAUSE        : return "ucause";
        case CSR_UTVAL         : return "utval";
        case CSR_UIP           : return "uip";
        case CSR_FFLAGS        : return "fflags";
        case CSR_FRM           : return "frm";
        case CSR_FCSR          : return "fcsr";
        case CSR_CYCLE         : return "cycle";
        case CSR_TIME          : return "time";
        case CSR_INSTRET       : return "instret";
        case CSR_HPMCOUNTER3   : return "hpmcounter3";
        case CSR_HPMCOUNTER4   : return "hpmcounter4";
        case CSR_HPMCOUNTER5   : return "hpmcounter5";
        case CSR_HPMCOUNTER6   : return "hpmcounter6";
        case CSR_HPMCOUNTER7   : return "hpmcounter7";
        case CSR_HPMCOUNTER8   : return "hpmcounter8";
        case CSR_HPMCOUNTER9   : return "hpmcounter9";
        case CSR_HPMCOUNTER10  : return "hpmcounter10";
        case CSR_HPMCOUNTER11  : return "hpmcounter11";
        case CSR_HPMCOUNTER12  : return "hpmcounter12";
        case CSR_HPMCOUNTER13  : return "hpmcounter13";
        case CSR_HPMCOUNTER14  : return "hpmcounter14";
        case CSR_HPMCOUNTER15  : return "hpmcounter15";
        case CSR_HPMCOUNTER16  : return "hpmcounter16";
        case CSR_HPMCOUNTER17  : return "hpmcounter17";
        case CSR_HPMCOUNTER18  : return "hpmcounter18";
        case CSR_HPMCOUNTER19  : return "hpmcounter19";
        case CSR_HPMCOUNTER20  : return "hpmcounter20";
        case CSR_HPMCOUNTER21  : return "hpmcounter21";
        case CSR_HPMCOUNTER22  : return "hpmcounter22";
        case CSR_HPMCOUNTER23  : return "hpmcounter23";
        case CSR_HPMCOUNTER24  : return "hpmcounter24";
        case CSR_HPMCOUNTER25  : return "hpmcounter25";
        case CSR_HPMCOUNTER26  : return "hpmcounter26";
        case CSR_HPMCOUNTER27  : return "hpmcounter27";
        case CSR_HPMCOUNTER28  : return "hpmcounter28";
        case CSR_HPMCOUNTER29  : return "hpmcounter29";
        case CSR_HPMCOUNTER30  : return "hpmcounter30";
        case CSR_HPMCOUNTER31  : return "hpmcounter31";
        case CSR_CYCLEH        : return "cycleh";
        case CSR_TIMEH         : return "timeh";
        case CSR_INSTRETH      : return "instreth";
        case CSR_HPMCOUNTER3H  : return "hpmcounter3h";
        case CSR_HPMCOUNTER4H  : return "hpmcounter4h";
        case CSR_HPMCOUNTER5H  : return "hpmcounter5h";
        case CSR_HPMCOUNTER6H  : return "hpmcounter6h";
        case CSR_HPMCOUNTER7H  : return "hpmcounter7h";
        case CSR_HPMCOUNTER8H  : return "hpmcounter8h";
        case CSR_HPMCOUNTER9H  : return "hpmcounter9h";
        case CSR_HPMCOUNTER10H : return "hpmcounter10h";
        case CSR_HPMCOUNTER11H : return "hpmcounter11h";
        case CSR_HPMCOUNTER12H : return "hpmcounter12h";
        case CSR_HPMCOUNTER13H : return "hpmcounter13h";
        case CSR_HPMCOUNTER14H : return "hpmcounter14h";
        case CSR_HPMCOUNTER15H : return "hpmcounter15h";
        case CSR_HPMCOUNTER16H : return "hpmcounter16h";
        case CSR_HPMCOUNTER17H : return "hpmcounter17h";
        case CSR_HPMCOUNTER18H : return "hpmcounter18h";
        case CSR_HPMCOUNTER19H : return "hpmcounter19h";
        case CSR_HPMCOUNTER20H : return "hpmcounter20h";
        case CSR_HPMCOUNTER21H : return "hpmcounter21h";
        case CSR_HPMCOUNTER22H : return "hpmcounter22h";
        case CSR_HPMCOUNTER23H : return "hpmcounter23h";
        case CSR_HPMCOUNTER24H : return "hpmcounter24h";
        case CSR_HPMCOUNTER25H : return "hpmcounter25h";
        case CSR_HPMCOUNTER26H : return "hpmcounter26h";
        case CSR_HPMCOUNTER27H : return "hpmcounter27h";
        case CSR_HPMCOUNTER28H : return "hpmcounter28h";
        case CSR_HPMCOUNTER29H : return "hpmcounter29h";
        case CSR_HPMCOUNTER30H : return "hpmcounter30h";
        case CSR_HPMCOUNTER31H : return "hpmcounter31h";
        case CSR_SSTATUS       : return "sstatus";
        case CSR_SEDELEG       : return "sedeleg";
        case CSR_SIDELEG       : return "sideleg";
        case CSR_SIE           : return "sie";
        case CSR_STVEC         : return "stvec";
        case CSR_SCOUNTEREN    : return "scounteren";
        case CSR_SSCRATCH      : return "sscratch";
        case CSR_SEPC          : return "sepc";
        case CSR_SCAUSE        : return "scause";
        case CSR_STVAL         : return "stval";
        case CSR_SIP           : return "sip";
        case CSR_SATP          : return "satp";
        case CSR_MVENDORID     : return "mvendorid";
        case CSR_MARCHID       : return "marchid";
        case CSR_MIMPID        : return "mimpid";
        case CSR_MHARTID       : return "mhartid";
        case CSR_MSTATUS       : return "mstatus";
        case CSR_MISA          : return "misa";
        case CSR_MEDELEG       : return "medeleg";
        case CSR_MIDELEG       : return "mideleg";
        case CSR_MIE           : return "mie";
        case CSR_MTVEC         : return "mtvec";
        case CSR_MCOUNTEREN    : return "mcounteren";
        case CSR_MSCRATCH      : return "mscratch";
        case CSR_MEPC          : return "mepc";
        case CSR_MCAUSE        : return "mcause";
        case CSR_MTVAL         : return "mtval";
        case CSR_MIP           : return "mip";
        case CSR_PMPCFG0       : return "pmpcfg0";
        case CSR_PMPCFG1       : return "pmpcfg1";
        case CSR_PMPCFG2       : return "pmpcfg2";
        case CSR_PMPCFG3       : return "pmpcfg3";
        case CSR_PMPADDR0      : return "pmpaddr0";
        case CSR_PMPADDR1      : return "pmpaddr1";
        case CSR_PMPADDR2      : return "pmpaddr2";
        case CSR_PMPADDR3      : return "pmpaddr3";
        case CSR_PMPADDR4      : return "pmpaddr4";
        case CSR_PMPADDR5      : return "pmpaddr5";
        case CSR_PMPADDR6      : return "pmpaddr6";
        case CSR_PMPADDR7      : return "pmpaddr7";
        case CSR_PMPADDR8      : return "pmpaddr8";
        case CSR_PMPADDR9      : return "pmpaddr9";
        case CSR_PMPADDR10     : return "pmpaddr10";
        case CSR_PMPADDR11     : return "pmpaddr11";
        case CSR_PMPADDR12     : return "pmpaddr12";
        case CSR_PMPADDR13     : return "pmpaddr13";
        case CSR_PMPADDR14     : return "pmpaddr14";
        case CSR_PMPADDR15     : return "pmpaddr15";
        case CSR_PMACFG0       : return "pmacfg0";
        case CSR_PMACFG1       : return "pmacfg1";
        case CSR_PMACFG2       : return "pmacfg2";
        case CSR_PMACFG3       : return "pmacfg3";
        case CSR_PMAADDR0      : return "pmaaddr0";
        case CSR_PMAADDR1      : return "pmaaddr1";
        case CSR_PMAADDR2      : return "pmaaddr2";
        case CSR_PMAADDR3      : return "pmaaddr3";
        case CSR_PMAADDR4      : return "pmaaddr4";
        case CSR_PMAADDR5      : return "pmaaddr5";
        case CSR_PMAADDR6      : return "pmaaddr6";
        case CSR_PMAADDR7      : return "pmaaddr7";
        case CSR_PMAADDR8      : return "pmaaddr8";
        case CSR_PMAADDR9      : return "pmaaddr9";
        case CSR_PMAADDR10     : return "pmaaddr10";
        case CSR_PMAADDR11     : return "pmaaddr11";
        case CSR_PMAADDR12     : return "pmaaddr12";
        case CSR_PMAADDR13     : return "pmaaddr13";
        case CSR_PMAADDR14     : return "pmaaddr14";
        case CSR_PMAADDR15     : return "pmaaddr15";
        case CSR_MCYCLE        : return "mcycle";
        case CSR_MINSTRET      : return "minstret";
        case CSR_MHPMCOUNTER3  : return "mhpmcounter3";
        case CSR_MHPMCOUNTER4  : return "mhpmcounter4";
        case CSR_MHPMCOUNTER5  : return "mhpmcounter5";
        case CSR_MHPMCOUNTER6  : return "mhpmcounter6";
        case CSR_MHPMCOUNTER7  : return "mhpmcounter7";
        case CSR_MHPMCOUNTER8  : return "mhpmcounter8";
        case CSR_MHPMCOUNTER9  : return "mhpmcounter9";
        case CSR_MHPMCOUNTER10 : return "mhpmcounter10";
        case CSR_MHPMCOUNTER11 : return "mhpmcounter11";
        case CSR_MHPMCOUNTER12 : return "mhpmcounter12";
        case CSR_MHPMCOUNTER13 : return "mhpmcounter13";
        case CSR_MHPMCOUNTER14 : return "mhpmcounter14";
        case CSR_MHPMCOUNTER15 : return "mhpmcounter15";
        case CSR_MHPMCOUNTER16 : return "mhpmcounter16";
        case CSR_MHPMCOUNTER17 : return "mhpmcounter17";
        case CSR_MHPMCOUNTER18 : return "mhpmcounter18";
        case CSR_MHPMCOUNTER19 : return "mhpmcounter19";
        case CSR_MHPMCOUNTER20 : return "mhpmcounter20";
        case CSR_MHPMCOUNTER21 : return "mhpmcounter21";
        case CSR_MHPMCOUNTER22 : return "mhpmcounter22";
        case CSR_MHPMCOUNTER23 : return "mhpmcounter23";
        case CSR_MHPMCOUNTER24 : return "mhpmcounter24";
        case CSR_MHPMCOUNTER25 : return "mhpmcounter25";
        case CSR_MHPMCOUNTER26 : return "mhpmcounter26";
        case CSR_MHPMCOUNTER27 : return "mhpmcounter27";
        case CSR_MHPMCOUNTER28 : return "mhpmcounter28";
        case CSR_MHPMCOUNTER29 : return "mhpmcounter29";
        case CSR_MHPMCOUNTER30 : return "mhpmcounter30";
        case CSR_MHPMCOUNTER31 : return "mhpmcounter31";
        case CSR_MCYCLEH       : return "mcycleh";
        case CSR_MINSTRETH     : return "minstreth";
        case CSR_MHPMCOUNTER3H : return "mhpmcounter3h";
        case CSR_MHPMCOUNTER4H : return "mhpmcounter4h";
        case CSR_MHPMCOUNTER5H : return "mhpmcounter5h";
        case CSR_MHPMCOUNTER6H : return "mhpmcounter6h";
        case CSR_MHPMCOUNTER7H : return "mhpmcounter7h";
        case CSR_MHPMCOUNTER8H : return "mhpmcounter8h";
        case CSR_MHPMCOUNTER9H : return "mhpmcounter9h";
        case CSR_MHPMCOUNTER10H: return "mhpmcounter10h";
        case CSR_MHPMCOUNTER11H: return "mhpmcounter11h";
        case CSR_MHPMCOUNTER12H: return "mhpmcounter12h";
        case CSR_MHPMCOUNTER13H: return "mhpmcounter13h";
        case CSR_MHPMCOUNTER14H: return "mhpmcounter14h";
        case CSR_MHPMCOUNTER15H: return "mhpmcounter15h";
        case CSR_MHPMCOUNTER16H: return "mhpmcounter16h";
        case CSR_MHPMCOUNTER17H: return "mhpmcounter17h";
        case CSR_MHPMCOUNTER18H: return "mhpmcounter18h";
        case CSR_MHPMCOUNTER19H: return "mhpmcounter19h";
        case CSR_MHPMCOUNTER20H: return "mhpmcounter20h";
        case CSR_MHPMCOUNTER21H: return "mhpmcounter21h";
        case CSR_MHPMCOUNTER22H: return "mhpmcounter22h";
        case CSR_MHPMCOUNTER23H: return "mhpmcounter23h";
        case CSR_MHPMCOUNTER24H: return "mhpmcounter24h";
        case CSR_MHPMCOUNTER25H: return "mhpmcounter25h";
        case CSR_MHPMCOUNTER26H: return "mhpmcounter26h";
        case CSR_MHPMCOUNTER27H: return "mhpmcounter27h";
        case CSR_MHPMCOUNTER28H: return "mhpmcounter28h";
        case CSR_MHPMCOUNTER29H: return "mhpmcounter29h";
        case CSR_MHPMCOUNTER30H: return "mhpmcounter30h";
        case CSR_MHPMCOUNTER31H: return "mhpmcounter31h";
        case CSR_MHPMEVENT3    : return "mhpmevent3";
        case CSR_MHPMEVENT4    : return "mhpmevent4";
        case CSR_MHPMEVENT5    : return "mhpmevent5";
        case CSR_MHPMEVENT6    : return "mhpmevent6";
        case CSR_MHPMEVENT7    : return "mhpmevent7";
        case CSR_MHPMEVENT8    : return "mhpmevent8";
        case CSR_MHPMEVENT9    : return "mhpmevent9";
        case CSR_MHPMEVENT10   : return "mhpmevent10";
        case CSR_MHPMEVENT11   : return "mhpmevent11";
        case CSR_MHPMEVENT12   : return "mhpmevent12";
        case CSR_MHPMEVENT13   : return "mhpmevent13";
        case CSR_MHPMEVENT14   : return "mhpmevent14";
        case CSR_MHPMEVENT15   : return "mhpmevent15";
        case CSR_MHPMEVENT16   : return "mhpmevent16";
        case CSR_MHPMEVENT17   : return "mhpmevent17";
        case CSR_MHPMEVENT18   : return "mhpmevent18";
        case CSR_MHPMEVENT19   : return "mhpmevent19";
        case CSR_MHPMEVENT20   : return "mhpmevent20";
        case CSR_MHPMEVENT21   : return "mhpmevent21";
        case CSR_MHPMEVENT22   : return "mhpmevent22";
        case CSR_MHPMEVENT23   : return "mhpmevent23";
        case CSR_MHPMEVENT24   : return "mhpmevent24";
        case CSR_MHPMEVENT25   : return "mhpmevent25";
        case CSR_MHPMEVENT26   : return "mhpmevent26";
        case CSR_MHPMEVENT27   : return "mhpmevent27";
        case CSR_MHPMEVENT28   : return "mhpmevent28";
        case CSR_MHPMEVENT29   : return "mhpmevent29";
        case CSR_MHPMEVENT30   : return "mhpmevent30";
        case CSR_MHPMEVENT31   : return "mhpmevent31";
        case CSR_TSELECT       : return "tselect";
        case CSR_TDATA1        : return "tdata1";
        case CSR_TDATA2        : return "tdata2";
        case CSR_TDATA3        : return "tdata3";
        case CSR_DCSR          : return "dcsr";
        case CSR_DPC           : return "dpc";
        case CSR_DSCRATCH      : return "dscratch";
    }
    return "unknown";
}

static char *insn_decode(char *buf, const struct trace_package *pkg,
                         struct trace_decode *dec) {

    uint32_t rs1, rs2;

    rs1 = (pkg->insn >> 15) & 0x1f;
    rs2 = (pkg->insn >> 20) & 0x1f;

    dec->rd = (pkg->insn >> 7) & 0x1f;
    dec->csr_wr = 0;
    dec->rd_wr = 0;
    dec->mem_rd = 0;
    dec->mem_wr = 0;

    sprintf(buf, "illegal insn");
    switch (RV_OPCODE_16(pkg->insn)) {
        case RV_OP16_C0:
            rs1 = ((1 << 3) | ((pkg->insn >> 7) & 0x7));
            rs2 = ((1 << 3) | ((pkg->insn >> 2) & 0x7));
            dec->rd = ((1 << 3) | ((pkg->insn >> 2) & 0x7));
            dec->rd_wr = !!(dec->rd);
            switch (RV_FUNCT3_16(pkg->insn)) {
                case RV_FUNCT3_C0_ADDI4SPN:             sprintf(buf, "c.addi4spn %s,%s,%d", regs_name(dec->rd), regs_name(RV_REG_SP), RV_IMM_CIW(pkg->insn)); break;
                case RV_FUNCT3_C0_FLD:                  sprintf(buf, "illegal insn"); break;
                case RV_FUNCT3_C0_LW:  dec->mem_rd = 1; sprintf(buf, "c.lw %s,%d(%s)", regs_name(dec->rd), RV_IMM_CL(pkg->insn), regs_name(rs1)); break;
                case RV_FUNCT3_C0_FLW: dec->mem_rd = 1; sprintf(buf, "c.ld %s,%d(%s)", regs_name(dec->rd), RV_IMM_CL64(pkg->insn), regs_name(rs1)); break;
                case RV_FUNCT3_C0_FSD:                  sprintf(buf, "illegal insn"); break;
                case RV_FUNCT3_C0_SW:  dec->mem_wr = 1; sprintf(buf, "c.sw %s,%d(%s)", regs_name(rs2), RV_IMM_CS(pkg->insn), regs_name(rs1)); break;
                case RV_FUNCT3_C0_FSW: dec->mem_wr = 1; sprintf(buf, "c.sd %s,%d(%s)", regs_name(rs2), RV_IMM_CL64(pkg->insn), regs_name(rs1)); break;
            } break;
        case RV_OP16_C1:
            rs1 = ((1 << 3) | ((pkg->insn >> 7) & 0x7));
            rs2 = ((1 << 3) | ((pkg->insn >> 2) & 0x7));
            dec->rd = ((1 << 3) | ((pkg->insn >> 7) & 0x7));
            switch (RV_FUNCT3_16(pkg->insn)) {
                case RV_FUNCT3_C1_ADDI:
                    rs1 = (((pkg->insn >> 7) & 0x1f));
                    dec->rd = (((pkg->insn >> 7) & 0x1f));
                    if (dec->rd == 0 && RV_IMM_CI_LI(pkg->insn) == 0) sprintf(buf, "c.nop");
                    else {
                        dec->rd_wr = !!(dec->rd);
                        sprintf(buf, "c.addi %s,%d", regs_name(dec->rd), RV_IMM_CI_LI(pkg->insn));
                    }
                    break;
                case RV_FUNCT3_C1_JAL:
                    rs1 = (((pkg->insn >> 7) & 0x1f));
                    dec->rd = (((pkg->insn >> 7) & 0x1f));
                    dec->rd_wr = !!(dec->rd);
                    if (pkg->misa_mxl) sprintf(buf, "c.addiw %s,%d", regs_name(dec->rd), RV_IMM_CI_LI(pkg->insn));
                    else               sprintf(buf, "c.jal %08llx", (pkg->pc + RV_IMM_CJ(pkg->insn)));
                    break;
                case RV_FUNCT3_C1_LI:
                    dec->rd = (((pkg->insn >> 7) & 0x1f));
                    dec->rd_wr = !!(dec->rd);
                    sprintf(buf, "c.li %s,%d", regs_name(dec->rd), RV_IMM_CI_LI(pkg->insn));
                    break;
                case RV_FUNCT3_C1_LUI:
                    rs1 = (((pkg->insn >> 7) & 0x1f));
                    dec->rd = (((pkg->insn >> 7) & 0x1f));
                    dec->rd_wr = !!(dec->rd);
                    if (dec->rd == RV_REG_SP) sprintf(buf, "c.addi16sp %s,%d", regs_name(RV_REG_SP), RV_IMM_CI_ADDI16SP(pkg->insn));
                    else                      sprintf(buf, "c.lui %s,0x%x", regs_name(dec->rd), (uint32_t)RV_IMM_CI_LUI(pkg->insn) >> 12);
                    break;
                case RV_FUNCT3_C1_OP:
                    dec->rd_wr = !!(dec->rd);
                    switch (RV_FUNCT2_16_OP_IMM(pkg->insn)) {
                        case RV_FUNCT2_OP_IMM_C_SRLI: sprintf(buf, "c.srli %s,0x%x", regs_name(dec->rd), (uint32_t)RV_IMM_CI_LI(pkg->insn) & 0x1f); break;
                        case RV_FUNCT2_OP_IMM_C_SRAI: sprintf(buf, "c.srai %s,0x%x", regs_name(dec->rd), (uint32_t)RV_IMM_CI_LI(pkg->insn) & 0x1f); break;
                        case RV_FUNCT2_OP_IMM_C_ANDI: sprintf(buf, "c.andi %s,0x%x", regs_name(dec->rd), (uint32_t)RV_IMM_CI_LI(pkg->insn)); break;
                        case RV_FUNCT2_OP_IMM_C_OP:
                            if (!(pkg->insn & (1 << 12))) {
                                switch (RV_FUNCT2_16_OP(pkg->insn)) {
                                    case RV_FUNCT2_OP_C_SUB: sprintf(buf, "c.sub %s,%s", regs_name(dec->rd), regs_name(rs2)); break;
                                    case RV_FUNCT2_OP_C_XOR: sprintf(buf, "c.xor %s,%s", regs_name(dec->rd), regs_name(rs2)); break;
                                    case RV_FUNCT2_OP_C_OR:  sprintf(buf, "c.or %s,%s",  regs_name(dec->rd), regs_name(rs2)); break;
                                    case RV_FUNCT2_OP_C_AND: sprintf(buf, "c.and %s,%s", regs_name(dec->rd), regs_name(rs2)); break;
                                }
                            }
                            else {
                                switch (RV_FUNCT2_16_OP(pkg->insn)) {
                                    case RV_FUNCT2_OP_C_SUBW: sprintf(buf, "c.subw %s,%s", regs_name(dec->rd), regs_name(rs2)); break;
                                    case RV_FUNCT2_OP_C_ADDW: sprintf(buf, "c.addw %s,%s", regs_name(dec->rd), regs_name(rs2)); break;
                                }
                            }
                            break;
                    } break;
                case RV_FUNCT3_C1_J: sprintf(buf, "c.j %08llx", (pkg->pc + RV_IMM_CJ(pkg->insn))); break;
                case RV_FUNCT3_C1_BEQZ: sprintf(buf, "c.beqz %s,%08llx", regs_name(rs1), (pkg->pc + RV_IMM_CB(pkg->insn))); break;
                case RV_FUNCT3_C1_BNEZ: sprintf(buf, "c.bnez %s,%08llx", regs_name(rs1), (pkg->pc + RV_IMM_CB(pkg->insn))); break;
            } break;
        case RV_OP16_C2:
            rs1 = (((pkg->insn >> 7) & 0x1f));
            rs2 = (((pkg->insn >> 2) & 0x1f));
            dec->rd = (((pkg->insn >> 7) & 0x1f));
            dec->rd_wr = !!(dec->rd);
            switch (RV_FUNCT3_16(pkg->insn)) {
                case RV_FUNCT3_C2_SLLI:                  sprintf(buf, "c.slli %s,0x%x", regs_name(dec->rd), (uint32_t)RV_IMM_CI_LI(pkg->insn) & 0x1f); break;
                case RV_FUNCT3_C2_FLDSP:                 sprintf(buf, "illegal insn"); break;
                case RV_FUNCT3_C2_LWSP: dec->mem_rd = 1; sprintf(buf, "c.lwsp %s,%d(%s)", regs_name(dec->rd), RV_IMM_CI_LWSP(pkg->insn), regs_name(RV_REG_SP)); break;
                case RV_FUNCT3_C2_FLWSP:
                    dec->mem_rd = 1;
                    if (pkg->misa_mxl) sprintf(buf, "c.ldsp %s,%d(%s)", regs_name(dec->rd), RV_IMM_CI_LDSP(pkg->insn), regs_name(RV_REG_SP));
                    else               sprintf(buf, "illegal insn");
                    break;
                case RV_FUNCT3_C2_OP:
                    if ((pkg->insn & (1 << 12)) == 0) {
                        if (rs2 == RV_REG_ZERO) dec->rd_wr = 0, sprintf(buf, "c.jr %s", regs_name(rs1));
                        else                                    sprintf(buf, "c.mv %s,%s", regs_name(dec->rd), regs_name(rs2));
                    }
                    else {
                        if (rs2 == RV_REG_ZERO) {
                            if (rs1 == RV_REG_ZERO) sprintf(buf, "c.ebreak");
                            else                    sprintf(buf, "c.jalr %s", regs_name(rs1));
                        }
                        else sprintf(buf, "c.add %s,%s", regs_name(dec->rd), regs_name(rs2));
                    }
                    break;
                case RV_FUNCT3_C2_FSDSP: sprintf(buf, "illegal insn"); break;
                case RV_FUNCT3_C2_SWSP: dec->mem_wr = 1; dec->rd_wr = 0; sprintf(buf, "c.swsp %s,%d(%s)", regs_name(rs2), RV_IMM_CSS(pkg->insn), regs_name(RV_REG_SP)); break;
                case RV_FUNCT3_C2_FSWSP:
                    dec->rd_wr = 0;
                    dec->mem_wr = 1;
                    if (pkg->misa_mxl) sprintf(buf, "c.sdsp %s,%d(%s)", regs_name(rs2), RV_IMM_CSS64(pkg->insn), regs_name(RV_REG_SP));
                    else sprintf(buf, "illegal insn");
                    break;
            } break;
        default:
            switch (RV_OPCODE_32(pkg->insn)) {
                case RV_OP_LOAD:
                    dec->rd_wr = !!(dec->rd);
                    dec->mem_rd = 1;
                    switch (RV_FUNCT3(pkg->insn)) {
                        case RV_FUNCT3_LB:  sprintf(buf, "lb %s,%d(%s)", regs_name(dec->rd), RV_IMM_I(pkg->insn), regs_name(rs1)); break;
                        case RV_FUNCT3_LH:  sprintf(buf, "lh %s,%d(%s)", regs_name(dec->rd), RV_IMM_I(pkg->insn), regs_name(rs1)); break;
                        case RV_FUNCT3_LW:  sprintf(buf, "lw %s,%d(%s)", regs_name(dec->rd), RV_IMM_I(pkg->insn), regs_name(rs1)); break;
                        case RV_FUNCT3_LBU: sprintf(buf, "lbu %s,%d(%s)", regs_name(dec->rd), RV_IMM_I(pkg->insn), regs_name(rs1)); break;
                        case RV_FUNCT3_LHU: sprintf(buf, "lhu %s,%d(%s)", regs_name(dec->rd), RV_IMM_I(pkg->insn), regs_name(rs1)); break;
                        case RV_FUNCT3_LWU: sprintf(buf, "lwu %s,%d(%s)", regs_name(dec->rd), RV_IMM_I(pkg->insn), regs_name(rs1)); break;
                        case RV_FUNCT3_LD:  sprintf(buf, "ld %s,%d(%s)", regs_name(dec->rd), RV_IMM_I(pkg->insn), regs_name(rs1)); break;
                    } break;
                case RV_OP_LOAD_FP: sprintf(buf, "illegal insn"); break;
                case RV_OP_CUST_0:  sprintf(buf, "illegal insn"); break;
                case RV_OP_MISC_MEM:
                    if (((pkg->insn >> 7) & 0x1f) != 0 || ((pkg->insn >> 15) & 0x1f) != 0)
                        break;
                    switch (RV_FUNCT3(pkg->insn)) {
                        case RV_FUNCT3_FENCE  :
                            if (!(pkg->insn >> 28)) {
                                if (RV_PRED(pkg->insn) != 0xf || RV_SUCC(pkg->insn) != 0xf)
                                    sprintf(buf, "fence %s%s%s%s,%s%s%s%s", RV_FENCE_FLAG(RV_PRED(pkg->insn)), RV_FENCE_FLAG(RV_SUCC(pkg->insn)));
                                else sprintf(buf, "fence");
                            }
                            else if (((pkg->insn >> 28) & 0xf) == 0x8) {
                                if (RV_PRED(pkg->insn) != 0xf || RV_SUCC(pkg->insn) != 0xf)
                                    sprintf(buf, "fence.tso %s%s%s%s,%s%s%s%s", RV_FENCE_FLAG(RV_PRED(pkg->insn)), RV_FENCE_FLAG(RV_SUCC(pkg->insn)));
                                else sprintf(buf, "fence.tso");
                            }
                            break;
                        case RV_FUNCT3_FENCE_I:
                            if (!(pkg->insn >> 20)) sprintf(buf, "fence.i");
                            break;
                    } break;
                case RV_OP_OP_IMM:
                    dec->rd_wr = !!(dec->rd);
                    switch (RV_FUNCT3(pkg->insn)) {
                        case RV_FUNCT3_ADDI:
                            if (dec->rd == 0 && rs1 == 0 && RV_IMM_I(pkg->insn) == 0) sprintf(buf, "nop");
                            else if (rs1 == 0)                 sprintf(buf, "li %s,%d", regs_name(dec->rd), RV_IMM_I(pkg->insn));
                            else if (RV_IMM_I(pkg->insn) == 0) sprintf(buf, "mv %s,%s", regs_name(dec->rd), regs_name(rs1));
                            else                               sprintf(buf, "addi %s,%s,%d", regs_name(dec->rd), regs_name(rs1), RV_IMM_I(pkg->insn));
                            break;
                        case RV_FUNCT3_SLTI:  sprintf(buf, "slti %s,%s,%d", regs_name(dec->rd), regs_name(rs1), RV_IMM_I(pkg->insn)); break;
                        case RV_FUNCT3_SLTIU: sprintf(buf, "sltiu %s,%s,%d", regs_name(dec->rd), regs_name(rs1), RV_IMM_I(pkg->insn)); break;
                        case RV_FUNCT3_XORI:
                            if (RV_IMM_I(pkg->insn) == -1) sprintf(buf, "not %s,%s", regs_name(dec->rd), regs_name(rs1));
                            else                           sprintf(buf, "xori %s,%s,0x%x", regs_name(dec->rd), regs_name(rs1), (uint32_t)RV_IMM_I(pkg->insn));
                            break;
                        case RV_FUNCT3_ORI: sprintf(buf, "ori %s,%s,0x%x", regs_name(dec->rd), regs_name(rs1), (uint32_t)RV_IMM_I(pkg->insn)); break;
                        case RV_FUNCT3_ANDI:
                            sprintf(buf, "andi %s,%s,0x%x", regs_name(dec->rd), regs_name(rs1), (uint32_t)RV_IMM_I(pkg->insn)); break;
                        case RV_FUNCT3_SLLI:
                            if ((RV_FUNCT7(pkg->insn) & 0x7e) == (RV_FUNCT7_SLLI & 0x7e))
                                sprintf(buf, "slli %s,%s,0x%x", regs_name(dec->rd), regs_name(rs1), (uint32_t)RV_SHAMT(pkg->insn));
                            else sprintf(buf, "illegal insn");
                            break;
                        case RV_FUNCT3_SRLI:
                            if ((RV_FUNCT7(pkg->insn) & 0x7e) == (RV_FUNCT7_SRLI & 0x7e))
                                sprintf(buf, "srli %s,%s,0x%x", regs_name(dec->rd), regs_name(rs1), (uint32_t)RV_SHAMT(pkg->insn));
                            else if ((RV_FUNCT7(pkg->insn) & 0x7e) == (RV_FUNCT7_SRAI & 0x7e))
                                sprintf(buf, "srai %s,%s,0x%x", regs_name(dec->rd), regs_name(rs1), (uint32_t)RV_SHAMT(pkg->insn));
                            else sprintf(buf, "illegal insn");
                            break;
                    } break;
                case RV_OP_AUIPC:
                    dec->rd_wr = !!(dec->rd);
                    sprintf(buf, "auipc %s,0x%x", regs_name(dec->rd), (uint32_t)(RV_IMM_U(pkg->insn) >> 12) & 0xfffff);
                    break;
                case RV_OP_OP_IMM_32:
                    dec->rd_wr = !!(dec->rd);
                    switch (RV_FUNCT3(pkg->insn))
                    {
                        case RV_FUNCT3_ADDI:
                            if (RV_IMM_I(pkg->insn) == 0) sprintf(buf, "sext.w %s,%s", regs_name(dec->rd), regs_name(rs1));
                            else sprintf(buf, "addiw %s,%s,%d", regs_name(dec->rd), regs_name(rs1), RV_IMM_I(pkg->insn));
                            break;
                        case RV_FUNCT3_SLLI:
                            if ((RV_FUNCT7(pkg->insn) & 0x3e) == (RV_FUNCT7_SLLI & 0x3e)) sprintf(buf, "slliw %s,%s,0x%x", regs_name(dec->rd), regs_name(rs1), (uint32_t)RV_SHAMT(pkg->insn));
                            else sprintf(buf, "illegal insn");
                            break;
                        case RV_FUNCT3_SRLI:
                            if ((RV_FUNCT7(pkg->insn) & 0x3e) == (RV_FUNCT7_SRLI & 0x3e)) sprintf(buf, "srliw %s,%s,0x%x", regs_name(dec->rd), regs_name(rs1), (uint32_t)RV_SHAMT(pkg->insn));
                            else if ((RV_FUNCT7(pkg->insn) & 0x3e) == (RV_FUNCT7_SRAI & 0x3e)) sprintf(buf, "sraiw %s,%s,0x%x", regs_name(dec->rd), regs_name(rs1), (uint32_t)RV_SHAMT(pkg->insn));
                            else sprintf(buf, "illegal insn");
                            break;
                    } break;
                case RV_OP_STORE:
                    dec->mem_wr = 1;
                    switch (RV_FUNCT3(pkg->insn))
                    {
                        case RV_FUNCT3_SB: sprintf(buf, "sb %s,%d(%s)", regs_name(rs2), RV_IMM_S(pkg->insn), regs_name(rs1)); break;
                        case RV_FUNCT3_SH: sprintf(buf, "sh %s,%d(%s)", regs_name(rs2), RV_IMM_S(pkg->insn), regs_name(rs1)); break;
                        case RV_FUNCT3_SW: sprintf(buf, "sw %s,%d(%s)", regs_name(rs2), RV_IMM_S(pkg->insn), regs_name(rs1)); break;
                        case RV_FUNCT3_SD: sprintf(buf, "sd %s,%d(%s)", regs_name(rs2), RV_IMM_S(pkg->insn), regs_name(rs1)); break;
                    } break;
                case RV_OP_STORE_FP: sprintf(buf, "illegal insn"); break;
                case RV_OP_CUST_1: sprintf(buf, "illegal insn"); break;
                case RV_OP_AMO:
                    dec->rd_wr = !!(dec->rd);
                    dec->mem_rd = 1;
                    switch (RV_FUNCT5(pkg->insn)) {
                        case RV_FUNCT5_LR:      sprintf(buf, "lr%s%s%s %s,(%s)", (RV_FUNCT3(pkg->insn) == 2) ? ".w" : ".d", RV_AQ(pkg->insn), RV_RL(pkg->insn), regs_name(dec->rd), regs_name(rs1)); break;
                        case RV_FUNCT5_SC:      sprintf(buf, "sc%s%s%s %s,%s,(%s)", (RV_FUNCT3(pkg->insn) == 2) ? ".w" : ".d", RV_AQ(pkg->insn), RV_RL(pkg->insn), regs_name(dec->rd), regs_name(rs2), regs_name(rs1)); break;
                        case RV_FUNCT5_AMOSWAP: sprintf(buf, "amoswap%s%s%s %s,%s,(%s)", (RV_FUNCT3(pkg->insn) == 2) ? ".w" : ".d", RV_AQ(pkg->insn), RV_RL(pkg->insn), regs_name(dec->rd), regs_name(rs2), regs_name(rs1)); break;
                        case RV_FUNCT5_AMOADD:  sprintf(buf, "amoadd%s%s%s %s,%s,(%s)", (RV_FUNCT3(pkg->insn) == 2) ? ".w" : ".d", RV_AQ(pkg->insn), RV_RL(pkg->insn), regs_name(dec->rd), regs_name(rs2), regs_name(rs1)); break;
                        case RV_FUNCT5_AMOXOR:  sprintf(buf, "amoxor%s%s%s %s,%s,(%s)", (RV_FUNCT3(pkg->insn) == 2) ? ".w" : ".d", RV_AQ(pkg->insn), RV_RL(pkg->insn), regs_name(dec->rd), regs_name(rs2), regs_name(rs1)); break;
                        case RV_FUNCT5_AMOAND:  sprintf(buf, "amoand%s%s%s %s,%s,(%s)", (RV_FUNCT3(pkg->insn) == 2) ? ".w" : ".d", RV_AQ(pkg->insn), RV_RL(pkg->insn), regs_name(dec->rd), regs_name(rs2), regs_name(rs1)); break;
                        case RV_FUNCT5_AMOOR:   sprintf(buf, "amoor%s%s%s %s,%s,(%s)", (RV_FUNCT3(pkg->insn) == 2) ? ".w" : ".d", RV_AQ(pkg->insn), RV_RL(pkg->insn), regs_name(dec->rd), regs_name(rs2), regs_name(rs1)); break;
                        case RV_FUNCT5_AMOMIN:  sprintf(buf, "amomin%s%s%s %s,%s,(%s)", (RV_FUNCT3(pkg->insn) == 2) ? ".w" : ".d", RV_AQ(pkg->insn), RV_RL(pkg->insn), regs_name(dec->rd), regs_name(rs2), regs_name(rs1)); break;
                        case RV_FUNCT5_AMOMAX:  sprintf(buf, "amomax%s%s%s %s,%s,(%s)", (RV_FUNCT3(pkg->insn) == 2) ? ".w" : ".d", RV_AQ(pkg->insn), RV_RL(pkg->insn), regs_name(dec->rd), regs_name(rs2), regs_name(rs1)); break;
                        case RV_FUNCT5_AMOMINU: sprintf(buf, "amominu%s%s%s %s,%s,(%s)", (RV_FUNCT3(pkg->insn) == 2) ? ".w" : ".d", RV_AQ(pkg->insn), RV_RL(pkg->insn), regs_name(dec->rd), regs_name(rs2), regs_name(rs1)); break;
                        case RV_FUNCT5_AMOMAXU: sprintf(buf, "amomaxu%s%s%s %s,%s,(%s)", (RV_FUNCT3(pkg->insn) == 2) ? ".w" : ".d", RV_AQ(pkg->insn), RV_RL(pkg->insn), regs_name(dec->rd), regs_name(rs2), regs_name(rs1)); break;
                    } break;
                case RV_OP_OP:
                    dec->rd_wr = !!(dec->rd);
                    switch (RV_FUNCT7(pkg->insn)) {
                        case RV_FUNCT7_OP0:
                            switch (RV_FUNCT3(pkg->insn)) {
                                case RV_FUNCT3_ADD:  sprintf(buf, "add %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_SLL:  sprintf(buf, "sll %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_SLT:  sprintf(buf, "slt %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_SLTU: sprintf(buf, "sltu %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_XOR:  sprintf(buf, "xor %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_SRL:  sprintf(buf, "srl %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_OR:   sprintf(buf, "or %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_AND:  sprintf(buf, "and %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                            } break;
                        case RV_FUNCT7_OP1:
                            switch (RV_FUNCT3(pkg->insn)) {
                                case RV_FUNCT3_ADD: sprintf(buf, "sub %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_SRL: sprintf(buf, "sra %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                            } break;
                        case RV_FUNCT7_MULDIV:
                            switch (RV_FUNCT3(pkg->insn)) {
                                case RV_FUNCT3_MUL:    sprintf(buf, "mul %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_MULH:   sprintf(buf, "mulh %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_MULHSU: sprintf(buf, "mulhsu %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_MULHU:  sprintf(buf, "mulhu %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_DIV:    sprintf(buf, "div %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_DIVU:   sprintf(buf, "divu %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_REM:    sprintf(buf, "rem %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_REMU:   sprintf(buf, "remu %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                            } break;
                    } break;
                case RV_OP_LUI:
                    dec->rd_wr = !!(dec->rd);
                    sprintf(buf, "lui %s,0x%x", regs_name(dec->rd), (uint32_t)RV_IMM_U(pkg->insn) >> 12 & 0xfffff);
                    break;
                case RV_OP_OP_32:
                    dec->rd_wr = !!(dec->rd);
                    switch (RV_FUNCT7(pkg->insn)) {
                        case RV_FUNCT7_OP0:
                            switch (RV_FUNCT3(pkg->insn)) {
                                case RV_FUNCT3_ADD: sprintf(buf, "addw %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_SLL: sprintf(buf, "sllw %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_SRL: sprintf(buf, "srlw %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                            } break;
                        case RV_FUNCT7_OP1:
                            switch (RV_FUNCT3(pkg->insn)) {
                                case RV_FUNCT3_ADD: sprintf(buf, "subw %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_SRL: sprintf(buf, "sraw %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                            } break;
                        case RV_FUNCT7_MULDIV:
                            switch (RV_FUNCT3(pkg->insn)) {
                                case RV_FUNCT3_MUL:  sprintf(buf, "mulw %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_DIV:  sprintf(buf, "divw %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_DIVU: sprintf(buf, "divuw %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_REM:  sprintf(buf, "remw %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                                case RV_FUNCT3_REMU: sprintf(buf, "remuw %s,%s,%s", regs_name(dec->rd), regs_name(rs1), regs_name(rs2)); break;
                            } break;
                    } break;
                case RV_OP_MADD: sprintf(buf, "illegal insn"); break;
                case RV_OP_MSUB: sprintf(buf, "illegal insn"); break;
                case RV_OP_NMSUB: sprintf(buf, "illegal insn"); break;
                case RV_OP_NMADD: sprintf(buf, "illegal insn"); break;
                case RV_OP_OP_FP: sprintf(buf, "illegal insn"); break;
                case RV_OP_CUST_2: sprintf(buf, "illegal insn"); break;
                case RV_OP_BRANCH:
                    switch (RV_FUNCT3(pkg->insn)) {
                        case RV_FUNCT3_BEQ:
                            if (rs2 != 0) sprintf(buf, "beq %s,%s,%08llx", regs_name(rs1), regs_name(rs2), (pkg->pc + RV_IMM_B(pkg->insn)));
                            else          sprintf(buf, "beqz %s,%08llx", regs_name(rs1), (pkg->pc + RV_IMM_B(pkg->insn)));
                            break;
                        case RV_FUNCT3_BNE:
                            if (rs2 != 0) sprintf(buf, "bne %s,%s,%08llx", regs_name(rs1), regs_name(rs2), (pkg->pc + RV_IMM_B(pkg->insn)));
                            else sprintf(buf, "bnez %s,%08llx", regs_name(rs1), (pkg->pc + RV_IMM_B(pkg->insn)));
                            break;
                        case RV_FUNCT3_BLT:
                            if (rs1 == 0) sprintf(buf, "bgtz %s,%08llx", regs_name(rs2), (pkg->pc + RV_IMM_B(pkg->insn)));
                            else if (rs2 == 0) sprintf(buf, "bltz %s,%08llx", regs_name(rs1), (pkg->pc + RV_IMM_B(pkg->insn)));
                            else sprintf(buf, "blt %s,%s,%08llx", regs_name(rs1), regs_name(rs2), (pkg->pc + RV_IMM_B(pkg->insn)));
                            break;
                        case RV_FUNCT3_BGE:
                            if (rs1 == 0) sprintf(buf, "blez %s,%08llx", regs_name(rs2), (pkg->pc + RV_IMM_B(pkg->insn)));
                            else if (rs2 == 0) sprintf(buf, "bgez %s,%08llx", regs_name(rs1), (pkg->pc + RV_IMM_B(pkg->insn)));
                            else sprintf(buf, "bge %s,%s,%08llx", regs_name(rs1), regs_name(rs2), (pkg->pc + RV_IMM_B(pkg->insn)));
                            break;
                        case RV_FUNCT3_BLTU: sprintf(buf, "bltu %s,%s,%08llx", regs_name(rs1), regs_name(rs2), (pkg->pc + RV_IMM_B(pkg->insn))); break;
                        case RV_FUNCT3_BGEU: sprintf(buf, "bgeu %s,%s,%08llx", regs_name(rs1), regs_name(rs2), (pkg->pc + RV_IMM_B(pkg->insn))); break;
                    } break;
                case RV_OP_JALR:
                    dec->rd_wr = !!(dec->rd);
                    if (RV_IMM_I(pkg->insn) != 0 || !(dec->rd == RV_REG_ZERO || dec->rd == RV_REG_RA)) sprintf(buf, "jalr %s,%d(%s)", regs_name(dec->rd), RV_IMM_I(pkg->insn), regs_name(rs1));
                    else if (dec->rd == RV_REG_RA) sprintf(buf, "jalr %s", regs_name(rs1));
                    else if (rs1 == RV_REG_RA) sprintf(buf, "ret");
                    else sprintf(buf, "jr %s", regs_name(rs1));
                    break;
                case RV_OP_JAL:
                    dec->rd_wr = !!(dec->rd);
                    if (dec->rd == 0) sprintf(buf, "j %08llx", (pkg->pc + RV_IMM_J(pkg->insn)));
                    else if (dec->rd == RV_REG_RA) sprintf(buf, "jal %08llx", (pkg->pc + RV_IMM_J(pkg->insn)));
                    else sprintf(buf, "jal %s,%08llx", regs_name(dec->rd), (pkg->pc + RV_IMM_J(pkg->insn)));
                    break;
                case RV_OP_SYSTEM:
                    switch (RV_FUNCT3(pkg->insn)) {
                        case RV_FUNCT3_PRIV:
                            if (RV_FUNCT7(pkg->insn) == RV_FUNCT7_SFENCE_VMA)
                                if (rs1 == 0 && rs2 == 0) sprintf(buf, "sfence.vma");
                                else if (rs2 == 0)        sprintf(buf, "sfence.vma %s", regs_name(rs1));
                                else                      sprintf(buf, "sfence.vma %s,%s", regs_name(rs1), regs_name(rs2));
                            else if (((pkg->insn >> 7) & 0x1f) == 0 && ((pkg->insn >> 15) & 0x1f) == 0)
                                switch ((pkg->insn >> 20) & 0xfff) {
                                    case RV_FUNCT12_ECALL:  sprintf(buf, "ecall"); break;
                                    case RV_FUNCT12_EBREAK: sprintf(buf, "ebreak"); break;
                                    case RV_FUNCT12_WFI:    sprintf(buf, "wfi"); break;
                                    case RV_FUNCT12_SRET:   sprintf(buf, "sret"); break;
                                    case RV_FUNCT12_MRET:   sprintf(buf, "mret"); break;
                                }
                            else sprintf(buf, "illegal insn");
                            break;
                        case RV_FUNCT3_CSRRW:
                            dec->csr_wr = 1;
                            dec->rd_wr = !!(dec->rd);
                            if (!!(dec->rd)) sprintf(buf, "csrrw %s,%s,%s", regs_name(dec->rd), RV_GET_CSR_NAME(pkg->insn), regs_name(rs1));
                            else sprintf(buf, "csrw %s,%s", RV_GET_CSR_NAME(pkg->insn), regs_name(rs1));
                            break;
                        case RV_FUNCT3_CSRRS:
                            dec->csr_wr = rs1 != 0;
                            dec->rd_wr = !!(dec->rd);
                            if (rs1 == 0) sprintf(buf, "csrr %s,%s", regs_name(dec->rd), RV_GET_CSR_NAME(pkg->insn));
                            else if (dec->rd == 0) sprintf(buf, "csrs %s,%s", RV_GET_CSR_NAME(pkg->insn), regs_name(rs1));
                            else sprintf(buf, "csrrs %s,%s,%s", regs_name(dec->rd), RV_GET_CSR_NAME(pkg->insn), regs_name(rs1));
                            break;
                        case RV_FUNCT3_CSRRC:
                            dec->csr_wr = rs1 != 0;
                            dec->rd_wr = !!(dec->rd);
                            if (rs1 == 0) sprintf(buf, "csrr %s,%s", regs_name(dec->rd), RV_GET_CSR_NAME(pkg->insn));
                            else if (dec->rd == 0) sprintf(buf, "csrc %s,%s", RV_GET_CSR_NAME(pkg->insn), regs_name(rs1));
                            else sprintf(buf, "csrrc %s,%s,%s", regs_name(dec->rd), RV_GET_CSR_NAME(pkg->insn), regs_name(rs1));
                            break;
                        case RV_FUNCT3_CSRRWI:
                            dec->csr_wr = 1;
                            dec->rd_wr = !!(dec->rd);
                            if (!!(dec->rd)) sprintf(buf, "csrrwi %s,%s,0x%x", regs_name(dec->rd), RV_GET_CSR_NAME(pkg->insn), (uint32_t)rs1);
                            else sprintf(buf, "csrwi %s,0x%x", RV_GET_CSR_NAME(pkg->insn), (uint32_t)rs1);
                            break;
                        case RV_FUNCT3_CSRRSI:
                            dec->csr_wr = rs1 != 0;
                            dec->rd_wr = !!(dec->rd);
                            if (rs1 == 0) sprintf(buf, "csrr %s,%s", regs_name(dec->rd), RV_GET_CSR_NAME(pkg->insn));
                            else if (dec->rd == 0) sprintf(buf, "csrsi %s,0x%x", RV_GET_CSR_NAME(pkg->insn), (uint32_t)rs1);
                            else sprintf(buf, "csrrsi %s,%s,0x%x", regs_name(dec->rd), RV_GET_CSR_NAME(pkg->insn), (uint32_t)rs1);
                            break;
                        case RV_FUNCT3_CSRRCI:
                            dec->csr_wr = rs1 != 0;
                            dec->rd_wr = !!(dec->rd);
                            if (rs1 == 0) sprintf(buf, "csrr %s,%s", regs_name(dec->rd), RV_GET_CSR_NAME(pkg->insn));
                            else if (dec->rd == 0) sprintf(buf, "csrci %s,0x%x", RV_GET_CSR_NAME(pkg->insn), (uint32_t)rs1);
                            else sprintf(buf, "csrrci %s,%s,0x%x", regs_name(dec->rd), RV_GET_CSR_NAME(pkg->insn), (uint32_t)rs1);
                            break;
                    } break;
                case RV_OP_CUST_3: sprintf(buf, "illegal insn"); break;
            }
    }
    return buf;
}

static char *tracer_decode(char *buf, const struct trace_package *pkg) {
    struct trace_decode dec;
    char tmp1[10], tmp2[64];
    uint32_t cnt;

    if (pkg->type == 0x3) {
        if (pkg->d2.mcause >> 31) 
            sprintf(buf, "(%d cycles) Interrupt %lld, epc = 0x%08llx, tval = 0x%08llx", pkg->cycle, pkg->d2.mcause & 0x7fffffff, pkg->pc, pkg->d1.mtval);
        else {
            switch (pkg->d2.mcause) {
                case RV_CAUSE_MISALIGNED_FETCH:       sprintf(tmp2, "InstructionAddressMisaligned"); break;
                case RV_CAUSE_INSTRUCTION_ACCESS:     sprintf(tmp2, "InstructionAccessFault"); break;
                case RV_CAUSE_ILLEGAL_INSTRUCTION:    sprintf(tmp2, "IllegalInstruction"); break;
                case RV_CAUSE_BREAKPOINT:             sprintf(tmp2, "Breakpoint"); break;
                case RV_CAUSE_MISALIGNED_LOAD:        sprintf(tmp2, "LoadAddressMisaligned"); break;
                case RV_CAUSE_LOAD_ACCESS:            sprintf(tmp2, "LoadAccessFault"); break;
                case RV_CAUSE_MISALIGNED_STORE:       sprintf(tmp2, "StoreAddressMisaligned"); break;
                case RV_CAUSE_STORE_ACCESS:           sprintf(tmp2, "StoreAccessFault"); break;
                case RV_CAUSE_USER_ECALL:             sprintf(tmp2, "UserEcall"); break;
                case RV_CAUSE_SUPERVISOR_ECALL:       sprintf(tmp2, "SupervisorEcall"); break;
                case RV_CAUSE_HYPERVISOR_ECALL:       sprintf(tmp2, "HypervisorEcall"); break;
                case RV_CAUSE_MACHINE_ECALL:          sprintf(tmp2, "MachineEcall"); break;
                case RV_CAUSE_INSTRUCTION_PAGE_FAULT: sprintf(tmp2, "InstructionPageFault"); break;
                case RV_CAUSE_LOAD_PAGE_FAULT:        sprintf(tmp2, "LoadPageFault"); break;
                case RV_CAUSE_STORE_PAGE_FAULT:       sprintf(tmp2, "StorePageFault"); break;
                default:                              sprintf(tmp2, "Unknown exception #%lld", pkg->d2.mcause); break;
            }
            sprintf(buf, "(%d cycles) %s, epc = 0x%08llx, tval = 0x%08llx", pkg->cycle, tmp2, pkg->pc, pkg->d1.mtval);
        }
    }
    else {
        insn_decode(tmp2, pkg, &dec);
        if ((pkg->insn & 3) == 3) sprintf(tmp1, "%08x", pkg->insn);
        else                      sprintf(tmp1, "----%04x", pkg->insn & 0xffff);
        cnt = sprintf(buf, "(%d cycles) [%s] %016llx:%s %s",
                      pkg->cycle,
                      pkg->prv == 0 ? "U" : pkg->prv == 1 ? "S" : pkg->prv == 3 ? "M" : "UNKNOWN",
                      pkg->pc, tmp1, tmp2);
        if (dec.mem_rd)      cnt += sprintf(buf + cnt, "\n  LOAD  MEM[%08llx]: %08x %08x", pkg->d2.mem_addr, (uint32_t)(pkg->d1.mem_data >> 32), (uint32_t)pkg->d1.mem_data);
        else if (dec.mem_wr) cnt += sprintf(buf + cnt, "\n  STORE MEM[%08llx]: %08x %08x", pkg->d2.mem_addr, (uint32_t)(pkg->d1.mem_data >> 32), (uint32_t)pkg->d1.mem_data);
        if (dec.csr_wr)      cnt += sprintf(buf + cnt, "\n  %-10s%016llx", RV_GET_CSR_NAME(pkg->insn), pkg->d2.csr_wdata);
        if (dec.rd_wr)       cnt += sprintf(buf + cnt, "\n  %-10s%016llx", regs_name(dec.rd), pkg->d1.rd_data);
    }
    return buf;
}