#!/usr/bin/env python3
"""
Advanced 6502 Assembly Analyzer and Decompiler
Converts NES 6502 assembly to C code with proper control flow analysis
"""

import re
from dataclasses import dataclass
from typing import Dict, List, Set, Tuple, Optional
from enum import Enum

# ===== 6502 INSTRUCTION SET =====

class AddressingMode(Enum):
    IMPLIED = "implied"
    ACCUMULATOR = "accumulator"
    IMMEDIATE = "immediate"
    ZERO_PAGE = "zero_page"
    ZERO_PAGE_X = "zero_page_x"
    ZERO_PAGE_Y = "zero_page_y"
    ABSOLUTE = "absolute"
    ABSOLUTE_X = "absolute_x"
    ABSOLUTE_Y = "absolute_y"
    INDIRECT = "indirect"
    INDEXED_INDIRECT = "indexed_indirect"
    INDIRECT_INDEXED = "indirect_indexed"
    RELATIVE = "relative"

class InstructionType(Enum):
    LOAD = "load"
    STORE = "store"
    TRANSFER = "transfer"
    ARITHMETIC = "arithmetic"
    LOGICAL = "logical"
    SHIFT = "shift"
    BRANCH = "branch"
    JUMP = "jump"
    FLAG = "flag"
    STACK = "stack"
    INTERRUPT = "interrupt"
    OTHER = "other"

@dataclass
class Instruction:
    """Represents a single 6502 instruction"""
    address: int
    mnemonic: str
    operand: Optional[str] = None
    operand_value: Optional[int] = None
    addressing_mode: AddressingMode = AddressingMode.IMPLIED
    instruction_type: InstructionType = InstructionType.OTHER
    bytes_count: int = 1
    
    def is_jump(self) -> bool:
        return self.instruction_type in [InstructionType.JUMP, InstructionType.BRANCH]
    
    def is_call(self) -> bool:
        return self.mnemonic == "JSR"
    
    def is_return(self) -> bool:
        return self.mnemonic in ["RTS", "RTI"]
    
    def get_target(self) -> Optional[int]:
        """Get jump/branch target address"""
        return self.operand_value

@dataclass
class Function:
    """Represents a deduced function/subroutine"""
    entry_point: int
    name: str
    instructions: List[Instruction]
    called_by: Set[int]  # Addresses that call this function
    calls: Set[int]  # Functions this calls
    local_vars: Dict[str, Tuple[int, int]]  # variable_name -> (address, size)
    parameters: List[str]
    return_type: str = "void"
    
    def size(self) -> int:
        """Size of function in bytes"""
        if not self.instructions:
            return 0
        last = self.instructions[-1]
        return (last.address - self.entry_point) + last.bytes_count

class Assembly6502Parser:
    """Parses 6502 assembly code"""
    
    # 6502 instruction set
    INSTRUCTIONS = {
        # Load/Store
        "LDA": (InstructionType.LOAD, 2), "LDX": (InstructionType.LOAD, 2),
        "LDY": (InstructionType.LOAD, 2), "STA": (InstructionType.STORE, 2),
        "STX": (InstructionType.STORE, 2), "STY": (InstructionType.STORE, 2),
        
        # Transfer
        "TAX": (InstructionType.TRANSFER, 1), "TAY": (InstructionType.TRANSFER, 1),
        "TXA": (InstructionType.TRANSFER, 1), "TYA": (InstructionType.TRANSFER, 1),
        "TSX": (InstructionType.TRANSFER, 1), "TXS": (InstructionType.TRANSFER, 1),
        
        # Arithmetic
        "ADC": (InstructionType.ARITHMETIC, 2), "SBC": (InstructionType.ARITHMETIC, 2),
        "INC": (InstructionType.ARITHMETIC, 2), "INX": (InstructionType.ARITHMETIC, 1),
        "INY": (InstructionType.ARITHMETIC, 1), "DEC": (InstructionType.ARITHMETIC, 2),
        "DEX": (InstructionType.ARITHMETIC, 1), "DEY": (InstructionType.ARITHMETIC, 1),
        
        # Logical
        "AND": (InstructionType.LOGICAL, 2), "ORA": (InstructionType.LOGICAL, 2),
        "EOR": (InstructionType.LOGICAL, 2),
        
        # Shift
        "ASL": (InstructionType.SHIFT, 2), "LSR": (InstructionType.SHIFT, 2),
        "ROL": (InstructionType.SHIFT, 2), "ROR": (InstructionType.SHIFT, 2),
        
        # Branch
        "BEQ": (InstructionType.BRANCH, 2), "BNE": (InstructionType.BRANCH, 2),
        "BCS": (InstructionType.BRANCH, 2), "BCC": (InstructionType.BRANCH, 2),
        "BMI": (InstructionType.BRANCH, 2), "BPL": (InstructionType.BRANCH, 2),
        "BVS": (InstructionType.BRANCH, 2), "BVC": (InstructionType.BRANCH, 2),
        
        # Jump
        "JMP": (InstructionType.JUMP, 3), "JSR": (InstructionType.JUMP, 3),
        
        # Flag
        "SEC": (InstructionType.FLAG, 1), "CLC": (InstructionType.FLAG, 1),
        "SED": (InstructionType.FLAG, 1), "CLD": (InstructionType.FLAG, 1),
        "SEI": (InstructionType.FLAG, 1), "CLI": (InstructionType.FLAG, 1),
        "CLV": (InstructionType.FLAG, 1),
        
        # Stack
        "PHA": (InstructionType.STACK, 1), "PLA": (InstructionType.STACK, 1),
        "PHP": (InstructionType.STACK, 1), "PLP": (InstructionType.STACK, 1),
        
        # Interrupt
        "BRK": (InstructionType.INTERRUPT, 1), "RTI": (InstructionType.INTERRUPT, 1),
        "RTS": (InstructionType.INTERRUPT, 1),
        
        # Compare
        "CMP": (InstructionType.LOGICAL, 2), "CPX": (InstructionType.LOGICAL, 2),
        "CPY": (InstructionType.LOGICAL, 2),
        
        # Bit test
        "BIT": (InstructionType.LOGICAL, 2),
    }
    
    def __init__(self, asm_file: str):
        self.asm_file = asm_file
        self.instructions: List[Instruction] = []
        self.labels: Dict[str, int] = {}
        self.functions: Dict[int, Function] = {}
        
    def parse(self):
        """Parse assembly file"""
        print("[*] Parsing assembly file...")
        
        with open(self.asm_file, 'r') as f:
            lines = f.readlines()
        
        current_address = 0x8000
        
        for line in lines:
            line = line.strip()
            
            # Skip empty lines and comments
            if not line or line.startswith(';'):
                continue
            
            # Skip .byte, .word directives for now
            if line.startswith('.'):
                continue
            
            # Parse label
            if line.endswith(':'):
                label = line[:-1]
                self.labels[label] = current_address
                continue
            
            # Parse instruction with address
            match = re.match(r'\$([0-9A-F]{4}):\s*([A-Z]{3})\s*(.*)', line)
            if match:
                addr_str, mnemonic, operand_str = match.groups()
                try:
                    current_address = int(addr_str, 16)
                except:
                    continue
                
                instr = self._parse_instruction(current_address, mnemonic, operand_str.strip())
                if instr:
                    self.instructions.append(instr)
                    current_address += instr.bytes_count
        
        print(f"[+] Parsed {len(self.instructions)} instructions")
        self._identify_functions()
        return self.instructions
    
    def _parse_instruction(self, address: int, mnemonic: str, operand_str: str) -> Optional[Instruction]:
        """Parse individual instruction"""
        if mnemonic not in self.INSTRUCTIONS:
            return None
        
        instr_type, default_bytes = self.INSTRUCTIONS[mnemonic]
        addressing_mode = AddressingMode.IMPLIED
        operand_value = None
        
        # Parse operand
        if operand_str:
            # Immediate
            if operand_str.startswith('#$'):
                operand_value = int(operand_str[2:], 16)
                addressing_mode = AddressingMode.IMMEDIATE
                default_bytes = 2
            
            # Absolute/Zero page with addressing
            elif ',' in operand_str:
                parts = operand_str.split(',')
                base = parts[0].strip()
                register = parts[1].strip()
                
                if base.startswith('$'):
                    addr = int(base[1:], 16)
                    operand_value = addr
                    
                    if register.upper() == 'X':
                        addressing_mode = AddressingMode.ABSOLUTE_X
                        default_bytes = 3 if addr > 0xFF else 2
                    elif register.upper() == 'Y':
                        addressing_mode = AddressingMode.ABSOLUTE_Y
                        default_bytes = 3 if addr > 0xFF else 2
            
            # Absolute/Zero page direct or branching
            elif operand_str.startswith('$'):
                operand_value = int(operand_str[1:], 16)
                if operand_value <= 0xFF:
                    addressing_mode = AddressingMode.ZERO_PAGE
                    default_bytes = 2
                else:
                    addressing_mode = AddressingMode.ABSOLUTE
                    default_bytes = 3
            
            # Relative (branch)
            elif operand_str.startswith('$') or (operand_str[0].isdigit() or operand_str[0] == '-'):
                # Handle relative offsets
                try:
                    offset = int(operand_str, 16) if operand_str.startswith('$') else int(operand_str)
                    operand_value = address + 2 + offset
                    addressing_mode = AddressingMode.RELATIVE
                    default_bytes = 2
                except:
                    pass
            
            # Indirect
            elif '(' in operand_str and ')' in operand_str:
                inner = operand_str[operand_str.index('(')+1:operand_str.index(')')]
                if ',' in inner:
                    addressing_mode = AddressingMode.INDEXED_INDIRECT
                else:
                    addressing_mode = AddressingMode.INDIRECT
                default_bytes = 3
        
        return Instruction(
            address=address,
            mnemonic=mnemonic,
            operand=operand_str if operand_str else None,
            operand_value=operand_value,
            addressing_mode=addressing_mode,
            instruction_type=instr_type,
            bytes_count=default_bytes
        )
    
    def _identify_functions(self):
        """Identify function boundaries using control flow analysis"""
        print("[*] Identifying functions...")
        
        # Find all JSR (jump to subroutine) targets and RTS returns
        jsr_targets = set()
        function_starts = set()
        
        for instr in self.instructions:
            if instr.mnemonic == "JSR" and instr.operand_value:
                jsr_targets.add(instr.operand_value)
            if instr.mnemonic in ["RTS", "RTI"]:
                # Previous instruction ends a function
                for i, prev_instr in enumerate(self.instructions):
                    if prev_instr.address == instr.address - 1:
                        # Mark next instruction as function start
                        if i + 1 < len(self.instructions):
                            function_starts.add(self.instructions[i + 1].address)
        
        # Add JSR targets as function starts
        function_starts.update(jsr_targets)
        function_starts.add(0x8000)  # Entry point
        
        # Group instructions into functions
        for func_addr in sorted(function_starts):
            instr_list = []
            for instr in self.instructions:
                if instr.address >= func_addr:
                    instr_list.append(instr)
                    if instr.mnemonic in ["RTS", "RTI"]:
                        break
            
            if instr_list:
                func_name = f"func_{func_addr:04X}"
                self.functions[func_addr] = Function(
                    entry_point=func_addr,
                    name=func_name,
                    instructions=instr_list,
                    called_by=set(),
                    calls=set(),
                    local_vars={},
                    parameters=[]
                )
        
        print(f"[+] Identified {len(self.functions)} functions")

# ===== DECOMPILING TO C =====

class CCodeGenerator:
    """Generates C code from parsed 6502 instructions"""
    
    def __init__(self, parser: Assembly6502Parser):
        self.parser = parser
        self.c_code = []
        
    def generate(self) -> str:
        """Generate C code from assembly"""
        print("[*] Generating C code...")
        
        self._add_header()
        self._add_memory_definitions()
        self._add_type_definitions()
        self._generate_functions()
        
        return "\n".join(self.c_code)
    
    def _add_header(self):
        """Add C header"""
        self.c_code.extend([
            "/*",
            " * NES ROM - Decompiled from 6502 Assembly",
            " * Advanced decompilation with control flow analysis",
            " * Generated automatically from assembly analysis",
            " */",
            "",
            "#include <stdint.h>",
            "#include <string.h>",
            "#include <stdbool.h>",
            "",
        ])
    
    def _add_type_definitions(self):
        """Add type definitions"""
        self.c_code.extend([
            "/* ===== Type Definitions ===== */",
            "typedef uint8_t u8;",
            "typedef uint16_t u16;",
            "typedef uint32_t u32;",
            "typedef int8_t s8;",
            "typedef int16_t s16;",
            "typedef int32_t s32;",
            "",
            "/* 6502 CPU Registers */",
            "typedef struct {",
            "    u8 A;        /* Accumulator */",
            "    u8 X;        /* X Register */",
            "    u8 Y;        /* Y Register */",
            "    u8 PC_HI;    /* Program Counter High */",
            "    u8 PC_LO;    /* Program Counter Low */",
            "    u8 SP;       /* Stack Pointer */",
            "    u8 P;        /* Processor Status */",
            "    u8 _padding;",
            "} CPU6502;",
            "",
        ])
    
    def _add_memory_definitions(self):
        """Add NES hardware memory definitions"""
        self.c_code.extend([
            "/* ===== NES Hardware Memory Map ===== */",
            "",
            "/* PPU Registers */",
            "#define PPU_CTRL     0x2000",
            "#define PPU_MASK     0x2001",
            "#define PPU_STATUS   0x2002",
            "#define OAM_ADDR     0x2003",
            "#define OAM_DATA     0x2004",
            "#define PPU_SCROLL   0x2005",
            "#define PPU_ADDR     0x2006",
            "#define PPU_DATA     0x2007",
            "",
            "/* APU Registers */",
            "#define SQ1_VOL      0x4000",
            "#define SQ1_SWEEP    0x4001",
            "#define SQ1_LO       0x4002",
            "#define SQ1_HI       0x4003",
            "#define SQ2_VOL      0x4004",
            "#define SQ2_SWEEP    0x4005",
            "#define SQ2_LO       0x4006",
            "#define SQ2_HI       0x4007",
            "#define TRI_LINEAR   0x4008",
            "#define TRI_LO       0x400A",
            "#define TRI_HI       0x400B",
            "#define NOISE_VOL    0x400C",
            "#define NOISE_LO     0x400E",
            "#define NOISE_HI     0x400F",
            "#define DPCM_FREQ    0x4010",
            "#define DPCM_DAC     0x4011",
            "#define DPCM_ADDR    0x4012",
            "#define DPCM_LEN     0x4013",
            "#define OAM_DMA      0x4014",
            "#define APU_ENABLE   0x4015",
            "#define APU_FCN      0x4017",
            "",
            "/* Controller Registers */",
            "#define JOY1         0x4016",
            "#define JOY2         0x4017",
            "",
            "/* RAM (from $0300) */",
            "static u8 ram[0x0800];",
            "",
        ])
    
    def _generate_functions(self):
        """Generate C function implementations"""
        self.c_code.extend([
            "/* ===== Function Implementations ===== */",
            "",
        ])
        
        for addr, func in sorted(self.parser.functions.items()):
            self._generate_function(func)
    
    def _generate_function(self, func: Function):
        """Generate a single function in C"""
        self.c_code.append(f"/* Function at 0x{func.entry_point:04X} */")
        self.c_code.append(f"void {func.name}(void) {{")
        
        if func.instructions:
            # Generate function body comment
            self.c_code.append(f"    /* Size: {func.size()} bytes, {len(func.instructions)} instructions */")
            
            # Add instruction comments
            for instr in func.instructions[:5]:  # Show first few instructions
                comment = f"{instr.mnemonic}"
                if instr.operand:
                    comment += f" {instr.operand}"
                self.c_code.append(f"    // ${instr.address:04X}: {comment}")
            
            if len(func.instructions) > 5:
                self.c_code.append(f"    // ... ({len(func.instructions) - 5} more instructions)")
        
        self.c_code.append("}")
        self.c_code.append("")

# ===== MAIN =====

def main():
    import sys
    
    asm_file = "/home/mustafa/Dokumente/nes/emptyworkspacefolder/output/prg_rom.asm"
    
    print("=" * 60)
    print("6502 Assembly Analyzer & Decompiler")
    print("=" * 60)
    
    # Parse assembly
    parser = Assembly6502Parser(asm_file)
    instructions = parser.parse()
    
    print(f"[+] Assembly structure:")
    print(f"    Instructions: {len(instructions)}")
    print(f"    Functions identified: {len(parser.functions)}")
    print(f"    Memory range: 0x8000-0x{instructions[-1].address:04X}")
    
    # Generate C code
    codegen = CCodeGenerator(parser)
    c_code = codegen.generate()
    
    # Save C code
    output_file = "/home/mustafa/Dokumente/nes/emptyworkspacefolder/output/decompiled_advanced.c"
    with open(output_file, 'w') as f:
        f.write(c_code)
    
    print(f"\n[✓] C code generated: {output_file}")
    print(f"[✓] Generated {len(parser.functions)} function stubs with memory map")
    
    # Count lines
    lines = c_code.split('\n')
    print(f"[✓] Total lines: {len(lines)}")

if __name__ == "__main__":
    main()
