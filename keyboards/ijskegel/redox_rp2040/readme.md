# redox_rp2040

This is a handwired redox utalising an RP2040

* Keyboard Maintainer: [IJskegel](https://github.com/ijskegel)
* Hardware Supported: Raspberry Pi Pico RP2040

Make example for this keyboard (after setting up your build environment):

    make ijskegel/redox_rp2040:default

Flashing example for this keyboard:

Put keyboard in bootloader mode and execute the following commands:
    left side: qmk flash -kb ijskegel/redox_rp2040 -km default -bl uf2-split-left
    right side: qmk flash -kb ijskegel/redox_rp2040 -km default -bl uf2-split-right

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
