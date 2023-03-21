// Copyright 2023 IJskegel
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
};

// Shortcut to make keymap more readable
#define KC_SYBS LT(_SYMB,   KC_BSPC)
#define KC_NASP LT(_NAV,    KC_SPC)
#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

/*
 * Row - column numbering for the two halves half of the keyboard, effectively creating a 5x7 matrix for each half
 *
 *             ┌────┐┌────┐┌────┐                                                  ┌────┐┌────┐┌────┐
 *┌─────┐┌────┐│0,2 ││0,3 ││0,4 │┌────┐                                      ┌────┐│0,9 ││0,10││0,11│┌────┐┌─────┐
 *│0,0  ││0,1 │└────┘└────┘└────┘│0,5 │┌────┐                          ┌────┐│0,8 │└────┘└────┘└────┘│0,12││0,13 │
 *└─────┘└────┘┌────┐┌────┐┌────┐└────┘│0,6 │                          │0,7 │└────┘┌────┐┌────┐┌────┐└────┘└─────┘
 *┌─────┐┌────┐│1,2 ││1,3 ││1,4 │┌────┐└────┘                          └────┘┌────┐│1,9 ││1,10││1,11│┌────┐┌─────┐
 *│1,0  ││1,1 │└────┘└────┘└────┘│1,5 │┌────┐                          ┌────┐│1,8 │└────┘└────┘└────┘│1,12││1,13 │
 *└─────┘└────┘┌────┐┌────┐┌────┐└────┘│1,6 │                          │1,7 │└────┘┌────┐┌────┐┌────┐└────┘└─────┘
 *┌─────┐┌────┐│2,2 ││2,3 ││2,4 │┌────┐│    │                          │    │┌────┐│2,9 ││2,10││2,11│┌────┐┌─────┐
 *│2,0  ││2,1 │└────┘└────┘└────┘│2,5 │└────┘                          └────┘│2,8 │└────┘└────┘└────┘│2,12││2,13 │
 *└─────┘└────┘┌────┐┌────┐┌────┐└────┘                                      └────┘┌────┐┌────┐┌────┐└────┘└─────┘
 *┌─────┐┌────┐│3,2 ││3,3 ││3,4 │┌────┐    ┌────┐┌────┐      ┌────┐┌────┐    ┌────┐│3,9 ││3,10││3,11│┌────┐┌─────┐
 *│3,0  ││3,1 │└────┘└────┘└────┘│3,5 │    │2,6 ││3,6 │      │3,7 ││2,7 │    │3,8 │└────┘└────┘└────┘│3,12││3,13 │
 *└─────┘└────┘┌────┐┌────┐      └────┘    └────┘└────┘      └────┘└────┘    └────┘      ┌────┐┌────┐└────┘└─────┘
 * ┌────┐┌────┐│4,2 ││4,3 │ ┌─────┐        ┌────┐┌────┐      ┌────┐┌────┐         ┌─────┐│4,10││4,11│┌────┐┌────┐
 * │4,0 ││4,1 │└────┘└────┘ │4,4  │        │4,5 ││4,6 │      │4,7 ││4,8 │         │4,9  │└────┘└────┘│4,12││4,13│
 * └────┘└────┘             └─────┘        │    ││    │      │    ││    │         └─────┘            └────┘└────┘
 *                                         └────┘└────┘      └────┘└────┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_MINS         ,KC_EQL  ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_LBRC         ,KC_RBRC ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_HOME         ,KC_PGDN ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADEN         ,KC_ADPU ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
     KC_HYPR ,KC_MEH  ,KC_LALT ,KC_LGUI ,KC_LCTL ,KC_SYBS ,KC_DEL          ,KC_ENT  ,KC_NASP ,KC_RCTL ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  ),

  [_SYMB] = LAYOUT(
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F11          ,KC_F12  ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,KC_7    ,KC_8    ,KC_9    ,KC_PMNS ,XXXXXXX ,
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BSPC         ,XXXXXXX ,XXXXXXX ,KC_4    ,KC_5    ,KC_6    ,KC_PPLS ,XXXXXXX ,
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,KC_PSLS ,_______ ,
     _______ ,_______ ,_______ ,_______ ,_______ ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,_______ ,KC_0    ,KC_DOT  ,KC_PAST ,KC_PEQL
  ),

  [_NAV] = LAYOUT(
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     _______ ,XXXXXXX ,XXXXXXX ,KC_LALT ,KC_LSFT ,XXXXXXX ,XXXXXXX         ,KC_SPC  ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
     _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
     _______ ,_______ ,_______ ,_______ ,_______ ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ),

  [_ADJUST] = LAYOUT(
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,QK_BOOT ,KC_INS  ,KC_PSCR ,KC_SCRL ,KC_PAUS ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,XXXXXXX ,
     KC_CAPS ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  )
};
