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
#define SWITCH_INPUT RGUI(KC_SPC)

#define MAC_SPOTLIGHT LGUI(KC_SPC)
#define SCREEN_SHOT LSG(KC_4)
#define MAC_LOCKSCREEN LCTL(LGUI(KC_Q))
#define MAC_SETTING LGUI(KC_COMMA)


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
    KC_NO,  KC_NO,  KC_NO,  LOWER,  LSFT_T(KC_SPC), _______,  OSM(MOD_LCTL), RAISE, KC_NO,  KC_NO,    KC_NO
  ),

  [_LOWER] = LAYOUT_planck_mit(
    _______, KC_UNDS,  KC_LABK, KC_RABK, KC_PERC,  _______,   _______, _______,   KC_AMPR,    KC_SCLN,  LSFT(KC_SCLN),   KC_ASTR,
    KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  _______,   _______,   _______, KC_LEFT,   KC_DOWN,   KC_UP,      KC_RIGHT,         KC_QUOTE,
    KC_CIRC, _______,  _______, _______,           _______,   _______,     _______, _______,   KC_HOME,    KC_END,  KC_QUES,   KC_DQUO,
    _______, _______,_______,_______,_______,_______,TMUX_PREFIX,_______,_______,_______,_______
  ),

  [_RAISE] = LAYOUT_planck_mit(
    KC_ESCAPE, KC_MINS, KC_LPRN, KC_RPRN, KC_BSLS,      _______,   _______, _______, KC_7, KC_8, KC_9, KC_DOT,
    KC_TAB,    KC_PIPE, KC_LCBR, KC_RCBR, KC_EQUAL,      _______, _______,   KC_PLUS, KC_4, KC_5, KC_6, KC_ENTER,
    KC_GRAVE,  RSFT(KC_GRAVE), KC_LBRC, KC_RBRC, _______, _______, _______, KC_0, KC_1, KC_2, KC_3, KC_ASTR,
    _______, _______, _______, KC_LGUI, KC_LALT, _______,_______,_______,_______,_______,_______
  ),

  [_ADJUST] = LAYOUT_planck_mit(
    KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP, KC_MS_UP, _______,_______,_______, _______, _______, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_BRIGHTNESS_UP,_______,
    _______, KC_MS_LEFT,KC_MS_DOWN,     KC_MS_RIGHT,    _______,    _______, _______, _______,    KC_MS_BTN1,     KC_MS_BTN2,   KC_BRIGHTNESS_DOWN,_______,
    _______, KC_MEDIA_PLAY_PAUSE,KC_MS_WH_UP,    KC_MS_WH_DOWN,  _______,    _______, _______,    _______, _______,   _______,   _______,   QK_BOOT,
    _______, _______,_______,_______,_______,_______,_______,_______,_______,_______,_______
  ),
  [MAC] = LAYOUT_planck_mit(
    MAC_EXIT,   MAC_COPY,   MAC_PASTE, MAC_REFRESH, MAC_NEWT, _______, _______,_______,_______,_______,_______,MAC_LOCKSCREEN,
    MAC_SELECT, MAC_SAVE,   _______,   MAC_FIND, SCREEN_SHOT, _______,_______,_______,_______,_______,_______,_______,
    MAC_UNDO,   MAC_CUT, _______,_______,MAC_CLOSEW,_______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,MAC_SETTING,MAC_SPOTLIGHT,    _______,    _______,_______,_______,_______,_______
  ),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    // Layer 0 (Base): Warm white with subtle accents
    [0] = { {0,0,80}, {0,0,80}, {0,0,80}, {0,0,80}, {0,0,80}, {0,0,0}, {0,0,0}, {0,0,80}, {0,0,80}, {0,0,80}, {0,0,80}, {0,255,120},
            {0,0,80}, {0,0,80}, {0,0,80}, {0,0,80}, {0,0,80}, {0,0,0}, {0,0,0}, {0,0,80}, {0,0,80}, {0,0,80}, {0,0,80}, {85,255,120},
            {0,0,80}, {0,0,80}, {0,0,80}, {0,0,80}, {0,0,80}, {0,0,0}, {0,0,0}, {0,0,80}, {0,0,80}, {0,0,80}, {0,0,80}, {31,255,120},
            {0,0,0}, {0,0,0}, {0,0,0}, {85,255,160}, {43,255,200}, {0,0,0}, {21,255,160}, {85,255,160}, {0,0,0}, {0,0,0}, {0,0,0} },

    // Layer 1 (Lower): Orange theme for symbols/navigation - updated for new layout
    [1] = { {0,0,80}, {30,255,255}, {120,255,200}, {120,255,200}, {30,255,255}, {0,0,0}, {0,0,0}, {0,0,80}, {30,255,255}, {21,255,200}, {21,255,200}, {21,255,200},
            {30,255,255}, {30,255,255}, {30,255,255}, {30,255,255}, {0,0,80}, {0,0,0}, {0,0,0}, {120,255,200}, {120,255,200}, {120,255,200}, {120,255,200}, {21,255,200},
            {43,255,200}, {0,0,80}, {0,0,80}, {0,0,80}, {0,0,80}, {0,0,0}, {0,0,0}, {0,0,80}, {21,255,200}, {21,255,200}, {21,255,200}, {120,255,200},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {170,255,200}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    // Layer 2 (Raise): Blue theme for numbers/brackets
    [2] = { {0,0,0}, {200,255,200}, {200,255,200}, {200,255,200}, {200,255,200}, {0,0,0}, {0,0,0}, {0,0,0}, {240,255,255}, {240,255,255}, {240,255,255}, {240,255,255},
            {0,0,0}, {200,255,200}, {200,255,200}, {200,255,200}, {0,0,0}, {0,0,0}, {0,0,0}, {180,255,200}, {240,255,255}, {240,255,255}, {240,255,255}, {240,255,255},
            {0,0,0}, {0,0,0}, {200,255,200}, {200,255,200}, {0,0,0}, {0,0,0}, {0,0,0}, {240,255,255}, {240,255,255}, {240,255,255}, {240,255,255}, {240,255,255},
            {0,0,0}, {0,0,0}, {0,0,0}, {85,255,200}, {43,255,200}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    // Layer 3 (Adjust): Purple theme for media/mouse
    [3] = { {170,255,200}, {170,255,200}, {200,255,150}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,255,200}, {85,255,200}, {43,255,200}, {0,0,0},
            {0,0,0}, {200,255,150}, {200,255,150}, {200,255,150}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {200,255,150}, {200,255,150}, {43,255,200}, {0,0,0},
            {0,0,0}, {85,255,200}, {200,255,150}, {200,255,150}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,80}, {0,0,80}, {0,0,80}, {255,100,255},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    // Layer 4 (MAC): Green theme for macOS shortcuts - updated layout
    [4] = { {85,255,200}, {85,255,200}, {85,255,200}, {85,255,200}, {85,255,200}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255},
            {85,255,200}, {85,255,200}, {85,255,200}, {85,255,200}, {120,255,180}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {85,255,200}, {85,255,200}, {0,0,0}, {0,0,0}, {85,255,200}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {120,255,180}, {43,255,200}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
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

bool rgb_matrix_indicators_user(void) {
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
  return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

