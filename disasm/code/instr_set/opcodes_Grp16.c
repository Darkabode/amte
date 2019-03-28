/* ====================================================================
 *
 * ==================================================================== */
void __stdcall G16_(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        if (GV.MOD_!= 0x3) {
            GV.MemDecoration = Arg2byte;
            (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "prefetchNTA ");
            #endif
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else if (GV.REGOPCODE == 1) {
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        if (GV.MOD_!= 0x3) {
            GV.MemDecoration = Arg2byte;
            (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "prefetchT0 ");
            #endif
        }
        else {
            FailDecode(pMyDisasm);
        }

    }
    else if (GV.REGOPCODE == 2) {
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        if (GV.MOD_!= 0x3) {
            GV.MemDecoration = Arg2byte;
            (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "prefetchT1 ");
            #endif
        }
        else {
            FailDecode(pMyDisasm);
        }

    }
    else if (GV.REGOPCODE == 3) {
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        if (GV.MOD_!= 0x3) {
            GV.MemDecoration = Arg2byte;
            (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "prefetchT2 ");
            #endif
        }
        else {
            FailDecode(pMyDisasm);
        }

    }

    else {
        FailDecode(pMyDisasm);
    }
    GV.EIP_+= GV.DECALAGE_EIP+2;
}
