RGB_MATRIX_ENABLE = no
RGBLIGHT_ENABLE = no
SPLIT_KEYBOARD = yes
TAP_DANCE_ENABLE = yes
MOUSEKEY_ENABLE = no
EXRAKEY_ENABLE = yes
NKRO_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306


# Link Time Optimization (Reduces compiled size)
LTO_ENABLE = yes

SRC += ./process_records.c

ifeq ($(TAP_DANCE_ENABLE),yes)
	SRC += ./tap_dances.c
endif

ifeq ($(OLED_ENABLE),yes)
	SRC += ./oled.c
endif
