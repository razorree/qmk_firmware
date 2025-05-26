RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE  = no

OLED_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = no

CONSOLE_ENABLE = yes

# COMBO_COUNT = 16


# MACCEL
SRC += ./maccel/maccel.c
ifeq ($(strip $(VIA_ENABLE)), yes)
	ifeq ($(strip $(MACCEL_VIA_ENABLE)), yes)
		SRC += ./maccel/maccel_via.c
	endif
endif
OPT_DEFS += -DMACCEL_ENABLE
