#include QMK_KEYBOARD_H


/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_GRV, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SCLN, KC_LCTL, MO(1), MO(2), OSL(3)),
	[1] = LAYOUT_split_3x5_2(KC_TAB, KC_NO, RALT(KC_S), KC_PSCR, KC_INS, RALT(KC_Q), RALT(KC_P), RALT(KC_Y), KC_DEL, KC_SPC, KC_ESC, KC_LALT, KC_LSFT, KC_LCTL, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC, KC_LGUI, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB),
	[2] = LAYOUT_split_3x5_2(KC_BSLS, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_TILD, KC_QUES, KC_EXLM, KC_QUOT, KC_DQUO, KC_CIRC, KC_UNDS, KC_EQL, KC_LPRN, KC_RPRN, KC_BSPC, KC_SLSH, KC_PIPE, KC_LT, KC_GT, RALT(KC_5), KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_COLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB),
	[3] = LAYOUT_split_3x5_2(KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_COMM, KC_7, KC_8, KC_9, KC_BSPC, KC_F11, OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_F12, KC_DOT, KC_0, KC_1, KC_2, KC_3, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, RALT(KC_5), KC_4, KC_5, KC_6, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)




