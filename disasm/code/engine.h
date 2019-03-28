#ifndef _BEA_ENGINE_
#define _BEA_ENGINE_


# define BEA_UNUSED_ARG(a) (a)
# define BEA_NOTREACHED(a)

	/*  Set up for C function definitions, even when using C++ */

#ifdef __cplusplus
#define CPP_VISIBLE_BEGIN extern "C" {
#define CPP_VISIBLE_END }
#else
#define CPP_VISIBLE_BEGIN
#define CPP_VISIBLE_END
#endif

#if defined(_MSC_VER)
#pragma warning( disable: 4251 )
#endif

#define BEA_EXPECT_CONDITIONAL(c)    (c)
#define BEA_UNEXPECT_CONDITIONAL(c)  (c)

#define __inline__	__inline


#include "..\..\..\0lib\code\platform.h"
#include "..\..\..\0lib\code\types.h"

#define INSTRUCT_LENGTH 64

#pragma pack(1)
typedef struct {
   uint8_t W_;
   uint8_t R_;
   uint8_t X_;
   uint8_t B_;
   uint8_t state;
} REX_Struct  ;
#pragma pack()

#pragma pack(1)
typedef struct {
   int Number;
   int NbUndefined;
   uint8_t LockPrefix;
   uint8_t OperandSize;
   uint8_t AddressSize;
   uint8_t RepnePrefix;
   uint8_t RepPrefix;
   uint8_t FSPrefix;
   uint8_t SSPrefix;
   uint8_t GSPrefix;
   uint8_t ESPrefix;
   uint8_t CSPrefix;
   uint8_t DSPrefix;
   uint8_t BranchTaken;
   uint8_t BranchNotTaken;
   REX_Struct REX;
   char alignment[2];
} PREFIXINFO  ;
#pragma pack()

#pragma pack(1)
typedef struct {
   uint8_t OF_;
   uint8_t SF_;
   uint8_t ZF_;
   uint8_t AF_;
   uint8_t PF_;
   uint8_t CF_;
   uint8_t TF_;
   uint8_t IF_;
   uint8_t DF_;
   uint8_t NT_;
   uint8_t RF_;
   uint8_t alignment;
} EFLStruct  ;
#pragma pack()

#pragma pack(4)
typedef struct {
   int32_t BaseRegister;
   int32_t IndexRegister;
   int32_t Scale;
   int64_t Displacement;
} MEMORYTYPE ;
#pragma pack()


#pragma pack(1)
typedef struct  {
   int32_t Category;
   int32_t Opcode;
   char Mnemonic[16];
   int32_t BranchType;
   EFLStruct Flags;
   uint64_t AddrValue;
   int64_t Immediat;
   uint32_t ImplicitModifiedRegs;
} INSTRTYPE;
#pragma pack()

#pragma pack(1)
typedef struct  {
   char ArgMnemonic[64];
   int32_t ArgType;
   int32_t ArgSize;
   int32_t ArgPosition;
   uint32_t AccessMode;
   MEMORYTYPE Memory;
   uint32_t SegmentReg;
} ARGTYPE;
#pragma pack()

/* reserved structure used for thread-safety */
/* unusable by customer */
#pragma pack(1)
typedef struct {
   puint_t EIP_;
   uint64_t EIP_VA;
   puint_t EIP_REAL;
   int32_t OriginalOperandSize;
   int32_t OperandSize;
   int32_t MemDecoration;
   int32_t AddressSize;
   int32_t MOD_;
   int32_t RM_;
   int32_t INDEX_;
   int32_t SCALE_;
   int32_t BASE_;
   int32_t MMX_;
   int32_t SSE_;
   int32_t CR_;
   int32_t DR_;
   int32_t SEG_;
   int32_t REGOPCODE;
   uint32_t DECALAGE_EIP;
   int32_t FORMATNUMBER;
   int32_t SYNTAX_;
   uint64_t EndOfBlock;
   int32_t RelativeAddress;
   uint32_t Architecture;
   int32_t ImmediatSize;
   int32_t NB_PREFIX;
   int32_t PrefRepe;
   int32_t PrefRepne;
   uint32_t SEGMENTREGS;
   uint32_t SEGMENTFS;
   int32_t third_arg;
   int32_t TAB_;
   int32_t ERROR_OPCODE;
   REX_Struct REX;
   int32_t OutOfBlock;
} InternalDatas;
#pragma pack()

/* ************** main structure ************ */
#pragma pack(1)
typedef struct _Disasm {
   puint_t EIP;
   uint64_t VirtualAddr;
   uint32_t SecurityBlock;
   char CompleteInstr[INSTRUCT_LENGTH];
   uint32_t Archi;
   uint64_t Options;
   INSTRTYPE Instruction;
   ARGTYPE Argument1;
   ARGTYPE Argument2;
   ARGTYPE Argument3;
   PREFIXINFO Prefix;
   InternalDatas Reserved_;
   int len;
} DISASM, *PDISASM, *LPDISASM;
#pragma pack()

#define ESReg 1
#define DSReg 2
#define FSReg 3
#define GSReg 4
#define CSReg 5
#define SSReg 6

#define InvalidPrefix 4
#define SuperfluousPrefix 2
#define NotUsedPrefix 0
#define MandatoryPrefix 8
#define InUsePrefix 1

#define LowPosition 0
#define HighPosition 1

enum INSTRUCTION_TYPE
{
  GENERAL_PURPOSE_INSTRUCTION   =    0x10000,
  FPU_INSTRUCTION               =    0x20000,
  MMX_INSTRUCTION               =    0x40000,
  SSE_INSTRUCTION               =    0x80000,
  SSE2_INSTRUCTION              =   0x100000,
  SSE3_INSTRUCTION              =   0x200000,
  SSSE3_INSTRUCTION             =   0x400000,
  SSE41_INSTRUCTION             =   0x800000,
  SSE42_INSTRUCTION             =  0x1000000,
  SYSTEM_INSTRUCTION            =  0x2000000,
  VM_INSTRUCTION                =  0x4000000,
  UNDOCUMENTED_INSTRUCTION      =  0x8000000,
  AMD_INSTRUCTION               = 0x10000000,
  ILLEGAL_INSTRUCTION           = 0x20000000,
  AES_INSTRUCTION               = 0x40000000,
  CLMUL_INSTRUCTION             = (int)0x80000000,


    DATA_TRANSFER = 0x1,
    ARITHMETIC_INSTRUCTION,
    LOGICAL_INSTRUCTION,
    SHIFT_ROTATE,
    BIT_UInt8,
    CONTROL_TRANSFER,
    STRING_INSTRUCTION,
    InOutINSTRUCTION,
    ENTER_LEAVE_INSTRUCTION,
    FLAG_CONTROL_INSTRUCTION,
    SEGMENT_REGISTER,
    MISCELLANEOUS_INSTRUCTION,
    COMPARISON_INSTRUCTION,
    LOGARITHMIC_INSTRUCTION,
    TRIGONOMETRIC_INSTRUCTION,
    UNSUPPORTED_INSTRUCTION,
    LOAD_CONSTANTS,
    FPUCONTROL,
    STATE_MANAGEMENT,
    CONVERSION_INSTRUCTION,
    SHUFFLE_UNPACK,
    PACKED_SINGLE_PRECISION,
    SIMD128bits,
    SIMD64bits,
    CACHEABILITY_CONTROL,
    FP_INTEGER_CONVERSION,
    SPECIALIZED_128bits,
    SIMD_FP_PACKED,
    SIMD_FP_HORIZONTAL ,
    AGENT_SYNCHRONISATION,
    PACKED_ALIGN_RIGHT  ,
    PACKED_SIGN,
    PACKED_BLENDING_INSTRUCTION,
    PACKED_TEST,
    PACKED_MINMAX,
    HORIZONTAL_SEARCH,
    PACKED_EQUALITY,
    STREAMING_LOAD,
    INSERTION_EXTRACTION,
    DOT_PRODUCT,
    SAD_INSTRUCTION,
    ACCELERATOR_INSTRUCTION,    /* crc32, popcnt (sse4.2) */
    ROUND_INSTRUCTION

};

enum EFLAGS_STATES
{
  TE_ = 1,
  MO_ = 2,
  RE_ = 4,
  SE_ = 8,
  UN_ = 0x10,
  PR_ = 0x20
};

enum BRANCH_TYPE
{
  JO = 1,
  JC = 2,
  JE = 3,
  JA = 4,
  JS = 5,
  JP = 6,
  JL = 7,
  JG = 8,
  JB = 2,       // JC == JB
  JECXZ = 10,
  JmpType = 11,
  CallType = 12,
  RetType = 13,
  JNO = -1,
  JNC = -2,
  JNE = -3,
  JNA = -4,
  JNS = -5,
  JNP = -6,
  JNL = -7,
  JNG = -8,
  JNB = -2      // JNC == JNB
};

enum ARGUMENTS_TYPE
{
  NO_ARGUMENT = 0x10000000,
  REGISTER_TYPE = 0x20000000,
  MEMORY_TYPE = 0x40000000,
  CONSTANT_TYPE = (int)0x80000000,

  MMX_REG = 0x10000,
  GENERAL_REG = 0x20000,
  FPU_REG = 0x40000,
  SSE_REG = 0x80000,
  CR_REG = 0x100000,
  DR_REG = 0x200000,
  SPECIAL_REG = 0x400000,
  MEMORY_MANAGEMENT_REG = 0x800000,
  SEGMENT_REG = 0x1000000,

  RELATIVE_ = 0x4000000,
  ABSOLUTE_ = 0x8000000,

  READ = 0x1,
  WRITE = 0x2,

  REG0 = 0x1,
  REG1 = 0x2,
  REG2 = 0x4,
  REG3 = 0x8,
  REG4 = 0x10,
  REG5 = 0x20,
  REG6 = 0x40,
  REG7 = 0x80,
  REG8 = 0x100,
  REG9 = 0x200,
  REG10 = 0x400,
  REG11 = 0x800,
  REG12 = 0x1000,
  REG13 = 0x2000,
  REG14 = 0x4000,
  REG15 = 0x8000
};

enum SPECIAL_INFO
{
  UNKNOWN_OPCODE = -1,
  OUT_OF_BLOCK = 0,

  /* === mask = 0xff */
  NoTabulation      = 0x00000000,
  Tabulation        = 0x00000001,

  /* === mask = 0xff0000 */
  PrefixedNumeral   = 0x00010000,
  SuffixedNumeral   = 0x00000000,

  /* === mask = 0xff000000 */
  ShowSegmentRegs   = 0x01000000
};


#ifdef __cplusplus
extern "C"
#endif
int __stdcall Disasm(LPDISASM pDisAsm);

#endif
