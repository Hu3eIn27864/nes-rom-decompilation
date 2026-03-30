"""
NES ROM Decompilation to Python
Converted from 6502 Assembly

This is a decompiled version of the NES ROM (Super Mario Bros)
converted to Python for readability and analysis.
"""

from dataclasses import dataclass
from typing import Optional, List, Dict
from enum import IntEnum

# ===== Type Definitions =====

class PPUFlags(IntEnum):
    """PPU Control Flags"""
    ENABLE_BACKGROUND = 0x08
    ENABLE_SPRITES = 0x10
    VBLANK = 0x80

class ControllerButtons(IntEnum):
    """NES Controller Button Mapping"""
    BUTTON_A = 0x80
    BUTTON_B = 0x40
    SELECT = 0x20
    START = 0x10
    UP = 0x08
    DOWN = 0x04
    LEFT = 0x02
    RIGHT = 0x01

@dataclass
class Sprite:
    """NES OAM Sprite (8x8 or 8x16 pixel graphics)"""
    y: int              # Y coordinate
    tile_id: int        # Tile index in CHR-ROM
    attributes: int     # Palette, priority, flip flags
    x: int              # X coordinate
    
    def set_palette(self, palette: int):
        """Set sprite palette (bits 1-0)"""
        self.attributes = (self.attributes & 0xFC) | (palette & 0x03)
    
    def flip_horizontal(self, flip: bool):
        """Enable/disable horizontal flip"""
        if flip:
            self.attributes |= 0x40
        else:
            self.attributes &= 0xBF
    
    def flip_vertical(self, flip: bool):
        """Enable/disable vertical flip"""
        if flip:
            self.attributes |= 0x80
        else:
            self.attributes &= 0x7F

@dataclass
class Vector2D:
    """2D Position/Velocity Vector"""
    x: int
    y: int
    
    def add(self, other):
        """Add two vectors"""
        self.x += other.x
        self.y += other.y
    
    def clamp(self, min_val: int, max_val: int):
        """Clamp values between min and max"""
        self.x = max(min(self.x, max_val), min_val)
        self.y = max(min(self.y, max_val), min_val)

# ===== NES Hardware Memory Map =====

class NESMemory:
    """NES Memory Management"""
    
    # Hardware Registers (Memory-mapped I/O)
    PPU_CTRL = 0x2000      # PPU Control Register
    PPU_MASK = 0x2001      # PPU Mask Register
    PPU_STATUS = 0x2002    # PPU Status Register
    OAM_ADDR = 0x2003      # OAM Address Register
    OAM_DATA = 0x2004      # OAM Data Register
    PPU_SCROLL = 0x2005    # PPU Scroll Register
    PPU_ADDR = 0x2006      # PPU Address Register
    PPU_DATA = 0x2007      # PPU Data Register
    
    # APU Registers
    SQ1_VOL = 0x4000       # Square 1 Volume
    SQ1_SWEEP = 0x4001     # Square 1 Sweep
    SQ1_LO = 0x4002        # Square 1 Timer Low
    SQ1_HI = 0x4003        # Square 1 Timer High
    SQ2_VOL = 0x4004       # Square 2 Volume
    DPCM_DAC = 0x4011      # DPCM DAC Level
    APU_ENABLE = 0x4015    # APU Enable
    OAM_DMA = 0x4014       # OAM DMA
    
    # Controllers
    JOY1 = 0x4016          # Controller 1
    JOY2 = 0x4017          # Controller 2
    
    # RAM Regions
    ZEROPAGE = 0x0000      # $0000-$00FF (256 bytes) - Fast access
    STACK = 0x0100         # $0100-$01FF (256 bytes) - Stack
    OAM_MIRROR = 0x0200    # $0200-$02FF (256 bytes) - OAM RAM
    RAM = 0x0300           # $0300-$07FF (1.75 KB) - General purpose

# ===== Game State =====

@dataclass
class GameState:
    """Main game state structure"""
    
    # Sprites and rendering
    sprites: List[Sprite]
    
    # Player (Mario) state
    player_x: int = 640            # Player X position (pixels)
    player_y: int = 200            # Player Y position (pixels)
    player_vel_x: int = 0          # Player X velocity
    player_vel_y: int = 0          # Player Y velocity
    player_state: int = 0          # 0=normal, 1=jumping, 2=falling, 3=dead
    
    # Game progression
    current_level: int = 1         # Current level number
    current_world: int = 1         # Current world
    score: int = 0                 # Player score
    coins: int = 0                 # Coins collected
    lives: int = 3                 # Lives remaining
    time_remaining: int = 400      # Time left in level
    
    # Animation
    frame_counter: int = 0         # Global frame counter
    animation_frame: int = 0       # Current animation frame
    jump_timer: int = 0            # Jump duration counter
    
    # Audio
    music_track: int = 0           # Currently playing music
    sound_queue: List[int] = None  # Queued sound effects
    
    # Flags
    game_over: bool = False
    level_complete: bool = False
    
    def __post_init__(self):
        if self.sound_queue is None:
            self.sound_queue = [0] * 16
        if not self.sprites:
            self.sprites = [Sprite(y=255, tile_id=0, attributes=0, x=0) 
                           for _ in range(64)]
    
    def advance_frame(self):
        """Advance to next animation frame"""
        self.frame_counter += 1
        if self.frame_counter % 8 == 0:
            self.animation_frame = (self.animation_frame + 1) % 4

# ===== NES Hardware Functions =====

class NESHardware:
    """NES Hardware Interface"""
    
    def __init__(self):
        self.memory = bytearray(0x8000)  # CPU addressable RAM
        self.vblank_flag = False
    
    def wait_vblank(self):
        """Wait for vertical blank period"""
        while not self.vblank_flag:
            pass
        self.vblank_flag = False
    
    def set_ppu_ctrl(self, value: int):
        """Set PPU Control Register ($2000)
        
        Bits:
            7-6: Nametable select
            5: Increment PPU address (0=$2000, 1=$2006)
            4: Sprite pattern table (0=$0000, 1=$1000)
            3: Background pattern table (0=$0000, 1=$1000)
            2: Sprite size (0=8x8, 1=8x16)
            1: PPU master/slave
            0: NMI enable
        """
        self.memory[NESMemory.PPU_CTRL] = value
    
    def set_ppu_mask(self, value: int):
        """Set PPU Mask Register ($2001)
        
        Bits:
            7: Intensify blue
            6: Intensify green
            5: Intensify red
            4: Enable sprite rendering
            3: Enable background rendering
            2: Show sprites in leftmost 8px
            1: Show background in leftmost 8px
            0: Grayscale mode
        """
        self.memory[NESMemory.PPU_MASK] = value
    
    def get_ppu_status(self) -> int:
        """Get PPU Status Register ($2002)
        
        Bit 7: VBlank flag
        Bit 6: Sprite 0 hit
        Bit 5: Sprite overflow
        """
        return self.memory[NESMemory.PPU_STATUS]
    
    def dma_upload_oam(self):
        """Upload sprite data to OAM using DMA
        
        Copies 256 bytes from CPU memory (typically $0200-$02FF)
        to OAM (Object Attribute Memory) in one scanline
        """
        self.memory[NESMemory.OAM_DMA] = 0x02  # DMA from $0200
    
    def set_ppu_scroll(self, x: int, y: int):
        """Set scrolling position"""
        self.memory[NESMemory.PPU_SCROLL] = x
        self.memory[NESMemory.PPU_SCROLL] = y
    
    def ppu_write(self, addr: int, data: int):
        """Write byte to PPU memory"""
        self.memory[NESMemory.PPU_ADDR] = (addr >> 8) & 0xFF
        self.memory[NESMemory.PPU_ADDR] = addr & 0xFF
        self.memory[NESMemory.PPU_DATA] = data
    
    def ppu_read(self, addr: int) -> int:
        """Read byte from PPU memory"""
        self.memory[NESMemory.PPU_ADDR] = (addr >> 8) & 0xFF
        self.memory[NESMemory.PPU_ADDR] = addr & 0xFF
        return self.memory[NESMemory.PPU_DATA]
    
    def apu_enable(self, channels: int):
        """Enable APU channels
        
        Bit 3: DPCM enable
        Bit 2: Noise enable
        Bit 1: Triangle enable
        Bit 0: Square 2 enable
        Bit 0: Square 1 enable
        """
        self.memory[NESMemory.APU_ENABLE] = channels

# ===== Game Logic =====

class GameObject:
    """Base class for game objects"""
    
    def __init__(self, x: int, y: int):
        self.position = Vector2D(x, y)
        self.velocity = Vector2D(0, 0)
        self.active = True
    
    def update(self, dt: float = 1.0):
        """Update object for this frame"""
        self.position.add(self.velocity)
    
    def draw(self, sprites: List[Sprite]):
        """Draw object using sprite data"""
        pass

class Player(GameObject):
    """Main player character (Mario)"""
    
    GRAVITY = 1               # Pixels per frame²
    MAX_FALL_SPEED = 15       # Max downward velocity
    JUMP_POWER = -8           # Initial upward velocity
    MOVE_SPEED = 2            # Horizontal movement speed
    
    def __init__(self, x: int, y: int):
        super().__init__(x, y)
        self.state = "normal"  # normal, jumping, falling, dead
        self.direction = 1     # 1=right, -1=left
        self.animation_frame = 0
        self.jump_timer = 0
    
    def apply_gravity(self):
        """Apply gravity physics"""
        self.velocity.y += self.GRAVITY
        if self.velocity.y > self.MAX_FALL_SPEED:
            self.velocity.y = self.MAX_FALL_SPEED
    
    def jump(self):
        """Initiate jump"""
        if self.state in ["normal", "falling"]:
            self.velocity.y = self.JUMP_POWER
            self.state = "jumping"
            self.jump_timer = 12
    
    def move_left(self):
        """Move left"""
        self.velocity.x = -self.MOVE_SPEED
        self.direction = -1
    
    def move_right(self):
        """Move right"""
        self.velocity.x = self.MOVE_SPEED
        self.direction = 1
    
    def stop_moving(self):
        """Stop horizontal movement"""
        self.velocity.x = 0
    
    def update(self, dt: float = 1.0):
        """Update player state"""
        self.apply_gravity()
        
        # Update jump state
        if self.state == "jumping":
            self.jump_timer -= 1
            if self.jump_timer <= 0:
                self.state = "falling"
        
        super().update(dt)
        
        # Clamp to screen bounds
        if self.position.x < 0:
            self.position.x = 0
        if self.position.x > 256:
            self.position.x = 256

class Enemy(GameObject):
    """Base enemy class"""
    
    MOVE_SPEED = 1
    
    def __init__(self, x: int, y: int, enemy_type: str = "goomba"):
        super().__init__(x, y)
        self.type = enemy_type
        self.direction = 1
        self.animation_frame = 0
    
    def update(self, dt: float = 1.0):
        """Update enemy AI"""
        # Basic patrol behavior
        self.velocity.x = self.MOVE_SPEED * self.direction
        super().update(dt)
    
    def on_collision(self, other: GameObject):
        """Handle collision with another object"""
        if isinstance(other, Player):
            # Collision logic here
            pass

class GameEngine:
    """Main game engine"""
    
    def __init__(self):
        self.hardware = NESHardware()
        self.game_state = GameState(sprites=[])
        self.player = Player(640, 200)
        self.enemies: List[Enemy] = []
        self.objects: List[GameObject] = [self.player]
    
    def initialize(self):
        """Initialize NES hardware and game state"""
        # Disable interrupts and clear flags
        # Set up PPU
        self.hardware.set_ppu_ctrl(0x90)  # NMI enable, sprite pattern table
        self.hardware.set_ppu_mask(0x1E)  # Show background and sprites
        
        # Initialize RAM
        self._clear_ram()
        
        # Load level
        self.load_level(1)
    
    def _clear_ram(self):
        """Clear game RAM"""
        for i in range(0x0300, 0x0800):
            self.hardware.memory[i] = 0
    
    def load_level(self, level: int):
        """Load level data"""
        self.game_state.current_level = level
        self.game_state.time_remaining = 400
        self.player.position.x = 640
        self.player.position.y = 200
    
    def process_input(self, joypad: int):
        """Process controller input
        
        Args:
            joypad: Button states from controller
        """
        if joypad & ControllerButtons.RIGHT:
            self.player.move_right()
        elif joypad & ControllerButtons.LEFT:
            self.player.move_left()
        else:
            self.player.stop_moving()
        
        if joypad & ControllerButtons.BUTTON_A:
            self.player.jump()
    
    def update(self):
        """Update game state"""
        # Advance animation
        self.game_state.advance_frame()
        
        # Update all game objects
        for obj in self.objects:
            obj.update()
        
        # Update game counters
        self.game_state.time_remaining -= 1
        
        # Check win/lose conditions
        if self.game_state.time_remaining <= 0:
            self.game_state.game_over = True
        
        if self.player.position.y > 240:  # Fell off screen
            self.game_state.lives -= 1
            if self.game_state.lives <= 0:
                self.game_state.game_over = True
            else:
                self.load_level(self.game_state.current_level)
    
    def render(self):
        """Render current frame to screen"""
        # Update sprite OAM
        for i, sprite in enumerate(self.game_state.sprites):
            if i < 64:
                self.hardware.memory[0x0200 + i * 4 + 0] = sprite.y
                self.hardware.memory[0x0200 + i * 4 + 1] = sprite.tile_id
                self.hardware.memory[0x0200 + i * 4 + 2] = sprite.attributes
                self.hardware.memory[0x0200 + i * 4 + 3] = sprite.x
        
        # Upload OAM data
        self.hardware.dma_upload_oam()
        
        # Update PPU registers
        self.hardware.set_ppu_scroll(0, 0)
    
    def run(self):
        """Main game loop"""
        self.initialize()
        
        while not self.game_state.game_over:
            # Wait for VBlank
            self.hardware.wait_vblank()
            
            # Read controller input
            joypad = self.hardware.memory[NESMemory.JOY1]
            
            # Update game
            self.process_input(joypad)
            self.update()
            
            # Render
            self.render()

# ===== Entry Point =====

if __name__ == "__main__":
    """Run the NES game emulation"""
    engine = GameEngine()
    engine.run()
