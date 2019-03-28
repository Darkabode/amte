/* ====================================================================
 *      0x 0f 38 db
 * ==================================================================== */
void __stdcall aesimc(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aesimc ");
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
 *      0x 0f 38 dc
 * ==================================================================== */
void __stdcall aesenc(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aesenc ");
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
 *      0x 0f 38 dd
 * ==================================================================== */
void __stdcall aesenclast(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aesenclast ");
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
 *      0x 0f 38 de
 * ==================================================================== */
void __stdcall aesdec(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aesdec ");
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
 *      0x 0f 38 df
 * ==================================================================== */
void __stdcall aesdeclast(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aesdeclast ");
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
 *      0x 0f 3a df
 * ==================================================================== */
void __stdcall aeskeygen(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = AES_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aeskeygenassist ");
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
