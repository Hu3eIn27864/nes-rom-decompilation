# NES Emulator Setup & Usage Guide

## Issues Found & Fixed ✅

### 1. **Corrupted ROM: `decompiled_reassembled_recompiled.nes`**
   - ❌ This file is corrupted (contains ANSI-colored hex text instead of binary)
   - Only `reassembled_CORRECT.nes` has a valid iNES header
   - **Action**: Regenerate this file using your disassembly/recompilation tools

### 2. **HTTP Server Requirement**
   - ❌ The emulator uses `fetch()` API which requires HTTP protocol
   - ❌ Opening as `file:///...` will fail with CORS errors
   - ✅ Fixed: Enhanced error messages explaining this issue

### 3. **Emulator Limitations**
   - The current emulator visualizes ROM data but doesn't execute 6502 code
   - It validates iNES headers and shows ROM metadata

## How to Run the Emulator

### Option 1: Using the Start Script (Recommended)
```bash
./start_emulator.sh
```
Then open your browser to: **http://localhost:8000/emulator.html**

### Option 2: Manual HTTP Server
```bash
python3 -m http.server 8000 --bind 127.0.0.1
```
Then open: **http://localhost:8000/emulator.html**

## Using the Emulator

1. **Load a ROM**:
   - Click "Load Original ROM" to load `reassembled_CORRECT.nes` (works ✅)
   - Click "Load Recompiled ROM" will fail (file is corrupted ❌)
   - Or manually select with "Load ROM" button

2. **ROM Information**:
   - Displays iNES header validation
   - Shows PRG (program) and CHR (character) ROM sizes
   - Lists mapper and mirroring mode

3. **Emulation**:
   - Click "▶️ Start" to begin visualization
   - Displays ROM data as pixel patterns
   - Shows real-time FPS counter

## Fixing the Corrupted ROM

The file `output/decompiled_reassembled_recompiled.nes` needs to be regenerated:

```bash
# Check which tool created it originally
ls -la output/ | grep decompiled_reassembled

# Run recompilation tool
python tools/recompile_rom.py output/decompiled_reassembled.asm
```

## Validation Results

| ROM File | Status | Details |
|----------|--------|---------|
| `reassembled_CORRECT.nes` | ✅ Valid | iNES header OK, 32KB PRG, 8KB CHR |
| `decompiled_reassembled_recompiled.nes` | ❌ Corrupted | Contains ASCII hex with ANSI codes, not binary |

## Troubleshooting

| Error | Solution |
|-------|----------|
| "Failed to load ROM" | Make sure server is running (`http://` not `file://`) |
| "Invalid iNES header" | ROM file is corrupted, needs regeneration |
| CORS error in console | You're opening via `file://` - use HTTP server instead |
| Blank canvas | ROM loaded but emulation requires 6502 CPU emulation implementation |

## Next Steps

1. **Start the HTTP server** (see instructions above)
2. **Fix the corrupted ROM** by regenerating it
3. **Implement full NES emulation** (optional - current version only visualizes data)
