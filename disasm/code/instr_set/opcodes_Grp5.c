/* ====================================================================
 *      0ffh
 * ==================================================================== */
void __stdcall G5_Ev(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        Ev(pMyDisasm);
        FillFlags(pMyDisasm, 40);
    }
    else if (GV.REGOPCODE == 1) {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        #endif
        Ev(pMyDisasm);
        FillFlags(pMyDisasm, 30);
    }
    else if (GV.REGOPCODE == 2) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = CallType;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "call ");
        #endif
        if (GV.Architecture == 64) {
            GV.OperandSize = 64;
        }
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
        }
        else {
            GV.MemDecoration = Arg1word;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    }
    else if (GV.REGOPCODE == 3) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = CallType;
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "call far ");
        #endif
        GV.MemDecoration = Arg1fword;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    }
    else if (GV.REGOPCODE == 4) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = JmpType;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp ");
        #endif
        if (GV.Architecture == 64) {
            GV.OperandSize = 64;
        }
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
        }
        else {
            GV.MemDecoration = Arg1word;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.REGOPCODE == 5) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = JmpType;
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp far ");
        #endif
        GV.MemDecoration = Arg1fword;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else if (GV.REGOPCODE == 6) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "push ");
        #endif
        if (GV.Architecture == 64) {
            GV.OperandSize = 64;
        }
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
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG4;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

