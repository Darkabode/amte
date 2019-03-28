/* ====================================================================
 *      0fc7h
 * ==================================================================== */
void __stdcall G9_(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
    GV.MemDecoration = Arg2qword;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    if (GV.REGOPCODE == 1) {
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2dqword;
            (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpxchg16b ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
            (*pMyDisasm).Argument1.ArgSize = 128;
            (*pMyDisasm).Argument1.AccessMode = READ;
            FillFlags(pMyDisasm, 23);
            GV.EIP_ += GV.DECALAGE_EIP+2;
        }
        else {
            (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpxchg8b ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
            (*pMyDisasm).Argument1.ArgSize = 64;
            (*pMyDisasm).Argument1.AccessMode = READ;
            FillFlags(pMyDisasm, 23);
            GV.EIP_ += GV.DECALAGE_EIP+2;
        }
    }
    else if (GV.REGOPCODE == 6) {
        (*pMyDisasm).Instruction.Category = VM_INSTRUCTION;
        if (GV.OperandSize == 16) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmclear ");
            #endif
        }
        else if (GV.PrefRepe == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmxon ");
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmptrld ");
            #endif
        }
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
    else if (GV.REGOPCODE == 7) {
        (*pMyDisasm).Instruction.Category = VM_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "vmptrst ");
        #endif
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }

}
