/* ====================================================================
 *
 * ==================================================================== */
void __stdcall D8_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((uint8_t*)(puint_t) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Nasm;
    if (MyMODRM <= 0xbf) {
        GV.MemDecoration = Arg2dword;
        GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}

/* ====================================================================
 *
 * ==================================================================== */
void __stdcall D9_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((uint8_t*)(puint_t) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Nasm;
    if (MyMODRM <= 0xbf) {
        GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fst ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2multibytes;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldenv ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldcw ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg1multibytes;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstenv ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstcw ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxch ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fnop ");
                #endif
            }
            else if (((MyMODRM & 0xf) >=0x8) && ((MyMODRM & 0xf) <=0xf)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp1 ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fchs ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fabs ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ftst ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxam ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld1 ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;

            }
            else if ((MyMODRM & 0xf) ==9) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldl2t ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xa) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldl2e ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xb) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldpi ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xc) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldlg2 ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }

            else if ((MyMODRM & 0xf) ==0xd) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldln2 ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xe) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldz ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }

            else {
                FailDecode(pMyDisasm);
            }
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "f2xm1 ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fyl2x ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==2) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fptan ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==3) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fpatan ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxtract ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fprem1 ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==6) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdecstp ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==7) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fincstp ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fprem ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==9) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fyl2xp1 ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xa) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsqrt ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xb) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsincos ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xc) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "frndint ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xd) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fscale ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xe) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsin ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xf) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcos ");
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __stdcall DA_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((uint8_t*)(puint_t) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Nasm;
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fiadd ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fimul ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficom ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficomp ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisub ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisubr ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidiv ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidivr ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovb ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmove ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovbe ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovu ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;

        }
        else if (MyMODRM == 0xe9) {
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucompp ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __stdcall DB_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((uint8_t*)(puint_t) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Nasm;
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fild ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisttp ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fist ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fistp ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2tbyte;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg1tbyte;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovnb ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovne ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovnbe ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovnu ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xe0) {

            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fneni ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fndisi ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==2) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fnclex ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==3) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fninit ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fnsetpm ");
                #endif
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "frstpm ");
                #endif
            }
            else if (((MyMODRM & 0xf) >=0x8) && ((MyMODRM & 0xf) <=0xf)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucomi ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0x0) && ((MyMODRM & 0xf) <=0x7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomi ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
        else {
                FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __stdcall DC_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((uint8_t*)(puint_t) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Nasm;
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
                #endif
                (*pMyDisasm).Argument1.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom2 ");
                #endif

            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp3 ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
                #endif
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;

        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __stdcall DD_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((uint8_t*)(puint_t) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Nasm;
    if (MyMODRM <= 0xbf) {
        GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg1qword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisttp ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg1qword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fst ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg1qword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2multibytes;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "frstor ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 108*8;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg1multibytes;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsave ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 108*8;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstsw ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG;
            (*pMyDisasm).Argument2.ArgSize = 16;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ffree ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxch4 ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fst ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucom ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
                #endif
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument2.ArgSize = 80;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucomp ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }

        }

        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __stdcall DE_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((uint8_t*)(puint_t) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Nasm;
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fiadd ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fimul ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficom ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficomp ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisub ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisubr ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidiv ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidivr ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "faddp ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmulp ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp5 ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if (MyMODRM == 0xd9){
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcompp ");
                #endif
            }
            else {
                FailDecode(pMyDisasm);
            }


        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubrp ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubp ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivrp ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivp ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;

        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __stdcall DF_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((uint8_t*)(puint_t) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Nasm;
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fild ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisttp ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fist ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fistp ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2multibytes;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fbld ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fild ");
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg1multibytes;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fbstp ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg1qword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fistp ");
            #endif
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ffreep ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxch7 ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp8 ");
                #endif
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp9 ");
                #endif
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (MyMODRM == 0xe0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstsw ");
                #endif
            }
            else if ((MyMODRM & 0xf) >=8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucomip ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }


            else {
                FailDecode(pMyDisasm);
            }
        }

        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomip ");
                #endif
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
                #endif
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                #ifndef BEA_LIGHT_DISASSEMBLY
                   (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                #endif
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }

        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}
