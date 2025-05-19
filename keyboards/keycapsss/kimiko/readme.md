# Kimiko rev1 board by Keycapsss.com
### What's added by me

1. OLED display enabled
    - layout name displayed

2. RGB key lights
    - RGB Matrix enabled for Graphite layout, keys heatmap works
    - RGB lights enabled for default layout
    
3. Multiple layouts
    - Graphite layout has 2 switchable layouts, **Graphite** and **Qwerty**


Put content of this repo in *qmk_firmware/keyboards/keycapsss/kimiko/* directory 
Build and flash with:
```
make keycapsss/kimiko/rev1:graphite:flash
```
#
#


Original documentation:
# Kimiko

## Rev1

A split keyboard with 4x6 vertically staggered keys and thumb keys.

![Kimiko Rev1](https://i.imgur.com/md6V6Eoh.jpg)

- Keyboard Maintainer: [BenRoe](https://github.com/BenRoe/) [@keycapsss](https://twitter.com/keycapsss)
- Hardware Supported: Pro Micro 5V/16Mhz and compatible
- Hardware Availability: [Keycapsss.com](https://keycapsss.com)

### Features (Rev1)

- Per key RGB led's (SK6812 Mini-E)
- 6 underglow RGB led's per side (SK6812 Mini)
- Support for 1 rotary encoder per side (two possible positions)

Make firmware .hex for this keyboard (after setting up your build environment):

```bash
qmk compile -kb keycapsss/kimiko/rev1 -km default
```

Use [QMK Toolbox](https://github.com/qmk/qmk_toolbox) to flash the firmware hex file to the keyboard controller.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
