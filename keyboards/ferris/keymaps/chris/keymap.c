#include QMK_KEYBOARD_H

enum td_keycodes {
    TD_LL = SAFE_RANGE,
    TD_LR = SAFE_RANGE + 1,
    TD_RL = SAFE_RANGE + 2,
    TD_RR = SAFE_RANGE + 3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base
    [0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
                             KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, 
                             KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_TAB, LALT_T(KC_GRV), KC_ENT,
                                             TD_LL, TD_LR, TD_RL, TD_RR),

    // symbol layer
    [1] = LAYOUT_split_3x5_2(KC_BSLS, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_CIRC, 
                             KC_QUES, KC_EXLM, KC_COMM, KC_DOT, KC_DQUO, KC_UNDS, KC_EQL, KC_LPRN, KC_RPRN, KC_COLN,
                             KC_SLSH, KC_PIPE, KC_LT, KC_GT, KC_QUOT, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_SCLN, 
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


    // navigation layer
    [2] = LAYOUT_split_3x5_2(KC_SPC, RALT(KC_Q), RALT(KC_P), RALT(KC_Y), RALT(KC_S), KC_PSCR, KC_INS, KC_LSFT, KC_DEL, KC_BSPC, 
                             KC_ESC, KC_LALT, KC_LSFT, KC_LCTL, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TAB, 
                             KC_LGUI, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_ENT, 
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    // number + fn layer
    [3] = LAYOUT_split_3x5_2(KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                            KC_COMM,    KC_7, KC_8, KC_9, KC_TRNS,
                             KC_F11, OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_F12,   KC_DOT,     KC_4, KC_5, KC_6, KC_0, 
                             KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                             RALT(KC_5), KC_1, KC_2, KC_3, 
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    // mouse layer
    [4] = LAYOUT_split_3x5_2(QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                             KC_TRNS, KC_BTN3, KC_BTN2, KC_BTN1, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, 
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, 
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    // left function layer
    [5] = LAYOUT_split_3x5_2(QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                             KC_ESC, KC_LALT, KC_LSFT, KC_LCTL, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                             KC_LGUI, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    //right function layer
    [6] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT, 
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_LCTL, KC_LSFT, KC_LALT, KC_ESC, 
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_MPLY, KC_LGUI, 
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

    // TODO: wasd layer
};

#define SYM_LAYER 1
#define NAV_LAYER 2
#define NUM_LAYER 3
#define MOUSE_LAYER 4
#define LFN_LAYER 5
#define RFN_LAYER 6

const uint8_t LL_HOLD     = 1 << 0;   // ctrl
const uint8_t LL_DOUBLE   = 1 << 1;   // fn-left
const uint8_t RR_HOLD     = 1 << 2;   // num
const uint8_t RR_DOUBLE   = 1 << 3;   // fn-right
const uint8_t LR_HOLD     = 1 << 4;   // space / nav
const uint8_t RL_HOLD     = 1 << 5;   // sym
const uint8_t RL_DOUBLE   = 1 << 6;   // shift
const uint8_t SPC_FLAG    = 1 << 7;
const uint8_t COMB_NAV    = LR_HOLD | RL_HOLD;
const uint8_t COMB_MOUSE  = LL_HOLD | RR_HOLD;

static uint32_t ll_deadline = 0;
static uint32_t rl_deadline = 0;
static uint32_t rr_deadline = 0;

static uint8_t state = 0;

inline bool is_set(uint8_t state, uint8_t flags) {
    return (state & flags) == flags;
}

inline bool changed(uint8_t state, uint8_t other_state, uint8_t flags) {
    return is_set(state, flags) != is_set(other_state, flags);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {

    uint8_t old_state = state;

    switch (keycode) {
    case TD_LL:
    {
        if (record->event.pressed) {
            if (!timer_expired32(timer_read32(), ll_deadline)) {
                state |= LL_DOUBLE;
            } else {
                ll_deadline = timer_read32() + TAPPING_TERM;
                state |= LL_HOLD;
            }
        } else {
            state &= ~(LL_HOLD | LL_DOUBLE);
            if (!timer_expired32(timer_read32(), ll_deadline)) {
                ll_deadline = timer_read32() + TAPPING_TERM;
            }
        }
        break;
    }

    case TD_LR:
    {
        if (record->event.pressed) {
            state |= LR_HOLD | SPC_FLAG;
        } else {
            if (is_set(state, SPC_FLAG)) {
                tap_code(KC_SPC);
            }
            state &= ~(LR_HOLD| SPC_FLAG);
        }
        break;
    }

    case TD_RL:
    {
        if (record->event.pressed) {
            del_oneshot_mods(MOD_LSFT);
            if (!timer_expired32(timer_read32(), rl_deadline)) {
                state |= RL_DOUBLE;
            } else {
                rl_deadline = timer_read32() + TAPPING_TERM;
                state |= RL_HOLD;
            }
        } else {
            state &= ~(RL_HOLD | RL_DOUBLE);
            if (!timer_expired32(timer_read32(), rl_deadline)) {
                add_oneshot_mods(MOD_LSFT);
                rl_deadline = timer_read32() + TAPPING_TERM;
            }
        }
        break;
    }

    case TD_RR:
    {
        if (record->event.pressed) {
            if (!timer_expired32(timer_read32(), rr_deadline)) {
                state |= RR_DOUBLE;
            } else {
                rr_deadline = timer_read32() + TAPPING_TERM;
                state |= RR_HOLD;
            }
        } else {
            state &= ~(RR_HOLD | RR_DOUBLE);
            if (!timer_expired32(timer_read32(), rr_deadline)) {
                rr_deadline = timer_read32() + TAPPING_TERM;
            }
        }
        break;
    }

    default:
    {
        // pressing any other key while LR_HOLD should send space before key
        if (record->event.pressed && is_set(state, SPC_FLAG) && !is_set(state, RL_HOLD)) {
            tap_code(KC_SPC);
            state &= ~SPC_FLAG;
        }
    }
    }

    layer_state_set(
        1
        | (is_set(state, COMB_MOUSE) ? 1 : 0) << MOUSE_LAYER
        | (is_set(state, COMB_NAV) ? 1 : 0) << NAV_LAYER
        | (is_set(state, RR_HOLD) ? 1 : 0) << NUM_LAYER
        | (is_set(state, RL_HOLD) ? 1 : 0) << SYM_LAYER
        | (is_set(state, LL_DOUBLE) ? 1 : 0) << LFN_LAYER
        | (is_set(state, RR_DOUBLE) ? 1 : 0) << RFN_LAYER
    );

    if (is_set(state, COMB_NAV)) {
        state &= ~SPC_FLAG;
    }

    if (changed(old_state, state, LL_HOLD)) {
        if (is_set(state, LL_HOLD)) {
            register_mods(MOD_LCTL);
        } else {
            unregister_mods(MOD_LCTL);
        }
    }

    if (changed(old_state, state, RL_DOUBLE)) {
        if (is_set(state, RL_DOUBLE)) {
            register_mods(MOD_LSFT);
        } else {
            unregister_mods(MOD_LSFT);
        }
    }
    

    if (keycode != TD_LL) {
        ll_deadline = 0;
    }
    if (keycode != TD_RL) {
        rl_deadline = 0;
    }
    if (keycode != TD_RR) {
        rr_deadline = 0;
    }

    return true;
}