#include QMK_KEYBOARD_H
#include "version.h"
#include "eeconfig.h"
#include "keymap_extras/keymap_swedish.h"
#include "i3.h"
#include "sv.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};
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
/*
    A80, A70, A60, A50, A40, A30, A20,               B20, B30, B40, B50, B60, B70, B80,     \
    A81, A71, A61, A51, A41, A31, A21,               B21, B31, B41, B51, B61, B71, B81,     \
    A82, A72, A62, A52, A42, A32,                         B32, B42, B52, B62, B72, B82,     \
    A83, A73, A63, A53, A43, A33, A23,               B23, B33, B43, B53, B63, B73, B83,     \
    A84, A74, A64, A54, A44,                                   B44, B54, B64, B74, B84,     \
                                  A13, A03,     B03, B13,                                   \
                                       A04,     B04,                                        \
                             A34, A24, A14,     B14, B24, B34                               \
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] =  {                                       \
    { KC_NO, KC_NO, KC_NO, RESET,                     KC_NO      }, // A00-A04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A10-A14
    { KC_NO, KC_NO, KC_NO, KC_NO,                     base[3][5] }, // A20-A24
    { KC_NO, base[0][5], base[1][5], base[2][5],      base[3][4] }, // A30-A34
    { KC_NO, base[0][4], base[1][4], base[2][4],      base[3][3] }, // A40-A44
    { KC_NO, base[0][3], base[1][3], base[2][3],      KC_NO      }, // A50-A54
    { KC_NO, base[0][2], base[1][2], base[2][2],      base[3][2]      }, // A60-A64
    { KC_NO, base[0][1], base[1][1], base[2][1],      base[3][1]      }, // A70-A74
    { KC_NO, base[0][0], base[1][0], base[2][0],      base[3][0]      }, // A80-A84
    { KC_NO, KC_NO, KC_NO, RESET,                     KC_NO      }, // BOO-B04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,                     base[3][6] }, \
    { KC_NO, base[0][6],  base[1][6],  base[2][6],    base[3][7] }, \
    { KC_NO, base[0][7],  base[1][7],  base[2][7],    base[3][8] }, \
    { KC_NO, base[0][8],  base[1][8],  base[2][8],    KC_NO      }, \
    { KC_NO, base[0][9],  base[1][9],  base[2][9],    base[3][9] }, \
    { KC_NO, base[0][10], base[1][10], base[2][10],   base[3][10]}, \
    { KC_NO, base[0][11], base[1][11], base[2][11],   base[3][11]}  \
},
[_MOVE] = {
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A00-A04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A10-A14
    { KC_NO, KC_NO, KC_NO, KC_NO,                     move[3][5] }, // A20-A24
    { KC_NO, move[0][5], move[1][5], move[2][5],      move[3][4] }, // A30-A34
    { KC_NO, move[0][4], move[1][4], move[2][4],      move[3][3] }, // A40-A44
    { KC_NO, move[0][3], move[1][3], move[2][3],      KC_NO      }, // A50-A54
    { KC_NO, move[0][2], move[1][2], move[2][2],      move[3][2]      }, // A60-A64
    { KC_NO, move[0][1], move[1][1], move[2][1],      move[3][1]      }, // A70-A74
    { KC_NO, move[0][0], move[1][0], move[2][0],      move[3][0]      }, // A80-A84
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // BOO-B04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,                     move[3][6] }, \
    { KC_NO, move[0][6],  move[1][6],  move[2][6],    move[3][7] }, \
    { KC_NO, move[0][7],  move[1][7],  move[2][7],    move[3][8] }, \
    { KC_NO, move[0][8],  move[1][8],  move[2][8],    KC_NO      }, \
    { KC_NO, move[0][9],  move[1][9],  move[2][9],    move[3][9] }, \
    { KC_NO, move[0][10], move[1][10], move[2][10],   move[3][10]}, \
    { KC_NO, move[0][11], move[1][11], move[2][11],   move[3][11]}  \
},

[_NUMPAD] = {
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A00-A04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A10-A14
    { KC_NO, KC_NO, KC_NO, KC_NO,                     num[3][5] }, // A20-A24
    { KC_NO, num[0][5], num[1][5], num[2][5],      num[3][4] }, // A30-A34
    { KC_NO, num[0][4], num[1][4], num[2][4],      num[3][3] }, // A40-A44
    { KC_NO, num[0][3], num[1][3], num[2][3],      KC_NO      }, // A50-A54
    { KC_NO, num[0][2], num[1][2], num[2][2],      num[3][2]      }, // A60-A64
    { KC_NO, num[0][1], num[1][1], num[2][1],      num[3][1]      }, // A70-A74
    { KC_NO, num[0][0], num[1][0], num[2][0],      num[3][0]      }, // A80-A84
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // BOO-B04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,                     num[3][6] }, \
    { KC_NO, num[0][6],  num[1][6],  num[2][6],    num[3][7] }, \
    { KC_NO, num[0][7],  num[1][7],  num[2][7],    num[3][8] }, \
    { KC_NO, num[0][8],  num[1][8],  num[2][8],    KC_NO      }, \
    { KC_NO, num[0][9],  num[1][9],  num[2][9],    num[3][9] }, \
    { KC_NO, num[0][10], num[1][10], num[2][10],   num[3][10]}, \
    { KC_NO, num[0][11], num[1][11], num[2][11],   num[3][11]}  \
},
[_PARENS] = {
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A00-A04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A10-A14
    { KC_NO, KC_NO, KC_NO, KC_NO,                     par[3][5] }, // A20-A24
    { KC_NO, par[0][5], par[1][5], par[2][5],      par[3][4] }, // A30-A34
    { KC_NO, par[0][4], par[1][4], par[2][4],      par[3][3] }, // A40-A44
    { KC_NO, par[0][3], par[1][3], par[2][3],      KC_NO      }, // A50-A54
    { KC_NO, par[0][2], par[1][2], par[2][2],      par[3][2]      }, // A60-A64
    { KC_NO, par[0][1], par[1][1], par[2][1],      par[3][1]      }, // A70-A74
    { KC_NO, par[0][0], par[1][0], par[2][0],      par[3][0]      }, // A80-A84
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // BOO-B04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,                     par[3][6] }, \
    { KC_NO, par[0][6],  par[1][6],  par[2][6],    par[3][7] }, \
    { KC_NO, par[0][7],  par[1][7],  par[2][7],    par[3][8] }, \
    { KC_NO, par[0][8],  par[1][8],  par[2][8],    KC_NO      }, \
    { KC_NO, par[0][9],  par[1][9],  par[2][9],    par[3][9] }, \
    { KC_NO, par[0][10], par[1][10], par[2][10],   par[3][10]}, \
    { KC_NO, par[0][11], par[1][11], par[2][11],   par[3][11]}  \
},
[_SIGNS] = {
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A00-A04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A10-A14
    { KC_NO, KC_NO, KC_NO, KC_NO,                     sign[3][5] }, // A20-A24
    { KC_NO, sign[0][5], sign[1][5], sign[2][5],      sign[3][4] }, // A30-A34
    { KC_NO, sign[0][4], sign[1][4], sign[2][4],      sign[3][3] }, // A40-A44
    { KC_NO, sign[0][3], sign[1][3], sign[2][3],      KC_NO      }, // A50-A54
    { KC_NO, sign[0][2], sign[1][2], sign[2][2],      sign[3][2]      }, // A60-A64
    { KC_NO, sign[0][1], sign[1][1], sign[2][1],      sign[3][1]      }, // A70-A74
    { KC_NO, sign[0][0], sign[1][0], sign[2][0],      sign[3][0]      }, // A80-A84
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // BOO-B04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,                     sign[3][6] }, \
    { KC_NO, sign[0][6],  sign[1][6],  sign[2][6],    sign[3][7] }, \
    { KC_NO, sign[0][7],  sign[1][7],  sign[2][7],    sign[3][8] }, \
    { KC_NO, sign[0][8],  sign[1][8],  sign[2][8],    KC_NO      }, \
    { KC_NO, sign[0][9],  sign[1][9],  sign[2][9],    sign[3][9] }, \
    { KC_NO, sign[0][10], sign[1][10], sign[2][10],   sign[3][10]}, \
    { KC_NO, sign[0][11], sign[1][11], sign[2][11],   sign[3][11]}  \
},
[_MOUSE] = {
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A00-A04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A10-A14
    { KC_NO, KC_NO, KC_NO, KC_NO,                     mouse[3][5] }, // A20-A24
    { KC_NO, mouse[0][5], mouse[1][5], mouse[2][5],      mouse[3][4] }, // A30-A34
    { KC_NO, mouse[0][4], mouse[1][4], mouse[2][4],      mouse[3][3] }, // A40-A44
    { KC_NO, mouse[0][3], mouse[1][3], mouse[2][3],      KC_NO      }, // A50-A54
    { KC_NO, mouse[0][2], mouse[1][2], mouse[2][2],      mouse[3][2]      }, // A60-A64
    { KC_NO, mouse[0][1], mouse[1][1], mouse[2][1],      mouse[3][1]      }, // A70-A74
    { KC_NO, mouse[0][0], mouse[1][0], mouse[2][0],      mouse[3][0]      }, // A80-A84
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // BOO-B04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,                     mouse[3][6] }, \
    { KC_NO, mouse[0][6],  mouse[1][6],  mouse[2][6],    mouse[3][7] }, \
    { KC_NO, mouse[0][7],  mouse[1][7],  mouse[2][7],    mouse[3][8] }, \
    { KC_NO, mouse[0][8],  mouse[1][8],  mouse[2][8],    KC_NO      }, \
    { KC_NO, mouse[0][9],  mouse[1][9],  mouse[2][9],    mouse[3][9] }, \
    { KC_NO, mouse[0][10], mouse[1][10], mouse[2][10],   mouse[3][10]}, \
    { KC_NO, mouse[0][11], mouse[1][11], mouse[2][11],   mouse[3][11]}  \
},
[_CONTROLS] = {
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A00-A04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A10-A14
    { KC_NO, KC_NO, KC_NO, KC_NO,                     cont[3][5] }, // A20-A24
    { KC_NO, cont[0][5], cont[1][5], cont[2][5],      cont[3][4] }, // A30-A34
    { KC_NO, cont[0][4], cont[1][4], cont[2][4],      cont[3][3] }, // A40-A44
    { KC_NO, cont[0][3], cont[1][3], cont[2][3],      KC_NO      }, // A50-A54
    { KC_NO, cont[0][2], cont[1][2], cont[2][2],      cont[3][2]      }, // A60-A64
    { KC_NO, cont[0][1], cont[1][1], cont[2][1],      cont[3][1]      }, // A70-A74
    { KC_NO, cont[0][0], cont[1][0], cont[2][0],      cont[3][0]      }, // A80-A84
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // BOO-B04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,                     cont[3][6] }, \
    { KC_NO, cont[0][6],  cont[1][6],  cont[2][6],    cont[3][7] }, \
    { KC_NO, cont[0][7],  cont[1][7],  cont[2][7],    cont[3][8] }, \
    { KC_NO, cont[0][8],  cont[1][8],  cont[2][8],    KC_NO      }, \
    { KC_NO, cont[0][9],  cont[1][9],  cont[2][9],    cont[3][9] }, \
    { KC_NO, cont[0][10], cont[1][10], cont[2][10],   cont[3][10]}, \
    { KC_NO, cont[0][11], cont[1][11], cont[2][11],   cont[3][11]}  \
},
[_FUNC] = {
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A00-A04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // A10-A14
    { KC_NO, KC_NO, KC_NO, KC_NO,                     func[3][5] }, // A20-A24
    { KC_NO, func[0][5], func[1][5], func[2][5],      func[3][4] }, // A30-A34
    { KC_NO, func[0][4], func[1][4], func[2][4],      func[3][3] }, // A40-A44
    { KC_NO, func[0][3], func[1][3], func[2][3],      KC_NO      }, // A50-A54
    { KC_NO, func[0][2], func[1][2], func[2][2],      func[3][2]      }, // A60-A64
    { KC_NO, func[0][1], func[1][1], func[2][1],      func[3][1]      }, // A70-A74
    { KC_NO, func[0][0], func[1][0], func[2][0],      func[3][0]      }, // A80-A84
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, // BOO-B04
    { KC_NO, KC_NO, KC_NO, KC_NO,                     KC_NO      }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,                     func[3][6] }, \
    { KC_NO, func[0][6],  func[1][6],  func[2][6],    func[3][7] }, \
    { KC_NO, func[0][7],  func[1][7],  func[2][7],    func[3][8] }, \
    { KC_NO, func[0][8],  func[1][8],  func[2][8],    KC_NO      }, \
    { KC_NO, func[0][9],  func[1][9],  func[2][9],    func[3][9] }, \
    { KC_NO, func[0][10], func[1][10], func[2][10],   func[3][10]}, \
    { KC_NO, func[0][11], func[1][11], func[2][11],   func[3][11]}  \
}



};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
