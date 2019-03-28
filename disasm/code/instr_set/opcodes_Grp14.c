
/* ====================================================================
 *
 * ==================================================================== */
void __stdcall G14_(PDISASM pMyDisasm)
{
    long MyNumber;

    GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 2) {
        if (GV.OperandSize == 16) {
            (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHIFT_ROTATE;
            GV.MemDecoration = Arg1dqword;
            GV.ImmediatSize = 8;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            if (GV.MOD_== 0x3) {
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrlq ");
                #endif
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((uint8_t*)(puint_t) (GV.EIP_-1));
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
            #endif
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        else {
            (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
            GV.MemDecoration = Arg1qword;
            GV.ImmediatSize = 8;
            GV.MMX_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 0;
            if (GV.MOD_== 0x3) {
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrlq ");
                #endif
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((uint8_t*)(puint_t) (GV.EIP_-1));
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
            #endif
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
    }
    else if (GV.REGOPCODE == 3) {
        if (GV.OperandSize == 16) {
            (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHIFT_ROTATE;
            GV.MemDecoration = Arg1dqword;
            GV.ImmediatSize = 8;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            if (GV.MOD_== 0x3) {
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrldq ");
                #endif
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((uint8_t*)(puint_t) (GV.EIP_-1));
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
            #endif
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        else {
            FailDecode(pMyDisasm);
        }

    }
    else if (GV.REGOPCODE == 6) {
        if (GV.OperandSize == 16) {
            (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHIFT_ROTATE;
            GV.MemDecoration = Arg1dqword;
            GV.ImmediatSize = 8;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            if (GV.MOD_== 0x3) {
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psllq ");
                #endif
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((uint8_t*)(puint_t) (GV.EIP_-1));
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
            #endif
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        else {
            (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
            GV.MemDecoration = Arg1qword;
            GV.ImmediatSize = 8;
            GV.MMX_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 0;
            if (GV.MOD_== 0x3) {
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psllq ");
                #endif
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((uint8_t*)(puint_t) (GV.EIP_-1));
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
            #endif
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
    }
    else if (GV.REGOPCODE == 7) {
        if (GV.OperandSize == 16) {
            (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHIFT_ROTATE;
            GV.MemDecoration = Arg1dqword;
            GV.ImmediatSize = 8;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            if (GV.MOD_== 0x3) {
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pslldq ");
                #endif
            }
            else {
                FailDecode(pMyDisasm);
            }
            GV.EIP_ += GV.DECALAGE_EIP+3;
            if (!Security(0, pMyDisasm)) return;

            MyNumber = *((uint8_t*)(puint_t) (GV.EIP_-1));
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
            #endif
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        else {
            FailDecode(pMyDisasm);
        }

    }
    else {
        FailDecode(pMyDisasm);
    }

}
