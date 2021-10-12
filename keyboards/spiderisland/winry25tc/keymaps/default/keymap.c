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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = LAYOUT(
        RESET, DEBUG, RGB_TOG, RGB_HUI, RGB_HUD,
        KC_F, KC_A, KC_R, KC_W, KC_P,
        KC_O,   KC_E,   KC_H,   KC_T, KC_D,
        KC_U,   KC_I,   KC_N,   KC_S, KC_Y,
        KC_SPC, TG(_NUMBER_LAYER), TG(_SYMBOL_LAYER) , KC_ENT, OSM(MOD_LSFT)
    ),
    [_NUMBER_LAYER] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_KP_ASTERISK,   KC_7,   KC_8,   KC_9, KC_TRNS,
        KC_KP_SLASH,   KC_4,   KC_5,  KC_6,   KC_KP_PLUS,
        KC_0,  KC_1,  KC_2, KC_3, KC_KP_DOT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS 
    ),
    [_SYMBOL_LAYER] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_QUESTION, KC_AMPERSAND, KC_KP_ASTERISK, KC_COLON, KC_SCOLON,
        KC_SLASH, KC_EXCLAIM, KC_MINUS, KC_AT, KC_UNDERSCORE,
        KC_DOUBLE_QUOTE, KC_LEFT_ANGLE_BRACKET, KC_LEFT_PAREN, KC_LBRACKET, KC_LEFT_CURLY_BRACE,
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

//num + key combos
const uint16_t PROGMEM backspace_combo[] = {TG(_NUMBER_LAYER), KC_I, COMBO_END};
const uint16_t PROGMEM left_combo[] = {TG(_NUMBER_LAYER), KC_N, COMBO_END};
const uint16_t PROGMEM down_combo[] = {TG(_NUMBER_LAYER), KC_S, COMBO_END};
const uint16_t PROGMEM right_combo[] = {TG(_NUMBER_LAYER), KC_Y, COMBO_END};
const uint16_t PROGMEM up_combo[] = {TG(_NUMBER_LAYER), KC_T, COMBO_END};

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
  //num + key combos
  COMBO(backspace_combo, KC_BSPC),
  COMBO(left_combo, KC_LEFT),
  COMBO(down_combo, KC_DOWN),
  COMBO(right_combo, KC_RGHT),
  COMBO(up_combo, KC_UP)
};

//RGB Layers. Marry layout layers and rgb state
const rgblight_segment_t PROGMEM symbol_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 10, HSV_GREEN}       // Light 4 LEDs, starting with LE 1
);

const rgblight_segment_t PROGMEM number_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 10, HSV_ORANGE}       // Light 4 LEDs, starting with LED 1
);

//Define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    number_rgb_layer,
    symbol_rgb_layer
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
    return state;
}
