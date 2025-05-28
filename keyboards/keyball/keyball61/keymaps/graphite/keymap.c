/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

#ifdef MACCEL_ENABLE
    #include "maccel/maccel.h"
#endif

enum my_keycodes {
    MA_TOGGLE = QK_USER,    // toggle mouse acceleration
    MA_TAKEOFF,   // mouse acceleration curve takeoff (initial acceleration) step key
    MA_GROWTH_RATE,         // mouse acceleration curve growth rate step key
    MA_OFFSET,              // mouse acceleration curve offset step key
    MA_LIMIT,               // mouse acceleration curve limit step key
};

/////////////////////////////////////////// tap-dance

//Tap Dance declarations
enum {
    TD_MINS_PLUS,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for MINUS, twice for PLUS
    [TD_MINS_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_PLUS),
};

////////////////////////////////////////// combos

// const uint16_t PROGMEM left_sqbracket[] = {KC_L, KC_D, COMBO_END};
// const uint16_t PROGMEM right_sqbracket[] = {KC_D, KC_W, COMBO_END};
// const uint16_t PROGMEM left_parenthesis[] = {KC_X, KC_M, COMBO_END};
// const uint16_t PROGMEM right_parenthesis[] = {KC_M, KC_C, COMBO_END};
// combo_t key_combos[] = {
//     COMBO(left_sqbracket, KC_LEFT_BRACKET),
//     COMBO(right_sqbracket, KC_RIGHT_BRACKET),
//     COMBO(left_parenthesis, KC_LEFT_PAREN),
//     COMBO(right_parenthesis, KC_RIGHT_PAREN)
// };


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC,     KC_1,       KC_2,         KC_3,         KC_4,           KC_5,                        KC_6,      KC_7,           KC_8,           KC_9,           KC_0,       KC_GRV,
    KC_TAB,     KC_B,       KC_L,         KC_D,         KC_W,           KC_Z,                        KC_QUOT,   KC_F,           KC_O,           KC_U,           KC_J,       TD(TD_MINS_PLUS),
    KC_LSFT,    KC_N,       LALT_T(KC_R), LCTL_T(KC_T), LSFT_T(KC_S),   KC_G,                        KC_Y,      RSFT_T(KC_H),   RCTL_T(KC_A),   LALT_T(KC_E),   KC_I,       KC_SLSH,
    MO(1)    ,  KC_Q,       KC_X,         KC_M,         KC_C,           KC_V,   KC_RBRC,    KC_NUHS, KC_K     , KC_P     ,      KC_COMM  ,      KC_DOT   ,      KC_SCLN  ,  KC_EQL,
    KC_LCTL  ,  KC_LGUI  ,  _______  ,    _______  ,    _______  ,      MO(1),   KC_SPC,    KC_ENT,  MO(2)    , KC_BSPC     ,   KC_DEL     ,    KC_RALT     ,   KC_RGUI  ,  MO(3)
  ),
//    _______  , KC_LCTL  , KC_LALT  , KC_LGUI,LT(1,KC_LNG2),LT(2,KC_SPC),LT(3,KC_LNG1),    KC_BSPC,LT(2,KC_ENT),LT(1,KC_LNG2),KC_RGUI, _______ , KC_RALT  , KC_PSCR

  [1] = LAYOUT_universal(
    S(KC_ESC), S(KC_1)  , KC_LBRC  , S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  KC_EQL   , S(KC_6)  ,S(KC_QUOT), S(KC_8)  ,  S(KC_9)  ,   S(KC_GRV),
    S(KC_TAB), KC_EXLM,   KC_AT,     KC_LBRC,   KC_RBRC,   KC_PIPE  ,                                  S(KC_QUOT),S(KC_U)  , S(KC_I)  , S(KC_O)  ,  S(KC_P)  ,   S(KC_MINS),
    KC_LSFT,   KC_HASH,   KC_DLR,    KC_LPRN,   KC_RPRN,   KC_GRV   ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  ,  KC_QUOT  ,   S(KC_SLSH)  ,
    _______  , KC_PERC,   KC_CIRC,   KC_LCBR,   KC_RCBR,   KC_TILD  ,S(KC_RBRC),           S(KC_NUHS), S(KC_N)  , S(KC_M)  ,S(KC_COMM), S(KC_DOT),  S(KC_SCLN),  S(KC_EQL),
    S(KC_LCTL),S(KC_LALT),_______,   _______,   _______  , _______  , _______  ,            _______  , _______  , _______  ,S(KC_RGUI), S(KC_RALT), S(KC_RGUI),  _______
  ),

  [2] = LAYOUT_universal(
    SSNP_FRE , KC_F1    , KC_F2 ,    KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    ,   KC_F7,      KC_F8,      KC_F9 ,     KC_F10,     KC_F11   ,
    SSNP_VRT , _______  , KC_7     , KC_8     , KC_9     , _______  ,                                  KC_PGUP,     KC_HOME,    KC_UP,      KC_END,     KC_INS,     KC_F12,
    SSNP_HOR , _______  , KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                  KC_PGDN,     KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_DEL,     XXXXXXX,
    _______  , _______  , KC_BTN1  , KC_BTN3  , KC_BTN2  ,S(KC_MINS), S(KC_8)  ,            S(KC_9)  , KC_PGDN  ,   C(KC_LEFT), _______ ,   C(KC_RGHT), _______  ,  _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,             KC_DEL  , _______  ,   _______  ,  _______  ,  _______  ,  _______  ,  _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR   ,            _______  , MA_TOGGLE,MA_TAKEOFF,MA_GROWTH_RATE,MA_OFFSET,MA_LIMIT,_______  ,
    QK_BOOT  , _______  , _______  , _______  , _______  , _______  , _______  ,            KC_LSFT  , KC_BSPC  , _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}


#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"

    void oledkit_render_info_user(void) {
        keyball_oled_render_keyinfo();
        keyball_oled_render_ballinfo();
        keyball_oled_render_layerinfo();
    }
#endif


//#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    void pointing_device_init_user(void) {
        set_auto_mouse_enable(true);         // always required before the auto mouse feature will work

        set_auto_mouse_layer(2); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
        set_auto_mouse_enable(true);
    }
//  #endif



void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_keyboard=true;
    debug_mouse=true;

        set_auto_mouse_layer(2); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
        set_auto_mouse_enable(true);

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_maccel(keycode, record, MA_TOGGLE, MA_TAKEOFF, MA_GROWTH_RATE, MA_OFFSET, MA_LIMIT)) {
        return false;
    }
    /* insert your own macros here */
    return true;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
 //   #ifdef MACCEL_ENABLE
        return pointing_device_task_maccel(mouse_report);
//    #endif
}
