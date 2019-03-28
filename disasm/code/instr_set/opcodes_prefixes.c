/* ====================================================================
 *      Legacy Prefix F0h-Group 1
 * ==================================================================== */
void __stdcall PrefLock(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Prefix.LockPrefix = InvalidPrefix;
    GV.EIP_++;
    (*pMyDisasm).Prefix.Number++;
    GV.NB_PREFIX++;
    (*pMyDisasm).Instruction.Opcode =  *((uint8_t*) (puint_t)GV.EIP_);
    (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
    GV.OperandSize = 32;
}

/* ====================================================================
 *      Legacy Prefix F2h-Group 1
 * ==================================================================== */
void __stdcall PrefREPNE(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Prefix.RepnePrefix = SuperfluousPrefix;
    GV.EIP_++;
    (*pMyDisasm).Prefix.Number++;
    GV.NB_PREFIX++;
    GV.PrefRepne = 1;
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
    (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
    GV.PrefRepne = 0;
}

/* ====================================================================
 *      Legacy Prefix F3h-Group 1
 * ==================================================================== */
void __stdcall PrefREPE(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Prefix.RepPrefix = SuperfluousPrefix;
    GV.EIP_++;
    (*pMyDisasm).Prefix.Number++;
    GV.NB_PREFIX++;
    GV.PrefRepe = 1;
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
    (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
    GV.PrefRepe = 0;
}

/* ====================================================================
 *      Legacy Prefix 2Eh-Group 2
 * ==================================================================== */
void __stdcall PrefSEGCS(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Prefix.CSPrefix = InUsePrefix;
    GV.EIP_++;
    (*pMyDisasm).Prefix.Number++;
    GV.NB_PREFIX++;
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
    (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 3Eh-Group 2
 * ==================================================================== */
void __stdcall PrefSEGDS(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Prefix.DSPrefix = InUsePrefix;
    GV.EIP_++;
    (*pMyDisasm).Prefix.Number++;
    GV.NB_PREFIX++;
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
    (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 26h-Group 2
 * ==================================================================== */
void __stdcall PrefSEGES(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Prefix.ESPrefix = InUsePrefix;
    GV.EIP_++;
    (*pMyDisasm).Prefix.Number++;
    GV.NB_PREFIX++;
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
    (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 64h-Group 2
 * ==================================================================== */
void __stdcall PrefSEGFS(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Prefix.FSPrefix = InUsePrefix;
    GV.EIP_++;
    (*pMyDisasm).Prefix.Number++;
    GV.NB_PREFIX++;
    GV.SEGMENTFS = 1;
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
    (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 65h-Group 2
 * ==================================================================== */
void __stdcall PrefSEGGS(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Prefix.GSPrefix = InUsePrefix;
    GV.EIP_++;
    (*pMyDisasm).Prefix.Number++;
    GV.NB_PREFIX++;
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
    (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
}


/* ====================================================================
 *      Legacy Prefix 36h-Group 2
 * ==================================================================== */
void __stdcall PrefSEGSS(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Prefix.SSPrefix = InUsePrefix;
    GV.EIP_++;
    (*pMyDisasm).Prefix.Number++;
    GV.NB_PREFIX++;
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
    (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Legacy Prefix 66h-Group 3
 * ==================================================================== */
void __stdcall PrefOpSize(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Prefix.OperandSize = InUsePrefix;
    GV.EIP_++;
    (*pMyDisasm).Prefix.Number++;
    GV.NB_PREFIX++;
    GV.OriginalOperandSize = GV.OperandSize;  /* if GV.OperandSize is used as a mandatory prefix, keep the real operandsize value */
    if (GV.Architecture == 16) {
        GV.OperandSize = 32;
    }
    else {
        if (GV.OperandSize != 64) {
            GV.OperandSize = 16;
        }
    }
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
    (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
    if (GV.Architecture == 16) {
        GV.OperandSize = 16;
    }
    else {
        GV.OperandSize = 32;
    }
}

/* ====================================================================
 *      Legacy Prefix 67h-Group 4
 * ==================================================================== */
void __stdcall PrefAdSize(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Prefix.AddressSize = InUsePrefix;
    GV.EIP_++;
    (*pMyDisasm).Prefix.Number++;
    GV.NB_PREFIX++;
    if (GV.Architecture == 16) {
        GV.AddressSize = GV.AddressSize << 1;
    }
    else {
        GV.AddressSize = GV.AddressSize >> 1;
    }    

    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_);
    (void) opcode_map1[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
    if (GV.Architecture == 16) {
        GV.AddressSize = GV.AddressSize >> 1;
    }
    else {
        GV.AddressSize = GV.AddressSize << 1;
    } 

}

/* ====================================================================
 *      Escape Prefix 0Fh-two bytes opcodes
 * ==================================================================== */
void __stdcall Esc_2byte(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    GV.EIP_++;
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_)+0x0F00;
    (void) opcode_map2[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
}

/* ====================================================================
 *      Escape Prefix 0F38h-three bytes opcodes
 * ==================================================================== */
void __stdcall Esc_tableA4(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    GV.EIP_++;
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_)+0x0F3800;
    (void) opcode_map3[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
}
/* ====================================================================
 *      Escape Prefix 0F3Ah-three bytes opcodes
 * ==================================================================== */
void __stdcall Esc_tableA5(PDISASM pMyDisasm)
{
    if (!Security(0, pMyDisasm)) return;
    GV.EIP_++;
    (*pMyDisasm).Instruction.Opcode = *((uint8_t*) (puint_t)GV.EIP_)+0x0F3A00;
    (void) opcode_map4[*((uint8_t*) (puint_t)GV.EIP_)](pMyDisasm);
}
