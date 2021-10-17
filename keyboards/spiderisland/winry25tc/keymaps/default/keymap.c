/* Copyright 2021 jereksel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define _BASE_LAYER 0
#define _NUMBER_LAYER 1
#define _SYMBOL_LAYER 2
#define _NUM_FUNC_LAYER 3

enum custom_keycodes {
  NUM_FUNC = SAFE_RANGE,
  CTRL_KEY,
  ALT_KEY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = LAYOUT(
        RESET, DEBUG, RGB_TOG, RGB_HUI, RGB_HUD,
        KC_F, KC_A, KC_R, KC_W, KC_P,
        KC_O,   KC_E,   KC_H,   KC_T, KC_D,
        KC_U,   KC_I,   KC_N,   KC_S, KC_Y,
        KC_SPC, NUM_FUNC, TG(_SYMBOL_LAYER) , KC_ENT, OSM(MOD_LSFT)
    ),
    [_NUMBER_LAYER] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_ASTERISK,   KC_7,   KC_8,   KC_9, KC_MINS,
        KC_SLASH,   KC_4,   KC_5,  KC_6, KC_PLUS,
        KC_0,  KC_1,  KC_2, KC_3, KC_DOT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
    ),
    [_SYMBOL_LAYER] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_QUESTION, KC_AMPERSAND, KC_KP_ASTERISK, KC_COLON, KC_SCOLON,
        KC_SLASH, KC_EXCLAIM, KC_MINUS, KC_AT, KC_UNDERSCORE,
        KC_DOUBLE_QUOTE, KC_LEFT_ANGLE_BRACKET, KC_LEFT_PAREN, KC_LBRACKET, KC_LEFT_CURLY_BRACE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
    ),
    [_NUM_FUNC_LAYER] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_ESC, KC_HOME, KC_END, KC_PAUS, KC_PGUP, 
        KC_INS, CTRL_KEY, ALT_KEY, KC_UP, KC_PGDN,
        KC_DEL, KC_BSPC, KC_LEFT, KC_DOWN, KC_RIGHT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
    )
};

//base_layer + space combos
const uint16_t PROGMEM tab_combo[] = {KC_SPC, KC_F, COMBO_END};
const uint16_t PROGMEM quote_combo[] = {KC_SPC, KC_A, COMBO_END};
const uint16_t PROGMEM b_combo[] = {KC_SPC, KC_R, COMBO_END};
const uint16_t PROGMEM m_combo[] = {KC_SPC, KC_W, COMBO_END};
const uint16_t PROGMEM j_combo[] = {KC_SPC, KC_P, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_SPC, KC_O, COMBO_END};
const uint16_t PROGMEM z_combo[] = {KC_SPC, KC_E, COMBO_END};
const uint16_t PROGMEM l_combo[] = {KC_SPC, KC_H, COMBO_END};
const uint16_t PROGMEM c_combo[] = {KC_SPC, KC_T, COMBO_END};
const uint16_t PROGMEM v_combo[] = {KC_SPC, KC_D, COMBO_END};
const uint16_t PROGMEM k_combo[] = {KC_SPC, KC_N, COMBO_END};
const uint16_t PROGMEM g_combo[] = {KC_SPC, KC_S, COMBO_END};
const uint16_t PROGMEM x_combo[] = {KC_SPC, KC_Y, COMBO_END};
const uint16_t PROGMEM comma_combo[] = {KC_SPC, TG(_SYMBOL_LAYER), COMBO_END};
const uint16_t PROGMEM period_combo[] = {KC_SPC, KC_ENT, COMBO_END};

// num + space
const uint16_t PROGMEM f1_combo[] = {KC_SPC, KC_1, COMBO_END};
const uint16_t PROGMEM f2_combo[] = {KC_SPC, KC_2, COMBO_END};
const uint16_t PROGMEM f3_combo[] = {KC_SPC, KC_3, COMBO_END};
const uint16_t PROGMEM f4_combo[] = {KC_SPC, KC_4, COMBO_END};
const uint16_t PROGMEM f5_combo[] = {KC_SPC, KC_5, COMBO_END};
const uint16_t PROGMEM f6_combo[] = {KC_SPC, KC_6, COMBO_END};
const uint16_t PROGMEM f7_combo[] = {KC_SPC, KC_7, COMBO_END};
const uint16_t PROGMEM f8_combo[] = {KC_SPC, KC_8, COMBO_END};
const uint16_t PROGMEM f9_combo[] = {KC_SPC, KC_9, COMBO_END};
const uint16_t PROGMEM f10_combo[] = {KC_SPC, KC_0, COMBO_END};
const uint16_t PROGMEM f11_combo[] = {KC_SPC, KC_SLASH, COMBO_END};
const uint16_t PROGMEM f12_combo[] = {KC_SPC, KC_PLUS, COMBO_END};

// sym + space
const uint16_t PROGMEM tab2_combo[] = {KC_SPC, KC_QUESTION, COMBO_END};
const uint16_t PROGMEM plus_combo[] = {KC_SPC, KC_AMPERSAND, COMBO_END};
const uint16_t PROGMEM eq_combo[] = {KC_SPC, KC_KP_ASTERISK, COMBO_END};
const uint16_t PROGMEM dollar_combo[] = {KC_SPC, KC_COLON, COMBO_END};
const uint16_t PROGMEM hash_combo[] = {KC_SPC, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM bslash_combo[] = {KC_SPC, KC_SLASH, COMBO_END};
const uint16_t PROGMEM percent_combo[] = {KC_SPC, KC_EXCLAIM, COMBO_END};
const uint16_t PROGMEM pipe_combo[] = {KC_SPC, KC_MINUS, COMBO_END};
const uint16_t PROGMEM tilde_combo[] = {KC_SPC, KC_AT, COMBO_END};
const uint16_t PROGMEM carrot_combo[] = {KC_SPC, KC_UNDERSCORE, COMBO_END};
const uint16_t PROGMEM btick_combo[] = {KC_SPC, KC_DOUBLE_QUOTE, COMBO_END};
const uint16_t PROGMEM rangle_combo[] = {KC_SPC, KC_LEFT_ANGLE_BRACKET, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {KC_SPC, KC_LEFT_PAREN, COMBO_END};
const uint16_t PROGMEM rbracket_combo[] = {KC_SPC, KC_LBRACKET, COMBO_END};
const uint16_t PROGMEM rcurly_combo[] = {KC_SPC, KC_LEFT_CURLY_BRACE, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
//base_layer + space combos
  COMBO(tab_combo, KC_TAB),
  COMBO(quote_combo, KC_QUOTE),
  COMBO(b_combo, KC_B),
  COMBO(m_combo, KC_M),
  COMBO(j_combo, KC_J),
  COMBO(q_combo, KC_Q),
  COMBO(z_combo, KC_Z),
  COMBO(l_combo, KC_L),
  COMBO(c_combo, KC_C),
  COMBO(v_combo, KC_V),
  COMBO(k_combo, KC_K),
  COMBO(g_combo, KC_G),
  COMBO(x_combo, KC_X),
  COMBO(comma_combo, KC_COMMA),
  COMBO(period_combo, KC_DOT),
  //num + space
  COMBO(f1_combo, KC_F1),
  COMBO(f2_combo, KC_F2),
  COMBO(f3_combo, KC_F3),
  COMBO(f4_combo, KC_F4),
  COMBO(f5_combo, KC_F5),
  COMBO(f6_combo, KC_F6),
  COMBO(f7_combo, KC_F7),
  COMBO(f8_combo, KC_F8),
  COMBO(f9_combo, KC_F9),
  COMBO(f10_combo, KC_F10),
  COMBO(f11_combo, KC_F10),
  COMBO(f12_combo, KC_F12),
  //sym + space
  COMBO(tab2_combo, KC_TAB),
  COMBO(plus_combo, KC_PLUS),
  COMBO(eq_combo, KC_EQUAL),
  COMBO(dollar_combo, KC_DOLLAR),
  COMBO(hash_combo, KC_HASH),
  COMBO(bslash_combo, KC_BSLASH),
  COMBO(percent_combo, KC_PERCENT),
  COMBO(pipe_combo, KC_PIPE),
  COMBO(tilde_combo, KC_TILDE),
  COMBO(carrot_combo, KC_CIRCUMFLEX),
  COMBO(btick_combo, KC_GRAVE),
  COMBO(rangle_combo, KC_RIGHT_ANGLE_BRACKET),
  COMBO(rparen_combo, KC_RIGHT_PAREN),
  COMBO(rbracket_combo, KC_RBRACKET),
  COMBO(rcurly_combo, KC_RIGHT_CURLY_BRACE)
};

//RGB Layers. Marry layout layers and rgb state
const rgblight_segment_t PROGMEM symbol_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 10, HSV_GREEN}       // Light 4 LEDs, starting with LE 1
);

const rgblight_segment_t PROGMEM number_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 10, HSV_ORANGE}       // Light 4 LEDs, starting with LED 1
);

const rgblight_segment_t PROGMEM num_func_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 31, HSV_BLUE}       // Light 4 LEDs, starting with LED 1
);

const rgblight_segment_t PROGMEM ctrl_rgb_light[] = RGBLIGHT_LAYER_SEGMENTS(
    {15, 1, HSV_RED},
    {16,1, HSV_BLUE},
    {17,1, HSV_YELLOW},
    {18,1, HSV_GREEN},
    {19,1, HSV_CYAN},
    {20,1, HSV_GOLD},
    {21,1, HSV_CORAL},
    {22,1, HSV_CHARTREUSE}
);

const rgblight_segment_t PROGMEM alt_rgb_light[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 10, HSV_PINK}       // Light 4 LEDs, starting with LED 1
);

//Define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    number_rgb_layer,
    symbol_rgb_layer,
    num_func_rgb_layer,
    ctrl_rgb_light,
    alt_rgb_light
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    //debug_mouse=true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _NUMBER_LAYER));
    rgblight_set_layer_state(1, layer_state_cmp(state, _SYMBOL_LAYER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUM_FUNC_LAYER));
    rgblight_set_layer_state(3, get_mods() & MOD_BIT(KC_LCTRL));
    rgblight_set_layer_state(4, get_mods() & MOD_BIT(KC_LALT));
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t num_func_timer;

  switch (keycode) {
    case NUM_FUNC:
      if(record->event.pressed) {
        num_func_timer = timer_read();
        // as soon as pressed, turn on num_func layer 
        layer_on(_NUM_FUNC_LAYER); 
      } else {
        // when released, unregister and check timer length
        layer_off(_NUM_FUNC_LAYER); 
        if (timer_elapsed(num_func_timer) < 200) {
          // if tapped, toggle number layer
          layer_invert(_NUMBER_LAYER); 
        }
      }
      return false; // We handled this keypress, don't proceed with normal functionaly
    case CTRL_KEY:  
      if(record->event.pressed) {
        // if button already pressed, unregister
        if (get_mods() & MOD_BIT(KC_LCTRL)) {
          unregister_code(KC_LCTRL);
        } else {
          // if not, register it and hold
          register_code(KC_LCTRL);
        }
      } 
      return false; 
    case ALT_KEY:  
      if(record->event.pressed) {
        if (get_mods() & MOD_BIT(KC_LALT)) {
          unregister_code(KC_LALT);
        } else {
          register_code(KC_LALT);
        }
      } 
      return false; 
  }
  return true; // Default case. We didn't handle other keypresses
}
