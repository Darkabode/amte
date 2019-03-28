/* ====================================================================
 *      0f00h
 * ==================================================================== */
void __stdcall G6_(PDISASM pMyDisasm)
{
    int32_t OperandSizeOld = 0;

    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    OperandSizeOld = GV.OperandSize;
    GV.OperandSize = 16;
    GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
    GV.MOD_= ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 6) & 0x3;

    if (GV.REGOPCODE == 0) {
        if ((OperandSizeOld == 64) && (GV.MOD_== 0x3)) {
            GV.OperandSize = OperandSizeOld;
        }
        else {
            GV.MemDecoration = Arg1word;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sldt ");
        #endif
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+MEMORY_MANAGEMENT_REG+REG1;
        (*pMyDisasm).Argument2.ArgSize = 32;
        GV.OperandSize = OperandSizeOld;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else if (GV.REGOPCODE == 1) {
        if ((OperandSizeOld == 64) && (GV.MOD_== 0x3)) {
            GV.OperandSize = OperandSizeOld;
        }
        else {
            GV.MemDecoration = Arg1word;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "str ");
        #endif
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+MEMORY_MANAGEMENT_REG+REG3;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.OperandSize = OperandSizeOld;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else if (GV.REGOPCODE == 2) {
        GV.MemDecoration = Arg2word;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lldt ");
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+MEMORY_MANAGEMENT_REG+REG1;
        (*pMyDisasm).Argument1.ArgSize = 16;
        GV.OperandSize = OperandSizeOld;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else if (GV.REGOPCODE == 3) {
        GV.MemDecoration = Arg2word;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ltr ");
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+MEMORY_MANAGEMENT_REG+REG3;
        (*pMyDisasm).Argument1.ArgSize = 16;
        GV.OperandSize = OperandSizeOld;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else if (GV.REGOPCODE == 4) {
        GV.MemDecoration = Arg1word;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "verr ");
        #endif
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.OperandSize = OperandSizeOld;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else if (GV.REGOPCODE == 5) {
        GV.MemDecoration = Arg1word;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "verw ");
        #endif
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.OperandSize = OperandSizeOld;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else if (GV.REGOPCODE == 6) {
        FailDecode(pMyDisasm);
        GV.OperandSize = OperandSizeOld;
    }
    else {
        FailDecode(pMyDisasm);
        GV.OperandSize = OperandSizeOld;
    }
}

