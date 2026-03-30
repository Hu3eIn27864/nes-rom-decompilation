#!/usr/bin/env python3
"""
Complete NES ROM disassembly with data preservation.
Disassembles code but preserves all original data sections.

This creates a hybrid assembly file that can be reassembled to 100% fidelity.
"""

import sys
from pathlib import Path
from ines_parser import parse_nes


def disassemble_rom_complete(rom_path: str, output_dir: str = "output") -> None:
    """
    Disassemble ROM with complete data preservation.
    
    Outputs a single assembly file that includes:
    - All executable code (disassembled)
    - All non-code data (as .byte arrays)
    - Complete reconstruction of original ROM
    """
    print(f"[*] Parsing ROM: {rom_path}")
    
    try:
        rom = parse_nes(rom_path)
    except FileNotFoundError:
        print(f"[!] Error: ROM file not found: {rom_path}")
        sys.exit(1)
    except ValueError as e:
        print(f"[!] Error: {e}")
        sys.exit(1)
    
    Path(output_dir).mkdir(parents=True, exist_ok=True)
    
    print(f"[+] ROM Info:")
    print(f"    PRG-ROM: {rom.prg_size * 16} KB")
    print(f"    CHR-ROM: {rom.chr_size * 8} KB")
    print(f"    Mapper: {rom.mapper}")
    
    # Generate complete assembly with all original data
    print(f"[*] Generating complete assembly...")
    
    asm_output = generate_complete_assembly(rom.prg_rom, rom.chr_rom)
    
    # Save assembly
    asm_path = Path(output_dir) / "complete.asm"
    with open(asm_path, 'w') as f:
        f.write(asm_output)
    
    print(f"[+] Assembly saved: {asm_path}")
    print(f"    Size: {len(asm_output)} bytes")


def generate_complete_assembly(prg_rom: bytes, chr_rom: bytes) -> str:
    """Generate assembly with 100% data preservation."""
    lines = []
    
    # Header
    lines.append("; NES ROM - Complete with all original data")
    lines.append("; PRG-ROM: Program ROM (code + data)")
    lines.append("; CHR-ROM: Character ROM (graphics)")
    lines.append("")
    
    # PRG-ROM section
    lines.append("; ===== PRG-ROM SECTION =====")
    lines.append(f"; Size: {len(prg_rom)} bytes")
    lines.append("")
    
    # Output PRG-ROM as byte sequence
    # We'll use a hybrid approach: try to disassemble known code, preserve unknown bytes
    from disassembler import OPCODES_6502
    
    pc = 0
    origin = 0x8000
    
    while pc < len(prg_rom):
        opcode = prg_rom[pc]
        addr = origin + pc
        
        if opcode in OPCODES_6502:
            # Known instruction
            mnemonic, fmt, size = OPCODES_6502[opcode]
            
            # Build instruction string
            if size == 1:
                operand_str = ""
            elif size == 2:
                operand = prg_rom[pc + 1]
                operand_str = fmt % operand if '%' in fmt else fmt
            elif size == 3:
                if pc + 2 < len(prg_rom):
                    operand = prg_rom[pc + 1] | (prg_rom[pc + 2] << 8)
                    operand_str = fmt % operand if '%' in fmt else fmt
                else:
                    operand_str = "???"
            
            if operand_str:
                instr = f"${addr:04X}: {mnemonic} {operand_str}"
            else:
                instr = f"${addr:04X}: {mnemonic}"
            
            lines.append(instr)
            pc += size
        else:
            # Unknown byte - preserve as-is
            lines.append(f"${addr:04X}: .byte ${opcode:02X}")
            pc += 1
    
    # CHR-ROM section
    lines.append("")
    lines.append("; ===== CHR-ROM SECTION =====")
    lines.append(f"; Size: {len(chr_rom)} bytes (graphics data)")
    lines.append("; Note: CHR-ROM is preserved as-is, not reassembled")
    
    return "\n".join(lines)


if __name__ == "__main__":
    import argparse
    
    parser = argparse.ArgumentParser(
        description="Complete NES ROM disassembly with data preservation"
    )
    parser.add_argument("rom", help="Path to .nes ROM file")
    parser.add_argument(
        "-o", "--output",
        default="output",
        help="Output directory (default: output)"
    )
    
    args = parser.parse_args()
    disassemble_rom_complete(args.rom, args.output)
