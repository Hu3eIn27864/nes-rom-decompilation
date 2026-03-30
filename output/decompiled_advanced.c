/*
 * NES ROM - Decompiled from 6502 Assembly
 * Advanced decompilation with control flow analysis
 * Generated automatically from assembly analysis
 */

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/* ===== NES Hardware Memory Map ===== */

/* PPU Registers */
#define PPU_CTRL     0x2000
#define PPU_MASK     0x2001
#define PPU_STATUS   0x2002
#define OAM_ADDR     0x2003
#define OAM_DATA     0x2004
#define PPU_SCROLL   0x2005
#define PPU_ADDR     0x2006
#define PPU_DATA     0x2007

/* APU Registers */
#define SQ1_VOL      0x4000
#define SQ1_SWEEP    0x4001
#define SQ1_LO       0x4002
#define SQ1_HI       0x4003
#define SQ2_VOL      0x4004
#define SQ2_SWEEP    0x4005
#define SQ2_LO       0x4006
#define SQ2_HI       0x4007
#define TRI_LINEAR   0x4008
#define TRI_LO       0x400A
#define TRI_HI       0x400B
#define NOISE_VOL    0x400C
#define NOISE_LO     0x400E
#define NOISE_HI     0x400F
#define DPCM_FREQ    0x4010
#define DPCM_DAC     0x4011
#define DPCM_ADDR    0x4012
#define DPCM_LEN     0x4013
#define OAM_DMA      0x4014
#define APU_ENABLE   0x4015
#define APU_FCN      0x4017

/* Controller Registers */
#define JOY1         0x4016
#define JOY2         0x4017

/* RAM (from $0300) */
static u8 ram[0x0800];

/* ===== Type Definitions ===== */
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

/* 6502 CPU Registers */
typedef struct {
    u8 A;        /* Accumulator */
    u8 X;        /* X Register */
    u8 Y;        /* Y Register */
    u8 PC_HI;    /* Program Counter High */
    u8 PC_LO;    /* Program Counter Low */
    u8 SP;       /* Stack Pointer */
    u8 P;        /* Processor Status */
    u8 _padding;
} CPU6502;

/* ===== Function Implementations ===== */

/* Function at 0x000D */
void func_000D(void) {
    /* Size: 32885 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x00AE */
void func_00AE(void) {
    /* Size: 32724 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x00DC */
void func_00DC(void) {
    /* Size: 32678 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x015C */
void func_015C(void) {
    /* Size: 32550 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x0173 */
void func_0173(void) {
    /* Size: 32527 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x017C */
void func_017C(void) {
    /* Size: 32518 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x0304 */
void func_0304(void) {
    /* Size: 32126 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x03CC */
void func_03CC(void) {
    /* Size: 31926 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x041E */
void func_041E(void) {
    /* Size: 31844 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x0434 */
void func_0434(void) {
    /* Size: 31822 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x0543 */
void func_0543(void) {
    /* Size: 31551 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x06B3 */
void func_06B3(void) {
    /* Size: 31183 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x06E5 */
void func_06E5(void) {
    /* Size: 31133 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x0783 */
void func_0783(void) {
    /* Size: 30975 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x0787 */
void func_0787(void) {
    /* Size: 30971 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x07D7 */
void func_07D7(void) {
    /* Size: 30891 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x0810 */
void func_0810(void) {
    /* Size: 30834 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x0820 */
void func_0820(void) {
    /* Size: 30818 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x0B52 */
void func_0B52(void) {
    /* Size: 30000 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x0BC9 */
void func_0BC9(void) {
    /* Size: 29881 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x1076 */
void func_1076(void) {
    /* Size: 28684 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x1149 */
void func_1149(void) {
    /* Size: 28473 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x150F */
void func_150F(void) {
    /* Size: 27507 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x1524 */
void func_1524(void) {
    /* Size: 27486 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x1820 */
void func_1820(void) {
    /* Size: 26722 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x1B18 */
void func_1B18(void) {
    /* Size: 25962 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x1C1E */
void func_1C1E(void) {
    /* Size: 25700 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x1D04 */
void func_1D04(void) {
    /* Size: 25470 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x1E84 */
void func_1E84(void) {
    /* Size: 25086 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x2026 */
void func_2026(void) {
    /* Size: 24668 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x2087 */
void func_2087(void) {
    /* Size: 24571 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x2094 */
void func_2094(void) {
    /* Size: 24558 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x20B7 */
void func_20B7(void) {
    /* Size: 24523 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x20D6 */
void func_20D6(void) {
    /* Size: 24492 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x20D7 */
void func_20D7(void) {
    /* Size: 24491 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x20F4 */
void func_20F4(void) {
    /* Size: 24462 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x2221 */
void func_2221(void) {
    /* Size: 24161 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x2263 */
void func_2263(void) {
    /* Size: 24095 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x2284 */
void func_2284(void) {
    /* Size: 24062 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x2293 */
void func_2293(void) {
    /* Size: 24047 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x2377 */
void func_2377(void) {
    /* Size: 23819 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x240E */
void func_240E(void) {
    /* Size: 23668 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x2422 */
void func_2422(void) {
    /* Size: 23648 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x2622 */
void func_2622(void) {
    /* Size: 23136 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x290F */
void func_290F(void) {
    /* Size: 22387 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x2925 */
void func_2925(void) {
    /* Size: 22365 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x300F */
void func_300F(void) {
    /* Size: 20595 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x3030 */
void func_3030(void) {
    /* Size: 20562 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x344F */
void func_344F(void) {
    /* Size: 19507 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x4060 */
void func_4060(void) {
    /* Size: 16418 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x406E */
void func_406E(void) {
    /* Size: 16404 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x446E */
void func_446E(void) {
    /* Size: 15380 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x456E */
void func_456E(void) {
    /* Size: 15124 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x4F24 */
void func_4F24(void) {
    /* Size: 12638 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x50B0 */
void func_50B0(void) {
    /* Size: 12242 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x52FD */
void func_52FD(void) {
    /* Size: 11653 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x666E */
void func_666E(void) {
    /* Size: 6676 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x7012 */
void func_7012(void) {
    /* Size: 4208 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x70AD */
void func_70AD(void) {
    /* Size: 4053 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x7139 */
void func_7139(void) {
    /* Size: 3913 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x72F4 */
void func_72F4(void) {
    /* Size: 3470 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x73C7 */
void func_73C7(void) {
    /* Size: 3259 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x7B95 */
void func_7B95(void) {
    /* Size: 1261 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x8000 */
void func_8000(void) {
    /* Size: 130 bytes, 53 instructions */
    // $8000: SEI
    // $8001: CLD
    // $8002: LDA #$10
    // $8004: STA $2000
    // $8007: LDX #$FF
    // ... (48 more instructions)
}

/* Function at 0x8040 */
void func_8040(void) {
    /* Size: 66 bytes, 24 instructions */
    // $8041: LDA #$06
    // $8043: STA $2001
    // $8046: JSR $8220
    // $8049: JSR $8E19
    // $804C: INC $0774
    // ... (19 more instructions)
}

/* Function at 0x8182 */
void func_8182(void) {
    /* Size: 27 bytes, 12 instructions */
    // $8182: LDA $0770
    // $8185: CMP #$02
    // $8187: BEQ $0B
    // $8189: CMP #$01
    // $818B: BNE $38
    // ... (7 more instructions)
}

/* Function at 0x81C6 */
void func_81C6(void) {
    /* Size: 76 bytes, 38 instructions */
    // $81C6: LDY $074E
    // $81C9: LDA #$28
    // $81CB: STA $00
    // $81CD: LDX #$0E
    // $81CF: LDA $06E4,X
    // ... (33 more instructions)
}

/* Function at 0x8212 */
void func_8212(void) {
    /* Size: 31 bytes, 15 instructions */
    // $8212: LDA $0770
    // $8215: JSR $8E04
    // $8218: AND ($82),Y
    // $821B: LDX $838B
    // $821E: CLC
    // ... (10 more instructions)
}

/* Function at 0x8220 */
void func_8220(void) {
    /* Size: 17 bytes, 10 instructions */
    // $8220: LDY #$00
    // $8222: BIT $04A0
    // $8225: LDA #$F8
    // $8227: STA $0200,Y
    // $822A: INY
    // ... (5 more instructions)
}

/* Function at 0x8223 */
void func_8223(void) {
    /* Size: 14 bytes, 8 instructions */
    // $8225: LDA #$F8
    // $8227: STA $0200,Y
    // $822A: INY
    // $822B: INY
    // $822C: INY
    // ... (3 more instructions)
}

/* Function at 0x830E */
void func_830E(void) {
    /* Size: 15 bytes, 6 instructions */
    // $830E: STA $075F
    // $8311: STA $0766
    // $8314: LDX #$00
    // $8316: STX $0760
    // $8319: STX $0767
    // ... (1 more instructions)
}

/* Function at 0x8325 */
void func_8325(void) {
    /* Size: 27 bytes, 12 instructions */
    // $8325: LDY #$07
    // $8327: LDA $831D,Y
    // $832A: STA $0300,Y
    // $832D: DEY
    // $832E: BPL $F7
    // ... (7 more instructions)
}

/* Function at 0x836B */
void func_836B(void) {
    /* Size: 32 bytes, 14 instructions */
    // $836B: LDX $0717
    // $836E: LDA $0718
    // $8371: BNE $0D
    // $8373: INX
    // $8374: INC $0717
    // ... (9 more instructions)
}

/* Function at 0x838A */
void func_838A(void) {
    /* Size: 1 bytes, 1 instructions */
    // $838A: RTS
}

/* Function at 0x83A0 */
void func_83A0(void) {
    /* Size: 86 bytes, 40 instructions */
    // $83A0: LDA $0772
    // $83A3: JSR $8E04
    // $83A6: LDY $CF,X
    // $83A8: BCS $83
    // $83AA: LDA $F683,X
    // ... (35 more instructions)
}

/* Function at 0x8407 */
void func_8407(void) {
    /* Size: 90 bytes, 44 instructions */
    // $8407: CPY #$07
    // $8409: BNE $09
    // $840B: CMP #$03
    // $840D: BCC $34
    // $840F: SBC #$01
    // ... (39 more instructions)
}

/* Function at 0x84C3 */
void func_84C3(void) {
    /* Size: 24 bytes, 11 instructions */
    // $84C3: LDA $0110,X
    // $84C6: BEQ $BE
    // $84C8: CMP #$0B
    // $84CA: BCC $05
    // $84CC: LDA #$0B
    // ... (6 more instructions)
}

/* Function at 0x85F1 */
void func_85F1(void) {
    /* Size: 82 bytes, 36 instructions */
    // $85F1: LDX $0300
    // $85F4: LDY #$00
    // $85F6: LDA $0753
    // $85F9: BEQ $02
    // $85FB: LDY #$04
    // ... (31 more instructions)
}

/* Function at 0x8649 */
void func_8649(void) {
    /* Size: 138 bytes, 57 instructions */
    // $864A: LDA #$0B
    // $864C: STA $0773
    // $864F: JMP $8745
    // $8652: LDA #$00
    // $8654: JSR $8808
    // ... (52 more instructions)
}

/* Function at 0x8808 */
void func_8808(void) {
    /* Size: 87 bytes, 42 instructions */
    // $880A: TAY
    // $880B: CPY #$04
    // $880D: BCC $0C
    // $880F: CPY #$08
    // $8811: BCC $02
    // ... (37 more instructions)
}

/* Function at 0x88A5 */
void func_88A5(void) {
    /* Size: 9 bytes, 4 instructions */
    // $88A5: LDA #$07
    // $88A7: STA $07A0
    // $88AA: INC $073C
    // $88AD: RTS
}

/* Function at 0x896A */
void func_896A(void) {
    /* Size: 89 bytes, 44 instructions */
    // $896A: LDA $0721
    // $896D: AND #$1F
    // $896F: SEC
    // $8970: SBC #$04
    // $8972: AND #$1F
    // ... (39 more instructions)
}

/* Function at 0x89E1 */
void func_89E1(void) {
    /* Size: 88 bytes, 41 instructions */
    // $89E1: LDA $09
    // $89E3: AND #$07
    // $89E5: BNE $51
    // $89E7: LDX $0300
    // $89EA: CPX #$31
    // ... (36 more instructions)
}

/* Function at 0x8A4D */
void func_8A4D(void) {
    /* Size: 20 bytes, 8 instructions */
    // $8A4E: EOR ($A9,X)
    // $8A51: LDX $074E
    // $8A54: BNE $02
    // $8A56: LDA #$04
    // $8A58: JSR $8A97
    // ... (3 more instructions)
}

/* Function at 0x8A61 */
void func_8A61(void) {
    /* Size: 10 bytes, 4 instructions */
    // $8A61: JSR $8A6D
    // $8A64: INC $03F0
    // $8A67: DEC $03EC,X
    // $8A6A: RTS
}

/* Function at 0x8A6B */
void func_8A6B(void) {
    /* Size: 157 bytes, 78 instructions */
    // $8A6B: LDA #$00
    // $8A6D: LDY #$03
    // $8A6F: CMP #$00
    // $8A71: BEQ $14
    // $8A73: LDY #$00
    // ... (73 more instructions)
}

/* Function at 0x8A6D */
void func_8A6D(void) {
    /* Size: 155 bytes, 77 instructions */
    // $8A6D: LDY #$03
    // $8A6F: CMP #$00
    // $8A71: BEQ $14
    // $8A73: LDY #$00
    // $8A75: CMP #$58
    // ... (72 more instructions)
}

/* Function at 0x8A8F */
void func_8A8F(void) {
    /* Size: 121 bytes, 59 instructions */
    // $8A8F: DEY
    // $8A90: TYA
    // $8A91: CLC
    // $8A92: ADC #$0A
    // $8A94: JMP $863F
    // ... (54 more instructions)
}

/* Function at 0x8A97 */
void func_8A97(void) {
    /* Size: 113 bytes, 54 instructions */
    // $8A97: STX $00
    // $8A99: STY $01
    // $8A9B: ASL
    // $8A9C: ASL
    // $8A9D: TAX
    // ... (49 more instructions)
}

/* Function at 0x8ACD */
void func_8ACD(void) {
    /* Size: 59 bytes, 23 instructions */
    // $8ACD: LDA $8A39,X
    // $8AD0: STA $0303,Y
    // $8AD3: LDA $8A3A,X
    // $8AD6: STA $0304,Y
    // $8AD9: LDA $8A3B,X
    // ... (18 more instructions)
}

/* Function at 0x8C46 */
void func_8C46(void) {
    /* Size: 1 bytes, 1 instructions */
    // $8C46: RTI
}

/* Function at 0x8C47 */
void func_8C47(void) {
    /* Size: 1 bytes, 1 instructions */
    // $8C47: RTI
}

/* Function at 0x8E04 */
void func_8E04(void) {
    /* Size: 137 bytes, 69 instructions */
    // $8E04: ASL
    // $8E05: TAY
    // $8E06: PLA
    // $8E07: STA $04
    // $8E09: PLA
    // ... (64 more instructions)
}

/* Function at 0x8E19 */
void func_8E19(void) {
    /* Size: 116 bytes, 56 instructions */
    // $8E19: LDA $2002
    // $8E1C: LDA $0778
    // $8E1F: ORA #$10
    // $8E21: AND #$F0
    // $8E23: JSR $8EED
    // ... (51 more instructions)
}

/* Function at 0x8E2D */
void func_8E2D(void) {
    /* Size: 96 bytes, 48 instructions */
    // $8E2D: STA $2006
    // $8E30: LDA #$00
    // $8E32: STA $2006
    // $8E35: LDX #$04
    // $8E37: LDY #$C0
    // ... (43 more instructions)
}

/* Function at 0x8E5C */
void func_8E5C(void) {
    /* Size: 49 bytes, 27 instructions */
    // $8E5C: LDA #$01
    // $8E5E: STA $4016
    // $8E61: LSR
    // $8E62: TAX
    // $8E63: STA $4016
    // ... (22 more instructions)
}

/* Function at 0x8E6A */
void func_8E6A(void) {
    /* Size: 35 bytes, 20 instructions */
    // $8E6A: LDY #$08
    // $8E6C: PHA
    // $8E6D: LDA $4016,X
    // $8E70: STA $00
    // $8E72: LSR
    // ... (15 more instructions)
}

/* Function at 0x8EDD */
void func_8EDD(void) {
    /* Size: 16 bytes, 7 instructions */
    // $8EDD: LDX $2002
    // $8EE0: LDY #$00
    // $8EE2: LDA ($00),Y
    // $8EE4: BNE $AC
    // $8EE6: STA $2005
    // ... (2 more instructions)
}

/* Function at 0x8EE6 */
void func_8EE6(void) {
    /* Size: 7 bytes, 3 instructions */
    // $8EE6: STA $2005
    // $8EE9: STA $2005
    // $8EEC: RTS
}

/* Function at 0x8EED */
void func_8EED(void) {
    /* Size: 7 bytes, 3 instructions */
    // $8EED: STA $2000
    // $8EF0: STA $0778
    // $8EF3: RTS
}

/* Function at 0x8F06 */
void func_8F06(void) {
    /* Size: 89 bytes, 47 instructions */
    // $8F07: BRK
    // $8F08: JSR $8F11
    // $8F0B: LDA $00
    // $8F0D: LSR
    // $8F0E: LSR
    // ... (42 more instructions)
}

/* Function at 0x8F11 */
void func_8F11(void) {
    /* Size: 78 bytes, 40 instructions */
    // $8F11: CLC
    // $8F12: ADC #$01
    // $8F14: AND #$0F
    // $8F16: CMP #$06
    // $8F18: BCS $44
    // ... (35 more instructions)
}

/* Function at 0x8F5F */
void func_8F5F(void) {
    /* Size: 40 bytes, 20 instructions */
    // $8F5F: LDA $0770
    // $8F62: CMP #$00
    // $8F64: BEQ $16
    // $8F66: LDX #$05
    // $8F68: LDA $0134,X
    // ... (15 more instructions)
}

/* Function at 0x8F97 */
void func_8F97(void) {
    /* Size: 37 bytes, 20 instructions */
    // $8F97: LDX #$05
    // $8F99: JSR $8F9E
    // $8F9C: LDX #$0B
    // $8F9E: LDY #$05
    // $8FA0: SEC
    // ... (15 more instructions)
}

/* Function at 0x8F9E */
void func_8F9E(void) {
    /* Size: 30 bytes, 17 instructions */
    // $8F9E: LDY #$05
    // $8FA0: SEC
    // $8FA1: LDA $07DD,X
    // $8FA4: SBC $07D7,Y
    // $8FA7: DEX
    // ... (12 more instructions)
}

/* Function at 0x90CC */
void func_90CC(void) {
    /* Size: 27 bytes, 15 instructions */
    // $90CC: LDX #$07
    // $90CE: LDA #$00
    // $90D0: STA $06
    // $90D2: STX $07
    // $90D4: CPX #$01
    // ... (10 more instructions)
}

/* Function at 0x90ED */
void func_90ED(void) {
    /* Size: 41 bytes, 18 instructions */
    // $90ED: LDA $0770
    // $90F0: BEQ $23
    // $90F2: LDA $0752
    // $90F5: CMP #$02
    // $90F7: BEQ $0D
    // ... (13 more instructions)
}

/* Function at 0x90FD */
void func_90FD(void) {
    /* Size: 25 bytes, 11 instructions */
    // $90FE: CMP #$06
    // $9100: BEQ $0E
    // $9102: CMP #$07
    // $9104: BEQ $0A
    // $9106: LDY $074E
    // ... (6 more instructions)
}

/* Function at 0x9248 */
void func_9248(void) {
    /* Size: 28 bytes, 12 instructions */
    // $9248: LDA #$80
    // $924A: STA $FC
    // $924C: JSR $9282
    // $924F: BCC $13
    // $9251: LDA $075F
    // ... (7 more instructions)
}

/* Function at 0x9282 */
void func_9282(void) {
    /* Size: 40 bytes, 19 instructions */
    // $9282: SEC
    // $9283: LDA $077A
    // $9286: BEQ $21
    // $9288: LDA $0761
    // $928B: BMI $1C
    // ... (14 more instructions)
}

/* Function at 0x92A9 */
void func_92A9(void) {
    /* Size: 1 bytes, 1 instructions */
    // $92A9: RTS
}

/* Function at 0x92AA */
void func_92AA(void) {
    /* Size: 6 bytes, 3 instructions */
    // $92AA: LDA #$FF
    // $92AC: STA $06C9
    // $92AF: RTS
}

/* Function at 0x92AF */
void func_92AF(void) {
    /* Size: 1 bytes, 1 instructions */
    // $92AF: RTS
}

/* Function at 0x92B0 */
void func_92B0(void) {
    /* Size: 24 bytes, 11 instructions */
    // $92B0: LDY $071F
    // $92B3: BNE $05
    // $92B5: LDY #$08
    // $92B7: STY $071F
    // $92BA: DEY
    // ... (6 more instructions)
}

/* Function at 0x92C8 */
void func_92C8(void) {
    /* Size: 47 bytes, 16 instructions */
    // $92C8: JSR $8E04
    // $92CD: LDX $AE88
    // $92D0: DEY
    // $92D5: LDX $AE88
    // $92D8: DEY
    // ... (11 more instructions)
}

/* Function at 0x9508 */
void func_9508(void) {
    /* Size: 129 bytes, 57 instructions */
    // $950A: STX $08
    // $950C: LDA #$00
    // $950E: STA $0729
    // $9511: LDY $072C
    // $9514: LDA ($E7),Y
    // ... (52 more instructions)
}

/* Function at 0x9589 */
void func_9589(void) {
    /* Size: 12 bytes, 5 instructions */
    // $9589: INC $072C
    // $958C: INC $072C
    // $958F: LDA #$00
    // $9591: STA $072B
    // $9594: RTS
}

/* Function at 0x9595 */
void func_9595(void) {
    /* Size: 161 bytes, 79 instructions */
    // $9595: LDA $0730,X
    // $9598: BMI $03
    // $959A: LDY $072D,X
    // $959D: LDX #$10
    // $959F: LDA ($E7),Y
    // ... (74 more instructions)
}

/* Function at 0x9716 */
void func_9716(void) {
    /* Size: 18 bytes, 10 instructions */
    // $9716: STA $00
    // $9718: LDA #$00
    // $971A: LDX #$04
    // $971C: LDY $16,X
    // $971E: CPY $00
    // ... (5 more instructions)
}

/* Function at 0x97FD */
void func_97FD(void) {
    /* Size: 108 bytes, 53 instructions */
    // $97FE: LSR
    // $9800: LSR
    // $9806: JSR $9BBD
    // $9809: STY $07
    // $980B: LDY #$04
    // ... (48 more instructions)
}

/* Function at 0x98B3 */
void func_98B3(void) {
    /* Size: 42 bytes, 20 instructions */
    // $98B3: DEY
    // $98B4: DEY
    // $98B5: STY $05
    // $98B7: LDY $0730,X
    // $98BA: STY $06
    // ... (15 more instructions)
}

/* Function at 0x9939 */
void func_9939(void) {
    /* Size: 17 bytes, 8 instructions */
    // $9939: LDY #$01
    // $993B: JSR $9BB1
    // $993E: JSR $9BBD
    // $9941: TYA
    // $9942: AND #$07
    // ... (3 more instructions)
}

/* Function at 0x994A */
void func_994A(void) {
    /* Size: 13 bytes, 8 instructions */
    // $994A: LDX #$00
    // $994C: CLC
    // $994D: LDA $0F,X
    // $994F: BEQ $05
    // $9951: INX
    // ... (3 more instructions)
}

/* Function at 0x9B38 */
void func_9B38(void) {
    /* Size: 7 bytes, 5 instructions */
    // $9B38: LDA $00
    // $9B3A: SEC
    // $9B3B: SBC #$00
    // $9B3D: TAY
    // $9B3E: RTS
}

/* Function at 0x9B3E */
void func_9B3E(void) {
    /* Size: 1 bytes, 1 instructions */
    // $9B3E: RTS
}

/* Function at 0x9B7F */
void func_9B7F(void) {
    /* Size: 47 bytes, 23 instructions */
    // $9B7F: STY $0735
    // $9B82: LDY $06A1,X
    // $9B85: BEQ $18
    // $9B87: CPY #$17
    // $9B89: BEQ $17
    // ... (18 more instructions)
}

/* Function at 0x9BAE */
void func_9BAE(void) {
    /* Size: 15 bytes, 8 instructions */
    // $9BAE: JSR $9BBD
    // $9BB1: LDA $0730,X
    // $9BB4: CLC
    // $9BB5: BPL $05
    // $9BB7: TYA
    // ... (3 more instructions)
}

/* Function at 0x9BB1 */
void func_9BB1(void) {
    /* Size: 12 bytes, 7 instructions */
    // $9BB1: LDA $0730,X
    // $9BB4: CLC
    // $9BB5: BPL $05
    // $9BB7: TYA
    // $9BB8: STA $0730,X
    // ... (2 more instructions)
}

/* Function at 0x9BBC */
void func_9BBC(void) {
    /* Size: 1 bytes, 1 instructions */
    // $9BBC: RTS
}

/* Function at 0x9BBD */
void func_9BBD(void) {
    /* Size: 16 bytes, 9 instructions */
    // $9BBD: LDY $072D,X
    // $9BC0: LDA ($E7),Y
    // $9BC2: AND #$0F
    // $9BC4: STA $07
    // $9BC6: INY
    // ... (4 more instructions)
}

/* Function at 0x9BCC */
void func_9BCC(void) {
    /* Size: 1 bytes, 1 instructions */
    // $9BCC: RTS
}

/* Function at 0x9BCD */
void func_9BCD(void) {
    /* Size: 8 bytes, 6 instructions */
    // $9BCD: LDA $0726
    // $9BD0: ASL
    // $9BD1: ASL
    // $9BD2: ASL
    // $9BD3: ASL
    // ... (1 more instructions)
}

/* Function at 0x9BD4 */
void func_9BD4(void) {
    /* Size: 1 bytes, 1 instructions */
    // $9BD4: RTS
}

/* Function at 0x9BD5 */
void func_9BD5(void) {
    /* Size: 10 bytes, 8 instructions */
    // $9BD5: LDA $07
    // $9BD7: ASL
    // $9BD8: ASL
    // $9BD9: ASL
    // $9BDA: ASL
    // ... (3 more instructions)
}

/* Function at 0x9BE3 */
void func_9BE3(void) {
    /* Size: 21 bytes, 13 instructions */
    // $9BE4: LSR
    // $9BE5: LSR
    // $9BE6: LSR
    // $9BE7: LSR
    // $9BE8: TAY
    // ... (8 more instructions)
}

/* Function at 0x9C03 */
void func_9C03(void) {
    /* Size: 16 bytes, 9 instructions */
    // $9C03: JSR $9C13
    // $9C06: STA $0750
    // $9C09: AND #$60
    // $9C0B: ASL
    // $9C0C: ROL
    // ... (4 more instructions)
}

/* Function at 0x9C09 */
void func_9C09(void) {
    /* Size: 10 bytes, 7 instructions */
    // $9C09: AND #$60
    // $9C0B: ASL
    // $9C0C: ROL
    // $9C0D: ROL
    // $9C0E: ROL
    // ... (2 more instructions)
}

/* Function at 0x9C13 */
void func_9C13(void) {
    /* Size: 15 bytes, 7 instructions */
    // $9C13: LDY $075F
    // $9C16: LDA $9CB4,Y
    // $9C19: CLC
    // $9C1A: ADC $0760
    // $9C1D: TAY
    // ... (2 more instructions)
}

/* Function at 0x9C22 */
void func_9C22(void) {
    /* Size: 146 bytes, 78 instructions */
    // $9C22: LDA $0750
    // $9C25: JSR $9C09
    // $9C28: TAY
    // $9C29: LDA $0750
    // $9C2C: AND #$1F
    // ... (73 more instructions)
}

/* Function at 0x9F3F */
void func_9F3F(void) {
    /* Size: 1 bytes, 1 instructions */
    // $9F3F: RTI
}

/* Function at 0xA4B8 */
void func_A4B8(void) {
    /* Size: 1 bytes, 1 instructions */
    // $A4B8: RTI
}

/* Function at 0xA5FF */
void func_A5FF(void) {
    /* Size: 213 bytes, 66 instructions */
    // $A604: CLD
    // $A607: LDA ($97),Y
    // $A60A: LDX $64,Y
    // $A60C: CMP $65
    // $A60F: ROR $E3
    // ... (61 more instructions)
}

/* Function at 0xAD10 */
void func_AD10(void) {
    /* Size: 155 bytes, 49 instructions */
    // $AD12: ROL $8802
    // $AD17: JSR $07D7
    // $AD1A: CPX $76
    // $AD1D: LDY #$17
    // $AD1F: ASL $48
    // ... (44 more instructions)
}

/* Function at 0xAD48 */
void func_AD48(void) {
    /* Size: 99 bytes, 34 instructions */
    // $AD48: AND $A871,Y
    // $AD4F: STA ($8F,X)
    // $AD52: LDX $FE00
    // $AD57: CMP ($17),Y
    // $AD5A: ROL $49
    // ... (29 more instructions)
}

/* Function at 0xAE37 */
void func_AE37(void) {
    /* Size: 1 bytes, 1 instructions */
    // $AE37: RTS
}

/* Function at 0xAEEA */
void func_AEEA(void) {
    /* Size: 20 bytes, 7 instructions */
    // $AEED: LDA $06FC,X
    // $AEF0: STA $06FC
    // $AEF3: JSR $B04A
    // $AEF6: LDA $0772
    // $AEF9: CMP #$03
    // ... (2 more instructions)
}

/* Function at 0xAF6F */
void func_AF6F(void) {
    /* Size: 36 bytes, 15 instructions */
    // $AF6F: LDA $0773
    // $AF72: CMP #$06
    // $AF74: BEQ $1C
    // $AF76: LDA $071F
    // $AF79: BNE $14
    // ... (10 more instructions)
}

/* Function at 0xAF93 */
void func_AF93(void) {
    /* Size: 161 bytes, 72 instructions */
    // $AF93: LDA $06FF
    // $AF96: CLC
    // $AF97: ADC $03A1
    // $AF9A: STA $06FF
    // $AF9D: LDA $0723
    // ... (67 more instructions)
}

/* Function at 0xAFC4 */
void func_AFC4(void) {
    /* Size: 112 bytes, 50 instructions */
    // $AFC4: TYA
    // $AFC5: STA $0775
    // $AFC8: CLC
    // $AFC9: ADC $073D
    // $AFCC: STA $073D
    // ... (45 more instructions)
}

/* Function at 0xB038 */
void func_B038(void) {
    /* Size: 18 bytes, 8 instructions */
    // $B038: LDA $071C
    // $B03B: CLC
    // $B03C: ADC #$FF
    // $B03E: STA $071D
    // $B041: LDA $071A
    // ... (3 more instructions)
}

/* Function at 0xB04A */
void func_B04A(void) {
    /* Size: 98 bytes, 41 instructions */
    // $B04A: LDA $0E
    // $B04C: JSR $8E04
    // $B04F: AND ($91),Y
    // $B052: LDA ($06),Y
    // $B055: SBC $B1
    // ... (36 more instructions)
}

/* Function at 0xB0E6 */
void func_B0E6(void) {
    /* Size: 213 bytes, 98 instructions */
    // $B0E6: STA $06FC
    // $B0E9: LDA $0E
    // $B0EB: CMP #$0B
    // $B0ED: BEQ $3C
    // $B0EF: LDA $074E
    // ... (93 more instructions)
}

/* Function at 0xB1DD */
void func_B1DD(void) {
    /* Size: 41 bytes, 19 instructions */
    // $B1DD: LDA #$02
    // $B1DF: STA $0752
    // $B1E2: JMP $B213
    // $B1E5: LDA #$01
    // $B1E7: JSR $B200
    // ... (14 more instructions)
}

/* Function at 0xB200 */
void func_B200(void) {
    /* Size: 6 bytes, 4 instructions */
    // $B200: CLC
    // $B201: ADC $CE
    // $B203: STA $CE
    // $B205: RTS
}

/* Function at 0xB213 */
void func_B213(void) {
    /* Size: 12 bytes, 5 instructions */
    // $B213: INC $0774
    // $B216: LDA #$00
    // $B218: STA $0772
    // $B21B: STA $0722
    // $B21E: RTS
}

/* Function at 0xB21F */
void func_B21F(void) {
    /* Size: 20 bytes, 11 instructions */
    // $B21F: LDA #$08
    // $B221: STA $57
    // $B223: LDY #$01
    // $B225: LDA $86
    // $B227: AND #$0F
    // ... (6 more instructions)
}

/* Function at 0xB273 */
void func_B273(void) {
    /* Size: 10 bytes, 5 instructions */
    // $B273: LDA #$00
    // $B275: STA $0747
    // $B278: LDA #$08
    // $B27A: STA $0E
    // $B27C: RTS
}

/* Function at 0xB288 */
void func_B288(void) {
    /* Size: 15 bytes, 7 instructions */
    // $B288: AND #$03
    // $B28A: STA $00
    // $B28C: LDA $03C4
    // $B28F: AND #$FC
    // $B291: ORA $00
    // ... (2 more instructions)
}

/* Function at 0xB29A */
void func_B29A(void) {
    /* Size: 9 bytes, 4 instructions */
    // $B29A: LDA $03C4
    // $B29D: AND #$FC
    // $B29F: STA $03C4
    // $B2A2: RTS
}

/* Function at 0xB2A3 */
void func_B2A3(void) {
    /* Size: 1 bytes, 1 instructions */
    // $B2A3: RTS
}

/* Function at 0xB329 */
void func_B329(void) {
    /* Size: 49 bytes, 20 instructions */
    // $B329: LDA #$00
    // $B32B: LDY $0754
    // $B32E: BNE $08
    // $B330: LDA $1D
    // $B332: BNE $07
    // ... (15 more instructions)
}

/* Function at 0xB450 */
void func_B450(void) {
    /* Size: 41 bytes, 19 instructions */
    // $B451: ORA $03C9,X
    // $B454: BNE $23
    // $B456: LDY #$00
    // $B458: LDA $0B
    // $B45A: AND $0490
    // ... (14 more instructions)
}

/* Function at 0xB537 */
void func_B537(void) {
    /* Size: 85 bytes, 36 instructions */
    // $B538: BNE $0B
    // $B53A: LDA $0A
    // $B53C: AND #$40
    // $B53E: BNE $19
    // $B540: LDA $0783
    // ... (31 more instructions)
}

/* Function at 0xB58F */
void func_B58F(void) {
    /* Size: 61 bytes, 28 instructions */
    // $B590: BRK
    // $B591: LDA $0700
    // $B594: CMP #$20
    // $B596: BCS $15
    // $B598: INY
    // ... (23 more instructions)
}

/* Function at 0xB5CC */
void func_B5CC(void) {
    /* Size: 88 bytes, 39 instructions */
    // $B5CC: AND $0490
    // $B5CF: CMP #$00
    // $B5D1: BNE $08
    // $B5D3: LDA $57
    // $B5D5: BEQ $49
    // ... (34 more instructions)
}

/* Function at 0xB624 */
void func_B624(void) {
    /* Size: 99 bytes, 45 instructions */
    // $B624: LDA $0756
    // $B627: CMP #$02
    // $B629: BCC $43
    // $B62B: LDA $0A
    // $B62D: AND #$40
    // ... (40 more instructions)
}

/* Function at 0xB689 */
void func_B689(void) {
    /* Size: 106 bytes, 51 instructions */
    // $B68A: PHP
    // $B68B: LDA $24,X
    // $B68D: ASL
    // $B68E: BCS $63
    // $B690: LDY $24,X
    // ... (46 more instructions)
}

/* Function at 0xB6F9 */
void func_B6F9(void) {
    /* Size: 82 bytes, 40 instructions */
    // $B6F9: LDA $07A8,X
    // $B6FC: AND #$01
    // $B6FE: STA $07
    // $B700: LDA $E4,X
    // $B702: CMP #$F8
    // ... (35 more instructions)
}

/* Function at 0xB70B */
void func_B70B(void) {
    /* Size: 64 bytes, 32 instructions */
    // $B70B: LDY #$00
    // $B70D: LDA $33
    // $B70F: LSR
    // $B710: BCC $02
    // $B712: LDY #$08
    // ... (27 more instructions)
}

/* Function at 0xB74F */
void func_B74F(void) {
    /* Size: 85 bytes, 35 instructions */
    // $B752: BEQ $4F
    // $B754: LDA $0E
    // $B756: CMP #$08
    // $B758: BCC $49
    // $B75A: CMP #$0B
    // ... (30 more instructions)
}

/* Function at 0xB7B8 */
void func_B7B8(void) {
    /* Size: 61 bytes, 29 instructions */
    // $B7B8: LDA $074E
    // $B7BB: BNE $37
    // $B7BD: STA $047D
    // $B7C0: LDA $0747
    // $B7C3: BNE $2F
    // ... (24 more instructions)
}

/* Function at 0xB855 */
void func_B855(void) {
    /* Size: 97 bytes, 42 instructions */
    // $B855: LDX #$05
    // $B857: STX $08
    // $B859: LDA $16,X
    // $B85B: CMP #$30
    // $B85D: BNE $56
    // ... (37 more instructions)
}

/* Function at 0xB923 */
void func_B923(void) {
    /* Size: 43 bytes, 19 instructions */
    // $B923: LDA #$2F
    // $B925: STA $16,X
    // $B927: LDA #$01
    // $B929: STA $0F,X
    // $B92B: LDA $0076,Y
    // ... (14 more instructions)
}

/* Function at 0xB9C1 */
void func_B9C1(void) {
    /* Size: 117 bytes, 52 instructions */
    // $B9C1: LDA $074E
    // $B9C4: BEQ $6F
    // $B9C6: LDX #$02
    // $B9C8: STX $08
    // $B9CA: LDA $0F,X
    // ... (47 more instructions)
}

/* Function at 0xBA38 */
void func_BA38(void) {
    /* Size: 86 bytes, 37 instructions */
    // $BA3B: BNE $3E
    // $BA3D: LDA $1E,X
    // $BA3F: BNE $2E
    // $BA41: LDA $03D1
    // $BA44: AND #$0C
    // ... (32 more instructions)
}

/* Function at 0xBA99 */
void func_BA99(void) {
    /* Size: 43 bytes, 19 instructions */
    // $BA9C: AND #$07
    // $BA9E: BNE $05
    // $BAA0: LDA $07A8
    // $BAA3: AND #$08
    // $BAA5: TAY
    // ... (14 more instructions)
}

/* Function at 0xBAC3 */
void func_BAC3(void) {
    /* Size: 1 bytes, 1 instructions */
    // $BAC3: RTS
}

/* Function at 0xBAC7 */
void func_BAC7(void) {
    /* Size: 1 bytes, 1 instructions */
    // $BAC7: RTS
}

/* Function at 0xBAC8 */
void func_BAC8(void) {
    /* Size: 117 bytes, 54 instructions */
    // $BAC8: LDA $0747
    // $BACB: BNE $63
    // $BACD: LDA $2A,X
    // $BACF: AND #$7F
    // $BAD1: LDY $06AE,X
    // ... (49 more instructions)
}

/* Function at 0xBB56 */
void func_BB56(void) {
    /* Size: 51 bytes, 23 instructions */
    // $BB56: JSR $BB89
    // $BB59: LDA $03EA,X
    // $BB5C: STA $007A,Y
    // $BB5F: LDA $06
    // $BB61: ASL
    // ... (18 more instructions)
}

/* Function at 0xBB89 */
void func_BB89(void) {
    /* Size: 18 bytes, 9 instructions */
    // $BB89: LDY #$08
    // $BB8B: LDA $002A,Y
    // $BB8E: BEQ $07
    // $BB90: DEY
    // $BB91: CPY #$05
    // ... (4 more instructions)
}

/* Function at 0xBB9B */
void func_BB9B(void) {
    /* Size: 98 bytes, 49 instructions */
    // $BB9B: LDX #$08
    // $BB9D: STX $08
    // $BB9F: LDA $2A,X
    // $BBA1: BEQ $56
    // $BBA3: ASL
    // ... (44 more instructions)
}

/* Function at 0xBC03 */
void func_BC03(void) {
    /* Size: 75 bytes, 29 instructions */
    // $BC03: LDA #$01
    // $BC05: STA $0139
    // $BC08: LDX $0753
    // $BC0B: LDY $BBFD,X
    // $BC0E: JSR $8F5F
    // ... (24 more instructions)
}

/* Function at 0xBC2C */
void func_BC2C(void) {
    /* Size: 34 bytes, 13 instructions */
    // $BC2C: LDX $0753
    // $BC2F: LDY $BBFF,X
    // $BC32: JSR $8F5F
    // $BC35: LDY $0753
    // $BC38: LDA $BC01,Y
    // ... (8 more instructions)
}

/* Function at 0xBC35 */
void func_BC35(void) {
    /* Size: 25 bytes, 10 instructions */
    // $BC35: LDY $0753
    // $BC38: LDA $BC01,Y
    // $BC3B: JSR $8F06
    // $BC3E: LDY $0300
    // $BC41: LDA $02FB,Y
    // ... (5 more instructions)
}

/* Function at 0xBC3B */
void func_BC3B(void) {
    /* Size: 19 bytes, 8 instructions */
    // $BC3B: JSR $8F06
    // $BC3E: LDY $0300
    // $BC41: LDA $02FB,Y
    // $BC44: BNE $05
    // $BC46: LDA #$24
    // ... (3 more instructions)
}

/* Function at 0xBCF2 */
void func_BCF2(void) {
    /* Size: 151 bytes, 68 instructions */
    // $BCF2: PHA
    // $BCF3: LDA #$11
    // $BCF5: LDX $03EE
    // $BCF8: LDY $0754
    // $BCFB: BNE $02
    // ... (63 more instructions)
}

/* Function at 0xBD89 */
void func_BD89(void) {
    /* Size: 23 bytes, 12 instructions */
    // $BD89: LDA $86
    // $BD8B: CLC
    // $BD8C: ADC #$08
    // $BD8E: AND #$F0
    // $BD90: STA $8F,X
    // ... (7 more instructions)
}

/* Function at 0xBDA0 */
void func_BDA0(void) {
    /* Size: 77 bytes, 32 instructions */
    // $BDA0: JSR $BE24
    // $BDA3: LDA #$02
    // $BDA5: STA $FF
    // $BDA7: LDA #$00
    // $BDA9: STA $60,X
    // ... (27 more instructions)
}

/* Function at 0xBDFB */
void func_BDFB(void) {
    /* Size: 12 bytes, 6 instructions */
    // $BDFC: ORA $EDD9
    // $BDFF: LDA $04F0,X
    // $BE02: DEY
    // $BE03: BPL $F8
    // $BE05: CLC
    // ... (1 more instructions)
}

/* Function at 0xBE06 */
void func_BE06(void) {
    /* Size: 1 bytes, 1 instructions */
    // $BE06: RTS
}

/* Function at 0xBE07 */
void func_BE07(void) {
    /* Size: 29 bytes, 12 instructions */
    // $BE07: JSR $BE24
    // $BE0A: LDA #$01
    // $BE0C: STA $03EC,X
    // $BE0F: STA $FD
    // $BE11: JSR $BE46
    // ... (7 more instructions)
}

/* Function at 0xBE24 */
void func_BE24(void) {
    /* Size: 34 bytes, 17 instructions */
    // $BE24: LDX $03EE
    // $BE27: LDY $02
    // $BE29: BEQ $1A
    // $BE2B: TYA
    // $BE2C: SEC
    // ... (12 more instructions)
}

/* Function at 0xBE46 */
void func_BE46(void) {
    /* Size: 47 bytes, 23 instructions */
    // $BE46: LDA $8F,X
    // $BE48: STA $03F1,X
    // $BE4B: LDA #$F0
    // $BE4D: STA $60,X
    // $BE4F: STA $62,X
    // ... (18 more instructions)
}

/* Function at 0xBE75 */
void func_BE75(void) {
    /* Size: 100 bytes, 51 instructions */
    // $BE75: LDA $26,X
    // $BE77: BEQ $5D
    // $BE79: AND #$0F
    // $BE7B: PHA
    // $BE7C: TAY
    // ... (46 more instructions)
}

/* Function at 0xBED9 */
void func_BED9(void) {
    /* Size: 46 bytes, 21 instructions */
    // $BED9: LDX #$01
    // $BEDB: STX $08
    // $BEDD: LDA $0301
    // $BEE0: BNE $21
    // $BEE2: LDA $03EC,X
    // ... (16 more instructions)
}

/* Function at 0xBF07 */
void func_BF07(void) {
    /* Size: 7 bytes, 4 instructions */
    // $BF07: INX
    // $BF08: JSR $BF14
    // $BF0B: LDX $08
    // $BF0D: RTS
}

/* Function at 0xBF0E */
void func_BF0E(void) {
    /* Size: 68 bytes, 41 instructions */
    // $BF0E: LDA $070E
    // $BF11: BNE $3E
    // $BF13: TAX
    // $BF14: LDA $57,X
    // $BF16: ASL
    // ... (36 more instructions)
}

/* Function at 0xBF14 */
void func_BF14(void) {
    /* Size: 62 bytes, 38 instructions */
    // $BF14: LDA $57,X
    // $BF16: ASL
    // $BF17: ASL
    // $BF18: ASL
    // $BF19: ASL
    // ... (33 more instructions)
}

/* Function at 0xBF68 */
void func_BF68(void) {
    /* Size: 60 bytes, 30 instructions */
    // $BF68: LDY #$3D
    // $BF6A: LDA $1E,X
    // $BF6C: CMP #$05
    // $BF6E: BNE $02
    // $BF70: LDY #$20
    // ... (25 more instructions)
}

/* Function at 0xBF70 */
void func_BF70(void) {
    /* Size: 52 bytes, 26 instructions */
    // $BF70: LDY #$20
    // $BF72: JMP $BF99
    // $BF75: LDY #$00
    // $BF77: JMP $BF7C
    // $BF7A: LDY #$01
    // ... (21 more instructions)
}

/* Function at 0xBF8D */
void func_BF8D(void) {
    /* Size: 23 bytes, 12 instructions */
    // $BF8D: LDY #$7F
    // $BF8F: BNE $02
    // $BF91: LDY #$12
    // $BF93: LDA #$02
    // $BF95: BNE $04
    // ... (7 more instructions)
}

/* Function at 0xBF91 */
void func_BF91(void) {
    /* Size: 19 bytes, 10 instructions */
    // $BF91: LDY #$12
    // $BF93: LDA #$02
    // $BF95: BNE $04
    // $BF97: LDY #$1F
    // $BF99: LDA #$04
    // ... (5 more instructions)
}

/* Function at 0xBF97 */
void func_BF97(void) {
    /* Size: 13 bytes, 7 instructions */
    // $BF97: LDY #$1F
    // $BF99: LDA #$04
    // $BF9B: STY $00
    // $BF9D: INX
    // $BF9E: JSR $BFB2
    // ... (2 more instructions)
}

/* Function at 0xBFA9 */
void func_BFA9(void) {
    /* Size: 51 bytes, 25 instructions */
    // $BFAB: LDA #$58
    // $BFAD: STA $00
    // $BFAF: LDA $BFA4,Y
    // $BFB2: STA $02
    // $BFB4: LDA #$00
    // ... (20 more instructions)
}

/* Function at 0xBFB2 */
void func_BFB2(void) {
    /* Size: 42 bytes, 22 instructions */
    // $BFB2: STA $02
    // $BFB4: LDA #$00
    // $BFB6: JMP $BFDC
    // $BFB9: LDA #$00
    // $BFBB: BIT $01A9
    // ... (17 more instructions)
}

/* Function at 0xBFB9 */
void func_BFB9(void) {
    /* Size: 35 bytes, 19 instructions */
    // $BFB9: LDA #$00
    // $BFBB: BIT $01A9
    // $BFBE: PHA
    // $BFBF: LDY $16,X
    // $BFC1: INX
    // ... (14 more instructions)
}

/* Function at 0xBFBC */
void func_BFBC(void) {
    /* Size: 32 bytes, 17 instructions */
    // $BFBE: PHA
    // $BFBF: LDY $16,X
    // $BFC1: INX
    // $BFC2: LDA #$05
    // $BFC4: CPY #$29
    // ... (12 more instructions)
}

/* Function at 0xBFDC */
void func_BFDC(void) {
    /* Size: 112 bytes, 55 instructions */
    // $BFDC: PHA
    // $BFDD: LDA $0416,X
    // $BFE0: CLC
    // $BFE1: ADC $0433,X
    // $BFE4: STA $0416,X
    // ... (50 more instructions)
}

/* Function at 0xC04D */
void func_C04D(void) {
    /* Size: 36 bytes, 19 instructions */
    // $C04D: LDA $0F,X
    // $C04F: PHA
    // $C050: ASL
    // $C051: BCS $12
    // $C053: PLA
    // ... (14 more instructions)
}

/* Function at 0xC08C */
void func_C08C(void) {
    /* Size: 1 bytes, 1 instructions */
    // $C08C: RTI
}

/* Function at 0xC092 */
void func_C092(void) {
    /* Size: 64 bytes, 26 instructions */
    // $C093: ADC $E938
    // $C097: STA $6D
    // $C099: LDA $0725
    // $C09C: SEC
    // $C09D: SBC #$04
    // ... (21 more instructions)
}

/* Function at 0xC22C */
void func_C22C(void) {
    /* Size: 8 bytes, 4 instructions */
    // $C22C: LDA #$00
    // $C22E: STA $1E,X
    // $C230: JSR $C272
    // $C233: RTS
}

/* Function at 0xC272 */
void func_C272(void) {
    /* Size: 133 bytes, 55 instructions */
    // $C272: LDA $16,X
    // $C274: CMP #$15
    // $C276: BCS $0D
    // $C278: TAY
    // $C279: LDA $CF,X
    // ... (50 more instructions)
}

/* Function at 0xC2F6 */
void func_C2F6(void) {
    /* Size: 1 bytes, 1 instructions */
    // $C2F6: RTS
}

/* Function at 0xC2FD */
void func_C2FD(void) {
    /* Size: 21 bytes, 11 instructions */
    // $C2FD: LDA #$02
    // $C2FF: STA $B6,X
    // $C301: STA $CF,X
    // $C303: LSR
    // $C304: STA $0796,X
    // ... (6 more instructions)
}

/* Function at 0xC314 */
void func_C314(void) {
    /* Size: 24 bytes, 11 instructions */
    // $C314: LDY #$01
    // $C316: LDA $076A
    // $C319: BNE $01
    // $C31B: DEY
    // $C31C: LDA $C312,Y
    // ... (6 more instructions)
}

/* Function at 0xC343 */
void func_C343(void) {
    /* Size: 46 bytes, 22 instructions */
    // $C343: LDA #$00
    // $C345: JMP $C31F
    // $C348: LDA #$00
    // $C34A: STA $58,X
    // $C34C: LDA #$09
    // ... (17 more instructions)
}

/* Function at 0xC34C */
void func_C34C(void) {
    /* Size: 37 bytes, 18 instructions */
    // $C34C: LDA #$09
    // $C34E: BNE $12
    // $C350: LDY #$30
    // $C352: LDA $CF,X
    // $C354: STA $0401,X
    // ... (13 more instructions)
}

/* Function at 0xC369 */
void func_C369(void) {
    /* Size: 8 bytes, 4 instructions */
    // $C369: LDA #$00
    // $C36B: STA $A0,X
    // $C36D: STA $0434,X
    // $C370: RTS
}

/* Function at 0xC390 */
void func_C390(void) {
    /* Size: 92 bytes, 41 instructions */
    // $C390: LDA #$00
    // $C392: STA $06D1
    // $C395: JSR $C343
    // $C398: JMP $C7DF
    // $C39B: JMP $C99E
    // ... (36 more instructions)
}

/* Function at 0xC57B */
void func_C57B(void) {
    /* Size: 40 bytes, 18 instructions */
    // $C57B: LDY #$FF
    // $C57D: INY
    // $C57E: LDA $000F,Y
    // $C581: BNE $FA
    // $C583: STY $06CF
    // ... (13 more instructions)
}

/* Function at 0xC5DE */
void func_C5DE(void) {
    /* Size: 89 bytes, 41 instructions */
    // $C5DE: STA $CF,X
    // $C5E0: LDA $071D
    // $C5E3: CLC
    // $C5E4: ADC #$20
    // $C5E6: STA $87,X
    // ... (36 more instructions)
}

/* Function at 0xC78D */
void func_C78D(void) {
    /* Size: 74 bytes, 35 instructions */
    // $C78D: LDA #$01
    // $C78F: STA $58,X
    // $C791: LSR
    // $C792: STA $1E,X
    // $C794: STA $A0,X
    // ... (30 more instructions)
}

/* Function at 0xC828 */
void func_C828(void) {
    /* Size: 29 bytes, 14 instructions */
    // $C828: TYA
    // $C829: CLC
    // $C82A: ADC $CF,X
    // $C82C: STA $58,X
    // $C82E: JSR $C369
    // ... (9 more instructions)
}

/* Function at 0xC851 */
void func_C851(void) {
    /* Size: 32 bytes, 14 instructions */
    // $C851: LDA #$10
    // $C853: STA $0434,X
    // $C856: LDA #$FF
    // $C858: STA $A0,X
    // $C85A: JMP $C866
    // ... (9 more instructions)
}

/* Function at 0xC85D */
void func_C85D(void) {
    /* Size: 20 bytes, 9 instructions */
    // $C85D: LDA #$F0
    // $C85F: STA $0434,X
    // $C862: LDA #$00
    // $C864: STA $A0,X
    // $C866: LDY #$01
    // ... (4 more instructions)
}

/* Function at 0xC877 */
void func_C877(void) {
    /* Size: 16 bytes, 8 instructions */
    // $C877: LDA $87,X
    // $C879: CLC
    // $C87A: ADC $C871,Y
    // $C87D: STA $87,X
    // $C87F: LDA $6E,X
    // ... (3 more instructions)
}

/* Function at 0xC887 */
void func_C887(void) {
    /* Size: 1 bytes, 1 instructions */
    // $C887: RTS
}

/* Function at 0xC8DD */
void func_C8DD(void) {
    /* Size: 217 bytes, 82 instructions */
    // $C8DD: JSR $F1B6
    // $C8E0: JSR $F159
    // $C8E3: JMP $E884
    // $C8E6: LDA #$00
    // $C8E8: STA $03C5,X
    // ... (77 more instructions)
}

/* Function at 0xC90B */
void func_C90B(void) {
    /* Size: 171 bytes, 66 instructions */
    // $C90B: LDA $16,X
    // $C90D: JSR $8E04
    // $C910: ADC $7DCA,X
    // $C913: DEX
    // $C914: ADC $7DCA,X
    // ... (61 more instructions)
}

/* Function at 0xC988 */
void func_C988(void) {
    /* Size: 46 bytes, 20 instructions */
    // $C988: LDA $16,X
    // $C98A: SEC
    // $C98B: SBC #$24
    // $C98D: JSR $8E04
    // $C993: CMP $17,X
    // ... (15 more instructions)
}

/* Function at 0xC99E */
void func_C99E(void) {
    /* Size: 24 bytes, 10 instructions */
    // $C99F: BRK
    // $C9A0: STA $0F,X
    // $C9A2: STA $16,X
    // $C9A4: STA $1E,X
    // $C9A6: STA $0110,X
    // ... (5 more instructions)
}

/* Function at 0xCA7D */
void func_CA7D(void) {
    /* Size: 81 bytes, 42 instructions */
    // $CA7D: LDY #$00
    // $CA7F: LDA $1E,X
    // $CA81: AND #$40
    // $CA83: BNE $19
    // $CA85: LDA $1E,X
    // ... (37 more instructions)
}

/* Function at 0xCAFF */
void func_CAFF(void) {
    /* Size: 32 bytes, 14 instructions */
    // $CAFF: JSR $BF97
    // $CB02: JMP $BF07
    // $CB05: LDA $A0,X
    // $CB07: ORA $0434,X
    // $CB0A: BNE $13
    // ... (9 more instructions)
}

/* Function at 0xCB4B */
void func_CB4B(void) {
    /* Size: 24 bytes, 13 instructions */
    // $CB4B: LDA #$13
    // $CB4D: STA $01
    // $CB4F: LDA $09
    // $CB51: AND #$03
    // $CB53: BNE $0D
    // ... (8 more instructions)
}

/* Function at 0xCB4D */
void func_CB4D(void) {
    /* Size: 22 bytes, 12 instructions */
    // $CB4D: STA $01
    // $CB4F: LDA $09
    // $CB51: AND #$03
    // $CB53: BNE $0D
    // $CB55: LDY $58,X
    // ... (7 more instructions)
}

/* Function at 0xCB6C */
void func_CB6C(void) {
    /* Size: 33 bytes, 18 instructions */
    // $CB6C: LDA $58,X
    // $CB6E: PHA
    // $CB6F: LDY #$01
    // $CB71: LDA $A0,X
    // $CB73: AND #$02
    // ... (13 more instructions)
}

/* Function at 0xCBE5 */
void func_CBE5(void) {
    /* Size: 37 bytes, 20 instructions */
    // $CBE5: LDA $A0,X
    // $CBE7: AND #$02
    // $CBE9: BNE $37
    // $CBEB: LDA $09
    // $CBED: AND #$07
    // ... (15 more instructions)
}

/* Function at 0xCD42 */
void func_CD42(void) {
    /* Size: 127 bytes, 56 instructions */
    // $CD42: JSR $F1B6
    // $CD45: LDA $03D1
    // $CD48: AND #$08
    // $CD4A: BNE $74
    // $CD4C: LDA $0747
    // ... (51 more instructions)
}

/* Function at 0xCDC1 */
void func_CDC1(void) {
    /* Size: 211 bytes, 108 instructions */
    // $CDC1: LDA $03
    // $CDC3: STA $05
    // $CDC5: LDY $06
    // $CDC7: LDA $01
    // $CDC9: LSR $05
    // ... (103 more instructions)
}

/* Function at 0xCE0E */
void func_CE0E(void) {
    /* Size: 134 bytes, 72 instructions */
    // $CE0E: JSR $ECF4
    // $CE11: TYA
    // $CE12: PHA
    // $CE13: LDA $079F
    // $CE16: ORA $0747
    // ... (67 more instructions)
}

/* Function at 0xCE94 */
void func_CE94(void) {
    /* Size: 71 bytes, 41 instructions */
    // $CE94: PHA
    // $CE95: AND #$0F
    // $CE97: CMP #$09
    // $CE99: BCC $05
    // $CE9B: EOR #$0F
    // ... (36 more instructions)
}

/* Function at 0xCF34 */
void func_CF34(void) {
    /* Size: 113 bytes, 60 instructions */
    // $CF34: LDY #$00
    // $CF36: JSR $E14B
    // $CF39: BPL $0A
    // $CF3B: INY
    // $CF3C: LDA $00
    // ... (55 more instructions)
}

/* Function at 0xD039 */
void func_D039(void) {
    /* Size: 14 bytes, 7 instructions */
    // $D039: LDX #$04
    // $D03B: JSR $C99E
    // $D03E: DEX
    // $D03F: BPL $FA
    // $D041: STA $06CB
    // ... (2 more instructions)
}

/* Function at 0xD184 */
void func_D184(void) {
    /* Size: 47 bytes, 17 instructions */
    // $D184: INC $036A
    // $D187: JSR $C8DD
    // $D18A: LDA $1E,X
    // $D18C: BNE $F5
    // $D18E: LDA #$0A
    // ... (12 more instructions)
}

/* Function at 0xD1A1 */
void func_D1A1(void) {
    /* Size: 18 bytes, 7 instructions */
    // $D1A1: LDY $0367
    // $D1A4: INC $0367
    // $D1A7: LDA $0367
    // $D1AA: AND #$07
    // $D1AC: STA $0367
    // ... (2 more instructions)
}

/* Function at 0xD32D */
void func_D32D(void) {
    /* Size: 49 bytes, 23 instructions */
    // $D32D: JSR $F159
    // $D330: LDY $06E5,X
    // $D333: LDX #$03
    // $D335: LDA $03B9
    // $D338: CLC
    // ... (18 more instructions)
}

/* Function at 0xD3D8 */
void func_D3D8(void) {
    /* Size: 20 bytes, 11 instructions */
    // $D3D8: STA $07
    // $D3DA: LDA $34,X
    // $D3DC: BNE $0E
    // $D3DE: LDY #$18
    // $D3E0: LDA $58,X
    // ... (6 more instructions)
}

/* Function at 0xD509 */
void func_D509(void) {
    /* Size: 87 bytes, 52 instructions */
    // $D509: PHA
    // $D50A: LDA $0087,Y
    // $D50D: CLC
    // $D50E: ADC #$08
    // $D510: LDX $06CC
    // ... (47 more instructions)
}

/* Function at 0xD579 */
void func_D579(void) {
    /* Size: 10 bytes, 4 instructions */
    // $D579: JSR $C369
    // $D57C: STA $00A0,Y
    // $D57F: STA $0434,Y
    // $D582: RTS
}

/* Function at 0xD5DC */
void func_D5DC(void) {
    /* Size: 29 bytes, 14 instructions */
    // $D5DC: LDA $86
    // $D5DE: CLC
    // $D5DF: ADC $00
    // $D5E1: STA $86
    // $D5E3: LDA $6D
    // ... (9 more instructions)
}

/* Function at 0xD61D */
void func_D61D(void) {
    /* Size: 28 bytes, 12 instructions */
    // $D61D: JSR $D623
    // $D620: JMP $D639
    // $D623: LDA $0747
    // $D626: BNE $19
    // $D628: LDA $0417,X
    // ... (7 more instructions)
}

/* Function at 0xD623 */
void func_D623(void) {
    /* Size: 22 bytes, 10 instructions */
    // $D623: LDA $0747
    // $D626: BNE $19
    // $D628: LDA $0417,X
    // $D62B: CLC
    // $D62C: ADC $0434,X
    // ... (5 more instructions)
}

/* Function at 0xD642 */
void func_D642(void) {
    /* Size: 92 bytes, 44 instructions */
    // $D642: LDA $16,X
    // $D644: CMP #$14
    // $D646: BEQ $55
    // $D648: LDA $071C
    // $D64B: LDY $16,X
    // ... (39 more instructions)
}

/* Function at 0xD6D9 */
void func_D6D9(void) {
    /* Size: 93 bytes, 54 instructions */
    // $D6D9: LDA $24,X
    // $D6DB: BEQ $56
    // $D6DD: ASL
    // $D6DE: BCS $53
    // $D6E0: LDA $09
    // ... (49 more instructions)
}

/* Function at 0xD73E */
void func_D73E(void) {
    /* Size: 134 bytes, 64 instructions */
    // $D73E: JSR $F159
    // $D741: LDX $01
    // $D743: LDA $0F,X
    // $D745: BPL $0B
    // $D747: AND #$0F
    // ... (59 more instructions)
}

/* Function at 0xD795 */
void func_D795(void) {
    /* Size: 47 bytes, 23 instructions */
    // $D795: LDA $16,X
    // $D797: CMP #$0D
    // $D799: BNE $06
    // $D79B: LDA $CF,X
    // $D79D: ADC #$18
    // ... (18 more instructions)
}

/* Function at 0xD7C4 */
void func_D7C4(void) {
    /* Size: 60 bytes, 30 instructions */
    // $D7C4: LDA $09
    // $D7C6: LSR
    // $D7C7: BCC $36
    // $D7C9: LDA $0747
    // $D7CC: ORA $03D6
    // ... (25 more instructions)
}

/* Function at 0xD853 */
void func_D853(void) {
    /* Size: 46 bytes, 21 instructions */
    // $D853: LDA $09
    // $D855: LSR
    // $D856: BCS $F4
    // $D858: JSR $DC43
    // $D85B: BCS $23
    // ... (16 more instructions)
}

/* Function at 0xD92D */
void func_D92D(void) {
    /* Size: 45 bytes, 20 instructions */
    // $D92D: LDA $079E
    // $D930: BNE $25
    // $D932: LDX $0756
    // $D935: BEQ $23
    // $D937: STA $0756
    // ... (15 more instructions)
}

/* Function at 0xD932 */
void func_D932(void) {
    /* Size: 40 bytes, 18 instructions */
    // $D932: LDX $0756
    // $D935: BEQ $23
    // $D937: STA $0756
    // $D93A: LDA #$08
    // $D93C: STA $079E
    // ... (13 more instructions)
}

/* Function at 0xD94A */
void func_D94A(void) {
    /* Size: 16 bytes, 8 instructions */
    // $D94A: STA $0E
    // $D94C: STY $1D
    // $D94E: LDY #$FF
    // $D950: STY $0747
    // $D953: INY
    // ... (3 more instructions)
}

/* Function at 0xDA07 */
void func_DA07(void) {
    /* Size: 12 bytes, 7 instructions */
    // $DA07: LDY #$01
    // $DA09: JSR $E14B
    // $DA0C: BPL $01
    // $DA0E: INY
    // $DA0F: STY $46,X
    // ... (2 more instructions)
}

/* Function at 0xDA12 */
void func_DA12(void) {
    /* Size: 1 bytes, 1 instructions */
    // $DA12: RTS
}

/* Function at 0xDA13 */
void func_DA13(void) {
    /* Size: 20 bytes, 8 instructions */
    // $DA13: STA $0110,X
    // $DA16: LDA #$30
    // $DA18: STA $012C,X
    // $DA1B: LDA $CF,X
    // $DA1D: STA $011E,X
    // ... (3 more instructions)
}

/* Function at 0xDA35 */
void func_DA35(void) {
    /* Size: 129 bytes, 62 instructions */
    // $DA37: LSR
    // $DA38: BCC $EC
    // $DA3A: LDA $074E
    // $DA3D: BEQ $E7
    // $DA3F: LDA $16,X
    // ... (57 more instructions)
}

/* Function at 0xDAB6 */
void func_DAB6(void) {
    /* Size: 61 bytes, 29 instructions */
    // $DAB6: LDA $001E,Y
    // $DAB9: ORA $1E,X
    // $DABB: AND #$20
    // $DABD: BNE $33
    // $DABF: LDA $1E,X
    // ... (24 more instructions)
}

/* Function at 0xDB1E */
void func_DB1E(void) {
    /* Size: 41 bytes, 22 instructions */
    // $DB1E: LDA $16,X
    // $DB20: CMP #$0D
    // $DB22: BEQ $22
    // $DB24: CMP #$11
    // $DB26: BEQ $1E
    // ... (17 more instructions)
}

/* Function at 0xDB47 */
void func_DB47(void) {
    /* Size: 54 bytes, 27 instructions */
    // $DB47: LDA #$FF
    // $DB49: STA $03A2,X
    // $DB4C: LDA $0747
    // $DB4F: BNE $29
    // $DB51: LDA $1E,X
    // ... (22 more instructions)
}

/* Function at 0xDB61 */
void func_DB61(void) {
    /* Size: 28 bytes, 15 instructions */
    // $DB61: JSR $DC43
    // $DB64: BCS $14
    // $DB66: TXA
    // $DB67: JSR $DC56
    // $DB6A: LDA $CF,X
    // ... (10 more instructions)
}

/* Function at 0xDB7D */
void func_DB7D(void) {
    /* Size: 63 bytes, 28 instructions */
    // $DB7D: LDA $0747
    // $DB80: BNE $37
    // $DB82: STA $03A2,X
    // $DB85: JSR $DC43
    // $DB88: BCS $2F
    // ... (23 more instructions)
}

/* Function at 0xDBBE */
void func_DBBE(void) {
    /* Size: 57 bytes, 28 instructions */
    // $DBBE: LDA $04AF,Y
    // $DBC1: SEC
    // $DBC2: SBC $04AD
    // $DBC5: CMP #$04
    // $DBC7: BCS $08
    // ... (23 more instructions)
}

/* Function at 0xDC1B */
void func_DC1B(void) {
    /* Size: 40 bytes, 21 instructions */
    // $DC1B: TAY
    // $DC1C: LDA $CF,X
    // $DC1E: CLC
    // $DC1F: ADC $DC18,Y
    // $DC22: BIT $CFB5
    // ... (16 more instructions)
}

/* Function at 0xDC23 */
void func_DC23(void) {
    /* Size: 32 bytes, 16 instructions */
    // $DC25: LDY $0E
    // $DC27: CPY #$0B
    // $DC29: BEQ $17
    // $DC2B: LDY $B6,X
    // $DC2D: CPY #$01
    // ... (11 more instructions)
}

/* Function at 0xDC43 */
void func_DC43(void) {
    /* Size: 17 bytes, 9 instructions */
    // $DC43: LDA $03D0
    // $DC46: CMP #$F0
    // $DC48: BCS $09
    // $DC4A: LDY $B5
    // $DC4C: DEY
    // ... (4 more instructions)
}

/* Function at 0xDC54 */
void func_DC54(void) {
    /* Size: 16 bytes, 10 instructions */
    // $DC54: LDA $08
    // $DC56: ASL
    // $DC57: ASL
    // $DC58: CLC
    // $DC59: ADC #$04
    // ... (5 more instructions)
}

/* Function at 0xDC56 */
void func_DC56(void) {
    /* Size: 14 bytes, 9 instructions */
    // $DC56: ASL
    // $DC57: ASL
    // $DC58: CLC
    // $DC59: ADC #$04
    // $DC5B: TAY
    // ... (4 more instructions)
}

/* Function at 0xDC66 */
void func_DC66(void) {
    /* Size: 52 bytes, 25 instructions */
    // $DC67: ASL $07,X
    // $DC69: BNE $2E
    // $DC6B: LDA $0E
    // $DC6D: CMP #$0B
    // $DC6F: BEQ $28
    // ... (20 more instructions)
}

/* Function at 0xDE24 */
void func_DE24(void) {
    /* Size: 29 bytes, 14 instructions */
    // $DE24: LDY $02
    // $DE26: LDA #$00
    // $DE28: STA ($06),Y
    // $DE2A: JMP $8A4D
    // $DE2D: SBC $FF07,Y
    // ... (9 more instructions)
}

/* Function at 0xDEC5 */
void func_DEC5(void) {
    /* Size: 7 bytes, 4 instructions */
    // $DEC5: CMP #$5F
    // $DEC7: BEQ $02
    // $DEC9: CMP #$60
    // $DECB: RTS
}

/* Function at 0xDECC */
void func_DECC(void) {
    /* Size: 25 bytes, 11 instructions */
    // $DECC: JSR $DEE5
    // $DECF: BCC $13
    // $DED1: LDA #$70
    // $DED3: STA $0709
    // $DED6: LDA #$F8
    // ... (6 more instructions)
}

/* Function at 0xDEE5 */
void func_DEE5(void) {
    /* Size: 11 bytes, 7 instructions */
    // $DEE5: CMP #$67
    // $DEE7: BEQ $05
    // $DEE9: CMP #$68
    // $DEEB: CLC
    // $DEEC: BNE $01
    // ... (2 more instructions)
}

/* Function at 0xDEEF */
void func_DEEF(void) {
    /* Size: 1 bytes, 1 instructions */
    // $DEEF: RTS
}

/* Function at 0xDEF0 */
void func_DEF0(void) {
    /* Size: 99 bytes, 46 instructions */
    // $DEF0: LDA $0B
    // $DEF2: AND #$04
    // $DEF4: BEQ $5C
    // $DEF6: LDA $00
    // $DEF8: CMP #$11
    // ... (41 more instructions)
}

/* Function at 0xDF53 */
void func_DF53(void) {
    /* Size: 64 bytes, 33 instructions */
    // $DF53: LDA #$00
    // $DF55: LDY $57
    // $DF57: LDX $00
    // $DF59: DEX
    // $DF5A: BNE $0A
    // ... (28 more instructions)
}

/* Function at 0xDF97 */
void func_DF97(void) {
    /* Size: 7 bytes, 3 instructions */
    // $DF98: CLV
    // $DF9A: CMP $DF93,X
    // $DF9D: RTS
}

/* Function at 0xDFA2 */
void func_DFA2(void) {
    /* Size: 7 bytes, 3 instructions */
    // $DFA3: CLV
    // $DFA5: CMP $DF9E,X
    // $DFA8: RTS
}

/* Function at 0xDFA9 */
void func_DFA9(void) {
    /* Size: 10 bytes, 6 instructions */
    // $DFA9: CMP #$C2
    // $DFAB: BEQ $06
    // $DFAD: CMP #$C3
    // $DFAF: BEQ $02
    // $DFB1: CLC
    // ... (1 more instructions)
}

/* Function at 0xDFB2 */
void func_DFB2(void) {
    /* Size: 1 bytes, 1 instructions */
    // $DFB2: RTS
}

/* Function at 0xDFC0 */
void func_DFC0(void) {
    /* Size: 1 bytes, 1 instructions */
    // $DFC0: RTS
}

/* Function at 0xDFC9 */
void func_DFC9(void) {
    /* Size: 166 bytes, 78 instructions */
    // $DFCA: ASL $2029,X
    // $DFCD: BNE $F1
    // $DFCF: JSR $E163
    // $DFD2: BCC $EC
    // $DFD4: LDY $16,X
    // ... (73 more instructions)
}

/* Function at 0xE023 */
void func_E023(void) {
    /* Size: 76 bytes, 38 instructions */
    // $E023: CMP #$09
    // $E025: BCC $10
    // $E027: CMP #$11
    // $E029: BCS $0C
    // $E02B: CMP #$0A
    // ... (33 more instructions)
}

/* Function at 0xE037 */
void func_E037(void) {
    /* Size: 56 bytes, 28 instructions */
    // $E037: LDA $1E,X
    // $E039: AND #$F0
    // $E03B: ORA #$02
    // $E03D: STA $1E,X
    // $E03F: DEC $CF,X
    // ... (23 more instructions)
}

/* Function at 0xE12C */
void func_E12C(void) {
    /* Size: 43 bytes, 22 instructions */
    // $E12C: CPX #$05
    // $E12E: BEQ $09
    // $E130: LDA $1E,X
    // $E132: ASL
    // $E133: BCC $04
    // ... (17 more instructions)
}

/* Function at 0xE14B */
void func_E14B(void) {
    /* Size: 12 bytes, 7 instructions */
    // $E14B: LDA $87,X
    // $E14D: SEC
    // $E14E: SBC $86
    // $E150: STA $00
    // $E152: LDA $6E,X
    // ... (2 more instructions)
}

/* Function at 0xE157 */
void func_E157(void) {
    /* Size: 12 bytes, 6 instructions */
    // $E157: JSR $C369
    // $E15A: LDA $CF,X
    // $E15C: AND #$F0
    // $E15E: ORA #$08
    // $E160: STA $CF,X
    // ... (1 more instructions)
}

/* Function at 0xE163 */
void func_E163(void) {
    /* Size: 8 bytes, 5 instructions */
    // $E163: LDA $CF,X
    // $E165: CLC
    // $E166: ADC #$3E
    // $E168: CMP #$44
    // $E16A: RTS
}

/* Function at 0xE16B */
void func_E16B(void) {
    /* Size: 51 bytes, 23 instructions */
    // $E16B: JSR $E163
    // $E16E: BCC $1A
    // $E170: LDA $A0,X
    // $E172: CLC
    // $E173: ADC #$02
    // ... (18 more instructions)
}

/* Function at 0xE196 */
void func_E196(void) {
    /* Size: 8 bytes, 4 instructions */
    // $E196: JSR $D795
    // $E199: LDA #$FC
    // $E19B: STA $A0,X
    // $E19D: RTS
}

/* Function at 0xE1B6 */
void func_E1B6(void) {
    /* Size: 26 bytes, 13 instructions */
    // $E1B6: LDA #$00
    // $E1B8: LDY #$15
    // $E1BA: JMP $E390
    // $E1BD: CMP #$26
    // $E1BF: BEQ $0E
    // ... (8 more instructions)
}

/* Function at 0xE1BD */
void func_E1BD(void) {
    /* Size: 19 bytes, 10 instructions */
    // $E1BD: CMP #$26
    // $E1BF: BEQ $0E
    // $E1C1: CMP #$C2
    // $E1C3: BEQ $0A
    // $E1C5: CMP #$C3
    // ... (5 more instructions)
}

/* Function at 0xE1D0 */
void func_E1D0(void) {
    /* Size: 39 bytes, 19 instructions */
    // $E1D0: LDA $D5,X
    // $E1D2: CMP #$18
    // $E1D4: BCC $21
    // $E1D6: JSR $E3A4
    // $E1D9: BEQ $1C
    // ... (14 more instructions)
}

/* Function at 0xE235 */
void func_E235(void) {
    /* Size: 111 bytes, 57 instructions */
    // $E235: TXA
    // $E236: CLC
    // $E237: ADC #$07
    // $E239: TAX
    // $E23A: LDY #$02
    // ... (52 more instructions)
}

/* Function at 0xE23E */
void func_E23E(void) {
    /* Size: 102 bytes, 51 instructions */
    // $E23E: TXA
    // $E23F: CLC
    // $E240: ADC #$09
    // $E242: TAX
    // $E243: LDY #$06
    // ... (46 more instructions)
}

/* Function at 0xE24B */
void func_E24B(void) {
    /* Size: 89 bytes, 44 instructions */
    // $E24B: LDY #$48
    // $E24D: STY $00
    // $E24F: LDY #$44
    // $E251: JMP $E25A
    // $E254: LDY #$08
    // ... (39 more instructions)
}

/* Function at 0xE254 */
void func_E254(void) {
    /* Size: 80 bytes, 40 instructions */
    // $E254: LDY #$08
    // $E256: STY $00
    // $E258: LDY #$04
    // $E25A: LDA $87,X
    // $E25C: SEC
    // ... (35 more instructions)
}

/* Function at 0xE27B */
void func_E27B(void) {
    /* Size: 41 bytes, 22 instructions */
    // $E27B: INX
    // $E27C: JSR $F1FD
    // $E27F: DEX
    // $E280: CMP #$FE
    // $E282: BCS $0D
    // ... (17 more instructions)
}

/* Function at 0xE2A4 */
void func_E2A4(void) {
    /* Size: 66 bytes, 36 instructions */
    // $E2A4: STX $00
    // $E2A6: LDA $03B8,Y
    // $E2A9: STA $02
    // $E2AB: LDA $03AD,Y
    // $E2AE: STA $01
    // ... (31 more instructions)
}

/* Function at 0xE32D */
void func_E32D(void) {
    /* Size: 39 bytes, 17 instructions */
    // $E32D: LDX #$00
    // $E32F: STY $06
    // $E331: LDA #$01
    // $E333: STA $07
    // $E335: LDA $04AC,Y
    // ... (12 more instructions)
}

/* Function at 0xE32F */
void func_E32F(void) {
    /* Size: 37 bytes, 16 instructions */
    // $E32F: STY $06
    // $E331: LDA #$01
    // $E333: STA $07
    // $E335: LDA $04AC,Y
    // $E338: CMP $04AC,X
    // ... (11 more instructions)
}

/* Function at 0xE390 */
void func_E390(void) {
    /* Size: 37 bytes, 23 instructions */
    // $E390: PHA
    // $E391: TXA
    // $E392: CLC
    // $E393: ADC #$01
    // $E395: TAX
    // ... (18 more instructions)
}

/* Function at 0xE3A4 */
void func_E3A4(void) {
    /* Size: 17 bytes, 10 instructions */
    // $E3A4: LDY #$1A
    // $E3A6: TXA
    // $E3A7: CLC
    // $E3A8: ADC #$07
    // $E3AA: TAX
    // ... (5 more instructions)
}

/* Function at 0xE3F0 */
void func_E3F0(void) {
    /* Size: 74 bytes, 40 instructions */
    // $E3F1: LDA #$00
    // $E3F3: BIT $01A9
    // $E3F6: LDX #$00
    // $E3F8: PHA
    // $E3F9: STY $04
    // ... (35 more instructions)
}

/* Function at 0xE3F1 */
void func_E3F1(void) {
    /* Size: 73 bytes, 40 instructions */
    // $E3F1: LDA #$00
    // $E3F3: BIT $01A9
    // $E3F6: LDX #$00
    // $E3F8: PHA
    // $E3F9: STY $04
    // ... (35 more instructions)
}

/* Function at 0xE3F4 */
void func_E3F4(void) {
    /* Size: 70 bytes, 38 instructions */
    // $E3F6: LDX #$00
    // $E3F8: PHA
    // $E3F9: STY $04
    // $E3FB: LDA $E3B8,Y
    // $E3FE: CLC
    // ... (33 more instructions)
}

/* Function at 0xE3F8 */
void func_E3F8(void) {
    /* Size: 66 bytes, 37 instructions */
    // $E3F8: PHA
    // $E3F9: STY $04
    // $E3FB: LDA $E3B8,Y
    // $E3FE: CLC
    // $E3FF: ADC $86,X
    // ... (32 more instructions)
}

/* Function at 0xE43C */
void func_E43C(void) {
    /* Size: 121 bytes, 56 instructions */
    // $E43D: BRK
    // $E43E: LDA $03B9
    // $E441: CLC
    // $E442: ADC $E43A,Y
    // $E445: LDX $039A,Y
    // ... (51 more instructions)
}

/* Function at 0xE4B5 */
void func_E4B5(void) {
    /* Size: 18 bytes, 12 instructions */
    // $E4B5: LDX #$06
    // $E4B7: STA $0200,Y
    // $E4BA: CLC
    // $E4BB: ADC #$08
    // $E4BD: INY
    // ... (7 more instructions)
}

/* Function at 0xE4E3 */
void func_E4E3(void) {
    /* Size: 101 bytes, 44 instructions */
    // $E4E3: LDY $06F3,X
    // $E4E6: LDA $0747
    // $E4E9: BNE $08
    // $E4EB: LDA $2A,X
    // $E4ED: AND #$7F
    // ... (39 more instructions)
}

/* Function at 0xE552 */
void func_E552(void) {
    /* Size: 125 bytes, 53 instructions */
    // $E552: LDY $06E5,X
    // $E555: LDA $03AE
    // $E558: STA $0203,Y
    // $E55B: CLC
    // $E55C: ADC #$08
    // ... (48 more instructions)
}

/* Function at 0xE5BA */
void func_E5BA(void) {
    /* Size: 21 bytes, 8 instructions */
    // $E5BA: LDA #$F8
    // $E5BC: STA $0214,Y
    // $E5BF: STA $0210,Y
    // $E5C2: STA $020C,Y
    // $E5C5: STA $0208,Y
    // ... (3 more instructions)
}

/* Function at 0xE5BC */
void func_E5BC(void) {
    /* Size: 19 bytes, 7 instructions */
    // $E5BC: STA $0214,Y
    // $E5BF: STA $0210,Y
    // $E5C2: STA $020C,Y
    // $E5C5: STA $0208,Y
    // $E5C8: STA $0204,Y
    // ... (2 more instructions)
}

/* Function at 0xE5C2 */
void func_E5C2(void) {
    /* Size: 13 bytes, 5 instructions */
    // $E5C2: STA $020C,Y
    // $E5C5: STA $0208,Y
    // $E5C8: STA $0204,Y
    // $E5CB: STA $0200,Y
    // $E5CE: RTS
}

/* Function at 0xE5C5 */
void func_E5C5(void) {
    /* Size: 10 bytes, 4 instructions */
    // $E5C5: STA $0208,Y
    // $E5C8: STA $0204,Y
    // $E5CB: STA $0200,Y
    // $E5CE: RTS
}

/* Function at 0xE5C8 */
void func_E5C8(void) {
    /* Size: 7 bytes, 3 instructions */
    // $E5C8: STA $0204,Y
    // $E5CB: STA $0200,Y
    // $E5CE: RTS
}

/* Function at 0xE5CF */
void func_E5CF(void) {
    /* Size: 141 bytes, 72 instructions */
    // $E5CF: LDY $06E5,X
    // $E5D2: STY $02
    // $E5D4: INY
    // $E5D5: INY
    // $E5D6: INY
    // ... (67 more instructions)
}

/* Function at 0xE68D */
void func_E68D(void) {
    /* Size: 56 bytes, 26 instructions */
    // $E68D: LDY $06F3,X
    // $E690: LDA $2A,X
    // $E692: CMP #$02
    // $E694: BCS $C6
    // $E696: LDA $DB,X
    // ... (21 more instructions)
}

/* Function at 0xE6D9 */
void func_E6D9(void) {
    /* Size: 471 bytes, 164 instructions */
    // $E6DB: ASL $AD
    // $E6DD: LDA $1803,Y
    // $E6E0: ADC #$08
    // $E6E2: STA $02
    // $E6E4: LDA $03AE
    // ... (159 more instructions)
}

/* Function at 0xE884 */
void func_E884(void) {
    /* Size: 44 bytes, 20 instructions */
    // $E884: LDA $CF,X
    // $E886: STA $02
    // $E888: LDA $03AE
    // $E88B: STA $05
    // $E88D: LDY $06E5,X
    // ... (15 more instructions)
}

/* Function at 0xEBB1 */
void func_EBB1(void) {
    /* Size: 35 bytes, 16 instructions */
    // $EBB1: LDA $E745,X
    // $EBB4: STA $00
    // $EBB6: LDA $E746,X
    // $EBB9: STA $01
    // $EBBB: JMP $F289
    // ... (11 more instructions)
}

/* Function at 0xEBB9 */
void func_EBB9(void) {
    /* Size: 27 bytes, 13 instructions */
    // $EBB9: STA $01
    // $EBBB: JMP $F289
    // $EBBE: CLC
    // $EBBF: ADC $06E5,X
    // $EBC2: TAY
    // ... (8 more instructions)
}

/* Function at 0xEBBE */
void func_EBBE(void) {
    /* Size: 22 bytes, 11 instructions */
    // $EBBE: CLC
    // $EBBF: ADC $06E5,X
    // $EBC2: TAY
    // $EBC3: LDA #$F8
    // $EBC5: JMP $E5C8
    // ... (6 more instructions)
}

/* Function at 0xEBC8 */
void func_EBC8(void) {
    /* Size: 12 bytes, 6 instructions */
    // $EBC8: CLC
    // $EBC9: ADC $06E5,X
    // $EBCC: TAY
    // $EBCD: JSR $EC51
    // $EBD0: STA $0210,Y
    // ... (1 more instructions)
}

/* Function at 0xEBD8 */
void func_EBD8(void) {
    /* Size: 130 bytes, 58 instructions */
    // $EBD8: LDA $03BC
    // $EBDB: STA $02
    // $EBDD: LDA $03B1
    // $EBE0: STA $05
    // $EBE2: LDA #$03
    // ... (53 more instructions)
}

/* Function at 0xEC4D */
void func_EC4D(void) {
    /* Size: 13 bytes, 6 instructions */
    // $EC4D: AND #$08
    // $EC4F: BEQ $08
    // $EC51: LDA #$F8
    // $EC53: STA $0200,Y
    // $EC56: STA $0208,Y
    // ... (1 more instructions)
}

/* Function at 0xEC51 */
void func_EC51(void) {
    /* Size: 9 bytes, 4 instructions */
    // $EC51: LDA #$F8
    // $EC53: STA $0200,Y
    // $EC56: STA $0208,Y
    // $EC59: RTS
}

/* Function at 0xEC5A */
void func_EC5A(void) {
    /* Size: 139 bytes, 63 instructions */
    // $EC5A: LDA #$02
    // $EC5C: STA $00
    // $EC5E: LDA #$75
    // $EC60: LDY $0E
    // $EC62: CPY #$05
    // ... (58 more instructions)
}

/* Function at 0xECF4 */
void func_ECF4(void) {
    /* Size: 25 bytes, 15 instructions */
    // $ECF4: LDA $09
    // $ECF6: LSR
    // $ECF7: LSR
    // $ECF8: PHA
    // $ECF9: AND #$01
    // ... (10 more instructions)
}

/* Function at 0xED1E */
void func_ED1E(void) {
    /* Size: 74 bytes, 33 instructions */
    // $ED1E: TAX
    // $ED1F: LDA $ED0D,X
    // $ED22: INY
    // $ED23: JSR $E5C2
    // $ED26: DEY
    // ... (28 more instructions)
}

/* Function at 0xED6D */
void func_ED6D(void) {
    /* Size: 123 bytes, 59 instructions */
    // $ED6D: LDY $06E5,X
    // $ED70: LDA #$5B
    // $ED72: INY
    // $ED73: JSR $E5BC
    // $ED76: INY
    // ... (54 more instructions)
}

/* Function at 0xEDE8 */
void func_EDE8(void) {
    /* Size: 38 bytes, 16 instructions */
    // $EDE8: LDY $B5
    // $EDEA: DEY
    // $EDEB: BNE $20
    // $EDED: LDA $03D3
    // $EDF0: AND #$08
    // ... (11 more instructions)
}

/* Function at 0xEE13 */
void func_EE13(void) {
    /* Size: 1 bytes, 1 instructions */
    // $EE13: RTI
}

/* Function at 0xEE1A */
void func_EE1A(void) {
    /* Size: 1 bytes, 1 instructions */
    // $EE1A: RTS
}

/* Function at 0xEEF0 */
void func_EEF0(void) {
    /* Size: 75 bytes, 37 instructions */
    // $EEF0: LDA $079E
    // $EEF3: BEQ $05
    // $EEF5: LDA $09
    // $EEF7: LSR
    // $EEF8: BCS $40
    // ... (32 more instructions)
}

/* Function at 0xEF3B */
void func_EF3B(void) {
    /* Size: 106 bytes, 50 instructions */
    // $EF3B: JSR $EFF3
    // $EF3E: JMP $EF4C
    // $EF41: JSR $F0B7
    // $EF44: JMP $EF4C
    // $EF47: LDY #$0E
    // ... (45 more instructions)
}

/* Function at 0xEFAB */
void func_EFAB(void) {
    /* Size: 26 bytes, 12 instructions */
    // $EFAB: LDX #$05
    // $EFAD: LDA $EFA5,X
    // $EFB0: STA $02,X
    // $EFB2: DEX
    // $EFB3: BPL $F8
    // ... (7 more instructions)
}

/* Function at 0xEFC5 */
void func_EFC5(void) {
    /* Size: 46 bytes, 19 instructions */
    // $EFC5: STA $07
    // $EFC7: LDA $03AD
    // $EFCA: STA $0755
    // $EFCD: STA $05
    // $EFCF: LDA $03B8
    // ... (14 more instructions)
}

/* Function at 0xEFE3 */
void func_EFE3(void) {
    /* Size: 16 bytes, 7 instructions */
    // $EFE3: LDA $EE1E,X
    // $EFE6: STA $00
    // $EFE8: LDA $EE1F,X
    // $EFEB: JSR $EBB9
    // $EFEE: DEC $07
    // ... (2 more instructions)
}

/* Function at 0xEFF3 */
void func_EFF3(void) {
    /* Size: 72 bytes, 33 instructions */
    // $EFF3: LDA $1D
    // $EFF5: CMP #$03
    // $EFF7: BEQ $52
    // $EFF9: CMP #$02
    // $EFFB: BEQ $3E
    // ... (28 more instructions)
}

/* Function at 0xF069 */
void func_F069(void) {
    /* Size: 47 bytes, 21 instructions */
    // $F069: LDA $070D
    // $F06C: JMP $F0D7
    // $F06F: LDA #$03
    // $F071: JMP $F076
    // $F074: LDA #$02
    // ... (16 more instructions)
}

/* Function at 0xF097 */
void func_F097(void) {
    /* Size: 1 bytes, 1 instructions */
    // $F097: RTS
}

/* Function at 0xF098 */
void func_F098(void) {
    /* Size: 11 bytes, 7 instructions */
    // $F098: LDA $0754
    // $F09B: BEQ $05
    // $F09D: TYA
    // $F09E: CLC
    // $F09F: ADC #$08
    // ... (2 more instructions)
}

/* Function at 0xF0A2 */
void func_F0A2(void) {
    /* Size: 1 bytes, 1 instructions */
    // $F0A2: RTS
}

/* Function at 0xF0B7 */
void func_F0B7(void) {
    /* Size: 39 bytes, 19 instructions */
    // $F0B7: LDY $070D
    // $F0BA: LDA $09
    // $F0BC: AND #$03
    // $F0BE: BNE $0D
    // $F0C0: INY
    // ... (14 more instructions)
}

/* Function at 0xF0F0 */
void func_F0F0(void) {
    /* Size: 65 bytes, 28 instructions */
    // $F0F0: LDY $06E4
    // $F0F3: LDA $0E
    // $F0F5: CMP #$0B
    // $F0F7: BEQ $13
    // $F0F9: LDA $06D5
    // ... (23 more instructions)
}

/* Function at 0xF131 */
void func_F131(void) {
    /* Size: 30 bytes, 13 instructions */
    // $F131: LDX #$00
    // $F133: LDY #$00
    // $F135: JMP $F149
    // $F138: LDY #$01
    // $F13A: JSR $F1AF
    // ... (8 more instructions)
}

/* Function at 0xF138 */
void func_F138(void) {
    /* Size: 23 bytes, 10 instructions */
    // $F138: LDY #$01
    // $F13A: JSR $F1AF
    // $F13D: LDY #$03
    // $F13F: JMP $F149
    // $F142: LDY #$00
    // ... (5 more instructions)
}

/* Function at 0xF139 */
void func_F139(void) {
    /* Size: 22 bytes, 9 instructions */
    // $F13A: JSR $F1AF
    // $F13D: LDY #$03
    // $F13F: JMP $F149
    // $F142: LDY #$00
    // $F144: JSR $F1AF
    // ... (4 more instructions)
}

/* Function at 0xF142 */
void func_F142(void) {
    /* Size: 13 bytes, 6 instructions */
    // $F142: LDY #$00
    // $F144: JSR $F1AF
    // $F147: LDY #$02
    // $F149: JSR $F178
    // $F14C: LDX $08
    // ... (1 more instructions)
}

/* Function at 0xF14F */
void func_F14F(void) {
    /* Size: 41 bytes, 21 instructions */
    // $F14F: LDY #$02
    // $F151: JSR $F1AF
    // $F154: LDY #$06
    // $F156: JMP $F149
    // $F159: LDA #$01
    // ... (16 more instructions)
}

/* Function at 0xF159 */
void func_F159(void) {
    /* Size: 31 bytes, 17 instructions */
    // $F159: LDA #$01
    // $F15B: LDY #$01
    // $F15D: JMP $F16C
    // $F160: LDA #$09
    // $F162: LDY #$04
    // ... (12 more instructions)
}

/* Function at 0xF160 */
void func_F160(void) {
    /* Size: 24 bytes, 14 instructions */
    // $F160: LDA #$09
    // $F162: LDY #$04
    // $F164: JSR $F16C
    // $F167: INX
    // $F168: INX
    // ... (9 more instructions)
}

/* Function at 0xF16C */
void func_F16C(void) {
    /* Size: 12 bytes, 7 instructions */
    // $F16C: STX $00
    // $F16E: CLC
    // $F16F: ADC $00
    // $F171: TAX
    // $F172: JSR $F178
    // ... (2 more instructions)
}

/* Function at 0xF178 */
void func_F178(void) {
    /* Size: 15 bytes, 7 instructions */
    // $F178: LDA $CE,X
    // $F17A: STA $03B8,Y
    // $F17D: LDA $86,X
    // $F17F: SEC
    // $F180: SBC $071C
    // ... (2 more instructions)
}

/* Function at 0xF187 */
void func_F187(void) {
    /* Size: 47 bytes, 21 instructions */
    // $F187: LDX #$00
    // $F189: LDY #$00
    // $F18B: JMP $F1C7
    // $F18E: LDY #$00
    // $F190: JSR $F1AF
    // ... (16 more instructions)
}

/* Function at 0xF18E */
void func_F18E(void) {
    /* Size: 40 bytes, 18 instructions */
    // $F18E: LDY #$00
    // $F190: JSR $F1AF
    // $F193: LDY #$02
    // $F195: JMP $F1C7
    // $F198: LDY #$01
    // ... (13 more instructions)
}

/* Function at 0xF198 */
void func_F198(void) {
    /* Size: 30 bytes, 14 instructions */
    // $F198: LDY #$01
    // $F19A: JSR $F1AF
    // $F19D: LDY #$03
    // $F19F: JMP $F1C7
    // $F1A2: LDY #$02
    // ... (9 more instructions)
}

/* Function at 0xF1A2 */
void func_F1A2(void) {
    /* Size: 20 bytes, 10 instructions */
    // $F1A2: LDY #$02
    // $F1A4: JSR $F1AF
    // $F1A7: LDY #$06
    // $F1A9: JMP $F1C7
    // $F1AD: ASL $0D,X
    // ... (5 more instructions)
}

/* Function at 0xF1AF */
void func_F1AF(void) {
    /* Size: 7 bytes, 5 instructions */
    // $F1AF: TXA
    // $F1B0: CLC
    // $F1B1: ADC $F1AC,Y
    // $F1B4: TAX
    // $F1B5: RTS
}

/* Function at 0xF1B5 */
void func_F1B5(void) {
    /* Size: 1 bytes, 1 instructions */
    // $F1B5: RTS
}

/* Function at 0xF1B6 */
void func_F1B6(void) {
    /* Size: 40 bytes, 24 instructions */
    // $F1B6: LDA #$01
    // $F1B8: LDY #$01
    // $F1BA: JMP $F1C1
    // $F1BD: LDA #$09
    // $F1BF: LDY #$04
    // ... (19 more instructions)
}

/* Function at 0xF1BD */
void func_F1BD(void) {
    /* Size: 33 bytes, 21 instructions */
    // $F1BD: LDA #$09
    // $F1BF: LDY #$04
    // $F1C1: STX $00
    // $F1C3: CLC
    // $F1C4: ADC $00
    // ... (16 more instructions)
}

/* Function at 0xF1DE */
void func_F1DE(void) {
    /* Size: 84 bytes, 36 instructions */
    // $F1DE: JSR $F1FD
    // $F1E1: LSR
    // $F1E2: LSR
    // $F1E3: LSR
    // $F1E4: LSR
    // ... (31 more instructions)
}

/* Function at 0xF1FD */
void func_F1FD(void) {
    /* Size: 53 bytes, 25 instructions */
    // $F1FD: STX $04
    // $F1FF: LDY #$01
    // $F201: LDA $071C,Y
    // $F204: SEC
    // $F205: SBC $86,X
    // ... (20 more instructions)
}

/* Function at 0xF274 */
void func_F274(void) {
    /* Size: 21 bytes, 13 instructions */
    // $F274: STA $05
    // $F276: LDA $07
    // $F278: CMP $06
    // $F27A: BCS $0C
    // $F27C: LSR
    // ... (8 more instructions)
}

/* Function at 0xF288 */
void func_F288(void) {
    /* Size: 1 bytes, 1 instructions */
    // $F288: RTS
}

/* Function at 0xF2D0 */
void func_F2D0(void) {
    /* Size: 1 bytes, 1 instructions */
    // $F2D0: RTS
}

/* Function at 0xF2D1 */
void func_F2D1(void) {
    /* Size: 9 bytes, 4 instructions */
    // $F2D1: LDA $0770
    // $F2D4: BNE $04
    // $F2D6: STA $4015
    // $F2D9: RTS
}

/* Function at 0xF382 */
void func_F382(void) {
    /* Size: 7 bytes, 3 instructions */
    // $F382: STY $4001
    // $F385: STX $4000
    // $F388: RTS
}

/* Function at 0xF389 */
void func_F389(void) {
    /* Size: 23 bytes, 10 instructions */
    // $F389: JSR $F382
    // $F38C: LDX #$00
    // $F38E: TAY
    // $F38F: LDA $FF01,Y
    // $F392: BEQ $0B
    // ... (5 more instructions)
}

/* Function at 0xF38C */
void func_F38C(void) {
    /* Size: 20 bytes, 9 instructions */
    // $F38C: LDX #$00
    // $F38E: TAY
    // $F38F: LDA $FF01,Y
    // $F392: BEQ $0B
    // $F394: STA $4002,X
    // ... (4 more instructions)
}

/* Function at 0xF3A0 */
void func_F3A0(void) {
    /* Size: 7 bytes, 3 instructions */
    // $F3A0: STX $4004
    // $F3A3: STY $4005
    // $F3A6: RTS
}

/* Function at 0xF3A7 */
void func_F3A7(void) {
    /* Size: 181 bytes, 88 instructions */
    // $F3A7: JSR $F3A0
    // $F3AA: LDX #$04
    // $F3AC: BNE $E0
    // $F3AE: LDX #$08
    // $F3B0: BNE $DC
    // ... (83 more instructions)
}

/* Function at 0xF3AA */
void func_F3AA(void) {
    /* Size: 178 bytes, 87 instructions */
    // $F3AA: LDX #$04
    // $F3AC: BNE $E0
    // $F3AE: LDX #$08
    // $F3B0: BNE $DC
    // $F3B4: TYA
    // ... (82 more instructions)
}

/* Function at 0xF3AE */
void func_F3AE(void) {
    /* Size: 174 bytes, 85 instructions */
    // $F3AE: LDX #$08
    // $F3B0: BNE $DC
    // $F3B4: TYA
    // $F3B5: STX $95,Y
    // $F3B7: STY $92,X
    // ... (80 more instructions)
}

/* Function at 0xF41C */
void func_F41C(void) {
    /* Size: 64 bytes, 36 instructions */
    // $F41C: LDY $FF
    // $F41E: BEQ $20
    // $F420: STY $F1
    // $F422: BMI $AA
    // $F424: LSR $FF
    // ... (31 more instructions)
}

/* Function at 0xF4A8 */
void func_F4A8(void) {
    /* Size: 15 bytes, 7 instructions */
    // $F4A8: LDX #$00
    // $F4AA: STX $F1
    // $F4AC: LDX #$0E
    // $F4AE: STX $4015
    // $F4B1: LDX #$0F
    // ... (2 more instructions)
}

/* Function at 0xF572 */
void func_F572(void) {
    /* Size: 11 bytes, 5 instructions */
    // $F572: LDX #$0D
    // $F574: STX $4015
    // $F577: LDX #$0F
    // $F579: STX $4015
    // $F57C: RTS
}

/* Function at 0xF57D */
void func_F57D(void) {
    /* Size: 70 bytes, 39 instructions */
    // $F57D: LDA $F2
    // $F57F: AND #$40
    // $F581: BNE $65
    // $F583: LDY $FE
    // $F585: BEQ $20
    // ... (34 more instructions)
}

/* Function at 0xF668 */
void func_F668(void) {
    /* Size: 25 bytes, 14 instructions */
    // $F668: LDY $FD
    // $F66A: BEQ $0A
    // $F66C: STY $F3
    // $F66E: LSR $FD
    // $F670: BCS $CA
    // ... (9 more instructions)
}

/* Function at 0xF695 */
void func_F695(void) {
    /* Size: 16 bytes, 8 instructions */
    // $F695: LDA $FC
    // $F697: BNE $0C
    // $F699: LDA $FB
    // $F69B: BNE $2C
    // $F69D: LDA $07B1
    // ... (3 more instructions)
}

/* Function at 0xF8C6 */
void func_F8C6(void) {
    /* Size: 19 bytes, 13 instructions */
    // $F8C6: TAX
    // $F8C7: ROR
    // $F8C8: TXA
    // $F8C9: ROL
    // $F8CA: ROL
    // ... (8 more instructions)
}

/* Function at 0xF8CC */
void func_F8CC(void) {
    /* Size: 13 bytes, 7 instructions */
    // $F8CC: AND #$07
    // $F8CE: CLC
    // $F8CF: ADC $F0
    // $F8D1: ADC $07C4
    // $F8D4: TAY
    // ... (2 more instructions)
}

/* Function at 0xF8D9 */
void func_F8D9(void) {
    /* Size: 28 bytes, 14 instructions */
    // $F8D9: LDA $07B1
    // $F8DC: AND #$08
    // $F8DE: BEQ $04
    // $F8E0: LDA #$04
    // $F8E2: BNE $0C
    // ... (9 more instructions)
}

/* Function at 0xF8F5 */
void func_F8F5(void) {
    /* Size: 11 bytes, 5 instructions */
    // $F8F5: LDA $07B1
    // $F8F8: AND #$08
    // $F8FA: BEQ $04
    // $F8FC: LDA $FF96,Y
    // $F8FF: RTS
}

/* Function at 0xF9B9 */
void func_F9B9(void) {
    /* Size: 90 bytes, 36 instructions */
    // $F9B9: STY $2C
    // $F9BB: BIT $822C
    // $F9BF: BIT $8504
    // $F9C2: BIT $2C84
    // $F9C5: BIT $2A2A
    // ... (31 more instructions)
}

/* Function at 0xFB4E */
void func_FB4E(void) {
    /* Size: 1 bytes, 1 instructions */
    // $FB4E: RTI
}

/* Function at 0xFB4F */
void func_FB4F(void) {
    /* Size: 1 bytes, 1 instructions */
    // $FB4F: RTI
}

/* Function at 0xFB50 */
void func_FB50(void) {
    /* Size: 1 bytes, 1 instructions */
    // $FB50: RTI
}

/* Function at 0xFCB1 */
void func_FCB1(void) {
    /* Size: 13 bytes, 3 instructions */
    // $FCB3: ASL $0C
    // $FCB8: STX $2C
    // $FCBD: RTS
}
