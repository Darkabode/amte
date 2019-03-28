/* ====================================================================
 *      0feh
 * ==================================================================== */
void __stdcall G4_Eb(PDISASM pMyDisasm)
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
        Eb(pMyDisasm);
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
        Eb(pMyDisasm);
        FillFlags(pMyDisasm, 30);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

