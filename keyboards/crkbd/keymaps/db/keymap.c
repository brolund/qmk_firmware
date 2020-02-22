#include QMK_KEYBOARD_H
#include "eeconfig.h"
#include "keymap_extras/keymap_swedish.h"
#include "sv.h"
#include "i3.h"


extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

const uint16_t base[4][12] = {
  [0]=BASE_1,
  [1]=BASE_2,
  [2]=BASE_3,
  [3]=THUMB_ROW
};
const uint16_t move[4][12] = {
  [0]=MOVE_1,
  [1]=MOVE_2,
  [2]=MOVE_3,
  [3]=THUMB_ROW
};
const uint16_t num[4][12] = {
  [0]=NUM_1,
  [1]=NUM_2,
  [2]=NUM_3,
  [3]=NUM_4
};
const uint16_t par[4][12] = {
  [0]=PAR_1,
  [1]=PAR_2,
  [2]=PAR_3,
  [3]=THUMB_ROW
};
const uint16_t sign[4][12] = {
  [0]=SIGN_1,
  [1]=SIGN_2,
  [2]=SIGN_3,
  [3]=THUMB_ROW
};
const uint16_t mouse[4][12] = {
  [0]=MOUS_1,
  [1]=MOUS_2,
  [2]=MOUS_3,
  [3]=THUMB_ROW
};
const uint16_t cont[4][12] = {
  [0]=CONT_1,
  [1]=CONT_2,
  [2]=CONT_3,
  [3]=THUMB_ROW
};
const uint16_t func[4][12] = {
  [0]=FUNC_1,
  [1]=FUNC_2,
  [2]=FUNC_3,
  [3]=THUMB_ROW
};
const uint16_t i3ws[4][12] = {
  [0]=I3WS_1,
  [1]=I3WS_2,
  [2]=I3WS_3,
  [3]=THUMB_ROW
};
const uint16_t i3mv[4][12] = {
  [0]=I3WS_1,
  [1]=I3WS_2,
  [2]=TRANS,
  [3]=THUMB_ROW
};


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};
/*
{ \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { KC_NO, KC_NO, KC_NO, L30, L31, L32 }, \
    { R05, R04, R03, R02, R01, R00 }, \
    { R15, R14, R13, R12, R11, R10 }, \
    { R25, R24, R23, R22, R21, R20 }, \
    { KC_NO, KC_NO, KC_NO, R32, R31, R30 } \
}
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = {
    { base[0][0],  base[0][1],  base[0][2], base[0][3], base[0][4], base[0][5]}, 
    { base[1][0],  base[1][1],  base[1][2], base[1][3], base[1][4], base[1][5]}, 
    { base[2][0],  base[2][1],  base[2][2], base[2][3], base[2][4], base[2][5]}, 
    { KC_NO,       KC_NO,       KC_NO,      base[3][3], base[3][4], base[3][5]}, 
    { base[0][11], base[0][10], base[0][9], base[0][8], base[0][7], base[0][6]}, 
    { base[1][11], base[1][10], base[1][9], base[1][8], base[1][7], base[1][6]}, 
    { base[2][11], base[2][10], base[2][9], base[2][8], base[2][7], base[2][6]}, 
    { KC_NO,       KC_NO,       KC_NO,      base[3][8], base[3][7], base[3][6]}, 
  },
  [_MOVE] = {
    { move[0][0],  move[0][1],  move[0][2], move[0][3], move[0][4], move[0][5]}, 
    { move[1][0],  move[1][1],  move[1][2], move[1][3], move[1][4], move[1][5]}, 
    { move[2][0],  move[2][1],  move[2][2], move[2][3], move[2][4], move[2][5]}, 
    { KC_NO,       KC_NO,       KC_NO,      move[3][3], move[3][4], move[3][5]}, 
    { move[0][11], move[0][10], move[0][9], move[0][8], move[0][7], move[0][6]}, 
    { move[1][11], move[1][10], move[1][9], move[1][8], move[1][7], move[1][6]}, 
    { move[2][11], move[2][10], move[2][9], move[2][8], move[2][7], move[2][6]}, 
    { KC_NO,       KC_NO,       KC_NO,      move[3][8], move[3][7], move[3][6]}, 
  },
  [_NUMPAD] = {
    { num[0][0],  num[0][1],  num[0][2], num[0][3], num[0][4], num[0][5]}, 
    { num[1][0],  num[1][1],  num[1][2], num[1][3], num[1][4], num[1][5]}, 
    { num[2][0],  num[2][1],  num[2][2], num[2][3], num[2][4], num[2][5]}, 
    { KC_NO,      KC_NO,      KC_NO,     num[3][3], num[3][4], num[3][5]}, 
    { num[0][11], num[0][10], num[0][9], num[0][8], num[0][7], num[0][6]}, 
    { num[1][11], num[1][10], num[1][9], num[1][8], num[1][7], num[1][6]}, 
    { num[2][11], num[2][10], num[2][9], num[2][8], num[2][7], num[2][6]}, 
    { KC_NO,      KC_NO,      KC_NO,     num[3][8], num[3][7], num[3][6]}, 
  },
  [_PARENS] = {
    { par[0][0],  par[0][1],  par[0][2], par[0][3], par[0][4], par[0][5]}, 
    { par[1][0],  par[1][1],  par[1][2], par[1][3], par[1][4], par[1][5]}, 
    { par[2][0],  par[2][1],  par[2][2], par[2][3], par[2][4], par[2][5]}, 
    { KC_NO,      KC_NO,      KC_NO,     par[3][3], par[3][4], par[3][5]}, 
    { par[0][11], par[0][10], par[0][9], par[0][8], par[0][7], par[0][6]}, 
    { par[1][11], par[1][10], par[1][9], par[1][8], par[1][7], par[1][6]}, 
    { par[2][11], par[2][10], par[2][9], par[2][8], par[2][7], par[2][6]}, 
    { KC_NO,      KC_NO,      KC_NO,     par[3][8], par[3][7], par[3][6]}, 
  },
  [_SIGNS] = {
    { sign[0][0],  sign[0][1],  sign[0][2], sign[0][3], sign[0][4], sign[0][5]}, 
    { sign[1][0],  sign[1][1],  sign[1][2], sign[1][3], sign[1][4], sign[1][5]}, 
    { sign[2][0],  sign[2][1],  sign[2][2], sign[2][3], sign[2][4], sign[2][5]}, 
    { KC_NO,       KC_NO,       KC_NO,      sign[3][3], sign[3][4], sign[3][5]}, 
    { sign[0][11], sign[0][10], sign[0][9], sign[0][8], sign[0][7], sign[0][6]}, 
    { sign[1][11], sign[1][10], sign[1][9], sign[1][8], sign[1][7], sign[1][6]}, 
    { sign[2][11], sign[2][10], sign[2][9], sign[2][8], sign[2][7], sign[2][6]}, 
    { KC_NO,       KC_NO,       KC_NO,      sign[3][8], sign[3][7], sign[3][6]}, 
  },
  [_MOUSE] = {
    { mouse[0][0],  mouse[0][1],  mouse[0][2], mouse[0][3], mouse[0][4], mouse[0][5]}, 
    { mouse[1][0],  mouse[1][1],  mouse[1][2], mouse[1][3], mouse[1][4], mouse[1][5]}, 
    { mouse[2][0],  mouse[2][1],  mouse[2][2], mouse[2][3], mouse[2][4], mouse[2][5]}, 
    { KC_NO,        KC_NO,        KC_NO,       mouse[3][3], mouse[3][4], mouse[3][5]}, 
    { mouse[0][11], mouse[0][10], mouse[0][9], mouse[0][8], mouse[0][7], mouse[0][6]}, 
    { mouse[1][11], mouse[1][10], mouse[1][9], mouse[1][8], mouse[1][7], mouse[1][6]}, 
    { mouse[2][11], mouse[2][10], mouse[2][9], mouse[2][8], mouse[2][7], mouse[2][6]}, 
    { KC_NO,        KC_NO,        KC_NO,       mouse[3][8], mouse[3][7], mouse[3][6]}, 
  },
  [_CONTROLS] = {
    { cont[0][0],  cont[0][1],  cont[0][2], cont[0][3], cont[0][4], cont[0][5]}, 
    { cont[1][0],  cont[1][1],  cont[1][2], cont[1][3], cont[1][4], cont[1][5]}, 
    { cont[2][0],  cont[2][1],  cont[2][2], cont[2][3], cont[2][4], cont[2][5]}, 
    { KC_NO,       KC_NO,       KC_NO,      cont[3][3], cont[3][4], cont[3][5]}, 
    { cont[0][11], cont[0][10], cont[0][9], cont[0][8], cont[0][7], cont[0][6]}, 
    { cont[1][11], cont[1][10], cont[1][9], cont[1][8], cont[1][7], cont[1][6]}, 
    { cont[2][11], cont[2][10], cont[2][9], cont[2][8], cont[2][7], cont[2][6]}, 
    { KC_NO,       KC_NO,       KC_NO,      cont[3][8], cont[3][7], cont[3][6]}, 
  },
  [_FUNC] = {
    { func[0][0],  func[0][1],  func[0][2], func[0][3], func[0][4], func[0][5]}, 
    { func[1][0],  func[1][1],  func[1][2], func[1][3], func[1][4], func[1][5]}, 
    { func[2][0],  func[2][1],  func[2][2], func[2][3], func[2][4], func[2][5]}, 
    { KC_NO,       KC_NO,       KC_NO,      func[3][3], func[3][4], func[3][5]}, 
    { func[0][11], func[0][10], func[0][9], func[0][8], func[0][7], func[0][6]}, 
    { func[1][11], func[1][10], func[1][9], func[1][8], func[1][7], func[1][6]}, 
    { func[2][11], func[2][10], func[2][9], func[2][8], func[2][7], func[2][6]}, 
    { KC_NO,       KC_NO,       KC_NO,      func[3][8], func[3][7], func[3][6]}, 
  },
  [_I3WS] = {
    { i3ws[0][0],  i3ws[0][1],  i3ws[0][2], i3ws[0][3], i3ws[0][4], i3ws[0][5]}, 
    { i3ws[1][0],  i3ws[1][1],  i3ws[1][2], i3ws[1][3], i3ws[1][4], i3ws[1][5]}, 
    { i3ws[2][0],  i3ws[2][1],  i3ws[2][2], i3ws[2][3], i3ws[2][4], i3ws[2][5]}, 
    { KC_NO,       KC_NO,       KC_NO,      i3ws[3][3], i3ws[3][4], i3ws[3][5]}, 
    { i3ws[0][11], i3ws[0][10], i3ws[0][9], i3ws[0][8], i3ws[0][7], i3ws[0][6]}, 
    { i3ws[1][11], i3ws[1][10], i3ws[1][9], i3ws[1][8], i3ws[1][7], i3ws[1][6]}, 
    { i3ws[2][11], i3ws[2][10], i3ws[2][9], i3ws[2][8], i3ws[2][7], i3ws[2][6]}, 
    { KC_NO,       KC_NO,       KC_NO,      i3ws[3][8], i3ws[3][7], i3ws[3][6]}, 
  },
  [_I3MV] = {
    { i3mv[0][0],  i3mv[0][1],  i3mv[0][2], i3mv[0][3], i3mv[0][4], i3mv[0][5]}, 
    { i3mv[1][0],  i3mv[1][1],  i3mv[1][2], i3mv[1][3], i3mv[1][4], i3mv[1][5]}, 
    { i3mv[2][0],  i3mv[2][1],  i3mv[2][2], i3mv[2][3], i3mv[2][4], i3mv[2][5]}, 
    { KC_NO,       KC_NO,       KC_NO,      i3mv[3][3], i3mv[3][4], i3mv[3][5]}, 
    { i3mv[0][11], i3mv[0][10], i3mv[0][9], i3mv[0][8], i3mv[0][7], i3mv[0][6]}, 
    { i3mv[1][11], i3mv[1][10], i3mv[1][9], i3mv[1][8], i3mv[1][7], i3mv[1][6]}, 
    { i3mv[2][11], i3mv[2][10], i3mv[2][9], i3mv[2][8], i3mv[2][7], i3mv[2][6]}, 
    { KC_NO,       KC_NO,       KC_NO,      i3mv[3][8], i3mv[3][7], i3mv[3][6]}, 
  }
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
