# NES ROM Disassembly Toolkit

A Python toolkit for inspecting iNES ROM images, extracting PRG/CHR regions, producing 6502 assembly listings, and experimenting with reassembly and higher-level analysis.

> **Status: research prototype.** The repository contains several analysis and reassembly experiments plus a browser-based ROM-data visualizer. It is not currently a complete NES emulator or a verified source-level decompiler.

## What is included

- iNES parsing and ROM metadata inspection.
- 6502 instruction decoding and PRG-ROM assembly output.
- Experimental lossless disassembly and reassembly utilities.
- Additional decompiler/compiler experiments under `tools/`.
- Browser pages for inspecting ROM metadata and visualizing ROM bytes.

See [the output index](OUTPUT_FILES_INDEX.md) and [the emulator notes](EMULATOR_README.md) for details about generated artifacts and current browser limitations.

## Requirements

- Python 3.8 or newer.
- Python dependencies are currently minimal; inspect individual tool imports before installing optional packages.
- A modern browser and Python 3 for the local HTTP server used by the HTML visualizer.

## Quick start

Place a legally obtained ROM outside version control, then run:

```bash
python tools/disassemble_rom.py /path/to/game.nes --output output/
```

Start the browser visualizer from the repository root:

```bash
./start_emulator.sh
```

Open `http://localhost:8000/emulator.html`. The page currently visualizes ROM data; it does **not** execute 6502 instructions.

## Important limitations

- Disassembly is not equivalent to decompilation. Correct code/data separation, bank mapping, jump-table recovery and control-flow analysis remain open problems.
- Mapper support must be verified per tool; do not infer broad mapper compatibility from iNES parsing alone.
- Reassembly experiments need automated byte-for-byte comparison against known test fixtures before being described as lossless.
- The browser visualizer is not a cycle-accurate NES emulator.
- Generated output should be reproducible and clearly labeled by the exact tool and input hash.

## Development roadmap

See [docs/ROADMAP.md](docs/ROADMAP.md) for milestones, acceptance criteria and a time-based estimate. Estimates assume one developer working roughly 8–12 focused hours per week and will change as test coverage improves.

## Legal and repository hygiene

Use only ROMs you are legally entitled to analyze. Do not commit commercial ROM images, copyrighted game assets, or generated files containing substantial copyrighted ROM data. Keep local input ROMs outside Git and use synthetic fixtures or homebrew test ROMs for CI.

## Contributing

Please include:
- The exact command and tool used.
- Input format and mapper details (without attaching copyrighted ROMs).
- Expected versus actual output.
- A minimal synthetic fixture or a legally distributable homebrew test case where possible.
