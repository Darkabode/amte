/* ====================================================================
 *      0fbah
 * ==================================================================== */
void __stdcall G8_EvIb(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((uint8_t*)(puint_t) (GV.EIP_+1))) >> 3) & 0x7;
    EvIb(pMyDisasm);
    if (GV.REGOPCODE == 4) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bt ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, 11);
    }
    else if (GV.REGOPCODE == 5) {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bts ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, 11);
    }
    else if (GV.REGOPCODE == 6) {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "btr ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, 11);
    }
    else if (GV.REGOPCODE == 7) {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
        #ifndef BEA_LIGHT_DISASSEMBLY
           (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "btc ");
        #endif
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, 11);
    }
    else {
        FailDecode(pMyDisasm);
    }
}
