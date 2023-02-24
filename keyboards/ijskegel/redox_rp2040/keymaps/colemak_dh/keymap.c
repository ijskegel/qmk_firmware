// Copyright 2023 IJskegel
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _COLEMAK 0   // traditional colemak layout
#define _SYMB 1      // symbols, function keys and num block
#define _NAV 2       // vim-style navigation
#define _ADJUST 3    // keyboard ajustments, including QK_BOOT on both halves to enter boot mode

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

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

  [_COLEMAK] = LAYOUT(
     KC_NAGR ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_LBRC         ,KC_RBRC ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_NAMI ,
     KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,SYM_L           ,SYM_L   ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_EQL  ,
     KC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_D    ,KC_ADPU         ,KC_ADEN ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT ,
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_PGDN         ,KC_HOME ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
     KC_LGUI ,KC_PPLS ,KC_PMNS ,KC_ALAS ,KC_CTPL ,KC_BSPC ,KC_DEL          ,KC_ENT  ,KC_SPC  ,KC_RALT ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  ),

  [_SYMB] = LAYOUT(
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,_______         ,_______ ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,_______         ,_______ ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,XXXXXXX ,
     _______ ,KC_HASH ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,_______         ,_______ ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX ,
     _______ ,KC_PERC ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______         ,_______ ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,KC_P0   ,KC_P0   ,KC_PDOT ,KC_PENT ,XXXXXXX
  ),

  [_NAV] = LAYOUT(
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,_______         ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,_______         ,_______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BTN1 ,KC_BTN2 ,_______         ,_______ ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ),

  [_ADJUST] = LAYOUT(
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,_______         ,_______ ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
     XXXXXXX ,QK_BOOT ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI         ,RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,QK_BOOT ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______         ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  )
};
