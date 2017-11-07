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
#define _SYMB 2
#define _FUNC 3
#define _MOUSE 4
#define _LAYERS 5
#define ENDASH LALT(KC_MINS)
#define POUND LALT(KC_3)
#define H(X) LALT(LCTL(X))

enum planck_keycodes {
  MOVE = SAFE_RANGE,
  SYMB,
  FUNC
};

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

#define THUMB_ROW { KC_DEL, KC_LGUI, KC_LALT, ALGR_T(KC_INS), GUI_T(KC_DEL), CTL_T(KC_SPC), ALT_T(KC_SPC), SFT_T(KC_ENT), KC_RALT, KC_RCTL, KC_ENT, KC_ENT}
/*
 * |------+------+------+------------+----------+-----------+----------+----------+------+------+------+------|
 * | Del  | Cmd  |  Alt | AltGr(Ins) | Gui(Del) | Ctrl(Spc) | Alt(Spc) | Sft(Ent) |  Alt | Ctrl | Ent  | Ent  |
 * `----------------------------------------------------------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Ä  |   Q  |   .  |   ,  |   Y  |   F  |   G  |   L  |   H  |   M  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   O  |   I  |   E  |   A  |   U  |   D  |   S  |   T  |   R  |   N  |  P   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  -   |   Ö  |   J  |   K  |   Å  |   Z  |   B  |   C  |   X  |   V  |   W  |  ;   |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = {
  { SWL,  SV_AE,   KC_Q,   KC_DOT,  KC_COMM,  KC_Y,    KC_F,    KC_G,    KC_L,    KC_H,    KC_M,    KC_BSPC },
  { KC_TAB,  KC_O,    KC_I,    KC_E,    KC_A,    KC_U,    KC_D,    KC_S,    KC_T,    KC_R,    KC_N,    KC_P },
  { NO_MINS, SV_OE,   KC_J,    KC_K,    SV_AA,   KC_Z,    KC_B,    KC_C,    KC_X,    KC_V,    KC_W,    NO_SCLN },
  THUMB_ROW
},

/* MOVE
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  | Pg Up| Home |  Up  | End  | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F6  |  F7  |  F8  |  F9  |  F10 | Pg Dn| Left | Down | Right| Vol- | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  F11 |  F12 |  F13 | F14  |  F15 |      | THome| BEnd | Del  |      | Ctrl |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  | Cmd  |  Alt | Ctrl | Shift| Symb | Move | Space|  Cmd |  Alt | Ctrl | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = {
  {SWL   ,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_PGUP, KC_HOME,    KC_UP,     KC_END,    _______, _______ },
  {KC_TAB,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PGDN, KC_LEFT,    KC_DOWN,   KC_RGHT,   _______, KC_LSFT },
  {KC_LSFT, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______, C(KC_HOME), C(KC_END), XXXXXXX,   _______, KC_LCTL },
  THUMB_ROW
},

/* SYMB
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   ~  |   !  |   {  |   }  |   #  |   |  |   7  |   8  |   9  |   +  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tab |   *  |   @  |   (  |   )  |   &  |   =  |   4  |   5  |   6  |   -  |   $  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ^  |   '  |   "  |   [  |   ]  |   $  |   \  |   1  |   2  |   3  |   /  |   £  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ?  | Cmd  |  Alt | Ctrl | Shift| Symb | Move |   0  | Space|  Alt | Ctrl | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = {
  { SWL   , KC_TILD, KC_EXLM    ,KC_LCBR, KC_RCBR ,KC_HASH, _______, KC_7,    KC_8,    KC_9, KC_MINS, _______},
  { KC_TAB, KC_ASTR, KC_AT      ,KC_LPRN, KC_RPRN, KC_AMPR, KC_EQL,  KC_4,    KC_5,    KC_6, KC_PLUS, KC_DLR },
  { KC_CIRC,KC_QUOT, S(KC_QUOT) ,KC_LBRC, KC_RBRC, KC_DLR , KC_SLASH,KC_1,    KC_2,    KC_3, KC_0   , POUND  },
  {_______, _______, _______    ,_______, _______, _______, _______, KC_0, _______, _______, _______, _______}
},

/* FUNC
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   –  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Del |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   £  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ~  |   `  |   +  |   =  |   |  |   \  |   [  |   ]  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = {
  {SWL    ,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    ENDASH },
  {KC_DEL ,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, POUND  },
  {_______, KC_TILD, KC_GRV,  KC_PLUS, KC_EQL,  KC_PIPE, KC_BSLS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      | A+S  | ACC-2| ACC-1| ACC-0|      |      | SW-L |  M-U | SW-R | SW-U |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LALt | C+A  | MB-3 | MB-2 | MB-1 |      |      |  M-L |  M-D |  M-R | SW-D |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift| C+S  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = {
  {SWL    , XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, XXXXXXX},
  {XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX, KC_1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[_LAYERS] = {
  {SWL    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, TO(_BASE),TO(_SYMB),TO(_MOVE),TO(_MOUSE), _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MOVE:
      if (record->event.pressed) {
        layer_on(_MOVE);
        update_tri_layer(_MOVE, _SYMB, _MOUSE);
      } else {
        layer_off(_MOVE);
        update_tri_layer(_MOVE, _SYMB, _MOUSE);
      }
      return false;
      break;
    case SYMB:
      if (record->event.pressed) {
        layer_on(_SYMB);
        update_tri_layer(_MOVE, _SYMB, _MOUSE);
      } else {
        layer_off(_SYMB);
        update_tri_layer(_MOVE, _SYMB, _MOUSE);
      }
      return false;
      break;
    case FUNC:
      if (record->event.pressed) {
        layer_on(_FUNC);
      } else {
        layer_off(_FUNC);
      }
      return false;
      break;
  }
  return true;
}
