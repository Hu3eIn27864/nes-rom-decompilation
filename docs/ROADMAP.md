# NES Toolkit Roadmap

This roadmap separates reliable ROM inspection from experimental decompilation and full emulation. Time estimates assume one developer at 8–12 focused hours per week; parallel work and unknown mapper behavior can change them substantially.

## M0 — Reproducible foundation (1–2 weeks)
- [ ] Inventory all scripts and document each CLI's actual behavior.
- [ ] Add a clean Python environment and pinned/declared dependencies.
- [ ] Add unit tests for iNES headers, truncated files and invalid sizes.
- [ ] Ensure ROMs and large generated dumps are excluded from version control.
**Exit criteria:** a clean checkout can run the documented parser tests.

## M1 — ROM container and metadata (2–3 weeks)
- [ ] Specify supported iNES 1.0 fields and explicitly report unsupported iNES 2.0 features.
- [ ] Validate PRG/CHR boundaries, trainer offsets and malformed input.
- [ ] Add stable JSON metadata output and input SHA-256.
**Exit criteria:** fixtures cover valid, truncated and malformed headers.

## M2 — 6502 decoder correctness (3–6 weeks)
- [ ] Define an opcode table with length, addressing mode, cycles and legality.
- [ ] Test all official 6502 opcodes and explicitly classify unofficial opcodes.
- [ ] Preserve addresses and raw bytes in listings.
**Exit criteria:** decoder tests cover every opcode classification.

## M3 — Code discovery and mapper-aware analysis (1–3 months)
- [ ] Separate linear decoding from control-flow-guided code discovery.
- [ ] Model vectors, branches, calls and indirect jump candidates.
- [ ] Add mapper abstraction and bank-aware address mapping, starting with a deliberately small supported set.
- [ ] Keep uncertain code/data classifications visible.
**Exit criteria:** documented test ROMs produce stable, reviewable analysis reports.

## M4 — Reassembly and verification (1–2 months)
- [ ] Define a lossless listing format that preserves data bytes and metadata.
- [ ] Add round-trip tests on synthetic and homebrew fixtures.
- [ ] Compare output bytes and report the first differing offset.
**Exit criteria:** supported fixtures round-trip byte-identically; unsupported cases fail explicitly.

## M5 — Browser inspection tool (3–6 weeks)
- [ ] Separate ROM loading, metadata, byte visualization and disassembly views.
- [ ] Add clear file-size limits and error handling.
- [ ] Avoid calling the visualizer an emulator until CPU/PPU/APU execution exists.
**Exit criteria:** browser tool accurately describes its supported inspection features.

## M6 — Optional NES emulator (6–18+ months)
- [ ] Implement 6502 CPU execution and interrupt behavior.
- [ ] Implement PPU timing/rendering and memory behavior.
- [ ] Implement APU and controller input.
- [ ] Add mapper implementations and public test ROM suites.
**Exit criteria:** documented compatibility results against selected homebrew test ROMs.

## Near-term schedule

| Period | Focus | Deliverable |
|---|---|---|
| Weeks 1–2 | M0 | Reproducible test baseline |
| Weeks 3–5 | M1 | Robust iNES parser |
| Weeks 6–11 | M2 | Tested 6502 decoder |
| Months 3–5 | M3–M4 | First reliable analysis and round-trip pipeline |
| Months 5–6 | M5 | Honest, maintainable browser inspector |

The optional full emulator is a separate long-term track and should not block the analysis toolkit.
