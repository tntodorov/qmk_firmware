/* Copyright 2020 gtips
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
                                            KC_LALT,   LOWER,    KC_SPC,   RAISE,    KC_RGUI
  ),

  [_LOWER] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,              KC_7,     KC_8,     KC_9,     KC_0,     KC_LBRC,  KC_DEL,
    _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,             KC_4,     KC_5,     KC_6,     KC_MINS,  KC_RBRC,  KC_APP,
    _______,  KC_F11,   KC_F12,   KC_F13,   KC_F14,    KC_F15,             KC_1,     KC_2,     KC_3,     KC_EQL,   KC_BSLS,  RSFT_T(KC_SPC),
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),

  [_RAISE] = LAYOUT(
    KC_ESC,   KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,   KC_LCBR,            KC_MYCM,  KC_CALC,  XXXXXXX,  XXXXXXX,  KC_INS,   KC_DEL,
    _______,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_MINS,   KC_RCBR,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_GRV,   KC_TILD,
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_EQL,    KC_BSLS,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_CAPS,  RSFT_T(KC_SPC),
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),

  [_ADJUST] = LAYOUT(
    QK_BOOT,  KC_F16,   KC_F17,   KC_F18,   KC_F19,    KC_F20,             RGB_VAI,  RGB_SAI,  RGB_HUI,  RGB_MOD,  RGB_M_R,  RGB_TOG,
    _______,  KC_F21,   KC_F22,   KC_F23,   KC_F24,    XXXXXXX,            RGB_VAD,  RGB_SAD,  RGB_HUD,  RGB_RMOD, KC_PSCR,  KC_SCRL,
    _______,  XXXXXXX,  XXXXXXX,  KC_MUTE,  KC_VOLD,   KC_VOLU,            KC_MPRV,  KC_MSTP,  KC_MPLY,  KC_MNXT,  KC_BRID,  KC_BRIU,
                                            _______,   _______,  XXXXXXX,  _______,  XXXXXXX
  ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    // static const uint8_t rgb_cols[][3] = {
    //     { 0xff, 0x00, 0x00, },
    //     { 0x00, 0xff, 0x00, },
    //     { 0x00, 0x00, 0xff, },
    //     { 0xff, 0x00, 0xff, },
    // };
    // static idx = 0;

    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

    // switch (get_highest_layer(state)) {
    // case _RAISE:
    //     rgblight_setrgb(rgb_cols[2][0], rgb_cols[2][1], rgb_cols[2][2]);
    //     break;
    // case _LOWER:
    //     rgblight_setrgb(rgb_cols[1][0], rgb_cols[1][1], rgb_cols[1][2]);
    //     break;
    // case _ADJUST:
    //     rgblight_setrgb(rgb_cols[3][0], rgb_cols[3][1], rgb_cols[3][2]);
    //     break;
    // default: //  for any other layers, or the default layer
    //     rgblight_setrgb(rgb_cols[0][0], rgb_cols[0][1], rgb_cols[0][2]);
    //     break;
    // }
    return state;
}
