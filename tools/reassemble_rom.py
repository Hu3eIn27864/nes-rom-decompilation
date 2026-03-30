#!/usr/bin/env python3
"""
NES ROM reassembly and repackaging tool.

Usage:
    python reassemble_rom.py <asm_file> <original_rom> <output_rom> [--metadata <metadata_file>]

Example:
    python reassemble_rom.py output/prg_rom.asm roms/original.nes output/modified.nes
"""

import sys
import argparse
from pathlib import Path

from ines_parser import parse_nes
from reassembler import reassemble_asm


def create_ines_rom(prg_data: bytes, chr_data: bytes, mapper: int, 
                    mirroring: int, battery: bool, output_path: str,
                    original_prg_size: int = None, original_chr_size: int = None) -> None:
    """
    Create an iNES ROM file from PRG and CHR data.
    
    Args:
        prg_data: PRG-ROM bytes
        chr_data: CHR-ROM bytes
        mapper: Mapper number
        mirroring: 0=horizontal, 1=vertical
        battery: Battery-backed RAM flag
        output_path: Output file path
        original_prg_size: PRG size in 16KB units (from original ROM if available)
        original_chr_size: CHR size in 8KB units (from original ROM if available)
    """
    # Calculate sizes (in 16KB and 8KB units)
    if original_prg_size is not None:
        prg_size = original_prg_size
    else:
        prg_size = len(prg_data) // 16384
    
    if original_chr_size is not None:
        chr_size = original_chr_size
    else:
        chr_size = len(chr_data) // 8192
    
    # Create header
    header = bytearray(16)
    header[0:4] = b'NES\x1a'
    header[4] = prg_size
    header[5] = chr_size
    
    # Flags 6
    flags6 = mirroring & 0x01
    if battery:
        flags6 |= 0x02
    flags6 |= (mapper & 0x0F) << 4
    header[6] = flags6
    
    # Flags 7
    flags7 = (mapper & 0xF0)
    header[7] = flags7
    
    # Write ROM file
    with open(output_path, 'wb') as f:
        f.write(header)
        f.write(prg_data)
        # Pad PRG-ROM to expected size if needed
        expected_prg_size = prg_size * 16384
        if len(prg_data) < expected_prg_size:
            padding = b'\x00' * (expected_prg_size - len(prg_data))
            f.write(padding)
        f.write(chr_data)
    
    print(f"[+] Created ROM: {output_path}")
    actual_prg_size = max(len(prg_data), prg_size * 16)
    print(f"    PRG-ROM: {len(prg_data)} bytes (header: {prg_size * 16} KB)")
    print(f"    CHR-ROM: {len(chr_data)} bytes ({chr_size * 8} KB)")


def reassemble_rom(asm_file: str, original_rom: str, output_rom: str) -> None:
    """
    Reassemble an NES ROM from disassembly.
    
    Args:
        asm_file: Path to .asm disassembly file
        original_rom: Path to original ROM (for metadata)
        output_rom: Path to output ROM file
    """
    print(f"[*] Reading disassembly: {asm_file}")
    
    try:
        with open(asm_file, 'r') as f:
            asm_code = f.read()
    except FileNotFoundError:
        print(f"[!] Error: Assembly file not found: {asm_file}")
        sys.exit(1)
    
    print(f"[*] Parsing original ROM: {original_rom}")
    try:
        original = parse_nes(original_rom)
    except FileNotFoundError:
        print(f"[!] Error: Original ROM not found: {original_rom}")
        sys.exit(1)
    except ValueError as e:
        print(f"[!] Error: {e}")
        sys.exit(1)
    
    print(f"[*] Reassembling PRG-ROM...")
    prg_code = reassemble_asm(asm_code)
    
    # Verify size matches
    if len(prg_code) != len(original.prg_rom):
        print(f"[!] Warning: Size mismatch!")
        print(f"    Original: {len(original.prg_rom)} bytes")
        print(f"    Reassembled: {len(prg_code)} bytes")
    
    # Create output ROM using ORIGINAL sizes for header
    # (disassembled data may lose a few bytes, but ROM size in header should match original)
    Path(output_rom).parent.mkdir(parents=True, exist_ok=True)
    create_ines_rom(
        prg_code,
        original.chr_rom,
        original.mapper,
        original.mirroring,
        original.battery,
        output_rom,
        original.prg_size,  # Use original PRG bank count
        original.chr_size   # Use original CHR bank count
    )
    
    print(f"\n[+] Reassembly complete!")
    print(f"    Output: {Path(output_rom).absolute()}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Reassemble NES ROMs from disassembly"
    )
    parser.add_argument("asm", help="Path to .asm disassembly file")
    parser.add_argument("original", help="Path to original .nes file")
    parser.add_argument(
        "-o", "--output",
        required=True,
        help="Output ROM file path"
    )
    
    args = parser.parse_args()
    reassemble_rom(args.asm, args.original, args.output)
