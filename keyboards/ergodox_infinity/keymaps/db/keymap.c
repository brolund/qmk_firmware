#include QMK_KEYBOARD_H
#include "version.h"
#include "config.h"
#include "i3.h"
#include "sv.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};
const uint16_t b1[] = BASE_1;
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
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, // A00-A04
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, b1[1], KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, b1[0], KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, // BOO-B04
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }  \
},
[_MOVE] =  {                                       \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, // A00-A04
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, // BOO-B04
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO }  \
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
