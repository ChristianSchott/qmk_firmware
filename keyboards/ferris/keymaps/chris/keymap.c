#include QMK_KEYBOARD_H

enum td_keycodes {
    TD_LL,
    TD_LR,
    TD_RL,
    TD_RR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base
    [0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
                             KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, 
                             KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_TAB, LALT_T(KC_GRV), KC_ENT,
                                             TD(TD_LL), TD(TD_LR), TD(TD_RL), TD(TD_RR)),

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
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

    // TODO: wasd layer
};

// static uint8_t ltb_state = 0;
// #define LTB_LAYER 2
static uint8_t rtb_state = 0;
#define RTB_LAYER 2



// bool process_record_user(uint16_t keycode, keyrecord_t* record) {  
    // {
    //     static uint32_t tap_deadline = 0;
    //     if (keycode == CKC_LTB) {
    //         if (record->event.pressed) {
    //             del_oneshot_mods(MOD_LCTL);
    //             if (ltb_state == 2 && !timer_expired32(timer_read32(), tap_deadline)) {
    //                 register_mods(MOD_LCTL);
    //                 ltb_state = 3;
    //             } else {
    //                 tap_deadline = timer_read32() + TAPPING_TERM;
    //                 layer_on(LTB_LAYER);
    //                 ltb_state = 1;
    //             }
    //         } else {
    //             if (ltb_state == 1) {
    //                 layer_off(LTB_LAYER);
    //                 if (!timer_expired32(timer_read32(), tap_deadline)) {
    //                     tap_deadline = timer_read32() + TAPPING_TERM;
    //                     add_oneshot_mods(MOD_LCTL);
    //                     ltb_state = 2;
    //                 }
    //             } else if (ltb_state == 3) {
    //                 unregister_mods(MOD_LCTL);
    //             }
    //         }
    //     } else {
    //         if (ltb_state == 1) {
    //             tap_deadline = 0;
    //         }
    //     }
    // }
    // {
    //     static uint32_t tap_deadline = 0;
    //     if (keycode == CKC_RTB) {
    //         if (record->event.pressed) {
    //             del_oneshot_mods(MOD_LSFT);
    //             if (rtb_state == 2 && !timer_expired32(timer_read32(), tap_deadline)) {
    //                 register_mods(MOD_LSFT);
    //                 rtb_state = 3;
    //             } else {
    //                 tap_deadline = timer_read32() + TAPPING_TERM;
    //                 layer_on(RTB_LAYER);
    //                 rtb_state = 1;
    //             }
    //         } else {
    //             if (rtb_state == 1) {
    //                 layer_off(RTB_LAYER);
    //                 if (!timer_expired32(timer_read32(), tap_deadline)) {
    //                     tap_deadline = timer_read32() + TAPPING_TERM;
    //                     add_oneshot_mods(MOD_LSFT);
    //                     rtb_state = 2;
    //                 }
    //             } else if (rtb_state == 3) {
    //                 unregister_mods(MOD_LSFT);
    //             }
    //         }
    //     } else {
    //         if (rtb_state == 1) {
    //             tap_deadline = 0;
    //         }
    //     }
        // if (keycode == CKC_NUM && record->event.pressed) {
        //     layer_move(RTB_LAYER);
        //     rtb_state    = 1;
        //     tap_deadline = 0;
        // }
    // }
    // if (IS_LAYER_ON(4)) {
    //     reset_oneshot_layer();
    //     clear_oneshot_mods();
    // }
//     return true;
// }

// void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
//   if (keycode != CKC_LTB && ltb_state == ) {
//     layer_off(LTB_LAYER);
// 	ltb_state=0;
//   }
// }
