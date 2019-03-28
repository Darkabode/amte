/* ====================================================================
 *      0f6h
 * ==================================================================== */
void __stdcall G3_Eb(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test ");
        #endif
        EbIb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, 104);
    }
    else if (GV.REGOPCODE == 1) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test ");
        #endif
        EbIb(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, 104);
    }
    else if (GV.REGOPCODE == 2) {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "not ");
        #endif
        Eb(pMyDisasm);
        FillFlags(pMyDisasm, 73);
    }
    else if (GV.REGOPCODE == 3) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "neg ");
        #endif
        Eb(pMyDisasm);
        FillFlags(pMyDisasm, 71);
    }
    else if (GV.REGOPCODE == 4) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mul ");
        #endif
        GV.MemDecoration = Arg2byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0;
        FillFlags(pMyDisasm, 70);
    }
    else if (GV.REGOPCODE == 5) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul ");
        #endif
        GV.MemDecoration = Arg2byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Argument1.ArgSize = 8;
        FillFlags(pMyDisasm, 38);
    }
    else if (GV.REGOPCODE == 6) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "div ");
        #endif
        GV.MemDecoration = Arg2byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Argument1.ArgSize = 8;
        FillFlags(pMyDisasm, 31);
    }
    else if (GV.REGOPCODE == 7) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "idiv ");
        #endif
        GV.MemDecoration = Arg2byte;
        GV.OperandSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.OperandSize = 32;
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0;
        FillFlags(pMyDisasm, 37);
    }
}

/* ====================================================================
 *      0f7h
 * ==================================================================== */
void __stdcall G3_Ev(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test ");
        #endif
        EvIv(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, 104);
    }
    else if (GV.REGOPCODE == 1) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "test ");
        #endif
        EvIv(pMyDisasm);
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, 104);
    }
    else if (GV.REGOPCODE == 2) {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "not ");
        #endif
        Ev(pMyDisasm);
        FillFlags(pMyDisasm, 73);
    }
    else if (GV.REGOPCODE == 3) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "neg ");
        #endif
        Ev(pMyDisasm);
        FillFlags(pMyDisasm, 71);
    }
    else if (GV.REGOPCODE == 4) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mul ");
        #endif
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
			(*pMyDisasm).Argument1.ArgSize = 64;			
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
			(*pMyDisasm).Argument1.ArgSize = 32;				
        }
        else {
            GV.MemDecoration = Arg2word;
			(*pMyDisasm).Argument1.ArgSize = 16;				
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        FillFlags(pMyDisasm, 70);
    }
    else if (GV.REGOPCODE == 5) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul ");
        #endif
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
			(*pMyDisasm).Argument1.ArgSize = 64;			
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
			(*pMyDisasm).Argument1.ArgSize = 32;				
        }
        else {
            GV.MemDecoration = Arg2word;
			(*pMyDisasm).Argument1.ArgSize = 16;				
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        FillFlags(pMyDisasm, 38);
    }
    else if (GV.REGOPCODE == 6) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "div ");
        #endif
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
			(*pMyDisasm).Argument1.ArgSize = 64;			
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
			(*pMyDisasm).Argument1.ArgSize = 32;				
        }
        else {
            GV.MemDecoration = Arg2word;
			(*pMyDisasm).Argument1.ArgSize = 16;				
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;		
        FillFlags(pMyDisasm, 31);
    }
    else if (GV.REGOPCODE == 7) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "idiv ");
        #endif
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
			(*pMyDisasm).Argument1.ArgSize = 64;			
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
			(*pMyDisasm).Argument1.ArgSize = 32;				
        }
        else {
            GV.MemDecoration = Arg2word;
			(*pMyDisasm).Argument1.ArgSize = 16;				
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = REGISTER_TYPE+GENERAL_REG+REG0+REG2;		
        FillFlags(pMyDisasm, 37);
    }
}
