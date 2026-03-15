# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## About This Fork

This is shuk's (stoyboy) personal fork of QMK firmware. It hosts custom keymaps for:
- Lulu (`keyboards/boardsource/lulu/keymaps/stoyboy/`) - a variant of the original Lily58
- Possibly Corne in the future

**Primary task:** Help with creating and refining keyboard layouts, especially for Lulu.

To test if things compile as expected: `qmk compile -kb boardsource/lulu/avr -km stoyboy -e CONVERT_TO=blok`

## CI / GitHub Actions

A custom workflow (`.github/workflows/build_stoyboy.yml`) automatically compiles the Lulu stoyboy keymap:
- **Triggers:** on push to `keyboards/boardsource/lulu/**` or `keyboards/lily58/**`, plus manual `workflow_dispatch`
- **What it does:** runs `qmk compile -kb boardsource/lulu/avr -km stoyboy -e CONVERT_TO=blok` inside the `ghcr.io/qmk/qmk_cli` container
- **Artifact:** uploads the compiled firmware (`.hex`/`.bin`/`.uf2`) as `lulu-stoyboy-firmware`
- Uses concurrency groups to cancel in-progress builds when new pushes arrive

## Project Overview

QMK (Quantum Mechanical Keyboard) is keyboard firmware written primarily in C, targeting AVR (via LUFA) and ARM (via ChibiOS) microcontrollers. The codebase supports 1000+ keyboards with customizable keymaps, layers, and extensive peripheral support (RGB, OLED, encoders, haptics, split keyboards, etc.).

## Build Commands

```bash
# Build firmware for a specific keyboard and keymap
make keyboard:keymap                    # e.g., make planck/rev6:default
qmk compile -kb keyboard -km keymap     # CLI alternative

# Build and flash
make keyboard:keymap:flash
qmk flash -kb keyboard -km keymap

# Compile all keymaps for a keyboard (use for keyboard changes)
make keyboard:all

# Compile everything (use for core changes)
make all
```

## Testing and Linting

```bash
# Run all unit tests
make test:all

# Run specific test
make test:test_name                     # e.g., make test:caps_word

# Python tests
python3 -m pytest lib/python/

# Format C code (requires Docker)
make format-core

# Preview documentation locally
qmk docs -b
```

## Architecture

### Key Directories

- **`keyboards/`** - One folder per keyboard (manufacturer/model/revision structure). Each contains `info.json`, optional `config.h`/`rules.mk`, keyboard `.c` files, and `keymaps/` subdirectory
- **`quantum/`** - Core QMK functionality: key processing, layers, tap/hold, and feature modules in `process_keycode/`
- **`platforms/`** - Hardware abstraction for `avr/` and `chibios/` (ARM)
- **`drivers/`** - Peripheral drivers (LED, OLED, encoders, etc.)
- **`tmk_core/`** - Legacy core with USB protocol handlers
- **`lib/python/qmk/`** - QMK CLI implementation
- **`tests/`** - Unit tests for firmware features
- **`docs/`** - Documentation (viewable at docs.qmk.fm)

### Configuration Hierarchy (lowest to highest priority)

1. QMK defaults
2. Keyboard `info.json`, `config.h`, `rules.mk`
3. Revision/variant folders (nested up to 5 levels)
4. Keymap-level `config.h`, `rules.mk`

### Key Configuration Files

- **`info.json`** - Data-driven config: keyboard metadata, matrix definition, layouts, feature flags
- **`config.h`** - C preprocessor definitions: hardware pins, USB identifiers, feature tuning
- **`rules.mk`** - Build variables: feature enables (`RGB_MATRIX_ENABLE = yes`), MCU selection, bootloader

### Code Patterns

- Features are **disabled by default** to save flash/RAM - enable in `rules.mk`
- Callback override pattern: `*_kb()` for keyboard-level, `*_user()` for keymap-level
- Process record chain: `pre_process → process_combo → process_record → post_process`
- Keymaps can have up to 32 layers

## Contribution Guidelines

- Verify compilation before submitting:
  - Keymaps: `make keyboard:keymap`
  - Keyboards: `make keyboard:all`
  - Core: `make all`
- Separate PRs into logical units (don't mix core changes with keyboard/keymap additions)
- Name `.c/.h` files after immediate parent folder
- New features should be disabled by default
- Core features need unit tests and documentation in `docs/`
- User-keymap and userspace contributions are no longer accepted
