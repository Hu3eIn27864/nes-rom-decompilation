"""
iNES ROM file parser.
Extracts PRG-ROM and CHR-ROM data from standard NES ROM files.
"""

import struct
from pathlib import Path
from dataclasses import dataclass


@dataclass
class iNES:
    """Represents an iNES format ROM file."""
    prg_rom: bytes  # Program ROM (6502 code)
    chr_rom: bytes  # Character ROM (graphics)
    prg_size: int   # PRG-ROM size in 16KB units
    chr_size: int   # CHR-ROM size in 8KB units
    mapper: int     # Mapper number
    mirroring: int  # 0=horizontal, 1=vertical
    battery: bool   # Has battery-backed RAM


def parse_nes(rom_path: str) -> iNES:
    """
    Parse an iNES format ROM file.
    
    Args:
        rom_path: Path to .nes file
        
    Returns:
        iNES object with extracted ROM data
    """
    with open(rom_path, 'rb') as f:
        header = f.read(16)
    
    # Verify iNES header
    if header[:4] != b'NES\x1a':
        raise ValueError("Invalid iNES ROM file")
    
    prg_size = header[4]  # 16KB units
    chr_size = header[5]  # 8KB units
    flags6 = header[6]
    flags7 = header[7]
    
    mapper = ((flags7 & 0xF0) << 4) | ((flags6 & 0xF0) >> 4)
    mirroring = flags6 & 0x01
    battery = bool(flags6 & 0x02)
    
    # Read PRG-ROM
    with open(rom_path, 'rb') as f:
        f.seek(16)
        prg_rom = f.read(prg_size * 16384)
        chr_rom = f.read(chr_size * 8192)
    
    return iNES(
        prg_rom=prg_rom,
        chr_rom=chr_rom,
        prg_size=prg_size,
        chr_size=chr_size,
        mapper=mapper,
        mirroring=mirroring,
        battery=battery
    )


def save_assembly(asm_code: str, output_path: str):
    """Save assembly code to file."""
    with open(output_path, 'w') as f:
        f.write(asm_code)
