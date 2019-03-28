/* ====================================================================
 *      0x 0f 3a 44
 * ==================================================================== */
void __stdcall pclmulqdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = CLMUL_INSTRUCTION;

        GV.ImmediatSize = 8;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;

        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));

        if ((*pMyDisasm).Instruction.Immediat == 0) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmullqlqdq ");
            #endif
        }
        else if ((*pMyDisasm).Instruction.Immediat == 0x01 ) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmulhqlqdq ");
            #endif
        }
        else if ((*pMyDisasm).Instruction.Immediat == 0x10 ) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmullqhqdq ");
            #endif
        }
        else if ((*pMyDisasm).Instruction.Immediat == 0x011 ) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmulhqhqdq ");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmulqdq ");
            #endif
            GV.third_arg = 1;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
            #endif
            (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument3.ArgSize = 8;
        }
    }
    else {
        FailDecode(pMyDisasm);
    }
}
