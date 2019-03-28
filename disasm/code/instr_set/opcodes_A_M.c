void __stdcall FailDecode(PDISASM pMyDisasm)
{
	#ifndef BEA_LIGHT_DISASSEMBLY
   (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "??? ");
#endif
	GV.ERROR_OPCODE = 1;
}
/* ====================================================================
 *
 * ==================================================================== */
void __stdcall aaa_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aaa ");
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        GV.EIP_++;
    };
}

/* ====================================================================
 *
 * ==================================================================== */
void __stdcall aad_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aad ");
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (!Security(1, pMyDisasm)) return;
        GV.ImmediatSize = 8;
	if (*((uint8_t*)(puint_t) (GV.EIP_+1)) != 0x0A) {
            (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_+1));
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_+1)));
            #endif
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        GV.EIP_+=2;
    };
}

/* ====================================================================
 *
 * ==================================================================== */
void __stdcall aam_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aam ");
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (!Security(1, pMyDisasm)) return;
        GV.ImmediatSize = 8;
        if (*((uint8_t*)(puint_t) (GV.EIP_+1)) != 0x0A) {
            (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_+1));
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_+1)));
            #endif
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        GV.EIP_+=2;
    };
}

/* =======================================
 *
 * ======================================= */
void __stdcall aas_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aas ");
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        GV.EIP_++;
    };
}

/* =======================================
 *      00h
 * ======================================= */
void __stdcall add_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    #endif
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      01h
 * ======================================= */
void __stdcall add_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      02h
 * ======================================= */
void __stdcall add_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    #endif
    GbEb(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      03h
 * ======================================= */
void __stdcall add_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      04h
 * ======================================= */
void __stdcall add_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    #endif
    ALIb(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      05h
 * ======================================= */
void __stdcall add_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    #endif
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      10h
 * ======================================= */
void __stdcall adc_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    #endif
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      11h
 * ======================================= */
void __stdcall adc_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      12h
 * ======================================= */
void __stdcall adc_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    #endif
    GbEb(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      13h
 * ======================================= */
void __stdcall adc_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      14h
 * ======================================= */
void __stdcall adc_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    #endif
    ALIb(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      15h
 * ======================================= */
void __stdcall adc_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    #endif
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      20h
 * ======================================= */
void __stdcall and_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    #endif
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      21h
 * ======================================= */
void __stdcall and_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      22h
 * ======================================= */
void __stdcall and_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    #endif
    GbEb(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      23h
 * ======================================= */
void __stdcall and_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      24h
 * ======================================= */
void __stdcall and_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    #endif
    ALIb(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      25h
 * ======================================= */
void __stdcall and_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    #endif
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *
 * ======================================= */
void __stdcall arpl_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsxd ");
        #endif
        GvEv(pMyDisasm);
        FillFlags(pMyDisasm,69);
    }
    else {
        (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "arpl ");
        #endif
        GV.OperandSize = 16;
        EvGv(pMyDisasm);
        GV.OperandSize = 32;
        FillFlags(pMyDisasm,7);
    }

}

/* =======================================
 *      62h
 * ======================================= */
void __stdcall bound_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bound ");
        #endif
        GvEv(pMyDisasm);
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm,8);
    }

}

/* =======================================
 *      0fc8h
 * ======================================= */
void __stdcall bswap_eax(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __stdcall bswap_ecx(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __stdcall bswap_edx(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __stdcall bswap_ebx(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __stdcall bswap_esp(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __stdcall bswap_ebp(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __stdcall bswap_esi(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __stdcall bswap_edi(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    #endif
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+8]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}

/* =======================================
 *      0fbch
 * ======================================= */
void __stdcall bsf_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bsf ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,9);
}

/* =======================================
 *      0fbdh
 * ======================================= */
void __stdcall bsr_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bsr ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,9);
}

/* =======================================
 *      0fbbh
 * ======================================= */
void __stdcall btc_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;

    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "btc ");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,11);
}

/* =======================================
 *      0fa3h
 * ======================================= */
void __stdcall bt_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bt ");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,11);
}

/* =======================================
 *      0fb3h
 * ======================================= */
void __stdcall btr_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "btr ");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,11);
}

/* =======================================
 *      0fabh
 * ======================================= */
void __stdcall bts_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bts ");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,11);
}

/* =======================================
 *      e8h
 * ======================================= */
void __stdcall call_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = CallType;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "call ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1))+5+GV.NB_PREFIX;
        CalculateRelativeAddress(&MyAddress,(int64_t) MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        if (MyAddress >= 0x80000000) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1))+3+GV.NB_PREFIX;
        CalculateRelativeAddress(&MyAddress,(int64_t) MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
    }
}

/* =======================================
 *
 * ======================================= */
void __stdcall callf_(PDISASM pMyDisasm)
{
    uint32_t MyNumber;
    uint64_t MyAddress;
    size_t i = 0;
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = CallType;
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "call far ");
        #endif
        if (GV.OperandSize ==32) {
            if (!Security(7, pMyDisasm)) return;
            MyNumber = *((uint16_t*)(puint_t) (GV.EIP_+5));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(int64_t) MyNumber);
            #endif
        }
        else {
            if (!Security(5, pMyDisasm)) return;
            MyNumber = *((uint16_t*)(puint_t) (GV.EIP_+3));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(int64_t) MyNumber);
            #endif
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic+i, " : ");
        #endif
        i+=3;
        MyAddress = MyNumber*16;
        MyNumber = *((uint32_t*)(puint_t) (GV.EIP_+1));
        if (GV.OperandSize == 16) {
            MyNumber = MyNumber & 0xffff;
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
           i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.8X",(int64_t) MyNumber);
        #endif
        if (GV.OperandSize == 32) {
            GV.EIP_+=7;
        }
        else {
            GV.EIP_+=5;
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        (*pMyDisasm).Instruction.AddrValue = MyAddress + MyNumber;
    }
}

/* =======================================
 *      99h
 * ======================================= */
void __stdcall cdq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG2;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cqo ");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else if (GV.OperandSize ==32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cdq ");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwd ");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 16;
    }
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __stdcall clts_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "clts ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+CR_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, 17);
    GV.EIP_++;
}


/* =======================================
 *      F5h
 * ======================================= */
void __stdcall cmc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmc ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, 18);
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovo_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovo ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovno_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovno ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovb ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovnb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnb ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmove_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmove ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovne_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovne ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovbe_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovbe ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovnbe_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnbe ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovs_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovs ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovns_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovns ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovp_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovp ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovnp_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnp ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovl_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovl ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovnl_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnl ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovle_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovle ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmovnle_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnle ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmpx_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpxchg ");
    #endif
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,22);
}

/* =======================================
 *
 * ======================================= */
void __stdcall cmpx_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpxchg ");
    #endif
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,22);
}

/* =======================================
 *      38h
 * ======================================= */
void __stdcall cmp_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    #endif
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      39h
 * ======================================= */
void __stdcall cmp_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    #endif
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3ah
 * ======================================= */
void __stdcall cmp_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    #endif
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3bh
 * ======================================= */
void __stdcall cmp_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    #endif
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3ch
 * ======================================= */
void __stdcall cmp_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    #endif
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3dh
 * ======================================= */
void __stdcall cmp_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    #endif
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      a6h
 * ======================================= */
void __stdcall cmpsb_(PDISASM pMyDisasm)
{

    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsb ");
    #endif
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    FillFlags(pMyDisasm,21);
    GV.EIP_++;
}

/* =======================================
 *      a7h
 * ======================================= */
void __stdcall cmps_(PDISASM pMyDisasm)
{
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    if (GV.Architecture == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsq ");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsd ");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsw ");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    FillFlags(pMyDisasm,21);
    GV.EIP_++;
}

/* =======================================
 *      98h
 * ======================================= */
void __stdcall cwde_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cdqe ");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwde ");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 32;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cbw ");
        #endif
        (*pMyDisasm).Argument1.ArgSize = 16;
    }
    GV.EIP_++;
}

/* =======================================
 *      f8h
 * ======================================= */
void __stdcall clc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "clc ");
    #endif
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, 14);
    GV.EIP_++;
}

/* =======================================
 *      f8h
 * ======================================= */
void __stdcall cld_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cld ");
    #endif
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, 15);
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __stdcall cli_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cli ");
    #endif
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, 16);
    GV.EIP_++;
}

/* =======================================
 *      0fa2h
 * ======================================= */
void __stdcall cpuid_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG1+REG2+REG3;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cpuid ");
    #endif
    (*pMyDisasm).Argument1.ArgSize = 32;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __stdcall daa_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "daa ");
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        FillFlags(pMyDisasm,28);
        GV.EIP_++;
    }

}

/* =======================================
 *
 * ======================================= */
void __stdcall das_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "das ");
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        FillFlags(pMyDisasm,29);
        GV.EIP_++;
    }

}

/* =======================================
 *      48h
 * ======================================= */
void __stdcall dec_eax(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      49h
 * ======================================= */
void __stdcall dec_ecx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4ah
 * ======================================= */
void __stdcall dec_edx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4bh
 * ======================================= */
void __stdcall dec_ebx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4ch
 * ======================================= */
void __stdcall dec_esp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4dh
 * ======================================= */
void __stdcall dec_ebp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4eh
 * ======================================= */
void __stdcall dec_esi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4fh
 * ======================================= */
void __stdcall dec_edi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      0c8h
 * ======================================= */
void __stdcall enter_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "enter ");
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber (pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic,"%.4X",(int64_t) *((uint16_t*)(puint_t) (GV.EIP_+1)));
    #endif
    (*pMyDisasm).Argument1.ArgSize = 16;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber (pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_+3)));
    #endif
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    GV.EIP_+=4;
}

/* =======================================
 *
 * ======================================= */
void __stdcall femms_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = AMD_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "femms ");
    #endif
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __stdcall hlt_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hlt ");
    #endif
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __stdcall invd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "invd ");
    #endif
    GV.EIP_++;
}

/* =======================================
 *      40h
 * ======================================= */
void __stdcall inc_eax(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      41h
 * ======================================= */
void __stdcall inc_ecx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      42h
 * ======================================= */
void __stdcall inc_edx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      43h
 * ======================================= */
void __stdcall inc_ebx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      44h
 * ======================================= */
void __stdcall inc_esp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;
    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      45h
 * ======================================= */
void __stdcall inc_ebp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      46h
 * ======================================= */
void __stdcall inc_esi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      47h
 * ======================================= */
void __stdcall inc_edi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
        (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        #endif
        if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7]);
            #endif
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}
/* =======================================
 *  0xcf
 * ======================================= */
void __stdcall iret_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    if (GV.OperandSize ==64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretq ");
        #endif
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretd ");
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretw ");
        #endif
    }
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __stdcall in_ALDX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers8Bits[0]);
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[2]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];
    (*pMyDisasm).Argument2.ArgSize = 16;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __stdcall in_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    #endif
    ALIb(pMyDisasm);
}

/* =======================================
 *      0xe5
 * ======================================= */
void __stdcall in_eAX_Ib(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_+1)));
    #endif
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_+=2;
}

/* =======================================
 *
 * ======================================= */
void __stdcall insb_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insb ");
    #endif
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgSize = 16;
    GV.EIP_++;
    FillFlags(pMyDisasm, 41);


}

/* =======================================
 *
 * ======================================= */
void __stdcall ins_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    if (GV.OperandSize >= 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insd ");
        #endif
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.EIP_++;
        FillFlags(pMyDisasm, 41);
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insw ");
        #endif
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.EIP_++;
        FillFlags(pMyDisasm, 41);
    }
}

/* =======================================
 *
 * ======================================= */
void __stdcall into_(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "into ");
        #endif
        GV.EIP_++;
        FillFlags(pMyDisasm, 43);
    }
}

/* =======================================
 *      0edh
 * ======================================= */
void __stdcall in_eAX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    #endif
    if (GV.OperandSize >=32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
        #endif
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[2]);
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
        #endif
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[2]);
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    GV.EIP_++;
}

/* =======================================
 *      0cdh
 * ======================================= */
void __stdcall int_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_+1)));
    #endif
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = 8;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, 42);
}

/* =======================================
 *      0f1h
 * ======================================= */
void __stdcall int1_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int1 ");
    #endif
    GV.EIP_++;
    FillFlags(pMyDisasm, 42);
}

/* =======================================
 *      0cch
 * ======================================= */
void __stdcall int3_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int3 ");
    #endif
    GV.EIP_++;
    FillFlags(pMyDisasm, 42);
}

/* =======================================
 *      69h
 * ======================================= */
void __stdcall imul_GvEvIv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul ");
    #endif
    if (GV.OperandSize >= 32) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        GV.ImmediatSize = 32;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+6;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint32_t*)(puint_t) (GV.EIP_- 4));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.8X",(int64_t) *((uint32_t*)(puint_t) (GV.EIP_- 4)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 32;

        FillFlags(pMyDisasm, 38);
    }
    else {
        GV.MemDecoration = Arg2word;
        GV.ImmediatSize = 16;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+4;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint16_t*)(puint_t) (GV.EIP_- 2));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.4X",(int64_t) *((uint16_t*)(puint_t) (GV.EIP_- 2)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 16;

        FillFlags(pMyDisasm, 38);
    }
}

/* =======================================
 *      6bh
 * ======================================= */
void __stdcall imul_GvEvIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul ");
    #endif
    if (GV.OperandSize >= 32) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

        FillFlags(pMyDisasm, 38);
    }
    else {
        GV.MemDecoration = Arg2word;
        GV.ImmediatSize = 8;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((uint8_t*)(puint_t) (GV.EIP_- 1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(int64_t) *((uint8_t*)(puint_t) (GV.EIP_- 1)));
        #endif
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;

        FillFlags(pMyDisasm, 38);
    }
}

/* =======================================
 *      0fafh
 * ======================================= */
void __stdcall imul_GvEv(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul ");
    #endif
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,38);
}

/* =======================================
 *      70h
 * ======================================= */
void __stdcall jo_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;

    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JO;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jo ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,116);
}

/* =======================================
 *      71h
 * ======================================= */
void __stdcall jno_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNO;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jno ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,116);
}

/* =======================================
 *      72h
 * ======================================= */
void __stdcall jc_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JC;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jc ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,117);
}

/* =======================================
 *      73h
 * ======================================= */
void __stdcall jnc_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNC;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnc ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,117);
}
/* =======================================
 *      74h
 * ======================================= */
void __stdcall je_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "je ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,118);
}

/* =======================================
 *      75h
 * ======================================= */
void __stdcall jne_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jne ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      76h
 * ======================================= */
void __stdcall jbe_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNA;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jbe ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,119);
}

/* =======================================
 *      77h
 * ======================================= */
void __stdcall jnbe_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JA;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnbe ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,119);
}

/* =======================================
 *      78h
 * ======================================= */
void __stdcall js_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "js ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,120);
}

/* =======================================
 *      79h
 * ======================================= */
void __stdcall jns_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNS;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jns ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,120);
}

/* =======================================
 *      7ah
 * ======================================= */
void __stdcall jp_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jp ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,121);
}

/* =======================================
 *      7bh
 * ======================================= */
void __stdcall jnp_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNP;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnp ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,121);
}

/* =======================================
 *      7ch
 * ======================================= */
void __stdcall jl_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jl ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,122);
}

/* =======================================
 *      7dh
 * ======================================= */
void __stdcall jnl_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNL;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnl ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,122);
}

/* =======================================
 *      7eh
 * ======================================= */
void __stdcall jle_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNG;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jle ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,115);
}

/* =======================================
 *      7fh
 * ======================================= */
void __stdcall jnle_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JG;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnle ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,115);
}


/* =======================================
 *      0f80h
 * ======================================= */
void __stdcall jo_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JO;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jo ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,116);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,116);
    }
}


/* =======================================
 *      0f81h
 * ======================================= */
void __stdcall jno_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNO;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jno ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,116);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,116);
    }
}

/* =======================================
 *      0f82h
 * ======================================= */
void __stdcall jc_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JC;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jc ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,117);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,117);
    }
}

/* =======================================
 *      0f83h
 * ======================================= */
void __stdcall jnc_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNC;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnc ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,117);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,117);
    }
}

/* =======================================
 *      0f84h
 * ======================================= */
void __stdcall je_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JE;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "je ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,118);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f85h
 * ======================================= */
void __stdcall jne_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNE;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jne ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}
/* =======================================
 *      0f86h
 * ======================================= */
void __stdcall jbe_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNA;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jbe ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}


/* =======================================
 *      0f87h
 * ======================================= */
void __stdcall ja_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JA;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ja ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,119);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,119);
    }
}

/* =======================================
 *      0f88h
 * ======================================= */
void __stdcall js_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JS;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "js ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,120);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f89h
 * ======================================= */
void __stdcall jns_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNS;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jns ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,120);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f8ah
 * ======================================= */
void __stdcall jp_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JP;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jp ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,121);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f8bh
 * ======================================= */
void __stdcall jnp_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNP;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnp ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,121);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,121);
    }
}

/* =======================================
 *      0f8ch
 * ======================================= */
void __stdcall jl_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JL;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jl ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,122);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,122);
    }
}

/* =======================================
 *      0f8dh
 * ======================================= */
void __stdcall jnl_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNL;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnl ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,122);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,122);
    }
}

/* =======================================
 *      0f8eh
 * ======================================= */
void __stdcall jle_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    int32_t MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNG;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jng ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,115);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,115);
    }
}

/* =======================================
 *      0f8fh
 * ======================================= */
void __stdcall jnle_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    int64_t MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JG;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jg ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,115);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,115);
    }
}

/* =======================================
 *      0e3h
 * ======================================= */
void __stdcall jecxz_(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    int64_t MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JECXZ;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    if (GV.AddressSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jrcxz ");
        #endif
    }
    else if (GV.AddressSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jecxz ");
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jcxz ");
        #endif
    }
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0e9h
 * ======================================= */
void __stdcall jmp_near(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp ");
    #endif
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((int32_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+5+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;

        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,51);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((int16_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+3+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,51);
    }
}


/* =======================================
 *      0ebh
 * ======================================= */
void __stdcall jmp_short(PDISASM pMyDisasm)
{
    uint64_t MyAddress = 0;
    signed long MyNumber = 0;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
        #endif
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}


/* =======================================
 *
 * ======================================= */
void __stdcall jmp_far(PDISASM pMyDisasm)
{
    uint32_t MyNumber;
    uint64_t MyAddress;
    size_t i = 0;
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = JmpType;
        (*pMyDisasm).Argument1.AccessMode = READ;
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp far ");
        #endif
        if (GV.OperandSize ==32) {
            if (!Security(7, pMyDisasm)) return;
            MyNumber = *((uint16_t*)(puint_t) (GV.EIP_+5));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(int64_t) MyNumber);
            #endif
        }
        else {
            if (!Security(5, pMyDisasm)) return;
            MyNumber = *((uint16_t*)(puint_t) (GV.EIP_+3));
            #ifndef BEA_LIGHT_DISASSEMBLY
               i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(int64_t) MyNumber);
            #endif
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic+i, " : ");
        #endif
        i+=3;
        MyAddress = MyNumber*16;
        MyNumber = *((uint32_t*)(puint_t) (GV.EIP_+1));
        if (GV.OperandSize == 16) {
            MyNumber = MyNumber & 0xffff;
        }
        #ifndef BEA_LIGHT_DISASSEMBLY
           i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.8X",(int64_t) MyNumber);
        #endif
        if (GV.OperandSize == 32) {
            GV.EIP_+=7;
        }
        else {
            GV.EIP_+=5;
        }
        (*pMyDisasm).Instruction.AddrValue = MyAddress + MyNumber;
        FillFlags(pMyDisasm,51);
    }
}

/* =======================================
 *
 * ======================================= */
void __stdcall lahf_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lahf ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __stdcall lar_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lar ");
    #endif
    GvEw(pMyDisasm);
    FillFlags(pMyDisasm, 53);
}

/* =======================================
 *
 * ======================================= */
void __stdcall lds_GvM(PDISASM pMyDisasm)
{
    /* if MOD == 11b, invalid instruction */
    /* or VEX Prefix - implemented in next release (AVX) */

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lds ");
        #endif
        if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2fword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}

/* =======================================
 *      0c9h
 * ======================================= */
void __stdcall leave_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "leave ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+SPECIAL_REG+REG5;
    (*pMyDisasm).Argument2.ArgSize = 32;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __stdcall lea_GvM(PDISASM pMyDisasm)
{

    /* if MOD == 11b, invalid instruction */
    /* or VEX Prefix - implemented in next release (AVX) */

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lea ");
    #endif
    if (GV.OperandSize >= 32) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        GV.MemDecoration = Arg2word;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    (*pMyDisasm).Argument2.AccessMode = 0;
}

/* =======================================
 *
 * ======================================= */
void __stdcall les_GvM(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "les ");
        #endif
        if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2fword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}

/* =======================================
 *      0ach
 * ======================================= */
void __stdcall lodsb_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsb ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
    GV.EIP_++;
    FillFlags(pMyDisasm, 59);
}

/* =======================================
 *      0adh
 * ======================================= */
void __stdcall lodsw_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsq ");
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, 59);
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsd ");
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, 59);
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsw ");
        #endif
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, 59);
    }
}

/* =======================================
 *      0e2h
 * ======================================= */
void __stdcall loop_(PDISASM pMyDisasm)
{
    signed long MyNumber;
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loop ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
        MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 60);
    }
    else {
        MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 60);
    }
}

/* =======================================
 *      0xe0
 * ======================================= */
void __stdcall loopne_(PDISASM pMyDisasm)
{
    signed long MyNumber;
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loopne ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
        MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 61);
    }
    else {
        MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 61);

    }
}

/* =======================================
 *      0xe1
 * ======================================= */
void __stdcall loope_(PDISASM pMyDisasm)
{
    signed long MyNumber;
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JE;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loope ");
    #endif
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
        MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
            #endif
        }
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 61);
    }
    else {
        MyNumber = *((int8_t*)(puint_t) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(int64_t) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 61);

    }
}

/* =======================================
 *
 * ======================================= */
void __stdcall lsl_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lsl ");
    #endif
    GvEw(pMyDisasm);
    FillFlags(pMyDisasm, 62);
}

/* =======================================
 *
 * ======================================= */
void __stdcall lss_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lss ");
    #endif
    GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __stdcall lfs_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lfs ");
    #endif
    GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __stdcall lgs_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lgs ");
    #endif
    GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __stdcall mov_RdCd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    if (GV.MOD_== 3) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        #endif
        GV.CR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.CR_ = 0;
        FillFlags(pMyDisasm,67);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* =======================================
 *
 * ======================================= */
void __stdcall mov_RdDd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    if (GV.MOD_== 3) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        #endif
        GV.DR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.DR_ = 0;
        FillFlags(pMyDisasm,67);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *
 * ======================================= */
void __stdcall mov_CdRd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    if (GV.MOD_== 3) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        #endif
        GV.CR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.CR_ = 0;
        FillFlags(pMyDisasm,67);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *
 * ======================================= */
void __stdcall mov_DdRd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    if (GV.MOD_== 3) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        #endif
        GV.DR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.DR_ = 0;
        FillFlags(pMyDisasm,67);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      88h
 * ======================================= */
void __stdcall mov_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    EbGb(pMyDisasm);
}

/* =======================================
 *      89h
 * ======================================= */
void __stdcall mov_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    EvGv(pMyDisasm);
}

/* =======================================
 *      8ah
 * ======================================= */
void __stdcall mov_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GbEb(pMyDisasm);
}

/* =======================================
 *      8bh
 * ======================================= */
void __stdcall mov_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GvEv(pMyDisasm);
}

/* =======================================
 *      0a0h
 * ======================================= */
void __stdcall mov_ALOb(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GV.MemDecoration = Arg2byte;
    GV.RM_ = 5;
    GV.MOD_= 0;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE ;
    (*pMyDisasm).Argument2.ArgSize = 8;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Argument2.Memory.Displacement = (int64_t)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Argument2.Memory.Displacement = (int64_t)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Argument2.Memory.Displacement = (int64_t)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers8Bits[0]);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers8Bits[0+8]);
        #endif
    }

}

/* =======================================
 *      0a1h
 * ======================================= */
void __stdcall mov_eAXOv(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GV.RM_ = 5;
    GV.MOD_= 0;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Argument2.Memory.Displacement = (int64_t)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Argument2.Memory.Displacement = (int64_t)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Argument2.Memory.Displacement = (int64_t)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            #endif
        }
        else {
            GV.MemDecoration = Arg2word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0+8]);
            #endif
        }
        else {
            GV.MemDecoration = Arg2word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0+8]);
            #endif
        }
    }
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE ;
    if (GV.MemDecoration == 104) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.MemDecoration == 103) {
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else if (GV.MemDecoration == 102) {
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

}

/* =======================================
 *      0a2h
 * ======================================= */
void __stdcall mov_ObAL(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GV.MemDecoration = Arg1byte;
    GV.RM_ = 5;
    GV.MOD_= 0;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE ;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgSize = 8;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Argument1.Memory.Displacement = (int64_t)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Argument1.Memory.Displacement = (int64_t)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Argument1.Memory.Displacement = (int64_t)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers8Bits[0]);
        #endif
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers8Bits[0+8]);
        #endif
    }

}

/* =======================================
 *      0a3h
 * ======================================= */
void __stdcall mov_OveAX(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GV.RM_ = 5;
    GV.MOD_= 0;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Argument1.Memory.Displacement = (int64_t)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Argument1.Memory.Displacement = (int64_t)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Argument1.Memory.Displacement = (int64_t)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers64Bits[0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers32Bits[0]);
            #endif
        }
        else {
            GV.MemDecoration = Arg1word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers64Bits[0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers32Bits[0+8]);
            #endif
        }
        else {
            GV.MemDecoration = Arg1word;
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[0+8]);
            #endif
        }
    }

    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE ;
    if (GV.MemDecoration == Arg1qword) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.MemDecoration == Arg1dword) {
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else if (GV.MemDecoration == Arg1word) {
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
}

/* =======================================
 *      0b0h
 * ======================================= */
void __stdcall mov_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    ALIb(pMyDisasm);
}

/* =======================================
 *      0b1h
 * ======================================= */
void __stdcall mov_CLIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((uint8_t*)(puint_t) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[1]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b2h
 * ======================================= */
void __stdcall mov_DLIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((uint8_t*)(puint_t) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[2]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b3h
 * ======================================= */
void __stdcall mov_BLIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((uint8_t*)(puint_t) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[3]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b4h
 * ======================================= */
void __stdcall mov_AHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((uint8_t*)(puint_t) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[4]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgPosition = HighPosition;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b5h
 * ======================================= */
void __stdcall mov_CHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((uint8_t*)(puint_t) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[5]);
    #endif
    (*pMyDisasm).Argument1.ArgPosition = HighPosition;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b6h
 * ======================================= */
void __stdcall mov_DHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((uint8_t*)(puint_t) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[6]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument1.ArgPosition = HighPosition;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b7h
 * ======================================= */
void __stdcall mov_BHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((uint8_t*)(puint_t) (GV.EIP_+1));
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(int64_t) MyNumber);
    #endif
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[7]);
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
	(*pMyDisasm).Argument1.ArgPosition = HighPosition;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}


/* =======================================
 *      0a4h
 * ======================================= */
void __stdcall movs_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsb ");
    #endif
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
    GV.EIP_++;
    FillFlags(pMyDisasm, 68);
}

/* =======================================
 *      0a5h
 * ======================================= */
void __stdcall movsw_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if (GV.OperandSize == 64) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsq ");
        #endif
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 68);
    }
    else if (GV.OperandSize == 32) {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsd ");
        #endif
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 68);
    }
    else {
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsw ");
        #endif
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 68);
    }
}

/* =======================================
 *      0fb6h
 * ======================================= */
void __stdcall movzx_GvEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movzx ");
    #endif
    GvEb(pMyDisasm);
}


/* =======================================
 *      0fbeh
 * ======================================= */
void __stdcall movsx_GvEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsx ");
    #endif
    GvEb(pMyDisasm);
}

/* =======================================
 *      0fbfh
 * ======================================= */
void __stdcall movsx_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsx ");
    #endif
    GvEw(pMyDisasm);
}

/* =======================================
 *      0fb7h
 * ======================================= */
void __stdcall movzx_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movzx ");
    #endif
    GvEw(pMyDisasm);
}

/* =======================================
 *      0b8h
 * ======================================= */
void __stdcall mov_EAX(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
        GV.EIP_+=9;
        (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0b9h
 * ======================================= */
void __stdcall mov_ECX(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
        #endif
        GV.EIP_+=9;
        (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0bah
 * ======================================= */
void __stdcall mov_EDX(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0bbh
 * ======================================= */
void __stdcall mov_EBX(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0bch
 * ======================================= */
void __stdcall mov_ESP(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0bdh
 * ======================================= */
void __stdcall mov_EBP(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG5;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0beh
 * ======================================= */
void __stdcall mov_ESI(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG6;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+0+8]);
            #endif
        }
    }

}

/* =======================================
 *      0bfh
 * ======================================= */
void __stdcall mov_EDI(PDISASM pMyDisasm)
{
    uint64_t MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG7;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((uint64_t *)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.16llX",(int64_t) MyAddress);
       #endif
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((uint32_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (int64_t)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((uint16_t*)(puint_t) (GV.EIP_+1));
       #ifndef BEA_LIGHT_DISASSEMBLY
          (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(int64_t) MyAddress);
       #endif
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (int64_t) MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+0]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+0]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+0]);
            #endif
        }
    }
    else {
        if (GV.OperandSize == 64) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+0+8]);
            #endif
        }
        else if (GV.OperandSize == 32) {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+0+8]);
            #endif
        }
        else {
            #ifndef BEA_LIGHT_DISASSEMBLY
               (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+0+8]);
            #endif
        }
    }

}
/* =======================================
 *      0c6h-Group 11
 * ======================================= */
void __stdcall mov_EbIb(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        #endif
        EbIb(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      0c7h-Group 11
 * ======================================= */
void __stdcall mov_EvIv(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        #endif
        EvIv(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      08ch
 * ======================================= */
void __stdcall mov_EwSreg(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GV.MemDecoration = Arg1word;
    GV.OperandSize = 16;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.OperandSize = 32;
    GV.SEG_ = 1;
    Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.SEG_ = 0;
    GV.EIP_ += GV.DECALAGE_EIP+2;
}

/* =======================================
 *      08eh
 * ======================================= */
void __stdcall mov_SregEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    #ifndef BEA_LIGHT_DISASSEMBLY
       (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    #endif
    GV.MemDecoration = Arg2word;
    GV.OperandSize = 16;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.OperandSize = 32;
    GV.SEG_ = 1;
    Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.SEG_ = 0;
    GV.EIP_ += GV.DECALAGE_EIP+2;
}
