void __stdcall emms_(PDISASM pMyDisasm)
{
	(*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+STATE_MANAGEMENT;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "emms ");
    #endif
	GV.EIP_++;
}

/* ====================================================================
 *      0x 0f 7e
 * ==================================================================== */
void __stdcall movd_EP(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        #endif
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg1qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
            #endif
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg1dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
            #endif
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    else {
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg1qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
            #endif
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg1dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
            #endif
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}


/* ====================================================================
 *      0x 0f 6e
 * ==================================================================== */
void __stdcall movd_PE(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
            #endif
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
            #endif
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    else {
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
            #endif
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
            #endif
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}



/* ====================================================================
 *      0x 0f 6f
 * ==================================================================== */
void __stdcall movq_PQ(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqu ");
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
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqa ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 7f
 * ==================================================================== */
void __stdcall movq_QP(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg1dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqu ");
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
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqa ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg1qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        #endif
        GV.MMX_ = 1;
        ExGx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d6
 * ==================================================================== */
void __stdcall movq_WV(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdq2q ");
        #endif
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;

    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq2dq ");
        #endif
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        #endif
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 1c
 * ==================================================================== */
void __stdcall pabsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsb ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 38 1e
 * ==================================================================== */
void __stdcall pabsd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsd ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 38 1d
 * ==================================================================== */
void __stdcall pabsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 63
 * ==================================================================== */
void __stdcall packsswb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packsswb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packsswb ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 6b
 * ==================================================================== */
void __stdcall packssdw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packssdw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packssdw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 67
 * ==================================================================== */
void __stdcall packuswb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packuswb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packuswb ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fc
 * ==================================================================== */
void __stdcall paddb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddb ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fd
 * ==================================================================== */
void __stdcall paddw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fe
 * ==================================================================== */
void __stdcall paddd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddd ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddd ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f ec
 * ==================================================================== */
void __stdcall paddsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddsb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddsb ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f ed
 * ==================================================================== */
void __stdcall paddsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddsw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddsw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f dc
 * ==================================================================== */
void __stdcall paddusb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddusb ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddusb ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f dd
 * ==================================================================== */
void __stdcall paddusw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddusw ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddusw ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f db
 * ==================================================================== */
void __stdcall pand_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pand ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pand ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}
/* ====================================================================
 *      0x 0f df
 * ==================================================================== */
void __stdcall pandn_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pandn ");
        #endif
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pandn ");
        #endif
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 74
 * ==================================================================== */
void __stdcall pcmpeqb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqb ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqb ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 75
 * ==================================================================== */
void __stdcall pcmpeqw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 76
 * ==================================================================== */
void __stdcall pcmpeqd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 64
 * ==================================================================== */
void __stdcall pcmpgtb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtb ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtb ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 65
 * ==================================================================== */
void __stdcall pcmpgtw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 66
 * ==================================================================== */
void __stdcall pcmpgtd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e5
 * ==================================================================== */
void __stdcall pmulhw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d5
 * ==================================================================== */
void __stdcall pmullw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmullw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmullw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f5
 * ==================================================================== */
void __stdcall pmaddwd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaddwd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaddwd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f eb
 * ==================================================================== */
void __stdcall por_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "por ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "por ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f1
 * ==================================================================== */
void __stdcall psllw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psllw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psllw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f2
 * ==================================================================== */
void __stdcall pslld_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pslld ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pslld ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f3
 * ==================================================================== */
void __stdcall psllq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psllq ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psllq ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d1
 * ==================================================================== */
void __stdcall psrlw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrlw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrlw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d2
 * ==================================================================== */
void __stdcall psrld_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrld ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrld ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d3
 * ==================================================================== */
void __stdcall psrlq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrlq ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrlq ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e1
 * ==================================================================== */
void __stdcall psraw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psraw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psraw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e2
 * ==================================================================== */
void __stdcall psrad_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrad ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrad ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f8
 * ==================================================================== */
void __stdcall psubb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubb ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubb ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f9
 * ==================================================================== */
void __stdcall psubw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fa
 * ==================================================================== */
void __stdcall psubd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e8
 * ==================================================================== */
void __stdcall psubsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubsb ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubsb ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e9
 * ==================================================================== */
void __stdcall psubsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubsw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubsw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d8
 * ==================================================================== */
void __stdcall psubusb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubusb ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubusb ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d9
 * ==================================================================== */
void __stdcall psubusw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubusw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubusw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 68
 * ==================================================================== */
void __stdcall punpckhbw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhbw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhbw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 69
 * ==================================================================== */
void __stdcall punpckhwd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhwd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhwd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 6a
 * ==================================================================== */
void __stdcall punpckhdq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhdq ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhdq ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 60
 * ==================================================================== */
void __stdcall punpcklbw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklbw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklbw ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 61
 * ==================================================================== */
void __stdcall punpcklwd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklwd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklwd ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 62
 * ==================================================================== */
void __stdcall punpckldq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckldq ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckldq ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f ef
 * ==================================================================== */
void __stdcall pxor_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pxor ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pxor ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}
