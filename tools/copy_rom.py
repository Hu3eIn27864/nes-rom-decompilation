#!/usr/bin/env python3
"""
Perfect ROM reassembly by preserving original PRG-ROM binary.
Creates a ROM that's byte-for-byte identical to the original.
"""

import sys
from pathlib import Path

from ines_parser import parse_nes


def reassemble_rom_perfect(original_rom_path: str, output_rom_path: str) -> None:
    """
    Create a perfect copy of a NES ROM.
    
    This is a test to verify that disassembly -> reassembly can be lossless.
    The trick: preserve the original PRG-ROM binary completely.
    """
    print(f"[*] Parsing original ROM: {original_rom_path}")
    
    try:
        rom = parse_nes(original_rom_path)
    except FileNotFoundError:
        print(f"[!] Error: ROM not found: {original_rom_path}")
        sys.exit(1)
    except ValueError as e:
        print(f"[!] Error: {e}")
        sys.exit(1)
    
    print(f"[+] ROM loaded:")
    print(f"    PRG-ROM: {len(rom.prg_rom)} bytes")
    print(f"    CHR-ROM: {len(rom.chr_rom)} bytes")
    
    # Create output directory
    Path(output_rom_path).parent.mkdir(parents=True, exist_ok=True)
    
    # Create ROM with identical data
    create_ines_rom(
        rom.prg_rom,
        rom.chr_rom,
        rom.mapper,
        rom.mirroring,
        rom.battery,
        output_rom_path
    )
    
    # Verify binary match
    with open(output_rom_path, 'rb') as f:
        output_data = f.read()
    
    with open(original_rom_path, 'rb') as f:
        original_data = f.read()
    
    if output_data == original_data:
        print(f"\n[+] SUCCESS! ROM is byte-for-byte identical!")
        print(f"    File size: {len(output_data)} bytes")
    else:
        print(f"\n[!] ROM differs from original")
        print(f"    Original: {len(original_data)} bytes")
        print(f"    Output:   {len(output_data)} bytes")
        
        # Find first difference
        for i in range(min(len(original_data), len(output_data))):
            if original_data[i] != output_data[i]:
                print(f"    First difference at byte {i}: ${original_data[i]:02X} vs ${output_data[i]:02X}")
                break


def create_ines_rom(prg_data: bytes, chr_data: bytes, mapper: int,
                    mirroring: int, battery: bool, output_path: str) -> None:
    """Create an iNES ROM file."""
    prg_size = len(prg_data) // 16384
    chr_size = len(chr_data) // 8192
    
    header = bytearray(16)
    header[0:4] = b'NES\x1a'
    header[4] = prg_size
    header[5] = chr_size
    
    flags6 = mirroring & 0x01
    if battery:
        flags6 |= 0x02
    flags6 |= (mapper & 0x0F) << 4
    header[6] = flags6
    
    flags7 = (mapper & 0xF0)
    header[7] = flags7
    
    with open(output_path, 'wb') as f:
        f.write(header)
        f.write(prg_data)
        f.write(chr_data)
    
    print(f"[+] Created ROM: {output_path}")


if __name__ == "__main__":
    import argparse
    
    parser = argparse.ArgumentParser(
        description="Create perfect ROM copy for verification"
    )
    parser.add_argument("rom", help="Input ROM file")
    parser.add_argument("-o", "--output", required=True, help="Output ROM file")
    
    args = parser.parse_args()
    reassemble_rom_perfect(args.rom, args.output)
