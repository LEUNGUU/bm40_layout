# bm40_layout
My bm40 keyboard layout 😄

## Introduction
Inspired by
[benballack](https://configure.zsa.io/planck-ez/layouts/4D3ym/jYYjx/0), but this
is for [bm40rgbhs](https://kprepublic.com/products/bm40-rgb-40-hot-swap-custom-mechanical-keyboard-pcb-qmk-underglow-type-c-planck)

Idea from [My 36 Key Layout Works BEAUTIFULLY on the Planck
EZ!](https://www.youtube.com/watch?v=vv98LPMA7-M). But I just need 34 keys, so I make my own base on this.

This layout is only for MacOS user, especially for using vim and tmux!

Detailed layout is [here](https://configure.zsa.io/planck-ez/layouts/ExmJ6/latest/2)

## Building and Flashing

### Prerequisites
- QMK CLI installed (preferably in a virtual environment)
- Your BM40 keyboard connected via USB

### Build Steps
1. **Setup QMK environment:**
   ```bash
   # Activate QMK virtual environment (if using one)
   source qmk-env/bin/activate
   
   # Setup QMK (first time only)
   qmk setup
   ```

2. **Create custom keymap directory:**
   ```bash
   mkdir -p ~/qmk_firmware/keyboards/kprepublic/bm40hsrgb/keymaps/custom
   ```

3. **Copy keymap files:**
   ```bash
   cp keymap.c config.h rules.mk ~/qmk_firmware/keyboards/kprepublic/bm40hsrgb/keymaps/custom/
   ```

4. **Compile firmware:**
   ```bash
   qmk compile -kb kprepublic/bm40hsrgb -km custom
   ```

### Flashing
1. **Put keyboard in bootloader mode:**
   - Hold reset button while plugging in USB, OR
   - Press `QK_BOOT` key (located on ADJUST layer)

2. **Flash firmware:**
   ```bash
   qmk flash -kb kprepublic/bm40hsrgb -km custom
   ```

### Verification
Check if keyboard is ready for flashing:
- **macOS:** `system_profiler SPUSBDataType | grep -A 5 -B 2 "Atmel\|DFU"`  
- **Linux:** `lsusb | grep -i "atmel\|dfu"`

Look for Atmel DFU device (VID: 0x03eb, PID: 0x2ff4) when in bootloader mode.

## Final
I will keep this updated. Hope this will inspired you. Especially YOU who are
reading this README! Thanks!
