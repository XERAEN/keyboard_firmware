#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _CAGS,
    _GACS,
    _SYMBOLS,
    _NUMBERS,
    _NAV,
    _FUNCTION,
    _LAYERS,
    _GAMING
};

enum custom_keycodes {
  CAGS = SAFE_RANGE,
  GACS,
  SYMBOLS,
  NUMBERS,
  NAV,
  FUNCTION,
  LAYERS,
  GAMING,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* CAGS Base Layer
 *   -uses CAGS for home row modifiers
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |Backsp|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | NAV  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LSHIFT|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RSHIFT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GACS | Func | ENTER|Sp/Fnc|Tb/Nav|BS/Num|Sp/Sym|Ent/Ly|CapWrd|  GUI | GACS | CAGS |
 * `-----------------------------------------------------------------------------------'
 */
[_CAGS] = LAYOUT(
  KC_ESC,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPC,
 LT(NUMBERS,KC_TAB),KC_Q,        KC_W,       KC_E,               KC_R,           KC_T,                KC_Y,               KC_U,              KC_I,        KC_O,        KC_P,           KC_BACKSLASH,
  LT(NAV,KC_NO),    CTL_T(KC_A), ALT_T(KC_S),GUI_T(KC_D),        SFT_T(KC_F),    KC_G,                KC_H,               RSFT_T(KC_J),      RGUI_T(KC_K),RALT_T(KC_L),RCTL_T(KC_SCLN),KC_QUOTE,
  KC_LSFT,          KC_Z,        KC_X,       KC_C,               KC_V,           KC_B,                KC_N,               KC_M,              KC_COMM,     KC_DOT,      KC_SLSH,        KC_RSFT,
  TO(GACS),         MO(FUNCTION),KC_ENT,     LT(FUNCTION,KC_SPC),LT(NAV, KC_TAB),LT(NUMBERS, KC_BSPC),LT(SYMBOLS, KC_SPC),LT(LAYERS, KC_ENT),CW_TOGG,     KC_RGUI,     TO(GACS),       TO(CAGS)
),

/* GACS Base Layer
 *   -uses GACS for home row modifiers
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |Backsp|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | NAV  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LSHIFT|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RSHIFT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GACS | Func | ENTER|Sp/Fnc|Tb/Nav|BS/Num|Sp/Sym|Ent/Ly|CapWrd|  GUI | GACS | CAGS |
 * `-----------------------------------------------------------------------------------'
 */

[_GACS] = LAYOUT(
  KC_ESC,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPC,
 LT(NUMBERS,KC_TAB),KC_Q,        KC_W,       KC_E,               KC_R,           KC_T,                KC_Y,               KC_U,              KC_I,        KC_O,        KC_P,           KC_BACKSLASH,
  LT(NAV,KC_NO),    GUI_T(KC_A), ALT_T(KC_S),CTL_T(KC_D),        SFT_T(KC_F),    KC_G,                KC_H,               RSFT_T(KC_J),      RCTL_T(KC_K),RALT_T(KC_L),RGUI_T(KC_SCLN),KC_QUOTE,
  KC_LSFT,          KC_Z,        KC_X,       KC_C,               KC_V,           KC_B,                KC_N,               KC_M,              KC_COMM,     KC_DOT,      KC_SLSH,        KC_RSFT,
  TO(GACS),         MO(FUNCTION),KC_ENT,     LT(FUNCTION,KC_SPC),LT(NAV, KC_TAB),LT(NUMBERS, KC_BSPC),LT(SYMBOLS, KC_SPC),LT(LAYERS, KC_ENT),CW_TOGG,     KC_RGUI,     TO(GACS),       TO(CAGS)
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ~   |  #   |   {  |   }  |   *  |   +  |  <   |  >   | ESC  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  @   |  $   |   (  |   )  |   -  |   =  |  "   |  '   |  `   |  :   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  !   |  ^   |   [  |   ]  |   |  |   %  |  &   |  \   | INS  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GACS |      |      |  DEL |  DEL |   _  |   _  |      |      |      | GACS | CAGS |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT(
  KC_NO,    KC_NO,        KC_NO,         KC_NO,               KC_NO,                KC_NO,         KC_NO,         KC_NO,                 KC_NO,                  KC_NO,  KC_NO,    KC_NO,
  KC_NO,    KC_TILDE,     KC_HASH,       KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_ASTERISK,   KC_PLUS,       KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, KC_ESC, KC_NO,    KC_NO,
  KC_NO,    KC_AT,        KC_DOLLAR,     KC_LEFT_PAREN,       KC_RIGHT_PAREN,       KC_MINUS,      KC_EQUAL,      KC_DOUBLE_QUOTE,       KC_QUOTE,               KC_GRV, KC_COLON, KC_NO,
  KC_NO,    KC_EXCLAIM,   KC_CIRCUMFLEX, KC_LEFT_BRACKET,     KC_RIGHT_BRACKET,     KC_PIPE,       KC_PERCENT,    KC_AMPERSAND,          KC_BACKSLASH,           KC_INS, KC_NO,    KC_NO,
  TO(GACS), KC_NO,        KC_NO,         KC_DEL,              KC_DEL,               KC_UNDERSCORE, KC_UNDERSCORE, KC_NO,                 KC_NO,                  KC_NO,  TO(GACS), TO(CAGS)
),

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |  +   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |  +   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |Enter | GACS |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GACS |      |      |      |      |      |   0  |   0  |   0  |   .  |Enter | CAGS |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS] = LAYOUT(
  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,    KC_NO,
  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7,  KC_8,  KC_9,   KC_PLUS,  KC_NO,
  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4,  KC_5,  KC_6,   KC_PLUS,  KC_NO,
  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1,  KC_2,  KC_3,   KC_ENTER, TO(GACS),
  TO(GACS), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0,  KC_0,  KC_0,  KC_DOT, KC_ENTER, TO(CAGS)
),

/* Nav
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MsRClk| MsUp |MsLClk|MsBtn3|      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |MsScUp|MsLft | MsDn |MsRgt |MsScDn| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GACS |      |      |      |      |      |      |      |      |      | GACS | CAGS |
 * `-----------------------------------------------------------------------------------'
 */

[_NAV] = LAYOUT(
  KC_NO,    KC_NO,       KC_NO,      KC_NO,      KC_NO,       KC_NO,         KC_NO,   KC_NO,        KC_NO,      KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_NO,       KC_MS_BTN2, KC_MS_UP,   KC_MS_BTN1,  KC_MS_BTN3,    KC_NO,   KC_NO,        KC_NO,      KC_NO,    KC_NO,    KC_NO,
  KC_NO,    KC_MS_WH_UP, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, KC_LEFT, KC_DOWN,      KC_UP,      KC_RIGHT, KC_NO,    KC_NO,
  KC_NO,    KC_NO,       KC_NO,      KC_NO,      KC_NO,       KC_NO,         KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP, KC_END,   KC_NO,    KC_NO,
  TO(GACS), KC_NO,       KC_NO,      KC_NO,      KC_NO,       KC_NO,         KC_NO,   KC_NO,        KC_NO,      KC_NO,    TO(GACS), TO(CAGS)
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F9  |  F10 |  F11 |  F12 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F5  |  F6  |  F7  |  F8  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F4  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GACS |      |      |      |      |      |      |      |      |      | GACS | CAGS |
 * `-----------------------------------------------------------------------------------'
 */

[_FUNCTION] = LAYOUT(
  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,    KC_NO,
  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12,   KC_NO,
  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F5, KC_F6,  KC_F7,  KC_F8,    KC_NO,
  KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2,  KC_F3,  KC_F4,    KC_NO,
  TO(GACS), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  TO(GACS), TO(CAGS)
),

/* LAYERS
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |FuncOS|Gaming| GACS | CAGS |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GACS |      |      |      |      |      |      |      |      |      | GACS | CAGS |
 * `-----------------------------------------------------------------------------------'
 */

[_LAYERS] = LAYOUT(
  KC_NO,    KC_NO,         KC_NO,      KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,
  KC_NO,    OSL(FUNCTION), TO(GAMING), TO(GACS), TO(CAGS), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,
  KC_NO,    KC_NO,         KC_NO,      KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,
  KC_NO,    KC_NO,         KC_NO,      KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,
  TO(GACS), KC_NO,         KC_NO,      KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(GACS), TO(CAGS)
),

/* GAMING Base Layer
 *   For use with Linux and Windows
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |Backsp|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | GACS |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   M  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Ctrl | Alt  | Alt  | Num  |Space |Space | Sym  |Layers| GACS | GACS | CAGS |
 * `-----------------------------------------------------------------------------------'
 */

[_GAMING] = LAYOUT(
  KC_ESC,        KC_1,         KC_2,        KC_3,        KC_4,        KC_5,    KC_6,   KC_7,        KC_8,       KC_9,      KC_0,     KC_BSPC,
  KC_TAB,        KC_Q,         KC_W,        KC_E,        KC_R,        KC_T,    KC_Y,   KC_U,        KC_I,       KC_O,      KC_P,     TO(GACS),
  KC_M,          KC_A,         KC_S,        KC_D,        KC_F,        KC_G,    KC_H,   KC_J,        KC_K,       KC_L,      KC_SCLN,  KC_ENT,
  KC_LEFT_SHIFT, KC_Z,         KC_X,        KC_C,        KC_V,        KC_B,    KC_N,   KC_M,        KC_COMM,    KC_DOT,    KC_SLSH,  KC_ENT,
  KC_LEFT_CTRL,  KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_ALT, MO(NUMBERS), KC_SPC,  KC_SPC, MO(SYMBOLS), MO(LAYERS), TO(GACS),  TO(GACS), TO(CAGS)
)

/* BLANK
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/*
[_BLANK] = LAYOUT(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),
*/

};
