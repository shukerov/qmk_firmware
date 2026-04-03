# CLAUDE.md

This is stoyboy's personal QMK fork. The only keymap to work on is the Lulu stoyboy keymap at `keyboards/boardsource/lulu/keymaps/stoyboy/`.

## Build

```bash
qmk compile -kb boardsource/lulu/avr -km stoyboy -e CONVERT_TO=blok
```

## Editing the layout

- The keymap is in `keymap.c`
- Each layer has a comment block above it showing the visual layout — **always update these comments to match any key changes**
- Layer order and names are defined as enums at the top of the file
