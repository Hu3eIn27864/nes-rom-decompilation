# NES ROM Disassembly Toolkit

A Python-based tool for disassembling NES ROM files to 6502 assembly code.

## Features

- **iNES Parser**: Extracts PRG-ROM and CHR-ROM from standard .nes files
- **6502 Disassembler**: Converts machine code to human-readable assembly
- **ROM Analysis**: Displays mapper info, ROM sizes, and hardware flags
- **Assembly Output**: Generates labeled .asm files with full disassembly

## Installation

1. Install Python 3.8 or higher
2. Install dependencies:
   ```bash
   pip install -r requirements.txt
   ```

## Usage

### Basic Disassembly

```bash
python tools/disassemble_rom.py roms/yourrom.nes
```

### Custom Output Directory

```bash
python tools/disassemble_rom.py roms/yourrom.nes --output my_output/
```

## Output Files

The disassembler generates:
- `prg_rom.asm` - Complete PRG-ROM disassembly with addresses and opcodes
- `metadata.asm` - ROM metadata and header information

## Project Structure

```
.
├── tools/
│   ├── ines_parser.py      # ROM file parser
│   ├── disassembler.py     # 6502 disassembler
│   └── disassemble_rom.py  # Main entry point
├── roms/                    # Place .nes files here
├── output/                  # Generated assembly files
└── requirements.txt         # Python dependencies
```

## Example

```bash
$ python tools/disassemble_rom.py roms/SuperMarioBros.nes
[*] Parsing ROM: roms/SuperMarioBros.nes
[+] ROM Info:
    PRG-ROM: 32 KB
    CHR-ROM: 8 KB
    Mapper: 0
    Mirroring: Vertical
    Battery: False

[*] Disassembling PRG-ROM...
[+] PRG-ROM assembly saved to: output/prg_rom.asm
    Lines: 8192

[+] Disassembly complete!
```

## Notes

- This tool handles standard iNES format ROMs (mapper 0 and others)
- Disassembly accuracy depends on proper code/data separation
- Bank switching and complex overlays require manual annotation
- 6502 opcode table includes most common instructions

## Legal Notice

This tool is for educational and preservation purposes. Ensure you have legal rights to disassemble any ROMs you work with.
