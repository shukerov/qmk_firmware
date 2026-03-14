#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _NAV,
    _NUM,
    _SYM,
    _MOUSE,
    _GAMING
};

// Layer switching
#define SPC_P LT(_NAV, KC_SPACE)
#define ENT_P LT(_SYM, KC_ENT)

// Home-row mods left
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define GUI_F LGUI_T(KC_F)

// Home-row mods right
#define CTL_SCLN RCTL_T(KC_SCLN)
#define ALT_L RALT_T(KC_L)
#define SFT_K RSFT_T(KC_K)
#define GUI_J RGUI_T(KC_J)

// Thumb layer keys
#define NAV MO(_NAV)
#define NUM MO(_NUM)
/* #define MOUSE MO(_MOUSE) */
/* #define SYM MO(_SYM) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  c-A | a-S  |  s-D |  g-F |   G  |-------.    ,-------|  H   | g-J  | s-K  | a-L  | c-;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |MOUSE | /Space  /       \Enter \  |BackSP|M-NUM | RGUI |
 *                   |      |      |      |/  &NAV /         \ &SYM \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL, CTL_A,  ALT_S,   SFT_D,   GUI_F,    KC_G,                     KC_H,   GUI_J,   SFT_K,   ALT_L,CTL_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                          KC_LALT,    KC_LGUI, NAV, SPC_P,  ENT_P,   KC_BSPC,   NUM, KC_RGUI
),

/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NAV] = LAYOUT(
  XXXXXXX, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,  KC_7,   KC_8,    KC_9,    KC_0,    _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,   _______, _______,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),

/* NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  7   |  8   |  9   |      |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  4   |  5   |  6   | =&+  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |  1   |  2   |  3   | \&|  |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  _______, _______,  KC_7,    KC_8,    KC_9,   _______,                      KC_6,    KC_7,    KC_8,   KC_9,     KC_0,  _______,
  _______, _______,  KC_4,    KC_5,    KC_6,   	KC_EQL,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,  _______,
  _______, _______,  KC_1,    KC_2,    KC_3,   KC_BSLS, KC_LBRC,  KC_RBRC,   KC_N,    KC_M, KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                            _______,_______,      KC_0,   SPC_P,   KC_ENT,_______, _______, _______
),

/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | GAME |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  &   |  *   |  (   |      |                    |      |      |      |      |      | MSWAP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  $   |  %   |  ^   | =&+  |-------.    ,-------|      |  {   |   }  |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|      |  !   |  @   |  #   |  |   |-------|    |-------|      |  [   |   ]  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt |  (   |  )   | /  -&_  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_SYM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_GAMING),
  XXXXXXX, XXXXXXX, KC_AMPR, KC_ASTR, KC_LPRN, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG,
  XXXXXXX, XXXXXXX,  KC_DLR, KC_PERC, KC_CIRC, 	KC_EQL,                   XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LSFT, XXXXXXX, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, KC_LPRN, KC_RPRN, KC_MINS, _______,  _______, _______, _______
  ),

/* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | Redo |Paste | Copy |  Cut | Undo |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ctrl | Alt  |Shift | GUI  |      |-------.    ,-------|      | WhlD | MsUp | WhlU |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| WhlL | MsL  | MsDn | MsR  | WhlR |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \Btn2  \  |Btn1  |Btn3  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_MOUSE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_AGIN, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, XXXXXXX,
  XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, XXXXXXX,                   XXXXXXX, MS_WHLD,   MS_UP, MS_WHLU, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MS_WHLL, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLR, XXXXXXX,
                             _______, _______, _______, _______, MS_BTN2, MS_BTN1, MS_BTN3, _______
  ),

/* GAMING - All keys explicitly defined (no transparent keys)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |M-NAV | /Space  /       \Enter \  |BackSP|M-NUM | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 *
 * Key changes: Home-row keys are plain (no mod-taps), Space/Enter are plain (no layer taps)
 * Use NAV thumb key to access NAV layer and toggle gaming mode off
 */
  [_GAMING] = LAYOUT(
  KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                              KC_LALT, KC_LGUI, NAV, KC_SPC,  KC_ENT, KC_BSPC, NUM, KC_RGUI
  )
};

/* TODO:
 * add equals sign on symbol layer
 * */
