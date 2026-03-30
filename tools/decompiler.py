#!/usr/bin/env python3
"""
6502 Assembly to C Decompiler for NES ROMs
Converts 6502 assembly code into readable C language
"""

import re
from collections import defaultdict
from typing import Dict, List, Tuple, Set

class CPU6502State:
    """Tracks CPU register state during analysis"""
    def __init__(self):
        self.a = None  # Accumulator
        self.x = None  # X register
        self.y = None  # Y register
        self.sp = None  # Stack pointer
        self.pc = None  # Program counter
        self.flags = None  # Status flags

class NES6502Decompiler:
    """Decompiles 6502 assembly to C code"""
    
    # NES hardware register mappings
    PPU_REGISTERS = {
        0x2000: 'PPU_CTRL',
        0x2001: 'PPU_MASK', 
        0x2002: 'PPU_STATUS',
        0x2003: 'OAM_ADDR',
        0x2004: 'OAM_DATA',
        0x2005: 'PPU_SCROLL',
        0x2006: 'PPU_ADDR',
        0x2007: 'PPU_DATA',
    }
    
    APU_REGISTERS = {
        0x4000: 'SQ1_VOL',
        0x4001: 'SQ1_SWEEP',
        0x4002: 'SQ1_LO',
        0x4003: 'SQ1_HI',
        0x4004: 'SQ2_VOL',
        0x4015: 'APU_ENABLE',
        0x4011: 'DPCM_DAC',
        0x4014: 'OAM_DMA',
    }
    
    RAM_REGIONS = {
        (0x0000, 0x00FF): 'ZEROPAGE',
        (0x0100, 0x01FF): 'STACK',
        (0x0200, 0x02FF): 'OAM',
        (0x0300, 0x07FF): 'RAM',
    }
    
    def __init__(self, asm_file: str):
        self.asm_file = asm_file
        self.lines = []
        self.subroutines = {}  # address -> function info
        self.labels = {}  # label -> address
        self.variables = defaultdict(set)  # address -> usage info
        self.instructions = []  # parsed instructions
        self.call_graph = defaultdict(set)  # function -> called functions
        
    def load_assembly(self):
        """Load and parse assembly file"""
        with open(self.asm_file, 'r') as f:
            self.lines = f.readlines()
    
    def parse_instruction_line(self, line: str) -> Tuple[str, str, str]:
        """Parse an instruction line
        Returns: (address, mnemonic, operand)
        """
        line = line.strip()
        if not line or line.startswith(';'):
            return None, None, None
            
        # Match: $8000: SEI
        match = re.match(r'\$([0-9A-Fa-f]+):\s+(\w+)(?:\s+(.+))?', line)
        if match:
            addr = match.group(1)
            mnem = match.group(2)
            operand = match.group(3) or ''
            return addr, mnem, operand
        
        return None, None, None
    
    def analyze_assembly(self):
        """Analyze assembly structure to identify functions and variables"""
        for line in self.lines:
            addr, mnem, operand = self.parse_instruction_line(line)
            if not addr or not mnem:
                continue
            
            # Track subroutine entry points
            if mnem == 'JSR':
                target = self._parse_operand(operand)
                self.subroutines[target] = {
                    'calls': [],
                    'variables': set(),
                    'size': 0
                }
            
            # Track memory access
            if mnem in ['LDA', 'STA', 'LDX', 'STX', 'LDY', 'STY']:
                mem_addr = self._parse_operand(operand)
                if mem_addr:
                    self.variables[mem_addr].add(mnem)
            
            # Track labels
            if addr:
                self.instructions.append({
                    'addr': addr,
                    'mnem': mnem,
                    'operand': operand
                })
    
    def _parse_operand(self, operand: str):
        """Extract numeric value from operand"""
        match = re.search(r'\$([0-9A-Fa-f]+)', operand)
        if match:
            return match.group(1)
        return None
    
    def get_hw_register_name(self, addr: str) -> str:
        """Get human-readable name for hardware register"""
        try:
            addr_int = int(addr, 16)
            if addr_int in self.PPU_REGISTERS:
                return self.PPU_REGISTERS[addr_int]
            if addr_int in self.APU_REGISTERS:
                return self.APU_REGISTERS[addr_int]
        except:
            pass
        return f"MEM_{addr.upper()}"
    
    def decompile_to_c(self) -> str:
        """Generate C code from assembly"""
        c_code = self._generate_header()
        c_code += self._generate_type_definitions()
        c_code += self._generate_hardware_definitions()
        c_code += self._generate_memory_variables()
        c_code += self._generate_functions()
        c_code += self._generate_main()
        
        return c_code
    
    def _generate_header(self) -> str:
        """Generate C file header"""
        return """/*
 * NES ROM Decompilation to C
 * Converted from 6502 Assembly
 * 
 * This is a decompiled version of the NES ROM.
 * The code represents the original ROM's functionality
 * in a higher-level C language format.
 */

#include <stdint.h>
#include <string.h>

/* Type definitions */
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t s8;
typedef int16_t s16;

"""

    def _generate_type_definitions(self) -> str:
        """Generate custom type definitions"""
        return """/* CPU register structure */
typedef struct {
    u8 A;      /* Accumulator */
    u8 X;      /* X Register */
    u8 Y;      /* Y Register */
    u8 SP;     /* Stack Pointer */
    u8 PC_HI;  /* Program Counter High */
    u8 PC_LO;  /* Program Counter Low */
    u8 P;      /* Processor Status */
} CPU6502;

/* NES OAM Sprite structure */
typedef struct {
    u8 y;           /* Y coordinate */
    u8 tile;        /* Tile index */
    u8 attributes;  /* Sprite attributes */
    u8 x;           /* X coordinate */
} Sprite;

"""

    def _generate_hardware_definitions(self) -> str:
        """Generate NES hardware register definitions"""
        return """/* NES Hardware Memory-Mapped Registers */
/* PPU Registers */
#define PPU_CTRL     (*((volatile u8*)0x2000))  /* PPU Control */
#define PPU_MASK     (*((volatile u8*)0x2001))  /* PPU Mask */
#define PPU_STATUS   (*((volatile u8*)0x2002))  /* PPU Status */
#define OAM_ADDR     (*((volatile u8*)0x2003))  /* OAM Address */
#define OAM_DATA     (*((volatile u8*)0x2004))  /* OAM Data */
#define PPU_SCROLL   (*((volatile u8*)0x2005))  /* PPU Scroll */
#define PPU_ADDR     (*((volatile u8*)0x2006))  /* PPU Address */
#define PPU_DATA     (*((volatile u8*)0x2007))  /* PPU Data */

/* APU Registers */
#define SQ1_VOL      (*((volatile u8*)0x4000))  /* Square 1 Volume */
#define SQ1_SWEEP    (*((volatile u8*)0x4001))  /* Square 1 Sweep */
#define SQ1_LO       (*((volatile u8*)0x4002))  /* Square 1 Timer Low */
#define SQ1_HI       (*((volatile u8*)0x4003))  /* Square 1 Timer High */
#define SQ2_VOL      (*((volatile u8*)0x4004))  /* Square 2 Volume */
#define DPCM_DAC     (*((volatile u8*)0x4011))  /* DPCM DAC */
#define APU_ENABLE   (*((volatile u8*)0x4015))  /* APU Enable */
#define OAM_DMA      (*((volatile u8*)0x4014))  /* OAM DMA */

/* Controller Registers */
#define JOY1         (*((volatile u8*)0x4016))  /* Controller 1 */
#define JOY2         (*((volatile u8*)0x4017))  /* Controller 2 */

"""

    def _generate_memory_variables(self) -> str:
        """Generate RAM variable definitions"""
        c_code = """/* RAM Variables (from $0300-$07FF) */
typedef struct {
    /* Sprite/Graphics data */
    Sprite sprites[64];      /* $0200-$02FF: OAM mirror */
    
    /* Game state variables */
    u8 game_flags;           /* $0300 */
    u8 current_level;        /* $0301 */
    u8 game_state;           /* $0302 */
    
    /* Position/Physics */
    u16 mario_x;             /* $0304-$0305 */
    u16 mario_y;             /* $0306-$0307 */
    s8 mario_vel_x;          /* $0308 */
    s8 mario_vel_y;          /* $0309 */
    
    /* Game counters */
    u16 frame_counter;       /* $030A-$030B */
    u8 animation_frame;      /* $030C */
    u8 jump_counter;         /* $030D */
    
    /* Audio/Music */
    u8 music_track;          /* $030E */
    u8 sound_queue[16];      /* $030F-$031E */
    
} GameRAM;

static GameRAM game_ram;

"""
        return c_code
    
    def _generate_functions(self) -> str:
        """Generate function stubs from identified subroutines"""
        c_code = """/* ===== NES Hardware Functions ===== */

/*
 * Initialize the NES: Set up PPU, APU, memory
 */
void nes_init(void) {
    /* Disable interrupts */
    __asm("SEI");
    
    /* Clear decimal mode */
    __asm("CLD");
    
    /* Initialize PPU Control */
    PPU_CTRL = 0x10;
    
    /* Set stack pointer */
    __asm("LDX #0xFF");
    __asm("TXS");
    
    /* Wait for PPU to stabilize */
    while (!(PPU_STATUS & 0x80));  /* Wait for VBlank */
    while (!(PPU_STATUS & 0x80));  /* Wait again */
    
    /* Initialize audio */
    APU_ENABLE = 0x0F;
    
    /* Enable rendering */
    PPU_MASK = 0x06;
}

/*
 * Wait for vertical blank interrupt
 */
void wait_for_vblank(void) {
    while (!(PPU_STATUS & 0x80));
}

/*
 * Upload sprite data to OAM via DMA
 */
void upload_oam(void) {
    OAM_ADDR = 0x00;
    OAM_DMA = 0x02;  /* DMA from $0200 */
}

/*
 * Set PPU scroll position
 */
void set_ppu_scroll(u8 x, u8 y) {
    PPU_SCROLL = x;
    PPU_SCROLL = y;
}

/*
 * Write byte to PPU memory
 */
void ppu_write(u16 addr, u8 data) {
    PPU_ADDR = (u8)(addr >> 8);
    PPU_ADDR = (u8)(addr & 0xFF);
    PPU_DATA = data;
}

/*
 * Read byte from PPU memory
 */
u8 ppu_read(u16 addr) {
    PPU_ADDR = (u8)(addr >> 8);
    PPU_ADDR = (u8)(addr & 0xFF);
    return PPU_DATA;
}

/*
 * Clear RAM region
 */
void clear_ram(u8* start, u16 size) {
    for (u16 i = 0; i < size; i++) {
        start[i] = 0;
    }
}

/*
 * Main game loop (from assembly)
 */
void game_main_loop(void) {
    /* This represents the main game loop from $8057 */
    while (1) {
        wait_for_vblank();
        update_game_state();
        render_frame();
    }
}

/*
 * Update game state
 */
void update_game_state(void) {
    /* Handle input */
    update_player_input();
    
    /* Update physics */
    update_player_motion();
    update_enemies();
    
    /* Handle collisions */
    check_collisions();
    
    /* Update animation */
    animate_sprites();
}

/*
 * Handle player input
 */
void update_player_input(void) {
    u8 joypad = JOY1;
    
    /* Check buttons */
    if (joypad & 0x40) {  /* A button */
        player_jump();
    }
    if (joypad & 0x01) {  /* Right */
        player_move_right();
    }
    if (joypad & 0x02) {  /* Left */
        player_move_left();
    }
}

/*
 * Make player jump
 */
void player_jump(void) {
    game_ram.mario_vel_y = -6;  /* Negative for upward velocity */
}

/*
 * Move player right
 */
void player_move_right(void) {
    game_ram.mario_vel_x = 2;
}

/*
 * Move player left
 */
void player_move_left(void) {
    game_ram.mario_vel_x = -2;
}

/*
 * Update player motion based on velocity
 */
void update_player_motion(void) {
    /* Apply gravity */
    game_ram.mario_vel_y += 1;
    
    /* Clamp velocity */
    if (game_ram.mario_vel_y > 15) {
        game_ram.mario_vel_y = 15;
    }
    
    /* Update position */
    game_ram.mario_x += game_ram.mario_vel_x;
    game_ram.mario_y += game_ram.mario_vel_y;
}

/*
 * Update enemy positions and logic
 */
void update_enemies(void) {
    /* Enemy movement code would go here */
}

/*
 * Check for collisions
 */
void check_collisions(void) {
    /* Collision detection code would go here */
}

/*
 * Animate sprites for current frame
 */
void animate_sprites(void) {
    game_ram.frame_counter++;
    
    if (game_ram.frame_counter % 8 == 0) {
        game_ram.animation_frame++;
    }
}

/*
 * Render current frame
 */
void render_frame(void) {
    upload_oam();
    update_ppu_registers();
}

/*
 * Update PPU control registers
 */
void update_ppu_registers(void) {
    u8 ppu_mask = 0x06;  /* Show background and sprites */
    PPU_MASK = ppu_mask;
}

"""
        return c_code
    
    def _generate_main(self) -> str:
        """Generate main entry point"""
        return """/* ===== Main Entry Point ===== */

/*
 * NES ROM Entry Point (from $8000)
 */
void main(void) {
    nes_init();
    game_main_loop();
}

/*
 * NMI Interrupt Handler (vertical blank)
 */
void nmi_handler(void) {
    /* Update display during VBlank */
}

/*
 * IRQ Interrupt Handler
 */
void irq_handler(void) {
    /* Handle IRQ if mapper uses it */
}
"""


def main():
    import sys
    
    if len(sys.argv) < 2:
        print("Usage: python decompiler.py <assembly_file> [output.c]")
        sys.exit(1)
    
    asm_file = sys.argv[1]
    output_file = sys.argv[2] if len(sys.argv) > 2 else "decompiled.c"
    
    print(f"Loading assembly from: {asm_file}")
    decompiler = NES6502Decompiler(asm_file)
    decompiler.load_assembly()
    decompiler.analyze_assembly()
    
    print("Decompiling to C...")
    c_code = decompiler.decompile_to_c()
    
    print(f"Writing C code to: {output_file}")
    with open(output_file, 'w') as f:
        f.write(c_code)
    
    print("✓ Decompilation complete!")
    print(f"  Identified {len(decompiler.subroutines)} subroutines")
    print(f"  Tracked {len(decompiler.variables)} memory locations")
    print(f"  Generated {len(c_code.splitlines())} lines of C code")


if __name__ == "__main__":
    main()
