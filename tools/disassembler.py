"""
6502 CPU disassembler.
Converts machine code to assembly language.
"""

# 6502 opcodes - comprehensive opcode table


OPCODES_6502 = {
    # ADC - Add with Carry
    0x69: ('ADC', '#$%02X', 2),      0x65: ('ADC', '$%02X', 2),        0x75: ('ADC', '$%02X,X', 2),
    0x6D: ('ADC', '$%04X', 3),       0x7D: ('ADC', '$%04X,X', 3),      0x79: ('ADC', '$%04X,Y', 3),
    0x61: ('ADC', '($%02X,X)', 2),   0x71: ('ADC', '($%02X),Y', 2),
    
    # AND - Logical AND
    0x29: ('AND', '#$%02X', 2),      0x25: ('AND', '$%02X', 2),        0x35: ('AND', '$%02X,X', 2),
    0x2D: ('AND', '$%04X', 3),       0x3D: ('AND', '$%04X,X', 3),      0x39: ('AND', '$%04X,Y', 3),
    0x21: ('AND', '($%02X,X)', 2),   0x31: ('AND', '($%02X),Y', 2),
    
    # ASL - Arithmetic Shift Left
    0x0A: ('ASL', 'A', 1),           0x06: ('ASL', '$%02X', 2),        0x16: ('ASL', '$%02X,X', 2),
    0x0E: ('ASL', '$%04X', 3),       0x1E: ('ASL', '$%04X,X', 3),
    
    # BIT - Bit Test
    0x24: ('BIT', '$%02X', 2),       0x2C: ('BIT', '$%04X', 3),
    
    # Branch instructions
    0x10: ('BPL', '$%02X', 2),       0x30: ('BMI', '$%02X', 2),     0x50: ('BVC', '$%02X', 2),
    0x70: ('BVS', '$%02X', 2),       0x90: ('BCC', '$%02X', 2),     0xB0: ('BCS', '$%02X', 2),
    0xD0: ('BNE', '$%02X', 2),       0xF0: ('BEQ', '$%02X', 2),
    
    # BRK
    0x00: ('BRK', '', 1),
    
    # CMP - Compare Accumulator
    0xC9: ('CMP', '#$%02X', 2),      0xC5: ('CMP', '$%02X', 2),        0xD5: ('CMP', '$%02X,X', 2),
    0xCD: ('CMP', '$%04X', 3),       0xDD: ('CMP', '$%04X,X', 3),      0xD9: ('CMP', '$%04X,Y', 3),
    0xC1: ('CMP', '($%02X,X)', 2),   0xD1: ('CMP', '($%02X),Y', 2),
    
    # CPX - Compare X
    0xE0: ('CPX', '#$%02X', 2),      0xE4: ('CPX', '$%02X', 2),        0xEC: ('CPX', '$%04X', 3),
    
    # CPY - Compare Y
    0xC0: ('CPY', '#$%02X', 2),      0xC4: ('CPY', '$%02X', 2),        0xCC: ('CPY', '$%04X', 3),
    
    # DEC - Decrement
    0xC6: ('DEC', '$%02X', 2),       0xD6: ('DEC', '$%02X,X', 2),      0xCE: ('DEC', '$%04X', 3),
    0xDE: ('DEC', '$%04X,X', 3),
    
    # DEX, DEY
    0xCA: ('DEX', '', 1),            0x88: ('DEY', '', 1),
    
    # EOR - Exclusive OR
    0x49: ('EOR', '#$%02X', 2),      0x45: ('EOR', '$%02X', 2),        0x55: ('EOR', '$%02X,X', 2),
    0x4D: ('EOR', '$%04X', 3),       0x5D: ('EOR', '$%04X,X', 3),      0x59: ('EOR', '$%04X,Y', 3),
    0x41: ('EOR', '($%02X,X)', 2),   0x51: ('EOR', '($%02X),Y', 2),
    
    # INC - Increment
    0xE6: ('INC', '$%02X', 2),       0xF6: ('INC', '$%02X,X', 2),      0xEE: ('INC', '$%04X', 3),
    0xFE: ('INC', '$%04X,X', 3),
    
    # INX, INY
    0xE8: ('INX', '', 1),            0xC8: ('INY', '', 1),
    
    # JMP
    0x4C: ('JMP', '$%04X', 3),       0x6C: ('JMP', '($%04X)', 3),
    
    # JSR
    0x20: ('JSR', '$%04X', 3),
    
    # LDA - Load Accumulator
    0xA9: ('LDA', '#$%02X', 2),      0xA5: ('LDA', '$%02X', 2),        0xB5: ('LDA', '$%02X,X', 2),
    0xAD: ('LDA', '$%04X', 3),       0xBD: ('LDA', '$%04X,X', 3),      0xB9: ('LDA', '$%04X,Y', 3),
    0xA1: ('LDA', '($%02X,X)', 2),   0xB1: ('LDA', '($%02X),Y', 2),
    
    # LDX
    0xA2: ('LDX', '#$%02X', 2),      0xA6: ('LDX', '$%02X', 2),        0xB6: ('LDX', '$%02X,Y', 2),
    0xAE: ('LDX', '$%04X', 3),       0xBE: ('LDX', '$%04X,Y', 3),
    
    # LDY
    0xA0: ('LDY', '#$%02X', 2),      0xA4: ('LDY', '$%02X', 2),        0xB4: ('LDY', '$%02X,X', 2),
    0xAC: ('LDY', '$%04X', 3),       0xBC: ('LDY', '$%04X,X', 3),
    
    # LSR
    0x4A: ('LSR', 'A', 1),           0x46: ('LSR', '$%02X', 2),        0x56: ('LSR', '$%02X,X', 2),
    0x4E: ('LSR', '$%04X', 3),       0x5E: ('LSR', '$%04X,X', 3),
    
    # NOP
    0xEA: ('NOP', '', 1),
    
    # ORA - OR Accumulator
    0x09: ('ORA', '#$%02X', 2),      0x05: ('ORA', '$%02X', 2),        0x15: ('ORA', '$%02X,X', 2),
    0x0D: ('ORA', '$%04X', 3),       0x1D: ('ORA', '$%04X,X', 3),      0x19: ('ORA', '$%04X,Y', 3),
    0x01: ('ORA', '($%02X,X)', 2),   0x11: ('ORA', '($%02X),Y', 2),
    
    # PHA, PHP, PLA, PLP
    0x48: ('PHA', '', 1),            0x08: ('PHP', '', 1),
    0x68: ('PLA', '', 1),            0x28: ('PLP', '', 1),
    
    # ROL - Rotate Left
    0x2A: ('ROL', 'A', 1),           0x26: ('ROL', '$%02X', 2),        0x36: ('ROL', '$%02X,X', 2),
    0x2E: ('ROL', '$%04X', 3),       0x3E: ('ROL', '$%04X,X', 3),
    
    # ROR - Rotate Right
    0x6A: ('ROR', 'A', 1),           0x66: ('ROR', '$%02X', 2),        0x76: ('ROR', '$%02X,X', 2),
    0x6E: ('ROR', '$%04X', 3),       0x7E: ('ROR', '$%04X,X', 3),
    
    # RTI, RTS
    0x40: ('RTI', '', 1),            0x60: ('RTS', '', 1),
    
    # SBC - Subtract with Carry
    0xE9: ('SBC', '#$%02X', 2),      0xE5: ('SBC', '$%02X', 2),        0xF5: ('SBC', '$%02X,X', 2),
    0xED: ('SBC', '$%04X', 3),       0xFD: ('SBC', '$%04X,X', 3),      0xF9: ('SBC', '$%04X,Y', 3),
    0xE1: ('SBC', '($%02X,X)', 2),   0xF1: ('SBC', '($%02X),Y', 2),
    
    # Flag operations
    0x18: ('CLC', '', 1),            0x38: ('SEC', '', 1),             0x58: ('CLI', '', 1),
    0x78: ('SEI', '', 1),            0xB8: ('CLV', '', 1),             0xD8: ('CLD', '', 1),
    0xF8: ('SED', '', 1),
    
    # STA - Store Accumulator
    0x85: ('STA', '$%02X', 2),       0x95: ('STA', '$%02X,X', 2),      0x8D: ('STA', '$%04X', 3),
    0x9D: ('STA', '$%04X,X', 3),     0x99: ('STA', '$%04X,Y', 3),      0x81: ('STA', '($%02X,X)', 2),
    0x91: ('STA', '($%02X),Y', 2),
    
    # STX
    0x86: ('STX', '$%02X', 2),       0x96: ('STX', '$%02X,Y', 2),      0x8E: ('STX', '$%04X', 3),
    
    # STY
    0x84: ('STY', '$%02X', 2),       0x94: ('STY', '$%02X,X', 2),      0x8C: ('STY', '$%04X', 3),
    
    # Transfers
    0xAA: ('TAX', '', 1),            0xA8: ('TAY', '', 1),             0xBA: ('TSX', '', 1),
    0x8A: ('TXA', '', 1),            0x98: ('TYA', '', 1),             0x9A: ('TXS', '', 1),
}


def disassemble_6502(data: bytes, origin: int = 0x8000) -> list[str]:
    """
    Disassemble 6502 machine code.
    
    Args:
        data: Raw machine code bytes
        origin: Starting memory address
        
    Returns:
        List of assembly instruction strings
    """
    instructions = []
    pc = 0
    
    while pc < len(data):
        opcode = data[pc]
        addr = origin + pc
        
        if opcode in OPCODES_6502:
            mnemonic, fmt, size = OPCODES_6502[opcode]
            operand_str = ""
            
            if size == 1:
                operand_str = ""
            elif size == 2:
                operand = data[pc + 1]
                operand_str = fmt % operand if '%' in fmt else fmt
            elif size == 3:
                if pc + 2 < len(data):
                    operand = data[pc + 1] | (data[pc + 2] << 8)
                    operand_str = fmt % operand if '%' in fmt else fmt
                else:
                    operand_str = "???"
            
            if operand_str:
                instr = f"${addr:04X}: {mnemonic} {operand_str}"
            else:
                instr = f"${addr:04X}: {mnemonic}"
            
            instructions.append(instr)
            pc += size
        else:
            # Unknown opcode
            instructions.append(f"${addr:04X}: .byte ${opcode:02X}")
            pc += 1
    
    return instructions
