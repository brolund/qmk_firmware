#ifdef MOUSEKEY_DELAY
#undef MOUSEKEY_DELAY
#endif
#ifdef MOUSEKEY_INTERVAL
#undef MOUSEKEY_INTERVAL
#endif

#ifdef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_MAX_SPEED
#endif
#ifdef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_TIME_TO_MAX
#endif
#ifdef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_MAX_SPEED
#endif
#ifdef MOUSEKEY_WHEEL_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#endif

#define MOUSEKEY_DELAY             30
#define MOUSEKEY_INTERVAL          20

#define MOUSEKEY_MAX_SPEED         5
#define MOUSEKEY_TIME_TO_MAX       20
#define MOUSEKEY_WHEEL_MAX_SPEED   6
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#define _BASE 0
#define _MOVE 1
#define _NUMPAD 2
#define _PARENS 3
#define _SIGNS 4
#define _MOUSE 5
#define _CONTROLS 6
#define _FUNC 7
#define _I3WS 8
#define _I3MV 9

#define ENDASH LALT(KC_MINS)
#define POUND ALGR(KC_3)
#define EURO ALGR(KC_E)
#define H(X) LALT(LCTL(X))

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define CA(n)   LCTL(LALT(n))
#define CAS(n)  LCTL(LALT(LSFT(n)))
#define CS(n)   LCTL(LSFT(n))
#define AS(n)   LALT(LSFT(n))
#define SLACKUP AS(KC_UP)
#define SLACKDN AS(KC_DOWN)

#define TRANS  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
#define THUMB_ROW {KC_DEL, KC_LGUI, KC_LALT, ALGR_T(KC_INS), CTL_T(KC_BSPC), GUI_T(KC_DEL), ALT_T(KC_ENT), SFT_T(KC_SPC), KC_RALT, KC_RCTL, KC_ENT, KC_ENT}
/*
 * |------+-------+------+------------+----------+-----------+----------+----------+------+------+------+------|
 * | Del  | Gui   |  Alt | Altgr(Ins) |Ctrl(Bspc)| Gui(Del)  | Alt(Ent) | Sft(Spc) |  Alt | Ctrl | Ent  | Ent  |
 * `-----------------------------------------------------------------------------------------------------------'*/

#define BASE_1 {KC_ESC,            NO_AE,             LT(_NUMPAD,KC_Q),  LT(_I3WS, KC_COMM), LT(_I3MV, KC_DOT), KC_Y, KC_F, KC_G, KC_L, KC_H, KC_M, KC_BSPC}
#define BASE_2 {LT(_MOUSE,KC_TAB), LT(_MOVE,KC_O),    KC_I,              KC_E,              KC_A,               KC_U, KC_D, KC_S, KC_T, KC_R, KC_N, KC_P}
#define BASE_3 {LSFT(KC_7),        LT(_FUNC,NO_OSLH), LT(_CONTROLS,KC_J),LT(_SIGNS,KC_K),   LT(_PARENS,SE_AA),  KC_Z, KC_B, KC_C, KC_X, KC_V, KC_W, NO_MINS}
/* BASE
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Ä  | Q/num|,/i3ws|./i3mv|  Y   | F    |   G  |   L  |   H  |   M  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Tab/ms| O/mv |   I  |   E  |   A  |  U   | D    |   S  |   T  |   R  |   N  |  P   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  /   |Ö/fun |J/cont|K/sign| Å/par|  Z   | B    |   C  |   X  |   V  |   W  |  -_  |
 */

#define MOVE_1 { _______, _______,   _______,   _______,  _______,  _______,  _______, KC_HOME,    KC_UP,     KC_END,  KC_PGUP, _______ }
#define MOVE_2 { _______, _______,   _______,   _______,  _______,  _______,  _______, KC_LEFT,    KC_DOWN,   KC_RGHT, KC_PGDN, KC_LSFT }
#define MOVE_3 { _______, _______,   _______,   _______,  _______,  _______,  _______, LCTL(KC_HOME), LCTL(KC_END), _______, _______, KC_LCTL }
/* MOVE
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | Pg Up| Home |  Up  | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Pg Dn| Left | Down | Right|      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | THome| BEnd | Del  |      | Ctrl |
 */

#define NUM_1  { _______, _______, _______ ,_______, _______, _______, SE_ASTR,  KC_7, KC_8,    KC_9,    NO_MINS, _______}
#define NUM_2  { _______, _______, _______ ,_______, _______, _______, NO_SLSH,  KC_4, KC_5,    KC_6,    NO_PLUS, NO_DLR }
#define NUM_3  { _______, _______, _______ ,_______, _______, _______, KC_PERC , KC_1, KC_2,    KC_3,    NO_EQL , NO_PND  }
#define NUM_4  { _______, _______, _______ ,_______, _______, _______, _______,  KC_0, KC_LSFT, _______, _______, _______}
/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   *  |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   /  |   4  |   5  |   6  |   =  |   $  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   %  |   1  |   2  |   3  |   -  |   £  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  | Shift|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

#define PAR_1  {_______, _______, _______, _______, _______, _______, _______, NO_QUO2, NO_APOS, NO_ACUT, _______, _______}
#define PAR_2  {_______, _______, _______, _______, _______, _______, NO_PIPE, NO_LPRN, NO_RPRN, NO_LCBR, NO_RCBR, NO_SLSH}
#define PAR_3  {_______, _______, _______, _______, _______, _______, NO_UNDS, NO_LBRC, NO_RBRC, NO_LESS, NO_GRTR, NO_BSLS}
/* PARENS
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   "  |   '  |   `´ |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |  |   (  |   )  |   {  |   }  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   _  |   [  |   ]  |   <  |   >  |  \   |
 */

#define SIGN_1 {_______, _______, _______, _______, _______, _______, NO_EQL,  NO_PLUS, NO_MINS, SE_ASTR, KC_PERC, _______}
#define SIGN_2 {_______, _______, _______, _______, _______, _______, NO_TILD, KC_DOT,  KC_EXLM, NO_QUES, NO_AMPR, _______}
#define SIGN_3 {_______, _______, _______, _______, _______, _______, NO_CIRC, NO_AT,   NO_HASH, NO_DLR,  NO_PND,  NO_EURO}
/* SIGNS
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   =  |  +   |   -  |   *  |   %  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   ~  |   .  |   !  |   ?  |   &  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   ^  |   @  |   #  |   $  |   £  |  €   |
 */

#define MOUS_1 {_______, _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______}
#define MOUS_2 {_______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______}
#define MOUS_3 {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  }
/* MOUSE
 * ,-----------------------------------------------------------------------------------.
 * |      |      | ACC-2| ACC-1| ACC-0|      |      | SW-L |  M-U | SW-R | SW-U |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | MB-3 | MB-2 | MB-1 |      |      |  M-L |  M-D |  M-R | SW-D |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |Reset |
 */

#define CONT_1 {_______, _______, _______, _______, _______, _______, _______, KC_VOLU, SLACKUP, _______, _______, _______}
#define CONT_2 {_______, _______, _______, _______, _______, _______, _______, KC_VOLD, SLACKDN, KC_APP , _______, _______}
#define CONT_3 {_______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_PSCR, _______, _______, _______}
/* CONTROLS
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | Vol+ |SlackU|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Vol- |SlackD|CtxMen|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |VolOff|PrScr |      |      |      |
 */

#define FUNC_1 {_______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______}
#define FUNC_2 {_______, _______, _______, _______, _______, _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______}
#define FUNC_3 {_______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______}
 /* FUNC
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F4  |  F5  |  F6  | F11  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F1  |  F2  |  F3  | F12  |      |
 */

#define I3WS_1 {_______, _______, _______, _______, _______, _______, _______, I3_WS7,  I3_WS8,  I3_WS9,  I3_WS0,  _______}
#define I3WS_2 {_______, _______, _______, _______, _______, _______, _______, I3_WS4,  I3_WS5,  I3_WS6,  I3_LNCH, _______}
#define I3WS_3 {_______, _______, _______, _______, _______, _______, _______, I3_WS1,  I3_WS2,  I3_WS3,  I3_TERM, _______}
 /* I3WS
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  W7  |  W8  |  W9  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  W4  |  W5  |  W6  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  W1  |  W2  |  W3  |      |      |
 */

#define I3MV_1 {_______, _______, _______, _______, _______, _______, _______, _______, I3_FUP,  _______, _______, _______}
#define I3MV_2 {_______, _______, _______, _______, _______, _______, _______, I3_FLFT, I3_FDWN, I3_FRGT, _______, _______}
 /* I3MV
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Lef  | Down | Right|      |      |
 */
