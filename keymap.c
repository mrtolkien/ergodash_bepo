#include "quantum.h"
#include QMK_KEYBOARD_H

// Tap dance advanced functions, needed for multiple modifier to work properly
// Ctrl and ctrl shift
void dance_ctrl_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
  	register_code (KC_RCTL);
  } else {
    register_code (KC_RCTL);
    register_code (KC_RSFT);
  }
}

void dance_ctrl_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RCTL);
  } else {
  	unregister_code (KC_RSFT);
    unregister_code (KC_RCTL);
  }
}

// Cmd and cmd shift
void dance_cmd_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RGUI);
  } else {
    register_code (KC_RGUI);
    register_code (KC_RSFT);
  }
}

void dance_cmd_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RGUI);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (KC_RGUI);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [0] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
  [1] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cmd_finished, dance_cmd_reset),
  [2] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, A(KC_SPC)),
  [3] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_ctrl_finished, dance_ctrl_reset),
  [4] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, RALT(KC_SPC)),
};

#define SP_ENT TD(0)
#define GUI_GIS TD(1)
#define ALT_UDS TD(2)
#define CTL_CFT TD(3)
#define RALT_UD TD(4)

// Simple aliases to keep the map nice and clean
#define A_DEL RALT(KC_DEL)
#define A_LEFT RALT(KC_LEFT)
#define A_RGHT RALT(KC_RGHT)
#define A_BSPC RALT(KC_BSPC)
#define C_BSPC LCTL(KC_BSPC)
#define C_DEL LCTL(KC_DEL)
#define C_LEFT LCTL(KC_LEFT)
#define C_RGHT LCTL(KC_RGHT)
#define C_UP LCTL(KC_UP)
#define C_1 LCTL(KC_1)
#define C_2 LCTL(KC_2) 
#define C_3 LCTL(KC_3)
#define C_4 LCTL(KC_4)
#define C_5 LCTL(KC_5)

#define W_LSCR LCTL(LGUI(KC_LEFT))
#define W_RSCR LCTL(LGUI(KC_RGHT))
#define W_TASK LGUI(KC_TAB)

// Naming layers for readability
#define MAC_BASE 0
#define WIN_BASE 1
#define GAMING 2
#define MAC_NAV 3
#define WIN_NAV 4

#define M_NAV MO(MAC_NAV)
#define W_NAV MO(WIN_NAV)
#define W_BASE TO(WIN_BASE)
#define M_BASE TO(MAC_BASE)
#define TO_GAME TO(GAMING)

// Actual layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[MAC_BASE] = LAYOUT_4key_2u_inner(
		KC_GRV,	KC_1,	  KC_2,	  KC_3,	  KC_4, 	KC_5,	  KC_PGUP,		KC_PGDN,KC_6,   KC_7,	  KC_8,   KC_9,	  KC_0,	  KC_LBRC,
		KC_MINS,KC_Q,	  KC_W,	  KC_E,	  KC_R,	  KC_T,	  KC_PGDN,		KC_DOWN,KC_Y,   KC_U,	  KC_I,	  KC_O,	  KC_P,	  KC_RBRC,
		KC_TAB, KC_A,	  KC_S,	  KC_D,	  KC_F,	  KC_G,	  W_BASE,		  TO_GAME,KC_H,   KC_J,	  KC_K,	  KC_L,	  KC_SCLN,KC_QUOT,
		KC_EQL,	KC_Z,	  KC_X,	  KC_C,	  KC_V,	  KC_B,   KC_ESC,			KC_DEL,	KC_N,	  KC_M,	  KC_COMM,KC_DOT, KC_SLSH,KC_BSLS,
		KC_LCTL,KC_LSFT,KC_LALT,KC_LCTL,M_NAV,  SP_ENT,	ALT_UDS,    GUI_GIS,KC_BSPC,KC_RSFT,CTL_CFT,KC_LEFT,KC_MINS,KC_EQL
		),

  [WIN_BASE] = LAYOUT_4key_2u_inner(
    _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,M_BASE,     _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,W_NAV,  _______,RALT_UD,    CTL_CFT,_______,_______,GUI_GIS,_______,_______,_______
    ),

  [GAMING] = LAYOUT_4key_2u_inner(
    _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,W_BASE,     M_BASE, _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,KC_LALT,KC_SPC, KC_LCTL,    CTL_CFT,_______,_______,GUI_GIS,_______,_______,_______
    ),

  [MAC_NAV] = LAYOUT_4key_2u_inner(
    RGB_TOG,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,     KC_F12, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_PAUS,
    RGB_MOD,A_DEL,  A_LEFT, KC_UP,  A_RGHT, A_BSPC, _______,    _______,_______,C_1,    C_2,    C_3,    C_4,    C_5,
    _______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END, _______,    _______,_______,C_LEFT, C_UP,   C_RGHT, KC_PAUS,KC__VOLUP,
    RGB_VAI,_______,C_LEFT, C_UP,   C_RGHT, _______,_______,    _______,_______,_______,_______,_______,KC_SLCK,KC__VOLDOWN,
    RGB_VAD,_______,_______,_______,M_NAV,  SP_ENT, RALT_UD,    _______,_______,_______,_______,_______,_______,KC__MUTE
    ),

  [WIN_NAV] = LAYOUT_4key_2u_inner(
    RGB_TOG,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F11,     KC_F12, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_PAUS,
    _______,C_DEL  ,C_LEFT, KC_UP,  C_RGHT, C_BSPC, _______,    _______,_______,_______,_______,_______,_______,_______,
    _______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END, _______,    _______,_______,W_LSCR, W_TASK, W_RSCR, KC_PAUS,KC_VOLU,
    _______,_______,W_LSCR, W_TASK, W_RSCR, _______,_______,    _______,_______,_______,_______,_______,KC_SLCK,KC_VOLD,
    _______,_______,_______,_______,_______,_______,RALT_UD,    CTL_CFT,_______,_______,GUI_GIS,_______,_______,KC_MUTE
    )
};
