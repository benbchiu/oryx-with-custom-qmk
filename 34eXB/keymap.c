#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};

const key_override_t lprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LBRC );
const key_override_t rprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RBRC);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&lprn_key_override,
	&rprn_key_override,
	NULL
};

void housekeeping_task_user(void) {
  achordion_task();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_CAPS,        KC_2,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_U,           KC_O,           KC_F,           KC_Q,                                           KC_B,           KC_P,           KC_Y,           KC_L,           KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LT(2,KC_I),     LT(1,KC_E),     MT(MOD_LSFT, KC_N),MT(MOD_LGUI, KC_M),                                MT(MOD_LGUI, KC_G),MT(MOD_LSFT, KC_T),LT(1,KC_S),     LT(2,KC_R),     KC_TRANSPARENT, KC_TRANSPARENT, 
    CW_TOGG,        MT(MOD_LCTL, KC_A),MT(MOD_LALT, KC_Z),KC_J,           LT(3,KC_H),     KC_X,                                           KC_K,           LT(3,KC_D),     KC_V,           MT(MOD_LALT, KC_W),MT(MOD_LCTL, KC_C),KC_DELETE,      
                                                    KC_BSPC,        KC_ESCAPE,                                      KC_ENTER,       KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_1,           KC_2,           KC_3,           KC_MINUS,                                       KC_TRANSPARENT, KC_NO,          KC_UP,          KC_NO,          KC_PAGE_UP,     KC_HOME,        
    KC_NO,          KC_NO,          KC_4,           KC_5,           KC_6,           KC_DOT,                                         KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDN,        KC_END,         
    KC_NO,          KC_0,           KC_7,           KC_8,           KC_9,           KC_EQUAL,                                       KC_NO,          LCTL(LSFT(KC_TAB)),KC_TAB,         LCTL(KC_TAB),   QK_LLCK,        KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_BSLS,        KC_EQUAL,       KC_SCLN,        KC_NO,                                          KC_NO,          KC_LCBR,        KC_RCBR,        KC_PERC,        KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_SLASH,       KC_COMMA,       KC_DOT,         KC_NO,                                          KC_GRAVE,       KC_LPRN,        KC_RPRN,        KC_MINUS,       KC_NO,          KC_NO,          
    KC_NO,          KC_QUOTE,       KC_AMPR,        KC_AT,          KC_HASH,        KC_NO,                                          KC_NO,          KC_CIRC,        KC_EXLM,        KC_ASTR,        KC_DLR,         KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_NO,                                          KC_NO,          KC_F13,         KC_F14,         KC_F15,         KC_F16,         KC_NO,          
    KC_NO,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,                                          KC_NO,          KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_NO,          
    KC_NO,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NO,                                          KC_NO,          KC_F21,         KC_F22,         KC_F23,         KC_F24,         KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {139,221,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,180,250}, {139,180,250}, {139,180,250}, {139,147,95}, {0,0,0}, {0,0,0}, {139,180,250}, {139,180,250}, {139,180,250}, {139,147,95}, {0,0,0}, {139,180,250}, {139,180,250}, {139,180,250}, {139,180,250}, {139,147,95}, {139,180,250}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,180,250}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,180,250}, {0,0,0}, {139,180,250}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {139,180,250}, {139,180,250} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {74,224,107}, {74,224,107}, {74,224,107}, {0,0,0}, {0,0,0}, {74,224,107}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {74,224,107}, {74,224,107}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,224,107}, {74,224,107}, {74,224,107}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {74,255,255}, {74,224,107}, {0,0,0}, {74,224,107}, {74,224,107} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {139,180,250}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {169,255,255}, {0,245,245}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,0}, {0,245,245}, {0,245,245} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
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
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }

  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



