#include QMK_KEYBOARD_H

#define MAC_EXIT LGUI(KC_Q)
#define MAC_CUT LGUI(KC_X)
#define MAC_UNDO LGUI(KC_Z)
#define MAC_COPY LGUI(KC_C)
#define MAC_PASTE LGUI(KC_V)
#define MAC_SELECT LGUI(KC_A)
#define MAC_FIND LGUI(KC_F)
#define MAC_SAVE LGUI(KC_S)
#define MAC_CLOSEW LGUI(KC_W)
#define MAC_NEWT LGUI(KC_T)
#define MAC_REFRESH LGUI(KC_R)
#define MAC_PRINT LGUI(KC_P)

#define MAC_SPOTLIGHT LGUI(KC_SPC)
#define SCREEN_SHOT LSG(KC_4)
#define MAC_LOCKSCREEN LCTL(LGUI(KC_Q))

#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define TMUX_PREFIX LCTL(KC_X)

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  MAC,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_mit(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   _______,   _______,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_BSPC,
    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   _______,   _______,   KC_H,   KC_J,   KC_K,   KC_L,   LT(MAC, KC_P),
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   _______,   _______,   KC_N,   KC_M,   KC_COMMA,   KC_DOT, KC_SLASH,
    KC_NO,  KC_NO,  KC_NO,  LOWER,  LCTL_T(KC_SPC), _______,  KC_LSFT, RAISE, KC_NO,  KC_NO,    KC_NO
  ),

  [_LOWER] = LAYOUT_planck_mit(
    _______, KC_UNDS, _______, _______, _______,  _______,   _______, _______,   KC_AMPR,   KC_ASTR, KC_SCOLON,  LSFT(KC_SCOLON),
    KC_EXLM, KC_AT,    KC_HASH, KC_DLR,            KC_PERC,   _______,   _______, KC_LEFT,   KC_DOWN,   KC_UP,   KC_RIGHT,   KC_QUOTE,
    KC_CIRC, _______,  KC_LABK, KC_RABK,           _______,   _______,     _______, _______,   KC_HOME,    KC_END,  KC_QUES,   KC_DQUO,
    _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______
  ),

  [_RAISE] = LAYOUT_planck_mit(
    KC_ESCAPE, KC_MINS, KC_LPRN, KC_RPRN, KC_BSLASH,      _______,   _______, _______, KC_7, KC_8, KC_9, KC_DOT,
    KC_TAB,    KC_PIPE, KC_LCBR, KC_RCBR, KC_EQUAL,      _______, _______,   KC_PLUS, KC_4, KC_5, KC_6, KC_ENTER,
    KC_GRAVE,  RSFT(KC_GRAVE), KC_LBRACKET, KC_RBRACKET, TMUX_PREFIX, _______, _______, KC_0, KC_1, KC_2, KC_3, KC_ASTR,
    _______, _______, _______, KC_LGUI, KC_LALT, _______,_______,_______,_______,_______,_______
  ),

  [_ADJUST] = LAYOUT_planck_mit(
    KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP, KC_MS_UP, _______,_______,_______, _______, _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_BRIGHTNESS_UP,_______,
    _______, KC_MS_LEFT,KC_MS_DOWN,     KC_MS_RIGHT,    _______,    _______, _______, _______,    KC_MS_BTN1,     KC_MS_BTN2,   KC_BRIGHTNESS_DOWN,_______,
    _______, KC_MEDIA_PLAY_PAUSE,KC_MS_WH_UP,    KC_MS_WH_DOWN,  _______,    _______, _______,    _______, _______,   _______,   _______,   RESET,
    _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______
  ),
  [MAC] = LAYOUT_planck_mit(
    MAC_EXIT,   MAC_COPY,   MAC_PASTE, MAC_REFRESH, MAC_NEWT, _______, _______,_______,_______,_______,_______,MAC_LOCKSCREEN,
    MAC_SELECT, MAC_SAVE,   MAC_CUT,   MAC_FIND, SCREEN_SHOT, _______,_______,_______,_______,_______,_______,_______,
    MAC_UNDO,   MAC_CLOSEW, _______,MAC_PRINT,_______,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,MAC_SPOTLIGHT,    _______,    _______,_______,_______,_______,_______
  ),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,114}, {0,0,114}, {0,0,114}, {40,116,237}, {0,0,114}, {0,0,0}, {0,0,0}, {0,0,114}, {40,116,237}, {40,116,237}, {0,0,114}, {15,253,248},
            {40,116,237}, {40,116,237}, {40,116,237}, {40,116,237}, {0,0,114}, {0,0,0}, {0,0,0}, {0,0,114}, {40,116,237}, {40,116,237}, {40,116,237}, {40,116,237},
            {0,0,114}, {0,0,114}, {40,116,237}, {40,116,237}, {0,0,114}, {0,0,0}, {0,0,0}, {0,0,114}, {40,116,237}, {0,0,114}, {0,0,114}, {31,255,255},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {209,253,248}, {0,0,0}, {31,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {33,255,255}, {33,255,255}, {33,255,255}, {30,96,255}, {33,255,255}, {0,0,0}, {0,0,0}, {30,96,255}, {33,255,255}, {33,255,255}, {249,255,255}, {249,255,255},
            {210,182,207}, {0,0,0}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,183,238}, {249,255,255},
            {47,202,250}, {47,202,250}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {151,183,237}, {169,120,255}, {0,183,238}, {249,255,255}, {0,183,238},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {107,241,250}, {67,212,242}, {67,212,242}, {0,183,238}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,183,238},
            {0,0,0}, {15,166,195}, {129,212,242}, {129,212,242}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {28,253,248},
            {0,0,0}, {0,0,0}, {157,212,242}, {157,212,242}, {196,183,238}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,205,155},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {31,255,255}, {0,183,238}, {14,255,255}, {31,255,255}, {0,205,155},
            {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {20,177,225}, {0,183,238}, {0,183,238}, {31,255,255}, {0,205,155},
            {0,0,0}, {31,255,255}, {31,255,255}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {137,177,211}, {137,177,211}, {137,177,211}, {205,255,255},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {31,255,255}, {31,255,255}, {0,183,238}, {31,255,255}, {31,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {14,255,255}, {31,255,255}, {0,205,155},
            {0,0,0}, {0,183,238}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {20,177,225}, {0,183,238}, {0,183,238}, {31,255,255}, {0,205,155},
            {0,0,0}, {31,255,255}, {31,255,255}, {33,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {137,177,211}, {137,177,211}, {137,177,211}, {205,255,255},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  // if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

