#include "quantum.h"
#include QMK_KEYBOARD_H

// Naming layers for readability
#define BASE 0
#define NAV 1
#define GAMING 2
 

// Defining keys for readability
#define SPC_NAV LT(NAV, KC_SPC)


// Actual layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Keymap: BASE layer
 *	Home, End as well as the bottom 3 on both sides are pretty much unused atm
 *	
 * ,----------------------------------------------------.           ,----------------------------------------------------.
 * |   `    |    1   |   2  |   3  |   4  |   5  | Caps |           | PrSc |   6  |   7  |   8  |   9  |   0    |   [    |
 * |--------+--------+------+------+------+-------------|           |------+------+------+------+------+--------+--------|
 * |   -    |    Q   |   W  |   E  |   R  |   T  | Pgup |           | LShft|   Y  |   U  |   I  |   O  |   P    |   ]    |
 * |--------+--------+------+------+------+------|------|           |------|------+------+------+------+--------+--------|
 * |  Ctrl  |    A   |   S  |   D  |   F  |   G  | Pgdn |           | LAlt |   H  |   J  |   K  |   L  |   ;    |   '    |
 * |--------+--------+------+------+------+------|------'           `------|------+------+------+------+--------+--------|
 * |   =    |    Z   |   X  |   C  |   V  |   B  |                         |   N  |   M  |   ,  |   .  |   /    |   \    |
 * |--------+--------+------+------+------+------'                         `------+------+------+------+--------+--------|
 * |  Left  |Alt+Tab |Right |_/shft|                                                     | LGUI | GUI+L| GUI+U  | GUI+R  |
 * `-------------------------------'                                                     `-------------------------------'
 *                                       ,--------------.           ,--------------.
 *                                       | Space| Escape|           |  Del |      |
 *                               ,-------|   /  |-------|           |------| Bksp |-------.
 *                               |  Ralt |  Nav |Enter/LAlt|        |Tab/Ctrl|    | Shift  |
 *                               `----------------------'           `----------------------'
 */

 	/*Keymaps are defined by left row, right row, left row, ...*/
	[BASE] = LAYOUT_4key_2u_inner(
		KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_CAPS,
													KC_PSCR,	KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_LBRC,


		KC_MINUS,	KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_PGUP,
													KC_LSFT,	KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_RBRC,


		KC_LCTL,	KC_A,		KC_S,		KC_D,		KC_F,		KC_G,		KC_PGDN,
													KC_LALT,	KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,


		KC_EQL,		KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_ESC,
													KC_DEL,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_BSLS,
		

		KC_LEFT,	LALT(KC_TAB),KC_RIGHT,	RALT(KC_SPC),KC_RALT,	SPC_NAV,	LALT_T(KC_ENT),
													CTL_T(KC_TAB),KC_BSPC,	KC_RSFT,	KC_LGUI,	RGUI(KC_LEFT),RGUI(KC_UP),RGUI(KC_RIGHT)
		),


	/* Keymap: NAV + numbers layer, thought mainly for the GNOME desktop
 *	Home, End as well as the bottom 3 on both sides are pretty much unused atm
 *	
 * ,----------------------------------------------------.           ,----------------------------------------------------.
 * |  RGB   |   F1   |  F2  |  F3  |  F4  |  F5  | GAME |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10   |  Next  |
 * |--------+--------+------+------+------+-------------|           |------+------+------+------+------+--------+--------|
 * |  xxx   |Ctrl+Del|Ctrl+L|  Up  |Ctrl+R|C+Bksp| PgUp |           |Numlok|   /  |   7  |   8  |   9  | Bspace |  Pause |
 * |--------+--------+------+------+------+------|------|           |------|------+------+------+------+--------+--------|
 * |  Ctrl  |  Home  | Left | Down | Right|  End | PgDn |           | xxxx |   *  |   4  |   5  |   6  |   -    | Vol up |
 * |--------+--------+------+------+------+------|------'           `------|------+------+------+------+--------+--------|
 * |  xxxx  | GUI+S+L|GUI+L |GUI+U |GUI+R |GUI+S+R|                        |   =  |   1  |   2  |   3  |   +    | Vol dn |
 * |--------+--------+------+------+------+------'                         `------+------+------+------+--------+--------|
 * |  xxxx  |Alt+Tab |Right | LAlt |                                                     |   0  |   .  | Enter  |  Mute  |
 * `-------------------------------'                                                     `-------------------------------'
 *                                       ,--------------.           ,--------------.
 *                                       | Space| Escape|           |  Del |      |
 *                               ,-------|   /  |-------|           |------|Uscore|-------.
 *                               |L/RAlt |  Nav | Enter |           |Tab/Ctrl|    | Shift  |
 *                               `----------------------'           `----------------------'
 */	
 	/*Keymaps are defined by left row, right row, left row, ...*/
	[NAV] = LAYOUT_4key_2u_inner(
		RGB_TOG,	KC_F1, 	 	KC_F2, 	 	KC_F3,		KC_F4,		KC_F5,		TG(GAMING),
													KC_F12,		KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_MEDIA_FAST_FORWARD,


		XXXXXXX,	LCTL(KC_DEL),LCTL(KC_LEFT),KC_UP,	LCTL(KC_RIGHT),LCTL(KC_BSPC),_______,
													KC_NUMLOCK,	KC_KP_SLASH,KC_KP_7,	KC_KP_8,	KC_KP_9,	KC_BSPC,	KC_MEDIA_PLAY_PAUSE,


		KC_LCTL,	KC_HOME,	KC_LEFT,	KC_DOWN,	KC_RIGHT,	KC_END,		_______,
													XXXXXXX,	KC_PAST,	KC_KP_4,	KC_KP_5,	KC_KP_6,	KC_PMNS,	KC__VOLUP,


		XXXXXXX,	SGUI(KC_LEFT),RGUI(KC_LEFT),RGUI(KC_UP),RGUI(KC_RIGHT),SGUI(KC_RIGHT),KC_ESC,
													KC_DELETE,	KC_PEQL,	KC_KP_1,	KC_KP_2,	KC_KP_3,	KC_PPLS,	KC__VOLDOWN,
		

		XXXXXXX,	LALT(KC_TAB),KC_RIGHT,	_______,	_______,	_______,	_______,
													CTL_T(KC_TAB),RALT(KC_SPC),KC_RSFT,	KC_KP_0,	KC_PDOT,	KC_PENT,	KC__MUTE
	),

	/* Keymap: Gaming layer
 *	
 * ,----------------------------------------------------.           ,----------------------------------------------------.
 * |   `    |    1   |   2  |   3  |   4  |   5  | BASE |           | PrSc |   6  |   7  |   8  |   9  |   0    |   [    |
 * |--------+--------+------+------+------+-------------|           |------+------+------+------+------+--------+--------|
 * |  Tab   |    Q   |   W  |   E  |   R  |   T  | Pgup |           | Home |   Y  |   U  |   I  |   O  |   P    |   ]    |
 * |--------+--------+------+------+------+------|------|           |------|------+------+------+------+--------+--------|
 * |  Caps  |    A   |   S  |   D  |   F  |   G  | Pgdn |           | End  |   H  |   J  |   K  |   L  |   ;    |   '    |
 * |--------+--------+------+------+------+------|------'           `------|------+------+------+------+--------+--------|
 * |  LShift|    Z   |   X  |   C  |   V  |   B  |                         |   N  |   M  |   ,  |   .  |   /    |   \    |
 * |--------+--------+------+------+------+------'                         `------+------+------+------+--------+--------|
 * |  Left  |Alt+Tab |Right | RAlt |                                                     | LGUI | GUI+L| GUI+U  | GUI+R  |
 * `-------------------------------'                                                     `-------------------------------'
 *                                       ,--------------.           ,--------------.
 *                                       |      | Escape|           |  Del |      |
 *                               ,-------| Space|-------|           |------| Bksp |-------.
 *                               |  Bksp |      | Rshift|        	|Tab/Ctrl|    | Enter  |
 *                               `----------------------'           `----------------------'
 */

	 	/*Keymaps are defined by left row, right row, left row, ...*/
	[GAMING] = LAYOUT_4key_2u_inner(
		KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		TG(GAMING),
													KC_PSCR,	KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_LBRC,


		KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_PGUP,
													KC_HOME,	KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_RBRC,


		KC_CAPS,	KC_A,		KC_S,		KC_D,		KC_F,		KC_G,		KC_PGDN,
													KC_END,		KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,


		KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_ESC,
													KC_DEL,		KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_BSLS,
		

		KC_LEFT,	LALT(KC_TAB),KC_RIGHT,	KC_RALT,	KC_BSPC,	KC_SPC,		KC_RSFT,
													CTL_T(KC_TAB),KC_BSPC,	KC_ENT,		KC_LGUI,	RGUI(KC_LEFT),RGUI(KC_UP),RGUI(KC_RIGHT)
		),
};
