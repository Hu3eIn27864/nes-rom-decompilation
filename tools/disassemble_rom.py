#!/usr/bin/env python3
"""
Main NES ROM disassembly script.

Usage:
    python disassemble_rom.py <rom_path> [--output <dir>]

Example:
    python disassemble_rom.py roms/SuperMarioBros.nes --output output/
"""

import sys
import argparse
from pathlib import Path

from ines_parser import parse_nes, save_assembly
from disassembler import disassemble_6502


def disassemble_rom(rom_path: str, output_dir: str = "output") -> None:
    """
    Main function to disassemble an NES ROM.
    
    Args:
        rom_path: Path to .nes file
        output_dir: Directory to save output assembly files
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
    
    # Create output directory
    Path(output_dir).mkdir(parents=True, exist_ok=True)
    
    print(f"[+] ROM Info:")
    print(f"    PRG-ROM: {rom.prg_size * 16} KB")
    print(f"    CHR-ROM: {rom.chr_size * 8} KB")
    print(f"    Mapper: {rom.mapper}")
    print(f"    Mirroring: {'Vertical' if rom.mirroring else 'Horizontal'}")
    print(f"    Battery: {rom.battery}")
    
    # Disassemble PRG-ROM
    print(f"\n[*] Disassembling PRG-ROM...")
    prg_asm = disassemble_6502(rom.prg_rom, origin=0x8000)
    
    # Save to file
    prg_output = Path(output_dir) / "prg_rom.asm"
    asm_text = "\n".join(prg_asm)
    save_assembly(asm_text, str(prg_output))
    print(f"[+] PRG-ROM assembly saved to: {prg_output}")
    print(f"    Lines: {len(prg_asm)}")
    
    # Save metadata
    metadata = f"""
; NES ROM Disassembly
; Generated from: {Path(rom_path).name}
; PRG-ROM Size: {rom.prg_size * 16} KB
; CHR-ROM Size: {rom.chr_size * 8} KB
; Mapper: {rom.mapper}
; Mirroring: {'Vertical' if rom.mirroring else 'Horizontal'}

"""
    
    metadata_output = Path(output_dir) / "metadata.asm"
    with open(metadata_output, 'w') as f:
        f.write(metadata)
    
    print(f"\n[+] Disassembly complete!")
    print(f"    Output directory: {Path(output_dir).absolute()}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Disassemble NES ROMs to 6502 assembly"
    )
    parser.add_argument("rom", help="Path to .nes ROM file")
    parser.add_argument(
        "-o", "--output",
        default="output",
        help="Output directory (default: output)"
    )
    
    args = parser.parse_args()
    disassemble_rom(args.rom, args.output)
