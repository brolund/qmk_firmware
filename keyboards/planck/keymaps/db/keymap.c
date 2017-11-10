#include "planck.h"
#include "config.h"
#include "mousekey.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"
#include "keymap_extras/keymap_nordic.h"
#include "sv.h"


extern keymap_config_t keymap_config;

#define _BASE 0
#define _MOVE 1
#define _NUMPAD 2
#define _PARENS 3
#define _SIGNS 4
#define _MOUSE 5
#define _LAYERS 6
#define ENDASH LALT(KC_MINS)
#define POUND LALT(KC_3)
#define H(X) LALT(LCTL(X))

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define C(n)    LCTL(n)
#define CA(n)   LCTL(LALT(n))
#define CAS(n)  LCTL(LALT(LSFT(n)))
#define CS(n)   LCTL(LSFT(n))
#define AS(n)   LALT(LSFT(n))
#define SWL     LT(_LAYERS, KC_ESC)
//#define S(n)    LSFT(n)

#define THUMB_ROW { KC_DEL, KC_LGUI, KC_LALT, ALGR_T(KC_INS), GUI_T(KC_DEL), CTL_T(KC_BSPC), ALT_T(KC_ENT), SFT_T(KC_SPC), KC_RALT, KC_RCTL, KC_ENT, KC_ENT}
/*
 * |------+-------+------+------------+----------+-----------+----------+----------+------+------+------+------|
 * | Del  | Gui   |  Alt | AltGr(Ins) | Gui(Del) | Ctrl(Bspc)| Alt(Ent) | Sft(Spc) |  Alt | Ctrl | Ent  | Ent  |
 * `-----------------------------------------------------------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Ä  |   Q  |   .  | ,/mv |Y/sign| F    |   G  |   L  |   H  |   M  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Tab/ms|   O  |   I  |  E   | A    | U/par| D    |   S  |   T  |   R  |   N  |  P   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  -   |   Ö  |   J  |   K  |   Å  | Z/num| B    |   C  |   X  |   V  |   W  |  ;   |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = {
  { SWL,               SV_AE, KC_Q, KC_DOT, LT(_MOVE,KC_COMM), LT(_SIGNS,KC_Y),  KC_F, KC_G, KC_L, KC_H,    KC_M,    KC_BSPC },
  { LT(_MOUSE,KC_TAB), KC_O,  KC_I, KC_E,   KC_A,              LT(_PARENS,KC_U), KC_D, KC_S, KC_T, KC_R,    KC_N,    KC_P },
  { NO_MINS,           SV_OE, KC_J, KC_K,   SV_AA,             LT(_NUMPAD,KC_Z), KC_B, KC_C, KC_X, KC_V,    KC_W,    NO_SCLN },
  THUMB_ROW
},

/* MOVE
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |      |      |      | Pg Up| Home |  Up  | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      | Pg Dn| Left | Down | Right|      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      | THome| BEnd | Del  |      | Ctrl |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = {
  {SWL   ,  _______,   _______,   _______,  _______,  _______,  _______, KC_HOME,    KC_UP,     KC_END,  KC_PGUP, _______ },
  {KC_TAB,  _______,   _______,   _______,  _______,  _______,  _______, KC_LEFT,    KC_DOWN,   KC_RGHT, KC_PGDN, KC_LSFT },
  {KC_LSFT, _______,   _______,   _______,  _______,  _______,  _______, C(KC_HOME), C(KC_END), _______, _______, KC_LCTL },
  THUMB_ROW
},

/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |      |      |      |      |      |   *  |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tab |      |      |      |      |      |   /  |   4  |   5  |   6  |   =  |   $  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ^  |      |      |      |      |      |   !  |   1  |   2  |   3  |   -  |   £  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  | Shift|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  { SWL   ,  _______, _______ ,_______, _______, _______, KC_ASTR,  KC_7,    KC_8,    KC_9, KC_MINS, _______},
  { KC_TAB,  _______, _______ ,_______, _______, _______, KC_SLASH, KC_4,    KC_5,    KC_6, KC_PLUS, KC_DLR },
  { KC_CIRC, _______, _______ ,_______, _______, _______, KC_EXLM , KC_1,    KC_2,    KC_3, KC_EQL , POUND  },
  {_______,  _______, _______ ,_______, _______, _______, _______,  KC_0,  KC_LSFT, _______, _______, _______}
},

/* PARENS
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |      |      |      |      |      |      |   "  |   '  |   `  |   ´  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Del |      |      |      |      |      |   |  |   (  |   )  |   {  |   }  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   [  |   ]  |   <  |   >  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PARENS] = {
  {SWL    , _______, _______, _______, _______, _______, _______, KC_QUOT, LSFT(KC_QUOT), KC_GRV,        _______,       _______},
  {KC_DEL , _______, _______, _______, _______, _______, KC_PIPE, KC_LPRN, KC_RPRN,       LSFT(KC_LBRC), LSFT(KC_RBRC), KC_SLASH},
  {_______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC,       LSFT(KC_COMM), LSFT(KC_DOT),  KC_BSLS},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,       _______,       _______}
},

/* SIGNS
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |      |      |      |      |      |      |      |      |      |   –  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Del |   !  |   @  |   #  |   $  |      |   ^  |   .  |   !  |   ?  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ~  |   `  |   +  |   =  |      |   \  |   @  |   #  |   ~  |   %  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SIGNS] = {
  {SWL    , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ENDASH },
  {KC_DEL , KC_EXLM, _______, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, POUND  },
  {_______, KC_TILD, KC_GRV,  KC_PLUS, KC_EQL,  KC_PIPE, KC_BSLS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      |      | ACC-2| ACC-1| ACC-0|      |      | SW-L |  M-U | SW-R | SW-U |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | MB-3 | MB-2 | MB-1 |      |      |  M-L |  M-D |  M-R | SW-D |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Reset |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = {
  {SWL    , _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______},
  {_______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  },
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_LAYERS] = {
  {SWL    , TO(_BASE), _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______},
  {_______, _______,   _______, _______, TO(_MOUSE),  _______, _______, _______, _______, _______, _______, _______},
  {_______, _______,   _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______},
  {_______, _______,   _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______}
} 

};

