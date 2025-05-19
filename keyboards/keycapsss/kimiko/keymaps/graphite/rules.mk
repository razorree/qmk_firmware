OLED_ENABLE = yes
ENCODER_ENABLE = yes       # ENables the use of one or more encoders

RGBLIGHT_ENABLE    = no    # Enable keyboard 'old' RGB lightning
RGB_MATRIX_ENABLE  = yes   # Enable keyboard RGB Matrix lightning
RGB_MATRIX_DRIVER = ws2812

# LTO: Link Time Optimizations.
# Reduce compiled size, but will automatically disable the legacy TMK Macros and Functions features.
# This does not affect QMK Macros and Layers
LTO_ENABLE = yes
ENCODER_MAP_ENABLE = yes
BOOTLOADER = caterina

TAP_DANCE_ENABLE = yes

CONSOLE_ENABLE = no

COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
