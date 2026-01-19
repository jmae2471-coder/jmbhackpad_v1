// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#pragma once

/* Direct pins: 4 individual buttons */
#define DIRECT_PINS { \
    { GP26, GP27 }, \
    { GP28, GP29 } \
}

#define DIODE_DIRECTION NONE

/* OLED (SSD1306 over I2C) */
#define OLED_DISPLAY_128X64
#define I2C_DRIVER I2CD0
#define I2C_SDA_PIN GP6
#define I2C_SCL_PIN GP7
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][2][2] = {
    [0] = LAYOUT_ortho_2x2(
        LCTL(KC_C),   LCTL(KC_V),
        LCTL(KC_Z),   LGUI(KC_S)
    )
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_clear();
    oled_write_ln("Hackpad", false);
    oled_write_ln("Layer 0", false);
    oled_write_ln("4-Key Pad", false);
    return false;
}
#endif

