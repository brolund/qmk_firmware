#include QMK_KEYBOARD_H
#include "config.h"
#include "mousekey.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"
#include "keymap_extras/keymap_swedish.h"
#include "sv.h"
#include "i3.h"


extern keymap_config_t keymap_config;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = {
  BASE_1,
  BASE_2,
  BASE_3,
  THUMB_ROW
},

[_MOVE] = {
  MOVE_1,
  MOVE_2,
  MOVE_3,
  THUMB_ROW
},

[_NUMPAD] = {
  NUM_1,
  NUM_2,
  NUM_3,
  NUM_4,
},

[_PARENS] = {
  PAR_1,
  PAR_2,
  PAR_3,
  TRANS
},

[_SIGNS] = {
  SIGN_1,
  SIGN_2,
  SIGN_3,
  TRANS
},


[_MOUSE] = {
  MOUS_1,
  MOUS_2,
  MOUS_3,
  TRANS
},

[_CONTROLS] = {
  CONT_1,
  CONT_2,
  CONT_3,
  TRANS
},

[_FUNC] = {
  FUNC_1,
  FUNC_2,
  FUNC_3,
  TRANS
},

[_I3WS] = {
  I3WS_1,
  I3WS_2,
  I3WS_3,
  TRANS
},

[_I3MV] = {
  I3MV_1,
  I3MV_2,
  TRANS,
  TRANS
}

};

