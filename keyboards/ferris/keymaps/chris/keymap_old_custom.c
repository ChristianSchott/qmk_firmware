#include QMK_KEYBOARD_H

enum td_keycodes {
    TD_LL = SAFE_RANGE,
    TD_LR = SAFE_RANGE + 1,
    TD_RL = SAFE_RANGE + 2,
    TD_RR = SAFE_RANGE + 3,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base
    [0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_F, KC_P,  KC_B,  KC_J,  KC_L, KC_U,   KC_Y,           KC_BSPC,
                             KC_A, KC_R, KC_S, KC_T,  KC_G,  KC_M,  KC_N, KC_E,   KC_I,           KC_O, 
                             KC_Z, KC_X, KC_C, KC_D,  KC_V,  KC_K,  KC_H, KC_TAB, LALT_T(KC_GRV), KC_ENT,
                                               TD_LL, TD_LR, TD_RL, TD_RR),

    // symbol layer
    [1] = LAYOUT_split_3x5_2(KC_BSLS, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_CIRC, 
                             KC_QUES, KC_EXLM, KC_COMM, KC_DOT,  KC_DQUO, KC_UNDS, KC_EQL,  KC_LPRN, KC_RPRN, KC_COLN,
                             KC_SLSH, KC_PIPE, KC_LT,   KC_GT,   KC_QUOT, KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_SCLN, 
                                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),


    // navigation layer
    [2] = LAYOUT_split_3x5_2(KC_SPC,  RALT(KC_5), RALT(KC_S), KC_PSCR,    KC_INS,     RALT(KC_Q), RALT(KC_P), RALT(KC_Y), KC_DEL,  KC_BSPC, 
                             KC_ESC,  KC_LALT,    KC_LSFT,    KC_LCTL,    KC_CAPS,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT, KC_TAB, 
                             KC_LGUI, KC_MPLY,    KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,  KC_ENT, 
                                                              KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),

    // number + fn layer
    [3] = LAYOUT_split_3x5_2(KC_F6,  KC_F7,         KC_F8,         KC_F9,         KC_F10,   KC_COMM,    KC_7,   KC_8,   KC_9,   KC_TRNS,
                             KC_F11, OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_F12,   KC_DOT,     KC_4,   KC_5,   KC_6,   KC_0, 
                             KC_F1,  KC_F2,         KC_F3,         KC_F4,         KC_F5,    KC_EQL,     KC_1,   KC_2,   KC_3,   KC_TRNS, 
                                                                   KC_TRNS,       KC_TRNS,  KC_TRNS,    KC_TRNS),

    // mouse layer
    [4] = LAYOUT_split_3x5_2(QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                             KC_TRNS, KC_BTN3, KC_BTN2, KC_BTN1, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, 
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, 
                                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    // left function layer
    [5] = LAYOUT_split_3x5_2(QK_BOOT, KC_RALT, TG(7),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                             KC_ESC,  KC_LALT, KC_LSFT, KC_LCTL, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                             KC_LGUI, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    // right function layer
    [6] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, QK_BOOT, 
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_LCTL, KC_LSFT, KC_LALT, KC_ESC, 
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_MPLY, KC_LGUI, 
                                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    // wasd layer
    [7] = LAYOUT_split_3x5_2(KC_ESC,  KC_Q, KC_W,  KC_E,    KC_R,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                             KC_LSFT, KC_A, KC_S,  KC_D,    KC_F,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                             KC_LCTL, KC_Z, KC_X,  KC_C,    KC_V,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                                     TG(7), KC_SPC, KC_TRNS, KC_TRNS),
};
// clang-format on

#define SYM_LAYER 1
#define NAV_LAYER 2
#define NUM_LAYER 3
#define MOUSE_LAYER 4
#define LFN_LAYER 5
#define RFN_LAYER 6
#define WASD_LAYER 7

#define QUICK_TAP_TIME 75

const uint8_t LL_HOLD    = 1 << 0; // ctrl
const uint8_t LL_DOUBLE  = 1 << 1; // fn-left
const uint8_t RR_HOLD    = 1 << 2; // num
const uint8_t RR_DOUBLE  = 1 << 3; // fn-right
const uint8_t LR_HOLD    = 1 << 4; // space / nav
const uint8_t RL_HOLD    = 1 << 5; // sym
const uint8_t SPC_FLAG   = 1 << 6;
const uint8_t SFT_FLAG   = 1 << 7;
const uint8_t COMB_SHIFT = LR_HOLD | RL_HOLD;
const uint8_t COMB_MOUSE = LL_HOLD | RR_HOLD;

static uint32_t ll_deadline = 0;
static uint32_t rr_deadline = 0;
static uint32_t key_timer   = 0;
static uint32_t lr_timer    = 0;
static uint32_t rl_timer    = 0;

static uint8_t state = 0;

inline bool is_set(uint8_t state, uint8_t flags) {
    return (state & flags) == flags;
}

inline bool changed(uint8_t state, uint8_t other_state, uint8_t flags) {
    return is_set(state, flags) != is_set(other_state, flags);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    const uint32_t timer     = timer_read32();
    uint8_t        old_state = state;

    switch (keycode) {
        case TD_LL: {
            if (record->event.pressed) {
                if (!timer_expired32(timer, ll_deadline)) {
                    state |= LL_DOUBLE;
                } else {
                    ll_deadline = timer + TAPPING_TERM;
                    state |= LL_HOLD;
                }
            } else {
                state &= ~(LL_HOLD | LL_DOUBLE);
                if (!timer_expired32(timer, ll_deadline)) {
                    ll_deadline = timer + TAPPING_TERM;
                }
            }
            break;
        }

        case TD_LR: {
            if (record->event.pressed) {
                if (timer_elapsed(key_timer) < 120) {
                    tap_code(KC_SPC);
                } else {
                    state |= LR_HOLD;
                    // only set space flag, if we did not just start holding rl
                    if (!(is_set(state, RL_HOLD) && timer_elapsed(rl_timer) < QUICK_TAP_TIME)) {
                        state |= SPC_FLAG;
                        lr_timer = timer;
                    }
                }
            } else {
                if (is_set(state, SPC_FLAG) && timer_elapsed(lr_timer) < TAPPING_TERM) {
                    tap_code(KC_SPC);
                }
                state &= ~(LR_HOLD | SPC_FLAG);
            }
            state &= ~SFT_FLAG;
            break;
        }

        case TD_RL: {
            if (record->event.pressed) {
                state |= RL_HOLD;
                // only set shift flag, if we did not just start holding lr
                if (!(is_set(state, LR_HOLD) && timer_elapsed(lr_timer) < QUICK_TAP_TIME)) {
                    state |= SFT_FLAG;
                    rl_timer = timer;
                    clear_oneshot_mods(); // don't use shift OSM when in symbol layer
                }
            } else {
                if (is_set(state, SFT_FLAG) && timer_elapsed(rl_timer) < TAPPING_TERM) {
                    // tap_code(KC_SPC);
                    set_oneshot_mods(MOD_BIT(KC_LSFT));
                }
                state &= ~(RL_HOLD | SFT_FLAG);
            }
            state &= ~SPC_FLAG;
            break;
        }

        case TD_RR: {
            if (record->event.pressed) {
                if (!timer_expired32(timer, rr_deadline)) {
                    state |= RR_DOUBLE;
                } else {
                    rr_deadline = timer + TAPPING_TERM;
                    state |= RR_HOLD;
                }
            } else {
                state &= ~(RR_HOLD | RR_DOUBLE);
                if (!timer_expired32(timer, rr_deadline)) {
                    rr_deadline = timer + TAPPING_TERM;
                }
            }
            break;
        }

        default: {
            if (record->event.pressed) {
                if (keycode >= KC_A && keycode <= KC_Z) {
                    key_timer = timer; // remember when the last key was pressed
                }
                state &= ~(SPC_FLAG | SFT_FLAG); // unset space flag when hitting other key while
            }
        }
    }

    // clang-format off
    bool shift = is_set(state, COMB_SHIFT);
    layer_state_set(
        1 
        | (is_set(state, COMB_MOUSE) ? 1 : 0) << MOUSE_LAYER 
        | (is_set(state, LR_HOLD) && !shift ? 1 : 0) << NAV_LAYER 
        | (is_set(state, RL_HOLD) && !shift ? 1 : 0) << SYM_LAYER 
        | (is_set(state, RR_HOLD) ? 1 : 0) << NUM_LAYER 
        | (is_set(state, LL_DOUBLE) ? 1 : 0) << LFN_LAYER 
        | (is_set(state, RR_DOUBLE) ? 1 : 0) << RFN_LAYER 
        | (IS_LAYER_ON(WASD_LAYER) ? 1 : 0) << WASD_LAYER // retain WASD layer state
    );
    // clang-format on

    if (changed(old_state, state, LL_HOLD) || changed(old_state, state, RR_HOLD)) {
        if (is_set(state, LL_HOLD) && !is_set(state, RR_HOLD)) {
            register_mods(MOD_LCTL);
        } else {
            unregister_mods(MOD_LCTL);
        }
    }

    if (changed(old_state, state, COMB_SHIFT)) {
        if (is_set(state, COMB_SHIFT)) {
            register_mods(MOD_LSFT);
        } else {
            unregister_mods(MOD_LSFT);
        }
    }

    if (keycode != TD_LL) {
        ll_deadline = 0;
    }
    if (keycode != TD_RR) {
        rr_deadline = 0;
    }

    return true;
}