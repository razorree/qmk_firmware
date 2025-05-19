/* Copyright 2019 Leo Batyuk
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2020 @ben_roe (keycapsss.com)
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

enum layers {
    _GRAPHITE,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const char* const PROGMEM LAYER_NAMES[] = { "Grpht", "QWERT" };

//////////////////////////////////////////////////
// Tap Dance declarations
enum {
    TD_MINS_PLUS,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for MINUS, twice for PLUS
    [TD_MINS_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_PLUS),
};

/////////////////////////////////////////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* focal
 * ,--------------------------------------------.                    ,----------------------------------------------.
 * |   ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `~       |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   Tab   |   V  |   L  |   H  |   G  |   K  |                    |   Q  |   F  |   O  |   U  |   J  |  -_/+     |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |  LShift |   S  |   R  |   N  |   T  |   B  |-------.    ,-------|   Y  |   C  |   A  |   E  |   I  |  /?       |
 * |---------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   M  |   D  |   P  |-------|    |-------|  '"  |   W  |  ,<  |  .>  |  ;:  |  =+       |
 * `--------------------------------------------|       /     \      |-----------------------------------------------'
 *                  | LCTRL| LGUI | LALT |RAISE | Space/       \Enter|LOWER |BackSP|Delete| RALT |
 *                  `----------------------------------'       '------------------------------------'
 */

//  [_FOCAL] = LAYOUT(
//     KC_ESC,  KC_1,   KC_2,         KC_3,        KC_4,    KC_5,                        KC_6,     KC_7,       KC_8,       KC_9,       KC_0,   KC_GRV,
//     KC_TAB,  KC_V,   KC_L,         KC_H,        KC_G,    KC_K,                        KC_Q,     KC_F,       KC_O,       KC_U,       KC_J,   TD(TD_MINS_PLUS),
//     KC_LSFT, KC_S,LALT_T(KC_R), LCTL_T(KC_N),LSFT_T(KC_T),KC_B,                       KC_Y, RSFT_T(KC_C), RCTL_T(KC_A), RALT_T(KC_E),KC_I,  KC_SLSH,
//     KC_LCTL, KC_Z,    KC_X,    KC_M,            KC_D,    KC_P,    KC_LBRC,  KC_RBRC,  KC_QUOT, KC_W,        KC_COMM,    KC_DOT,     KC_SCLN,KC_EQL,
//                       KC_LCTL, KC_LGUI,         KC_LALT, RAISE,   KC_SPC,   KC_ENT,   LOWER,   KC_BSPC,     KC_DEL,     KC_RALT
// ),

    /* Graphite
 * ,--------------------------------------------.                    ,---------------------------------------------.
 * |   ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `~      |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+----------|
 * |   Tab   |   B  |   L  |   D  |   W  |   Z  |                    |  '"  |   F  |   O  |   U  |   J  |  -_/+    |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+----------|
 * |  LShift |   N  |   R  |   T  |   S  |   G  |-------.    ,-------|   Y  |   H  |   A  |   E  |   I  |  /?      |
 * |---------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+----------|
 * |  LCTRL  |   Q  |   X  |   M  |   C  |   V  |-------|    |-------|   K  |   P  |  ,<  |  .>  |  ;:  |  =+      |
 * `--------------------------------------------|       /     \      |---------------------------------------------'
 *                  | LCTRL| LGUI | LALT |RAISE | Space/       \Enter|LOWER |BackSP|Delete| RALT |
 *                  `----------------------------------'       '------------------------------------'
 */

 [_GRAPHITE] = LAYOUT(
    KC_ESC,  KC_1,   KC_2,         KC_3,        KC_4,    KC_5,                        KC_6,     KC_7,        KC_8,      KC_9,       KC_0,   KC_GRV,
    KC_TAB,  KC_B,   KC_L,         KC_D,        KC_W,    KC_Z,                        KC_QUOT,  KC_F,        KC_O,      KC_U,       KC_J,   TD(TD_MINS_PLUS),
    KC_LSFT, KC_N,LALT_T(KC_R), LCTL_T(KC_T),LSFT_T(KC_S),KC_G,                       KC_Y, RSFT_T(KC_H), RCTL_T(KC_A), RALT_T(KC_E),KC_I,  KC_SLSH,
    KC_LCTL, KC_Q,    KC_X,    KC_M,            KC_C,    KC_V,    KC_LBRC,  KC_RBRC,  KC_K,     KC_P,        KC_COMM,   KC_DOT,     KC_SCLN,KC_EQL,
                      KC_LCTL, KC_LGUI,         KC_LALT, RAISE,   KC_SPC,   KC_ENT,   LOWER,    KC_BSPC,     KC_DEL,    KC_RALT
),

/* QWERTY
 * ,--------------------------------------------.                    ,----------------------------------------------.
 * |   ESC   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `~       |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -_ TD +  |
 * |---------+------+------+------+------+------|                    |------+------+------+------+------+-----------|
 * |  LShift |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ;:  |  '"       |
 * |---------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,<  |  .>  |  /?  |RShift/Enter|
 * `-------------------------------------------|       /     \      \-----------------------------------------------'
 *                 | LCTRL| LGUI | LALT |RAISE | Space/       \Enter |LOWER |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

 [_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(TD_MINS_PLUS),
    KC_LSFT,  KC_A,   LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,                        KC_H,    RSFT_T(KC_J),    RCTL_T(KC_K),    RALT_T(KC_L),    KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
                      KC_LCTL, KC_LGUI, KC_LALT, RAISE,   KC_SPC,   KC_ENT,  LOWER,   KC_BSPC, KC_RGUI, KC_RALT
),
/* LOWER
 * ,-------------------------------------------.                    ,-----------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |   !  |   @  |  [   |  ]   |  |   |                    |   =  |   7  |   8  |   9  |   *  | F12  |
 * |--------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |        |   #  |   $  |  (   |  )   |  `   |-------.    ,-------|   _  |   4  |   5  |   6  |   +  |   _  |
 * |--------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |        |   %  |   ^  |  {   |  }   |  ~   |-------|    |-------|   &  |   1  |   2  |   3  |   /  |   \  |
 * `-------------------------------------------|       /     \      \-----------------------------------------------'
 *                 | LCTRL| LGUI | LALT |RAISE | Space/       \Enter|LOWER |BackSP|   0  |   .  |
 *                 `----------------------------------'       '------------------------------------'
 */

[_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    _______, KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_PIPE,                   KC_EQL,  KC_7,    KC_8,    KC_9,   KC_ASTR, KC_F12,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                    KC_MINS, KC_4,    KC_5,    KC_6,   KC_PLUS, KC_UNDS,
    _______, KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_TILD, _______, _______, KC_AMPR, KC_1,    KC_2,    KC_3,   KC_SLASH,KC_BSLS,
                      _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    | PgUp | Home |  Up  | End  | Ins  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------| PgDn | Left | Down |Right | Del  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *               | LCTRL| LGUI | LALT |RAISE | Space/       \Enter|LOWER |BackSP| RGUI | RALT |
 *               `---------------------------------'         '------------------------------------'
 */

[_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,  _______,
    _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  XXXXXXX,
    _______, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                      _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______
),
/* ADJUST (Press LOWER and RAISE together)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |QK_BOOT|     |      |      |      |      |                    |      |      |      |      |      | def. layer to QWERTY    |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB ON| HUE+ | SAT+ | VAL+ |      |      |                    | PREV | PLAY | NEXT |      |      | def. layer to FOCAL    |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | MODE | HUE- | SAT- | VAL- |      |      |-------.    ,-------| VOL+ | MUTE | VOL- |      |      | def. layer to GRAPHITE     |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 |LCTRL| LGUI | LALT |RAISE|Space /       \Enter|LOWER |BackSP| RGUI | RALT |
 *                 `----------------------------------'       '------------------------------------'
 */

[_ADJUST] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_GRAPHITE), DF(_QWERTY),
    RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                   KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
    RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                   KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______
  )
};


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

// void keyboard_post_init_user(void) {
// //     // Customise these values to desired behaviour
//      debug_enable=true;
//      debug_keyboard=true;
//      //     debug_matrix=true;
// //     //debug_mouse=true;
// }


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] =   { ENCODER_CCW_CW(KC_DOWN, KC_UP),          ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [_GRAPHITE] = { ENCODER_CCW_CW(KC_DOWN, KC_UP),          ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [_LOWER] =    { ENCODER_CCW_CW(UG_HUEU, KC_TAB),         ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_RAISE] =    { ENCODER_CCW_CW(UG_VALD, UG_VALU),        ENCODER_CCW_CW(UG_SPDD, UG_SPDU) },
    [_ADJUST] =   { ENCODER_CCW_CW(UG_PREV, UG_NEXT),        ENCODER_CCW_CW(UG_SATD, UG_SATU) },
};
#endif // ENCODER_MAP_ENABLE
