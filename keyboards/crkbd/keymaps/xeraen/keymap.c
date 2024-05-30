/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keycodes {
  XPW = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 0 - CAGS Base Layer
 *   - uses GACS for home row modifiers
 */
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                            ,-----------------------------------------------------.
     XXXXXXX,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
  XXXXXXX,CTL_T(KC_A),ALT_T(KC_S),GUI_T(KC_D),SFT_T(KC_F),KC_G,                     KC_H,RSFT_T(KC_J),RGUI_T(KC_K),RALT_T(KC_L),RCTL_T(KC_SCLN),XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
     XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
                                    LT(5,KC_SPC),  LT(4,KC_TAB),  LT(3,KC_BSPC),  LT(2,KC_SPC), LSFT_T(KC_ENT),CW_TOGG
                                      //`--------------------------'  `        --------------------------'

  ),

/* 1 - GACS Base Layer
 *   - uses CAGS for home row modifiers
 */
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                            ,-----------------------------------------------------.
     XXXXXXX,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
  XXXXXXX,GUI_T(KC_A),ALT_T(KC_S),CTL_T(KC_D),SFT_T(KC_F),KC_G,                     KC_H,RSFT_T(KC_J),RCTL_T(KC_K),RALT_T(KC_L),RGUI_T(KC_SCLN),XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+--------|
     XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+--------|
                                    LT(5,KC_SPC),  LT(4,KC_TAB),  LT(3,KC_BSPC),  LT(2,KC_SPC), LSFT_T(KC_ENT),CW_TOGG
                                      //`--------------------------'  `        --------------------------'

  ),

/* 2 - Symbols Layer
 * ,----------------------------------.    ,----------------------------------.
 * |  ~   |  #   |   {  |   }  |   *  |    |   +  |  <   |  >   | ESC  |      |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |  @   |  $   |   (  |   )  |   -  |    |   =  |  "   |  '   |  `   |  :   |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |  !   |  ^   |   [  |   ]  |   |  |    |   %  |  &   |  \   | INS  |      |
 * `------+------+------+------+------|    +------+------+------+-------------'
 *               |  XPW |  DEL |   _  |    |   _  |      |      |
 *               '--------------------'    '--------------------'
 */
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,  KC_TILDE, KC_HASH,KC_LEFT_CURLY_BRACE,KC_RIGHT_CURLY_BRACE,KC_ASTERISK,KC_PLUS,KC_LEFT_ANGLE_BRACKET,KC_RIGHT_ANGLE_BRACKET,KC_ESC,KC_NO,KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_AT, KC_DOLLAR,KC_LEFT_PAREN,KC_RIGHT_PAREN,KC_MINUS,         KC_EQUAL,KC_DOUBLE_QUOTE,KC_QUOTE,KC_GRV,KC_COLON, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,KC_EXCLAIM,KC_CIRCUMFLEX,KC_LEFT_BRACKET,KC_RIGHT_BRACKET,KC_PIPE, KC_PERCENT,KC_AMPERSAND,KC_BACKSLASH,KC_INS,KC_NO,KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XPW,KC_DEL,KC_UNDERSCORE,KC_UNDERSCORE, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

/* 3 - Numbers Layer
 * ,---------- -----------------------.    ,----------------------------------.
 * | Boot |      |      |      |      |    |      |  7   |  8   |  9   |  +   |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |      |      |      |      |      |    |      |  4   |  5   |  6   |  +   |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |      |      |      |      |      |    |      |  1   |  2   |  3   |  +   |
 * `------+------+------+------+------|    +------+------+------+-------------'
 *               |      |      |      |    |   0  |  0   |  0   |
 *               '--------------------'    '--------------------'
 */
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_7  ,  KC_8  ,  KC_9  ,KC_PLUS , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_4  ,  KC_5  ,  KC_6  ,KC_PLUS , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_1  ,  KC_2  ,  KC_3  ,KC_PLUS , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,     KC_0  ,  KC_0  ,  KC_0
                                      //`--------------------------'  `--------------------------'
  ),

/* 4 - Nav Layer
 * ,---------- -----------------------.    ,----------------------------------.
 * | Boot |      |      |      |      |    |      |      |      |      |      |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |      |      |      |      |      |    | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |      |      |      |      |      |    |      | Home | PgUp | PgDn | End  |
 * `------+------+------+------+------|    +------+------+------+-------------'
 *               |      | CAGS | GACS |    | DEL  |      |      |
 *               '--------------------'    '--------------------'
 */
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_LEFT ,KC_DOWN ,  KC_UP ,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX,KC_HOME,KC_PAGE_UP,KC_PAGE_DOWN,KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, TO(0)  , TO(1)  ,   KC_DEL,  XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

/* 5 - Function Keys Layer
 * ,---------- -----------------------.    ,----------------------------------.
 * | Boot |      |      |      |      |    |      |  F9  |  F10 |  F11 | F12  |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |      |      |      |      |      |    |      |  F5  |  F6  |  F6  | F8   |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |      |      |      |      |      |    |      |  F1  |  F2  |  F3  | F4   |
 * `------+------+------+------+------|    +------+------+------+-------------'
 *               |      |      | CAGS |    | GACS |      |      |
 *               '--------------------'    '--------------------'
 */
  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_F9 , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, TO(0)  ,    TO(1)  , XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )

/* 6 - Layers Layer
 * ,---------- -----------------------.    ,----------------------------------.
 * |FuncOS|      | GACS | CAGS |      |    |      |      |      |      |      |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |      |      |      |      |      |    |      |      |      |      |      |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |      |      |      |      |      |    |      |      |      |      |      |
 * `------+------+------+------+------|    +------+------+------+-------------'
 *               |      |      |      |    |      |      |      |
 *               '--------------------'    '--------------------'
 */
//  [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//      XXXXXXX, OSL(5) , XXXXXXX,  TO(1) ,  TO(0) , XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
//  )
};

/* Empty Layout
 * ,---------- -----------------------.    ,----------------------------------.
 * |      |      |      |      |      |    |      |      |      |      |      |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |      |      |      |      |      |    |      |      |      |      |      |
 * |------+------+------+------+------|    +------+------+------+------+------|
 * |      |      |      |      |      |    |      |      |      |      |      |
 * `------+------+------+------+------|    +------+------+------+-------------'
 *               |      |      |      |    |      |      |      |
 *               '--------------------'    '--------------------'
 */
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
//      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
//                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
        //0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        //0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        //0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    static const char PROGMEM crkbd_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x00, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x00, 0x00, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0x00, 0x80, 0x80,
        0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
        0x80, 0x80, 0x80, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
        0x1F, 0x3F, 0x7F, 0xFF, 0xFE, 0xFC,
        0xF8, 0xF0, 0xF8, 0xFC, 0xFC, 0x7E,
        0x3F, 0x1F, 0x0F, 0x0F, 0x07, 0x03,
        0xE1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xCF, 0xCF, 0xCF, 0xCF, 0xCF, 0xCF,
        0xCF, 0xCF, 0xCF, 0xCF, 0xCF, 0xCF,
        0x07, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF,
        0x1F, 0x8F, 0xEF, 0xEF, 0xEF, 0xEF,
        0xEF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0x07, 0xE0, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xCF, 0xCF, 0xCF, 0xCF,
        0xCF, 0xCF, 0xCF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0x07, 0x00, 0xE0, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0xCF,
        0xCF, 0xCF, 0xCF, 0xCF, 0xCF, 0xCF,
        0xCF, 0xCF, 0xCF, 0xCF, 0x07, 0xE0,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
        0xFC, 0xF8, 0xF0, 0xC0, 0x80, 0x00,
        0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0,
        0xF0, 0xF0, 0xF8, 0xFC, 0x7E, 0x3F,
        0x1F, 0x1F, 0x0F, 0x1F, 0x3F, 0x7F,
        0xFF, 0xFE, 0xFC, 0xF8, 0xE0, 0x00,
        0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7,
        0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7,
        0xF7, 0x07, 0xE0, 0xFF, 0xFF, 0xFF,
        0xFF, 0x3F, 0x00, 0x07, 0x0F, 0x1F,
        0x3F, 0xFF, 0xFF, 0xFF, 0xFB, 0xF3,
        0xE3, 0xC3, 0x83, 0xE0, 0xFF, 0xFF,
        0xFF, 0xFF, 0x3F, 0x07, 0x07, 0x07,
        0x07, 0x07, 0x07, 0x07, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xE0,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7,
        0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0xF7,
        0xF7, 0xF7, 0xF7, 0xF7, 0xF7, 0x07,
        0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
        0x00, 0x01, 0x07, 0x0F, 0x1F, 0x3F,
        0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x01, 0x01,
        0x01, 0x00, 0x00, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x00, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
        0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x00, 0x01, 0x01, 0x01, 0x01,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
        0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00,
        0};
    //oled_write_P(crkbd_logo, false);
    oled_write_raw_P((crkbd_logo), sizeof(crkbd_logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case XPW:
      if (record->event.pressed) {
        SEND_STRING("THIS_IS_MY_password!");
      }
      break;
  }
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
