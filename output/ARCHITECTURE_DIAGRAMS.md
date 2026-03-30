# NES Decompilation Architecture Diagrams

## Overall Decompilation Pipeline

```
┌──────────────────────────────────────────────────────────────────┐
│                    NES ROM (.nes file)                           │
│         32 KB PRG-ROM (Program Code) + 8 KB CHR-ROM (Graphics)   │
└─────────────────────────────────────┬──────────────────────────┘
                                       │
┌──────────────────────────────────────▼──────────────────────────┐
│              ines_parser.py                                      │
│   Extract binary code from NES file format                       │
└─────────────────────────────────────┬──────────────────────────┘
                                       │
┌──────────────────────────────────────▼──────────────────────────┐
│              disassembler.py                                     │
│   Convert raw 6502 machine code to assembly (.asm)              │
│   - Parse opcodes                                                │
│   - Resolve addressing modes                                     │
│   - Generate labels                                              │
└─────────────────────────────────────┬──────────────────────────┘
                                       │
┌──────────────────────────────────────▼──────────────────────────┐
│              16,227 lines of 6502 Assembly                       │
│   (lossless.asm, prg_rom.asm, metadata.asm)                      │
└─────────────────────────────────────┬──────────────────────────┘
                                       │
┌──────────────────────────────────────▼──────────────────────────┐
│              decompiler.py                                       │
│   Convert assembly to high-level languages                       │
│   - Parse instructions                                           │
│   - Identify subroutines (369 found)                            │
│   - Track memory usage (947 locations)                           │
│   - Recognize hardware patterns                                  │
│   - Generate C/Python with comments                              │
└──────┬──────────────────────────────┬──────────────┬────────────┘
       │                              │              │
       ▼                              ▼              ▼
   ┌────────────┐             ┌──────────────┐  ┌─────────────┐
   │ C Output   │             │ Python Out   │  │ Documentation
   │ (322 lines)│             │ (350+ lines) │  │ (GUIDES)
   │            │             │              │  │
   │ - Hardware │             │ - Game Engine│  │ - Architecture
   │ - Registers│             │ - Classes    │  │ - Patterns
   │ - Structs  │             │ - Physics    │  │ - Memory Map
   └────────────┘             └──────────────┘  └─────────────┘
```

---

## NES Hardware Architecture

```
                        NES Motherboard (1983)
┌─────────────────────────────────────────────────────────────┐
│                                                              │
│  CPU (6502 @ 1.79 MHz)           APU (Audio)              │
│  ┌─────────────────┐         ┌──────────────┐             │
│  │ Registers       │         │ 5 Channels   │             │
│  │ A, X, Y, SP, PC │         │ SQ1, SQ2, TRI│             │
│  └──────┬──────────┘         │ NOISE, DPCM  │             │
│         │                     └──────────────┘             │
│         │                                                   │
│  RAM (2 KB) $0000-$07FF         PPU (Video)               │
│  ┌─────────────────┐         ┌──────────────┐             │
│  │ Zero Page       │         │ Rendering    │             │
│  │ Stack ($0100)   │         │ 256×240 pixel│             │
│  │ Game State      │         │ 60 FPS       │             │
│  └─────────────────┘         │ 4 colors/tile│             │
│                              └──────────────┘             │
│                                                            │
│  Controller Interface       Cartridge Slot               │
│  ┌─────────────────┐         ┌──────────────┐             │
│  │ 2 Joypads       │         │ PRG-ROM 32KB │             │
│  │ 8 Buttons each  │         │ CHR-ROM 8KB  │             │
│  └─────────────────┘         │ Mapper chip  │             │
│                              └──────────────┘             │
│                                                            │
└─────────────────────────────────────────────────────────────┘
         ▲                                      ▲
         │ Controller signals                  │ Video output
         │                                     ▼
    ┌──────────┐                        [TV Screen]
    │Joystick 1│
    └──────────┘
```

---

## Memory Map (16-bit address space)

```
Address    Size    Region          Purpose
───────────────────────────────────────────────────
$FFFF                             ┌─────────────────┐
  │                               │ PRG-ROM (16 KB) │
  │                    $E000-$FFFF│ (Bank 2)        │
  │                               └─────────────────┘
  │
  │                               ┌─────────────────┐
  │                    $C000-$DFFF│ PRG-ROM (16 KB) │
  │                               │ (Switchable)    │
  │                               └─────────────────┘
  │
  ├─ $8000                        ┌─────────────────┐
  │                    $8000-$BFFF│ PRG-ROM (16 KB) │
  │                               │ (Often fixed)   │
  │                               └─────────────────┘
  │
  ├─ $6000  SRAM                  ┌─────────────────┐
  │          (Battery-backed)  $6000-$7FFF│ Cartridge SRAM  │
  │                               │ (Mapper WRAM)   │
  │                               └─────────────────┘
  │
  ├─ $4020  Expansion ROM         ┌─────────────────┐
  │                    $4020-$5FFF│ Unused/Expansion│
  │                               └─────────────────┘
  │
  ├─ $4000  I/O Registers
  │                    $4000-$401F│ ┌──────────────┐
  │          APU        │ │
  │          Controller │ │
  │          OAM DMA    │ │
  │                               └──────────────┘
  │
  ├─ $2000  PPU I/O
  │          (Mirrored)   $2000-$3FFF│ ┌──────────────┐
  │                    │ │ PPU MMIO   │
  │                    │ │ (8 bytes)  │
  │                    │ └──────────────┘
  │
  ├─ $0200  OAM Mirror
  │          (Sprite RAM) │ $0200-$02FF│ ┌──────────────┐
  │                    │ │ 64 Sprites │
  │                    │ │ 256 bytes  │
  │                    │ └──────────────┘
  │
  ├─ $0100  Stack       │ $0100-$01FF│ ┌──────────────┐
  │                    │ │ CPU Stack  │
  │                    │ │ 256 bytes  │
  │                    │ └──────────────┘
  │
  └─ $0000  Zero Page   │ $0000-$00FF│ ┌──────────────┐
                        │ │ Fast RAM   │
  $0000                  │ │ 256 bytes  │
                        └──────────────┘
```

---

## Game Engine Architecture (Python)

```
┌───────────────────────────────────────────────────────┐
│                  GameEngine                           │
│                                                       │
│  ┌─────────────────────────────────────────┐         │
│  │ Public Methods                          │         │
│  │ - initialize()  → Set up NES            │         │
│  │ - load_level()  → Load map/sprites      │         │
│  │ - update()      → Game tick             │         │
│  │ - render()      → Draw frame            │         │
│  │ - run()         → Main loop             │         │
│  └────────┬────────────────────────────────┘         │
│           │                                           │
│  ┌────────▼────────────────────────────────┐         │
│  │ Private Components                      │         │
│  │                                          │         │
│  │ ┌──────────────┐ ┌──────────────┐      │         │
│  │ │ NESHardware  │ │ GameState    │      │         │
│  │ │ ├─ PPU       │ │ ├─ Sprites   │      │         │
│  │ │ ├─ APU       │ │ ├─ Player    │      │         │
│  │ │ ├─ Memory    │ │ ├─ Enemies   │      │         │
│  │ │ └─ I/O       │ │ └─ Score/Time│      │         │
│  │ └──────────────┘ └──────────────┘      │         │
│  │                                          │         │
│  │ ┌──────────────┐ ┌──────────────┐      │         │
│  │ │ Player       │ │ Enemy        │      │         │
│  │ │ GameObject   │ │ GameObject   │      │         │
│  │ │ ├─ Physics   │ │ ├─ AI        │      │         │
│  │ │ ├─ Animation │ │ ├─ Collision │      │         │
│  │ │ └─ Input     │ │ └─ Sprite    │      │         │
│  │ └──────────────┘ └──────────────┘      │         │
│  └─────────────────────────────────────────┘         │
│                                                       │
└───────────────────────────────────────────────────────┘
```

---

## Game Loop Execution Timeline

```
Frame 0-59 (60 FPS = ~16.67 ms per frame)

t=0 ms      ┌─────────────────┐
            │ wait_vblank()   │  Wait for PPU vertical blank
            │                 │  (PPU finishes rendering)
            └────────┬────────┘
                     │
                     ▼
t=1-2 ms    ┌─────────────────┐
            │ process_input() │  Read NES controller ($4016)
            │                 │  Store button state
            └────────┬────────┘
                     │
                     ▼
t=3-5 ms    ┌─────────────────┐
            │ update()        │  Update all game state
            │ ├─ Physics      │  - Apply gravity
            │ ├─ AI           │  - Move enemies
            │ ├─ Collision    │  - Check hits
            │ └─ Animation    │  - Advance frames
            └────────┬────────┘
                     │
                     ▼
t=6-8 ms    ┌─────────────────┐
            │ render()        │  Prepare screen
            │ ├─ Update OAM   │  - Update sprite positions
            │ ├─ Upload DMA   │  - DMA to PPU OAM
            │ └─ Set scroll   │  - Set camera position
            └────────┬────────┘
                     │
t=8-16 ms           │
     ┌───────────────▼──────────────┐
     │ (Idle/PPU rendering)         │
     │ While NES draws scanlines:   │
     │ - Tile lookup in CHR-ROM     │
     │ - Color palette translation  │
     │ - Sprite layer composition   │
     │ - Output to TV/Display       │
     └───────────────┬──────────────┘
                     │
t=16.67 ms          │
     ┌───────────────▼──────────────┐
     │ (Repeat for next frame)      │
     └──────────────────────────────┘
```

---

## Data Structures

### Sprite (OAM Entry)

```
Offset  Size   Field        Description
──────  ────   ──────────   ──────────────────────────
  +0    1 byte Y Coord      Y position on screen (0-239)
  +1    1 byte Tile ID      Pattern table index
  +2    1 byte Attributes   │ Palette│Flip│Flags
                            │ 76543210
                            └─────┬──┐  │   │
  +3    1 byte X Coord      7-6: Unused
                            5-4: Palette (0-3)
                            3: Sprite priority
                            2: Horizontal flip
                            1: Vertical flip  
                            0: Unused

Total: 4 bytes × 64 sprites = 256 bytes (OAM)
```

### Tile Format (8×8 pixels)

```
CHR-ROM Storage (8 KB total):
┌─ Pattern Table 0 ($0000-$0FFF)  4 KB
│  ┌─ Tiles 0-127 (256 tiles)
│  └─ Graphics data (each 2 bits/pixel)
│
└─ Pattern Table 1 ($1000-$1FFF)  4 KB
   └─ Tiles 128-255 (256 tiles)

Each tile is 16 bytes:
- Bytes 0-7:   Bit plane 0 (8 pixels × 1 bit)
- Bytes 8-15:  Bit plane 1 (8 pixels × 1 bit)

Color = (bit_plane_1 << 1) | bit_plane_0
Result: 0-3 (4 color palette)
```

### PPU Cycle

```
Visible Scanlines: 0-239 (240 pixels high)
VBlank Scanlines:  240-260 (21 scanlines)
Total: 262 scanlines/frame @ 60 Hz = 15.7 kHz horizontal frequency

Horizontal Blanks: 86 PPU cycles between scanlines
Visible Period:    256 PPU cycles per scanline

During VBlank:
- CPU can safely modify VRAM
- OAM DMA transfers can occur
- No rendering conflicts
- NMI interrupt fires once per VBlank
```

---

## 6502 Register State After nes_init()

```
┌─ Accumulator (A)       = 0x10
├─ X Register (X)        = 0xFF (stack pointer set)
├─ Y Register (Y)        = unchanged
├─ Stack Pointer (SP)    = 0xFF (top of stack)
├─ Program Counter (PC)  = 0x8046 (main loop)
│
└─ Processor Status (P)  [NV-BDIZC]
   ├─ N (Negative)       = 0
   ├─ V (Overflow)       = 0
   ├─ B (Break)          = 0
   ├─ D (Decimal)        = 0 (cleared by CLD)
   ├─ I (Interrupt)      = 1 (disabled by SEI)
   ├─ Z (Zero)           = 0
   └─ C (Carry)          = 0
```

---

## Class Hierarchy (Python)

```
object
│
└─ GameObject
   ├─ Player
   │  ├─ position: Vector2D
   │  ├─ velocity: Vector2D
   │  ├─ state: str
   │  ├─ direction: int
   │  └─ Methods: jump(), move_left/right(), apply_gravity()
   │
   └─ Enemy
      ├─ type: str
      ├─ animation_frame: int
      ├─ position: Vector2D
      ├─ velocity: Vector2D
      └─ Methods: update(), on_collision()

DataClasses:
├─ Sprite (OAM entry)
├─ Vector2D (2D math)
├─ GameState (game data)
└─ CPU6502 (register state)

Enums:
├─ PPUFlags
├─ ControllerButtons
└─ Addressing modes (implied, accumulator, etc.)
```

---

## Signal Flow: Input → Processing → Output

```
NES Controller
     │
     ▼
┌─────────────────┐
│  Read JOY1      │  $4016 input latch
│  ($4016)        │
└────────┬────────┘
         │
         ▼
   ┌──────────────┐
   │ Button State │  8-bit register
   │ ABLSUDLR     │
   └────────┬─────┘
            │
            ▼
   ┌──────────────────────┐
   │ process_input()      │
   │ ├─ if RIGHT: move   │
   │ ├─ if LEFT: move    │ Logic layer
   │ ├─ if A: jump       │
   │ └─ if B: attack     │
   └────────┬─────────────┘
            │
            ▼
   ┌──────────────────────┐
   │ update()             │
   │ ├─ apply_gravity()   │
   │ ├─ check_collisions()│ Physics layer
   │ ├─ update_enemies()  │
   │ └─ animate_sprites() │
   └────────┬─────────────┘
            │
            ▼
   ┌──────────────────────┐
   │ render()             │
   │ ├─ update_oam()      │
   │ ├─ dma_upload()      │ Rendering layer
   │ └─ set_scroll()      │
   └────────┬─────────────┘
            │
            ▼
   ┌──────────────────────┐
   │ Hardware Registers   │  Memory-mapped I/O
   │ ├─ $0200-$02FF: OAM  │
   │ ├─ $2005: Scroll     │
   │ └─ $4014: DMA Trigger│
   └────────┬─────────────┘
            │
            ▼
   ┌──────────────────────┐
   │ PPU (GPU)            │  Graphics processing
   │ Renders to frame     │
   │ buffer               │
   └────────┬─────────────┘
            │
            ▼
      [TV Screen]
```

---

## Interrupt Handling

```
NMI Interrupt (Non-Maskable, from PPU)
────────────────────────────────────────

┌─ Vertical Blank Detected (PPU)
│
├─ PC pushed to stack
├─ Status pushed to stack
├─ Jump to $FFFA/$FFFB (NMI vector)
│
└─→ [NMI Handler]
    ├─ Update game display
    ├─ Set flag for main loop
    └─ RTI (return from interrupt)

IRQ Interrupt (Maskable, optional from cartridge)
───────────────────────────────────────────────────

Can be blocked by I flag. Used by some mappers
for bank switching and timing.
```

---

## Performance Profile (Typical Frame)

```
Frame Time Budget: 16.67 ms (60 FPS)

Activity              Time    CPU Cycles
────────────────────────────────────────
Wait VBlank           ~2 ms   ~3,500 cycles
Input Processing      0.5 ms  ~900 cycles
Physics Update        4 ms    ~7,200 cycles
Animation Update      1 ms    ~1,800 cycles
Collision Check       2 ms    ~3,600 cycles
Render Prep           1 ms    ~1,800 cycles
────────────────────────────────────────
Total Active CPU:    ~10.5 ms ~18,800 cycles

Idle Time:           ~6 ms    (PPU rendering)
────────────────────────────────────────
Total Frame Time:    16.67 ms

* 1.79 MHz CPU = ~1790 cycles/ms
* Assumes no sprite scaling/rotation
* ROM often uses unrolled loops for speed
```

---

## Memory Pressure

```
Total Addressable: 64 KB

Used in Game:
├─ CPU RAM:        2.5 KB  (3.9%)
├─ PPU access:     64 B    (bank mapped)
├─ APU registers:  24 B    (bank mapped)
├─ PRG-ROM code:   32 KB   (large, swappable on some mappers)
├─ CHR-ROM data:   8 KB    (graphics, PPU-accessible)
└─ Unused:         21.5 KB

Strategy:
- Code in ROM (read-only)
- Sprite positions in RAM ($0200-$02FF)
- Game state in RAM ($0300-$07FF)
- Frequent data in zero page ($0000-$00FF) for speed
- Stack at ($0100-$01FF)
```

---

These diagrams show how the 6502 assembly decompiles into structured C
and Python code, and how the hardware components interact to create
the complete game experience.
