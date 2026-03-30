"""
6502 assembler - converts assembly back to machine code.
Handles the opcodes and addressing modes for NES ROM reassembly.
"""


# Reverse mapping: (mnemonic, addressing_mode) -> opcode
ASSEMBLER_MAP = {
    # ADC - Add with Carry
    ('ADC', 'IMM'): 0x69, ('ADC', 'ZP'):  0x65, ('ADC', 'ZPX'): 0x75,
    ('ADC', 'ABS'): 0x6D, ('ADC', 'ABX'): 0x7D, ('ADC', 'ABY'): 0x79,
    ('ADC', 'IDX'): 0x61, ('ADC', 'IDY'): 0x71,
    
    # AND - Logical AND
    ('AND', 'IMM'): 0x29, ('AND', 'ZP'):  0x25, ('AND', 'ZPX'): 0x35,
    ('AND', 'ABS'): 0x2D, ('AND', 'ABX'): 0x3D, ('AND', 'ABY'): 0x39,
    ('AND', 'IDX'): 0x21, ('AND', 'IDY'): 0x31,
    
    # ASL - Arithmetic Shift Left
    ('ASL', 'ACC'): 0x0A, ('ASL', 'ZP'):  0x06, ('ASL', 'ZPX'): 0x16,
    ('ASL', 'ABS'): 0x0E, ('ASL', 'ABX'): 0x1E,
    
    # BIT - Bit Test
    ('BIT', 'ZP'):  0x24, ('BIT', 'ABS'): 0x2C,
    
    # Branch instructions
    ('BPL', 'REL'): 0x10, ('BMI', 'REL'): 0x30, ('BVC', 'REL'): 0x50,
    ('BVS', 'REL'): 0x70, ('BCC', 'REL'): 0x90, ('BCS', 'REL'): 0xB0,
    ('BNE', 'REL'): 0xD0, ('BEQ', 'REL'): 0xF0,
    
    # BRK
    ('BRK', 'IMP'): 0x00,
    
    # CMP - Compare Accumulator
    ('CMP', 'IMM'): 0xC9, ('CMP', 'ZP'):  0xC5, ('CMP', 'ZPX'): 0xD5,
    ('CMP', 'ABS'): 0xCD, ('CMP', 'ABX'): 0xDD, ('CMP', 'ABY'): 0xD9,
    ('CMP', 'IDX'): 0xC1, ('CMP', 'IDY'): 0xD1,
    
    # CPX - Compare X
    ('CPX', 'IMM'): 0xE0, ('CPX', 'ZP'):  0xE4, ('CPX', 'ABS'): 0xEC,
    
    # CPY - Compare Y
    ('CPY', 'IMM'): 0xC0, ('CPY', 'ZP'):  0xC4, ('CPY', 'ABS'): 0xCC,
    
    # DEC - Decrement
    ('DEC', 'ZP'):  0xC6, ('DEC', 'ZPX'): 0xD6, ('DEC', 'ABS'): 0xCE,
    ('DEC', 'ABX'): 0xDE,
    
    # DEX, DEY
    ('DEX', 'IMP'): 0xCA, ('DEY', 'IMP'): 0x88,
    
    # EOR - Exclusive OR
    ('EOR', 'IMM'): 0x49, ('EOR', 'ZP'):  0x45, ('EOR', 'ZPX'): 0x55,
    ('EOR', 'ABS'): 0x4D, ('EOR', 'ABX'): 0x5D, ('EOR', 'ABY'): 0x59,
    ('EOR', 'IDX'): 0x41, ('EOR', 'IDY'): 0x51,
    
    # INC - Increment
    ('INC', 'ZP'):  0xE6, ('INC', 'ZPX'): 0xF6, ('INC', 'ABS'): 0xEE,
    ('INC', 'ABX'): 0xFE,
    
    # INX, INY
    ('INX', 'IMP'): 0xE8, ('INY', 'IMP'): 0xC8,
    
    # JMP
    ('JMP', 'ABS'): 0x4C, ('JMP', 'IND'): 0x6C,
    
    # JSR
    ('JSR', 'ABS'): 0x20,
    
    # LDA - Load Accumulator
    ('LDA', 'IMM'): 0xA9, ('LDA', 'ZP'):  0xA5, ('LDA', 'ZPX'): 0xB5,
    ('LDA', 'ABS'): 0xAD, ('LDA', 'ABX'): 0xBD, ('LDA', 'ABY'): 0xB9,
    ('LDA', 'IDX'): 0xA1, ('LDA', 'IDY'): 0xB1,
    
    # LDX
    ('LDX', 'IMM'): 0xA2, ('LDX', 'ZP'):  0xA6, ('LDX', 'ZPY'): 0xB6,
    ('LDX', 'ABS'): 0xAE, ('LDX', 'ABY'): 0xBE,
    
    # LDY
    ('LDY', 'IMM'): 0xA0, ('LDY', 'ZP'):  0xA4, ('LDY', 'ZPX'): 0xB4,
    ('LDY', 'ABS'): 0xAC, ('LDY', 'ABX'): 0xBC,
    
    # LSR
    ('LSR', 'ACC'): 0x4A, ('LSR', 'ZP'):  0x46, ('LSR', 'ZPX'): 0x56,
    ('LSR', 'ABS'): 0x4E, ('LSR', 'ABX'): 0x5E,
    
    # NOP
    ('NOP', 'IMP'): 0xEA,
    
    # ORA - OR Accumulator
    ('ORA', 'IMM'): 0x09, ('ORA', 'ZP'):  0x05, ('ORA', 'ZPX'): 0x15,
    ('ORA', 'ABS'): 0x0D, ('ORA', 'ABX'): 0x1D, ('ORA', 'ABY'): 0x19,
    ('ORA', 'IDX'): 0x01, ('ORA', 'IDY'): 0x11,
    
    # PHA, PHP, PLA, PLP
    ('PHA', 'IMP'): 0x48, ('PHP', 'IMP'): 0x08,
    ('PLA', 'IMP'): 0x68, ('PLP', 'IMP'): 0x28,
    
    # ROL - Rotate Left
    ('ROL', 'ACC'): 0x2A, ('ROL', 'IMP'): 0x2A, ('ROL', 'ZP'):  0x26, ('ROL', 'ZPX'): 0x36,
    ('ROL', 'ABS'): 0x2E, ('ROL', 'ABX'): 0x3E,
    
    # ROR - Rotate Right
    ('ROR', 'ACC'): 0x6A, ('ROR', 'IMP'): 0x6A, ('ROR', 'ZP'):  0x66, ('ROR', 'ZPX'): 0x76,
    ('ROR', 'ABS'): 0x6E, ('ROR', 'ABX'): 0x7E,
    
    # ASL/LSR accumulator vs implied
    ('ASL', 'IMP'): 0x0A, ('LSR', 'IMP'): 0x4A,
    
    # RTI, RTS
    ('RTI', 'IMP'): 0x40, ('RTS', 'IMP'): 0x60,
    
    # SBC - Subtract with Carry
    ('SBC', 'IMM'): 0xE9, ('SBC', 'ZP'):  0xE5, ('SBC', 'ZPX'): 0xF5,
    ('SBC', 'ABS'): 0xED, ('SBC', 'ABX'): 0xFD, ('SBC', 'ABY'): 0xF9,
    ('SBC', 'IDX'): 0xE1, ('SBC', 'IDY'): 0xF1,
    
    # Flag operations
    ('CLC', 'IMP'): 0x18, ('SEC', 'IMP'): 0x38, ('CLI', 'IMP'): 0x58,
    ('SEI', 'IMP'): 0x78, ('CLV', 'IMP'): 0xB8, ('CLD', 'IMP'): 0xD8,
    ('SED', 'IMP'): 0xF8,
    
    # STA - Store Accumulator
    ('STA', 'ZP'):  0x85, ('STA', 'ZPX'): 0x95, ('STA', 'ABS'): 0x8D,
    ('STA', 'ABX'): 0x9D, ('STA', 'ABY'): 0x99, ('STA', 'IDX'): 0x81,
    ('STA', 'IDY'): 0x91,
    
    # STX
    ('STX', 'ZP'):  0x86, ('STX', 'ZPY'): 0x96, ('STX', 'ABS'): 0x8E,
    
    # STY
    ('STY', 'ZP'):  0x84, ('STY', 'ZPX'): 0x94, ('STY', 'ABS'): 0x8C,
    
    # Transfers
    ('TAX', 'IMP'): 0xAA, ('TAY', 'IMP'): 0xA8, ('TSX', 'IMP'): 0xBA,
    ('TXA', 'IMP'): 0x8A, ('TYA', 'IMP'): 0x98, ('TXS', 'IMP'): 0x9A,
}


def parse_operand(operand_str: str, mnemonic: str = '') -> tuple[str, int]:
    """
    Parse operand and return (addressing_mode, value).
    Uses mnemonic context to select the best (smallest) valid mode.
    
    Examples:
        "#$10" -> ('IMM', 0x10)
        "$00" -> ('ZP', 0x00)
        "$0000" -> ('ABS', 0x0000)
        "A" -> ('ACC', 0)
    """
    operand_str = operand_str.strip()
    
    # Accumulator
    if operand_str == 'A':
        return ('ACC', 0)
    
    # No operand (implied)
    if not operand_str:
        return ('IMP', 0)
    
    # Immediate #$XX
    if operand_str.startswith('#$'):
        value = int(operand_str[2:], 16)
        return ('IMM', value)
    
    # Indirect addressing
    if operand_str.startswith('(') and ')' in operand_str:
        # Find the closing paren
        close_paren = operand_str.find(')')
        inner = operand_str[1:close_paren]
        after_paren = operand_str[close_paren+1:].strip()
        
        if ',' in inner:
            # Indexed indirect ($XX,X)
            parts = inner.split(',')
            addr = int(parts[0].replace('$', ''), 16)
            idx_reg = parts[1].strip()
            if idx_reg == 'X':
                return ('IDX', addr)
        elif after_paren.startswith(','):
            # Indirect indexed ($XX),Y
            addr = int(inner.replace('$', ''), 16)
            idx_reg = after_paren[1:].strip()
            if idx_reg == 'Y':
                return ('IDY', addr)
        else:
            # Pure indirect ($XXXX)
            addr = int(inner.replace('$', ''), 16)
            return ('IND', addr)
    
    # Absolute or Zero Page with optional indexing
    if operand_str.startswith('$'):
        # Extract address and index register
        if ',' in operand_str:
            addr_part = operand_str.split(',')[0][1:]
            idx_part = operand_str.split(',')[1].strip()
        else:
            addr_part = operand_str[1:]
            idx_part = None
        
        try:
            addr = int(addr_part, 16)
        except ValueError:
            raise ValueError(f"Invalid address: {operand_str}")
        
        if idx_part:
            # Respect the notation: # of hex digits determines mode
            # 4-digit ($XXXX) = ABS, 2-digit ($XX) = ZP
            is_y_indexed = (idx_part == 'Y')
            
            if len(addr_part) >= 4:
                # 4+ digit address = force ABS,X or ABS,Y
                return (('ABY' if is_y_indexed else 'ABX'), addr)
            else:
                # 2-digit or less = try ZP first, fall back to ABS
                preferred_mode = ('ZPY' if is_y_indexed else 'ZPX')
                alt_mode = ('ABY' if is_y_indexed else 'ABX')
                if (mnemonic, preferred_mode) in ASSEMBLER_MAP:
                    return (preferred_mode, addr)
                else:
                    return (alt_mode, addr)
        else:
            # No index: respect the notation -# of hex digits determines mode
            # 4-digit ($XXXX) = ABS, 2-digit ($XX) = ZP
            if len(addr_part) >= 4:
                # 4+ digit address = force ABS mode
                return ('ABS', addr)
            elif addr <= 0xFF and (mnemonic, 'ZP') in ASSEMBLER_MAP:
                # 2-digit address and ZP available = use ZP
                return ('ZP', addr)
            else:
                return ('ABS', addr)
    
    # Relative (for branches) - just the value
    try:
        value = int(operand_str, 16)
        return ('REL', value)
    except:
        pass
    
    raise ValueError(f"Cannot parse operand: {operand_str}")


def assemble_instruction(mnemonic: str, operand_str: str) -> bytes:
    """
    Assemble a single instruction to machine code.
    Intelligently selects the smallest valid addressing mode.
    
    Returns:
        Bytes representing the assembled instruction
    """
    # Branch instructions need special handling
    branch_instructions = {'BPL', 'BMI', 'BVC', 'BVS', 'BCC', 'BCS', 'BNE', 'BEQ'}
    abs_only = {'JSR', 'JMP'}  # Instructions that only support ABS
    
    if not operand_str.strip():
        addressing_mode = 'IMP'
        value = 0
    elif mnemonic in branch_instructions:
        addressing_mode = 'REL'
        operand_str = operand_str.strip()
        value = int(operand_str[1:], 16) if operand_str.startswith('$') else int(operand_str, 16)
    elif mnemonic in abs_only:
        # JSR/JMP only support ABS or IND
        if operand_str.strip().startswith('('):
            addressing_mode = 'IND'
            inner = operand_str[1:-1]
            value = int(inner.replace('$', ''), 16)
        else:
            addressing_mode = 'ABS'
            value = int(operand_str[1:], 16) if operand_str.startswith('$') else int(operand_str, 16)
    else:
        # For other instructions, try to pick the most compact valid mode
        addressing_mode, value = parse_operand(operand_str, mnemonic)
    
    # Look up opcode
    key = (mnemonic, addressing_mode)
    if key not in ASSEMBLER_MAP:
        raise ValueError(f"Unknown instruction: {mnemonic} {addressing_mode}")
    
    opcode = ASSEMBLER_MAP[key]
    result = bytes([opcode])
    
    # Add operand bytes
    if addressing_mode in ('IMP', 'ACC'):
        pass
    elif addressing_mode == 'IMM':
        result += bytes([value & 0xFF])
    elif addressing_mode in ('ZP', 'ZPX', 'ZPY', 'IDX', 'IDY'):
        result += bytes([value & 0xFF])
    elif addressing_mode in ('ABS', 'ABX', 'ABY', 'IND'):
        result += bytes([value & 0xFF, (value >> 8) & 0xFF])
    elif addressing_mode == 'REL':
        result += bytes([value & 0xFF])
    
    return result


def reassemble_asm(asm_code: str, silent: bool = True) -> bytes:
    """
    Reassemble complete 6502 assembly code to machine code.
    
    Args:
        asm_code: Assembly code string with format:
                 $ADDR: MNEMONIC OPERAND
                 or
                 $ADDR: .byte $XX
        silent: If True, silently skip problematic lines
    
    Returns:
        Assembled machine code bytes
    """
    machine_code = bytearray()
    errors = 0
    
    for line in asm_code.split('\n'):
        line = line.strip()
        
        # Skip empty lines and comments
        if not line or line.startswith(';'):
            continue
        
        # Parse line format: "$ADDR: MNEMONIC OPERAND" or "$ADDR: .byte $XX"
        if ':' not in line:
            continue
        
        try:
            parts = line.split(':', 1)[1].strip()
            if not parts:
                continue
            
            # Handle .byte directive
            if parts.startswith('.byte'):
                # Parse .byte $XX or multiple bytes
                tokens = parts.split()
                for token in tokens[1:]:  # Skip '.byte'
                    if token.startswith('$'):
                        machine_code.append(int(token[1:], 16))
                    elif token.startswith('0x'):
                        machine_code.append(int(token[2:], 16))
                continue
            
            # Parse mnemonic and operand
            tokens = parts.split(None, 1)
            mnemonic = tokens[0]
            operand = tokens[1] if len(tokens) > 1 else ""
            
            instr_bytes = assemble_instruction(mnemonic, operand)
            machine_code.extend(instr_bytes)
        
        except Exception as e:
            errors += 1
            if not silent:
                print(f"Warning: {e} in line: {line}")
    
    if errors > 0 and not silent:
        print(f"[!] {errors} assembly errors encountered")
    
    return bytes(machine_code)
