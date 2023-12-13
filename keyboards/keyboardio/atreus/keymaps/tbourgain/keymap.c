// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
//#include "keymap_extras/keymap_french.h"
//#include "keymap_extras/sendstring_french.h"

enum layer_names {
    _QW,
    _RS,
    _LW,
    _MS,
};

#define SFT_Z  LSFT_T(KC_Z)
#define SFTSL  RSFT_T(KC_SLSH)
#define LTLWS  LT(_LW, KC_SPC)
#define LTRSS  LT(_RS, KC_SPC)
#define LTMOS  LT(_MS, KC_SPC)
#define MTAGR  MT(MOD_RALT, KC_SPC)
// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LALT_T(KC_F)

// Right-hand home row mods
#define HOME_J LALT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RCTL_T(KC_L)
#define HOME_SCLN RSFT_T(KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,                    KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,  KC_G,                    KC_H,   KC_J,  KC_K,    KC_L,    HOME_SCLN,
    SFT_Z,   KC_X,    KC_C,    KC_V,  KC_B,   KC_GRV, KC_BSLS, KC_N,   KC_M,  KC_COMM, KC_DOT,  SFTSL,
    KC_LCTL, KC_LGUI, KC_LALT, LTLWS, KC_SPC, LTMOS,  MTAGR,   KC_SPC, LTRSS, KC_MINS, KC_QUOT, KC_ENT ),

  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_DLR,  KC_PERC,                  KC_PGUP, KC_7,    KC_8,   KC_9, KC_BSPC,
    KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,                  KC_PGDN, KC_4,    KC_5,   KC_6, KC_COLN,
    SFT_T(KC_LBRC), KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR,KC_ASTR, KC_1,    KC_2,   KC_3, RSFT_T(KC_PPLS),
    QK_LEAD, KC_LGUI,  KC_LALT , KC_LSFT, KC_SPC, KC_LCTL, MTAGR,KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL ),

  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    KC_NO,   KC_VOLU, DM_REC1, DM_PLY1,   QK_BOOT, _______, _______, KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,
    KC_NO,   KC_VOLD, KC_LALT, KC_TRNS, KC_BSPC, KC_LCTL, MTAGR, KC_SPC,  TO(_QW), KC_PSCR, KC_SCRL, DM_RSTP ),

  [_MS] = LAYOUT( /* [> MOUSE <] */
    _______, _______, _______, _______, _______,                   _______, KC_BTN1, KC_MS_U, KC_BTN2, _______,
    _______, _______, _______, _______, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ )

};

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_G, KC_M)) {
       SEND_STRING("thomas.bourgain@gmail.com");
    } else if (leader_sequence_two_keys(KC_I, KC_M)) {
       SEND_STRING("thomas.bourgain@ing.com");
    }
}

