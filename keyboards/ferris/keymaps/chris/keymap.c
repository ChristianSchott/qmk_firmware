#include QMK_KEYBOARD_H

enum td_keycodes {
    TD_L = SAFE_RANGE,
    TD_R = SAFE_RANGE + 1,
};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_S, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_A, KC_R, KC_SPC, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_F, KC_COMM, KC_DOT, KC_LCTL, TD_L, TD_R, OSL(3)),
//                                                               [1] = LAYOUT_split_3x5_2(KC_TAB, KC_NO, RALT(KC_S), KC_PSCR, KC_INS, RALT(KC_Q), RALT(KC_P), RALT(KC_Y), KC_DEL, KC_GRV, KC_ESC, KC_LALT, KC_LSFT, KC_LCTL, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC, KC_LGUI, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB),
//                                                               [2] = LAYOUT_split_3x5_2(KC_BSLS, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_COLN, KC_QUES, KC_EXLM, KC_QUOT, KC_DQUO, KC_TILD, KC_UNDS, KC_EQL, KC_LPRN, KC_RPRN, KC_BSPC, KC_SLSH, KC_PIPE, KC_LT, KC_GT, KC_CIRC, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB),
//                                                               [3] = LAYOUT_split_3x5_2(KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_COMM, KC_7, KC_8, KC_9, KC_BSPC, KC_F11, OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_F12, KC_DOT, KC_4, KC_5, KC_6, KC_0, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, RALT(KC_5), KC_1, KC_2, KC_3, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x5_2(
                                                                KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_GRV, 
                                                                KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, 
                                                                KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, RALT_T(KC_SCLN), 
                                                                                    KC_LCTL, TD_L, TD_R, OSL(3)),
                                                              [1] = LAYOUT_split_3x5_2(
                                                                KC_ESC, KC_NO, RALT(KC_S), KC_PSCR, KC_INS, RALT(KC_Q), RALT(KC_P), RALT(KC_Y), KC_DEL, KC_SPC,
                                                                KC_TAB, KC_LALT, KC_LSFT, KC_LCTL, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC, 
                                                                KC_LGUI, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_ENT, 
                                                                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB),
                                                              [2] = LAYOUT_split_3x5_2(KC_BSLS, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_TILD, KC_QUES, KC_EXLM, KC_QUOT, KC_DQUO, KC_CIRC, KC_UNDS, KC_EQL, KC_LPRN, KC_RPRN, KC_BSPC, KC_SLSH, KC_PIPE, KC_LT, KC_GT, RALT(KC_5), KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_COLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB),
                                                              [3] = LAYOUT_split_3x5_2(
                                                                KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                             KC_COMM, KC_7, KC_8, KC_9, KC_DOT, 
                                                                KC_F11, OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_F12,    KC_0, KC_1, KC_2, KC_3, KC_BSPC,
                                                                KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                              RALT(KC_5), KC_4, KC_5, KC_6, KC_ENT, 
                                                                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};
// clang-format on

#define NAV_LAYER 1
#define SYM_LAYER 2

const uint8_t HOLD_L     = 1 << 0; // ctrl
const uint8_t HOLD_R     = 1 << 1; // fn-left
const uint8_t SPACE_FLAG = 1 << 2; // fn-left

static uint8_t state = 0;

static uint32_t lr_timer    = 0;
static uint32_t alpha_timer = 0;

inline bool is_set(uint8_t state, uint8_t flags) {
    return (state & flags) == flags;
}

inline bool changed(uint8_t state, uint8_t other_state, uint8_t flags) {
    return is_set(state, flags) != is_set(other_state, flags);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    const uint8_t old_state = state;

    switch (keycode) {
        case TD_L: {
            if (record->event.pressed) {
                state |= HOLD_L;
                if (!is_set(state, HOLD_R)) {
                    // pressing L right after an alpha -> force send space instead of layer
                    if (timer_elapsed(alpha_timer) < 60) {
                        tap_code(KC_SPC);
                    } else {
                        state |= SPACE_FLAG;
                        lr_timer = timer_read32();
                    }
                }
            } else {
                if (is_set(state, SPACE_FLAG) && timer_elapsed(lr_timer) < TAPPING_TERM) {
                    tap_code(KC_SPC);
                }
                state &= ~(HOLD_L | SPACE_FLAG);
            }
            break;
        }
        case TD_R: {
            if (record->event.pressed) {
                state |= HOLD_R;
            } else {
                state &= ~HOLD_R;
            }
            break;
        }
        default: {
            if (record->event.pressed && keycode >= KC_A && keycode <= KC_Z) {
                alpha_timer = timer_read32();
            }
        }
    }
    if (keycode != TD_L) {
        state &= ~SPACE_FLAG;
    }

    if (old_state != state) {
        if (is_set(state, HOLD_L) && !is_set(state, HOLD_R)) {
            layer_on(NAV_LAYER);
        } else {
            layer_off(NAV_LAYER);
        }

        if (is_set(state, HOLD_R) && !is_set(state, HOLD_L)) {
            layer_on(SYM_LAYER);
        } else {
            layer_off(SYM_LAYER);
        }

        if (is_set(state, HOLD_L) && is_set(state, HOLD_R)) {
            register_mods(MOD_LSFT);
        } else {
            unregister_mods(MOD_LSFT);
        }
    }

    return true;
}
