/* Copyright 2020 marksard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "./common/oled_helper.h"

enum layer_number {
  _MACOS,
  _CAGS,
  _SYMBOLS,
  _NUMBERS,
  _NAV,
  _FUNCTION,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  CAGS = SAFE_RANGE,
  XPW = SAFE_RANGE,
  MACOS,
  SYMBOLS,
  NUMBERS,
  NAV,
  FUNCTION,
  RAISE,
  ADJUST,
  KANJI,
  RGBRST
};

/*
// Base layer mod tap
#define KC_Z_SF  LSFT_T(KC_Z)
#define KC_SLSF  RSFT_T(KC_SLSH)

// Lower layer mod tap
#define KC_11SF  LSFT_T(KC_F11)
#define KC_GRSF  RSFT_T(KC_GRV)
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* MACOS and CAGS
 *   -MACOS uses GACS for home row modifiers
 *   -CAGS uses, you guessed it, CAGS for home row modifiers
 * ,-----------------------------------------------------------------------------------------.
 * |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   ;    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   ,    |   .    |   /    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |  CAGS  |  MAC   | Sp/Fnc | Tb/Nav | BS/Num | Sp/Sym |  Enter | CapWrd |   MAC  |  CAGS  |
 * `-----------------------------------------------------------------------------------------'
 */
  [_MACOS] = LAYOUT_ortho_4x10(
  //,----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
          KC_Q,           KC_W,              KC_E,             KC_R,            KC_T,                 KC_Y,              KC_U,              KC_I,             KC_O,             KC_P,
  //|---------------+---------------+-------------------+---------------+---------------------+-------------------+-------------------+-----------------+----------------+-------------------|
       GUI_T(KC_A),    ALT_T(KC_S),      CTL_T(KC_D),      SFT_T(KC_F),         KC_G,                 KC_H,           RSFT_T(KC_J),       RCTL_T(KC_K),    RALT_T(KC_L),    RGUI_T(KC_SCLN),
  //|---------------+---------------+-------------------+---------------+---------------------+-------------------+-------------------+-----------------+----------------+-------------------|
          KC_Z,           KC_X,              KC_C,             KC_V,            KC_B,                 KC_N,              KC_M,              KC_COMM,         KC_DOT,          KC_SLSH,
  //`---------------+---------------+-------------------+---------------+---------------------+-------------------+-------------------+-----------------+----------------+-------------------'
         TO(CAGS),      TO(MACOS),   LT(FUNCTION,KC_SPC),LT(NAV, KC_TAB),LT(NUMBERS, KC_BSPC), LT(SYMBOLS, KC_SPC),      KC_ENT,            CW_TOGG,        TO(MACOS),        TO(CAGS)
  //,----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
  ),

  [_CAGS] = LAYOUT_ortho_4x10(
  //,----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
          KC_Q,           KC_W,              KC_E,             KC_R,            KC_T,                 KC_Y,              KC_U,              KC_I,             KC_O,             KC_P,
  //|---------------+---------------+-------------------+---------------+---------------------+-------------------+-------------------+-----------------+----------------+-------------------|
       CTL_T(KC_A),    ALT_T(KC_S),      GUI_T(KC_D),      SFT_T(KC_F),         KC_G,                 KC_H,           RSFT_T(KC_J),       RGUI_T(KC_K),    RALT_T(KC_L),    RCTL_T(KC_SCLN),
  //|---------------+---------------+-------------------+---------------+---------------------+-------------------+-------------------+-----------------+----------------+-------------------|
          KC_Z,           KC_X,              KC_C,             KC_V,            KC_B,                 KC_N,              KC_M,              KC_COMM,         KC_DOT,          KC_SLSH,
  //`---------------+---------------+-------------------+---------------+---------------------+-------------------+-------------------+-----------------+----------------+-------------------'
         TO(CAGS),      TO(MACOS),   LT(FUNCTION,KC_SPC),LT(NAV, KC_TAB),LT(NUMBERS, KC_BSPC), LT(SYMBOLS, KC_SPC),      KC_ENT,            CW_TOGG,        TO(MACOS),        TO(CAGS)
  //,----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
  ),

/* Symbols
 * ,---------------------------------------------------------------------.
 * |  ~   |  #   |   {  |   }  |   *  |   +  |  <   |  >   | ESC  | ESC  |
 * |------+------+------+------+-------------+------+------+------+------|
 * |  @   |  $   |   (  |   )  |   -  |   =  |  "   |  '   |  `   |  :   |
 * |------+------+------+------+------|------+------+------+------+------|
 * |  !   |  ^   |   [  |   ]  |   |  |   %  |  &   |  \   | INS  |      |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |  XPW |  DEL |   _  |   _  |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
  [_SYMBOLS] = LAYOUT_ortho_4x10(
  //,------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
        KC_TILDE,       KC_HASH,     KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE,      KC_ASTERISK,         KC_PLUS,       KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET,     KC_ESC,          KC_ESC,
  //|---------------+---------------+-------------------+---------------------+---------------------+-------------------+---------------------+-----------------------+----------------+-------------------|
          KC_AT,        KC_DOLLAR,      KC_LEFT_PAREN,       KC_RIGHT_PAREN,         KC_MINUS,            KC_EQUAL,         KC_DOUBLE_QUOTE,          KC_QUOTE,             KC_GRV,          KC_COLON,
  //|---------------+---------------+-------------------+---------------------+---------------------+-------------------+---------------------+-----------------------+----------------+-------------------|
        KC_EXCLAIM,   KC_CIRCUMFLEX,   KC_LEFT_BRACKET,    KC_RIGHT_BRACKET,          KC_PIPE,           KC_PERCENT,         KC_AMPERSAND,           KC_BACKSLASH,          KC_INS,          KC_NO,
  //`---------------+---------------+-------------------+---------------------+---------------------+-------------------+---------------------+-----------------------+----------------+-------------------'
          KC_NO,        KC_NO,              XPW,                KC_DEL,            KC_UNDERSCORE,      KC_UNDERSCORE,            KC_NO,                 KC_NO,              KC_NO,           KC_NO
  //,------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------.
  ),

/* Numbers
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |   7  |   7  |   8  |   9  |  +   |
 * |------+------+------+------+-------------+------+------+------+------|
 * |      |      |      |      |      |   4  |   4  |   5  |   6  |  +   |
 * |------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      |      |   1  |   1  |   2  |   3  |  +   |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   0  |   0  |   0  |   .  |Enter |
 * `---------------------------------------------------------------------'
 */
  [_NUMBERS] = LAYOUT_ortho_4x10(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7,   KC_7,   KC_8,   KC_9,   KC_PLUS,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4,   KC_4,   KC_5,   KC_6,   KC_PLUS,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1,   KC_1,   KC_2,   KC_3,   KC_PLUS,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0,   KC_0,   KC_0,   KC_DOT, KC_ENTER
  ),

/* Nav
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+-------------+------+------+------+------|
 * |      |      |      |      |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      |      |      | Home | PgDn | PgUp | End  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
  [_NAV] = LAYOUT_ortho_4x10(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO,        KC_NO,      KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN,  KC_UP,        KC_RIGHT,   KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_HOME,  KC_PAGE_DOWN, KC_PAGE_UP, KC_END,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO,        KC_NO,      KC_NO
  ),

/* Function
 * ,---------------------------------------------------------------------.
 * |      |      |      |      |      |      |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+-------------+------+------+------+------|
 * |      |      |      |      |      |      |  F5  |  F6  |  F7  |  F8  |
 * |------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F4  |
 * |------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |
 * `---------------------------------------------------------------------'
 */
  [_FUNCTION] = LAYOUT_ortho_4x10(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F5, KC_F6,  KC_F7,  KC_F8,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2,  KC_F3,  KC_F4,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO
  )
};

#define L_BASE _MACOS
#define L_LOWER (1<<_CAGS)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

#ifdef OLED_ENABLE
#include <stdio.h>
#include <string.h>

typedef struct {
  uint8_t state;
  char name[8];
}LAYER_DISPLAY_NAME;

#define LAYER_DISPLAY_MAX 5
const LAYER_DISPLAY_NAME layer_display_name[LAYER_DISPLAY_MAX] = {
  {L_BASE, "Base"},
  {L_BASE + 1, "Base"},
  {L_LOWER, "Lower"},
  {L_RAISE, "Raise"},
  {L_ADJUST_TRI, "Adjust"}
};

static inline const char* get_leyer_status(void) {

  for (uint8_t i = 0; i < LAYER_DISPLAY_MAX; ++i) {
    if (layer_state == 0 && layer_display_name[i].state == default_layer_state) {

      return layer_display_name[i].name;
    } else if (layer_state != 0 && layer_display_name[i].state == layer_state) {

      return layer_display_name[i].name;
    }
  }

  return "?";
}

static char layer_status_buf[24] = "Layer state ready.\n";
static inline void update_keymap_status(void) {

  snprintf(layer_status_buf, sizeof(layer_status_buf) - 1, "OS:%s Layer:%s\n",
    keymap_config.swap_lalt_lgui? "win" : "mac", get_leyer_status());
}

static inline void render_keymap_status(void) {

  oled_write(layer_status_buf, false);
}

#define UPDATE_KEYMAP_STATUS() update_keymap_status()

static inline void render_status(void) {

  UPDATE_LED_STATUS();
  RENDER_LED_STATUS();
  render_keymap_status();
  RENDER_LOCK_STATUS();
  RENDER_KEY_STATUS();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

  if (is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

bool oled_task_user(void) {

  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
    return false;
}

#else

#define UPDATE_KEYMAP_STATUS()

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  UPDATE_KEY_STATUS(keycode, record);

  bool result = false;
  switch (keycode) {
    case XPW:
      if (record->event.pressed) {
        SEND_STRING("THIS_IS_MY_password!");
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_CAGS);
      } else {
        layer_off(_CAGS);
      }

      update_tri_layer(_CAGS, _RAISE, _ADJUST);
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }

      update_tri_layer(_CAGS, _RAISE, _ADJUST);
      break;
    case KANJI:
      if (record->event.pressed) {
        if (keymap_config.swap_lalt_lgui == false) {
          register_code(KC_LNG2);
        } else {
          register_code16(A(KC_GRV));
        }
      } else {
        unregister_code(KC_LNG2);
      }
      break;
    #ifdef RGBLIGHT_ENABLE
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  UPDATE_KEYMAP_STATUS();
  return result;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case XPW:
      if (record->event.pressed) {
        SEND_STRING("THIS_IS_MY_password!");
      }
      break;
  }
  return true;
}
