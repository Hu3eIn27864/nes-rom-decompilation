# NES ROM Disassembly & Decompilation Project

This workspace provides tools for disassembling and analyzing NES ROMs at the 6502 assembly level.

## Key Tools
- **ines_parser.py**: Extracts ROM data from .nes files
- **disassembler.py**: Converts 6502 machine code to assembly
- **disassemble_rom.py**: Main entry point for ROM disassembly

## Workflow
1. Place your .nes ROM file in the `roms/` directory
2. Run: `python tools/disassemble_rom.py roms/yourrom.nes`
3. Output assembly files appear in `output/`

## Requirements
- Python 3.8+
- Dependencies listed in requirements.txt
