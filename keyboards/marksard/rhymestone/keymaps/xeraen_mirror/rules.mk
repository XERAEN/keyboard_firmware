MOUSEKEY_ENABLE = yes       # Mouse keys
TAP_DANCE_ENABLE = no

RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
OLED_ENABLE = no
LTO_ENABLE = yes

# If you want to change the display of OLED, you need to change here
SRC +=  ./common/oled_helper.c \

# Custom
CAPS_WORD_ENABLE = yes
