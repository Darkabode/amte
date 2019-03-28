/* ====================================================================
 *      0x 0f 58
 * ==================================================================== */
void __stdcall addps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d0
 * ==================================================================== */
void __stdcall addsubpd_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_PACKED;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addsubps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }

    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_PACKED;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addsubpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 55
 * ==================================================================== */
void __stdcall andnps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andnpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andnps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 54
 * ==================================================================== */
void __stdcall andps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 0d
 * ==================================================================== */
void __stdcall blendpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendpd ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 0c
 * ==================================================================== */
void __stdcall blendps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendps ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 15
 * ==================================================================== */
void __stdcall blendvpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendvpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 14
 * ==================================================================== */
void __stdcall blendvps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendvps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f c2
 * ==================================================================== */
void __stdcall cmpps_VW(PDISASM pMyDisasm)
{

    /* ========= 0xf2 */
    GV.ImmediatSize = 8;
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmppd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    GV.third_arg = 1;
    (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
    #endif
    (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument3.ArgSize = 8;

}


/* ====================================================================
 *      0x 0f 38 f0
 * ==================================================================== */
void __stdcall crc32_GvEb(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+ACCELERATOR_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "crc32 ");
        #endif
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2byte;
            GV.OperandSize = 8;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.OperandSize = 64;
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2byte;
            GV.OperandSize = 8;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.OperandSize = 32;
        }
        else {
            GV.MemDecoration = Arg2byte;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        }

        if (GV.OperandSize == 16) {
            GV.OperandSize = 32;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.OperandSize = 16;
        }
        else {
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        }
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 f1
 * ==================================================================== */
void __stdcall crc32_GvEv(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+ACCELERATOR_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "crc32 ");
        #endif

        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
        }
        else {
            GV.MemDecoration = Arg2word;
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);

        if (GV.OperandSize == 16) {
            GV.OperandSize = 32;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.OperandSize = 16;
        }
        else {
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        }
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 2f
 * ==================================================================== */
void __stdcall comiss_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "comisd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "comiss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 5a
 * ==================================================================== */
void __stdcall cvtps2pd_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsd2ss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtss2sd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpd2ps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtps2pd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 5b
 * ==================================================================== */
void __stdcall cvtdq2ps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttps2dq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtps2dq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtdq2ps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 2a
 * ==================================================================== */
void __stdcall cvtpi2ps_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsi2sd ");
        #endif
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsi2ss ");
        #endif
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpi2pd ");
        #endif
        GV.MemDecoration = Arg2qword;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpi2ps ");
        #endif
        GV.MemDecoration = Arg2qword;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
}


/* ====================================================================
 *      0x 0f 2d
 * ==================================================================== */
void __stdcall cvtps2pi_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsd2si ");
        #endif
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2qword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtss2si ");
        #endif
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2dword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpd2pi ");
        #endif
        GV.MemDecoration = Arg2dqword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtps2pi ");
        #endif
        GV.MemDecoration = Arg2qword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
}


/* ====================================================================
 *      0x 0f 2c
 * ==================================================================== */
void __stdcall cvttps2pi_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttsd2si ");
        #endif
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2qword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttss2si ");
        #endif
        GV.MemDecoration = Arg2dword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttpd2pi ");
        #endif
        GV.MemDecoration = Arg2dqword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttps2pi ");
        #endif
        GV.MemDecoration = Arg2qword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
}


/* ====================================================================
 *      0x 0f e6
 * ==================================================================== */
void __stdcall cvtpd2dq_(PDISASM pMyDisasm)
{
    /* ========== 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpd2dq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtdq2pd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttpd2dq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 41
 * ==================================================================== */
void __stdcall dppd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+DOT_PRODUCT;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dppd ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f 3a 40
 * ==================================================================== */
void __stdcall dpps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+DOT_PRODUCT;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dpps ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 5e
 * ==================================================================== */
void __stdcall divps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 17
 * ==================================================================== */
void __stdcall extractps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1dword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "extractps ");
        #endif
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 7c
 * ==================================================================== */
void __stdcall haddpd_VW(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "haddpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "haddps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 7d
 * ==================================================================== */
void __stdcall hsubpd_VW(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hsubpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hsubps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 21
 * ==================================================================== */
void __stdcall insertps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insertps ");
        #endif
        GV.SSE_ = 1;
        GV.MOD_= ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }

        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);


        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}



/* ====================================================================
 *      0x 0f f0
 * ==================================================================== */
void __stdcall lddqu_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SPECIALIZED_128bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lddqu ");
        #endif
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f f7
 * ==================================================================== */
void __stdcall maskmovq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maskmovdqu ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maskmovq ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 5f
 * ==================================================================== */
void __stdcall maxps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 5d
 * ==================================================================== */
void __stdcall minps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 28
 * ==================================================================== */
void __stdcall movaps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movapd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movaps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 29
 * ==================================================================== */
void __stdcall movaps_WV(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movapd ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movaps ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 16
 * ==================================================================== */
void __stdcall movhps_VM(PDISASM pMyDisasm)
{

    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movshdup ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        GV.MOD_= ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlhps ");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhps ");
            #endif
        }
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 17
 * ==================================================================== */
void __stdcall movhps_MV(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhpd ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhps ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 12
 * ==================================================================== */
void __stdcall movlps_VM(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movddup ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsldup ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        if (GV.MOD_== 0x3) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhlps ");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlps ");
            #endif
        }
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 13
 * ==================================================================== */
void __stdcall movlps_MV(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlpd ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlps ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 50
 * ==================================================================== */
void __stdcall movmskps_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_!= 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movmskpd ");
        #endif
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movmskps ");
        #endif
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
}


/* ====================================================================
 *      0x 0f 38 2a
 * ==================================================================== */
void __stdcall movntdqa_(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+STREAMING_LOAD;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntdqa ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f c3
 * ==================================================================== */
void __stdcall movnti_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movnti ");
    #endif
    EvGv(pMyDisasm);

}


/* ====================================================================
 *      0x 0f 2b
 * ==================================================================== */
void __stdcall movntps_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_== 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntpd ");
        #endif
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
    else {
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntps ");
        #endif
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
}


/* ====================================================================
 *      0x 0f e7
 * ==================================================================== */
void __stdcall movntq_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_== 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntdq ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntq ");
        #endif
        GV.MMX_ = 1;
        ExGx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 10
 * ==================================================================== */
void __stdcall movups_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movupd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movups ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}



/* ====================================================================
 *      0x 0f 11
 * ==================================================================== */
void __stdcall movups_WV(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsd ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg1dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movss ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movupd ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movups ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 42
 * ==================================================================== */
void __stdcall mpsadbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+SAD_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mpsadbw ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 59
 * ==================================================================== */
void __stdcall mulps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 56
 * ==================================================================== */
void __stdcall orps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+LOGICAL_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "orpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "orps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 2b
 * ==================================================================== */
void __stdcall packusdw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packusdw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f d4
 * ==================================================================== */
void __stdcall paddq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddq ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f e0
 * ==================================================================== */
void __stdcall pavgb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pavgb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pavgb ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f e3
 * ==================================================================== */
void __stdcall pavgw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pavgw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pavgw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 0f
 * ==================================================================== */
void __stdcall palignr_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "palignr ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "palignr ");
        #endif
        GV.ImmediatSize = 8;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
}


/* ====================================================================
 *      0x 0f 38 10
 * ==================================================================== */
void __stdcall pblendvb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pblendvb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pblendvb ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 0e
 * ==================================================================== */
void __stdcall pblendw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+SAD_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pblendw ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 29
 * ==================================================================== */
void __stdcall pcmpeqq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_EQUALITY;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 61
 * ==================================================================== */
void __stdcall pcmpestri_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpestri ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 60
 * ==================================================================== */
void __stdcall pcmpestrm_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpestrm ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 63
 * ==================================================================== */
void __stdcall pcmpistri_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpistri ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 62
 * ==================================================================== */
void __stdcall pcmpistrm_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpestrm ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 37
 * ==================================================================== */
void __stdcall pcmpgtq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 14
 * ==================================================================== */
void __stdcall pextrb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrb ");
        #endif
        GV.MOD_= ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            GV.MemDecoration = Arg1dword;
        }
        else {
            GV.MemDecoration = Arg1byte;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 16
 * ==================================================================== */
void __stdcall pextrd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        if (GV.REX.W_ == 0x1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrq ");
            #endif
            GV.MemDecoration = Arg1qword;
            GV.OperandSize = 64;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrd ");
            #endif
            GV.MemDecoration = Arg1dword;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f c5
 * ==================================================================== */
void __stdcall pextrw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrw ");
        #endif
        GV.MemDecoration = Arg2dqword;
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrw ");
        #endif
        GV.MemDecoration = Arg2dqword;
        GV.ImmediatSize = 8;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }

}

/* ====================================================================
 *      0x 0f 3a 15
 * ==================================================================== */
void __stdcall pextrw2_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrw ");
        #endif
        GV.MOD_= ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            GV.MemDecoration = Arg1dword;
        }
        else {
            GV.MemDecoration = Arg1word;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 02
 * ==================================================================== */
void __stdcall phaddd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddd ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 03
 * ==================================================================== */
void __stdcall phaddsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddsw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddsw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 01
 * ==================================================================== */
void __stdcall phaddw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 41
 * ==================================================================== */
void __stdcall phminposuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+HORIZONTAL_SEARCH;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phminposuw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 05
 * ==================================================================== */
void __stdcall phsubw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 06
 * ==================================================================== */
void __stdcall phsubd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubd ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 07
 * ==================================================================== */
void __stdcall phsubsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubsw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubsw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 20
 * ==================================================================== */
void __stdcall pinsrb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2byte;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrb ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 22
 * ==================================================================== */
void __stdcall pinsrd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        if (GV.REX.W_ == 0x1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrq ");
            #endif
            GV.MemDecoration = Arg1qword;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrd ");
            #endif
            GV.MemDecoration = Arg1dword;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f c4
 * ==================================================================== */
void __stdcall pinsrw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrw ");
        #endif
        GV.MemDecoration = Arg2word;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;


    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrw ");
        #endif
        GV.MemDecoration = Arg2word;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }

}


/* ====================================================================
 *      0x 0f 38 3c
 * ==================================================================== */
void __stdcall pmaxsb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxsb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3d
 * ==================================================================== */
void __stdcall pmaxsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3e
 * ==================================================================== */
void __stdcall pmaxuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxuw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3f
 * ==================================================================== */
void __stdcall pmaxud_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxud ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 38
 * ==================================================================== */
void __stdcall pminsb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminsb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 39
 * ==================================================================== */
void __stdcall pminsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3a
 * ==================================================================== */
void __stdcall pminuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminuw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3b
 * ==================================================================== */
void __stdcall pminud_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminud ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f da
 * ==================================================================== */
void __stdcall pminub_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminub ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminub ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f de
 * ==================================================================== */
void __stdcall pmaxub_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxub ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxub ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f ea
 * ==================================================================== */
void __stdcall pminsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminsw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminsw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f ee
 * ==================================================================== */
void __stdcall pmaxsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxsw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxsw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 04
 * ==================================================================== */
void __stdcall pmaddubsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaddubsw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaddubsw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f d7
 * ==================================================================== */
void __stdcall pmovmskb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {

        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovmskb ");
        #endif
        GV.MemDecoration = Arg2dqword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovmskb ");
        #endif
        GV.MemDecoration = Arg2qword;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }

}


/* ====================================================================
 *      0x 0f 38 21
 * ==================================================================== */
void __stdcall pmovsxbd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxbd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 22
 * ==================================================================== */
void __stdcall pmovsxbq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxbq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 20
 * ==================================================================== */
void __stdcall pmovsxbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxbw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 25
 * ==================================================================== */
void __stdcall pmovsxdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxdq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 23
 * ==================================================================== */
void __stdcall pmovsxwd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxwd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 24
 * ==================================================================== */
void __stdcall pmovsxwq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxwq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 31
 * ==================================================================== */
void __stdcall pmovzxbd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxbd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 32
 * ==================================================================== */
void __stdcall pmovzxbq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxbq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 30
 * ==================================================================== */
void __stdcall pmovzxbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxbw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 35
 * ==================================================================== */
void __stdcall pmovzxdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxdq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 33
 * ==================================================================== */
void __stdcall pmovzxwd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxwd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 34
 * ==================================================================== */
void __stdcall pmovzxwq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxwq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 28
 * ==================================================================== */
void __stdcall pmuldq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmuldq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 40
 * ==================================================================== */
void __stdcall pmulld_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulld ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 0b
 * ==================================================================== */
void __stdcall pmulhrsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhrsw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhrsw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f e4
 * ==================================================================== */
void __stdcall pmulhuw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhuw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhuw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f f4
 * ==================================================================== */
void __stdcall pmuludq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmuludq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmuludq ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* =======================================
 *      0x 0f b8
 * ======================================= */
void __stdcall popcnt_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "popcnt ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,114);
}


/* ====================================================================
 *      0x 0f f6
 * ==================================================================== */
void __stdcall psadbw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psadbw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psadbw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 00
 * ==================================================================== */
void __stdcall pshufb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+SHUFFLE_UNPACK;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+SHUFFLE_UNPACK;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufb ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 70
 * ==================================================================== */
void __stdcall pshufw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufhw ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    /* ========= 0xf2 */
    else if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshuflw ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }

    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufd ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufw ");
        #endif
        GV.ImmediatSize = 8;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
}

/* ====================================================================
 *      0x 0f 38 08
 * ==================================================================== */
void __stdcall psignb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignb ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 0a
 * ==================================================================== */
void __stdcall psignd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignd ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 09
 * ==================================================================== */
void __stdcall psignw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f fb
 * ==================================================================== */
void __stdcall psubq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubq ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 17
 * ==================================================================== */
void __stdcall ptest_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_TEST;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ptest ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f 6c
 * ==================================================================== */
void __stdcall punpcklqdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklqdq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f 6d
 * ==================================================================== */
void __stdcall punpckhqdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhqdq ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 53
 * ==================================================================== */
void __stdcall rcpps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rcpss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rcpps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 09
 * ==================================================================== */
void __stdcall roundpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundpd ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 08
 * ==================================================================== */
void __stdcall roundps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundps ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0b
 * ==================================================================== */
void __stdcall roundsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundsd ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0a
 * ==================================================================== */
void __stdcall roundss_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundss ");
        #endif
        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 52
 * ==================================================================== */
void __stdcall rsqrtps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rsqrtss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rsqrtps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f c6
 * ==================================================================== */
void __stdcall shufps_(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    GV.ImmediatSize = 8;
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shufpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHUFFLE_UNPACK;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shufps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    GV.third_arg = 1;
    (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
    #endif
    (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument3.ArgSize = 8;

}


/* ====================================================================
 *      0x 0f 51
 * ==================================================================== */
void __stdcall sqrtps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 5c
 * ==================================================================== */
void __stdcall subps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 2e
 * ==================================================================== */
void __stdcall ucomiss_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ucomisd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ucomiss ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 15
 * ==================================================================== */
void __stdcall unpckhps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpckhpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpckhps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 14
 * ==================================================================== */
void __stdcall unpcklps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpcklpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpcklps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 57
 * ==================================================================== */
void __stdcall xorps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+LOGICAL_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xorpd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xorps ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}
