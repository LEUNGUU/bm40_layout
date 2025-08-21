#pragma once

#define TAPPING_FORCE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 265

#define RGB_DI_PIN E2
#define DRIVER_LED_TOTAL 53
#ifdef RGB_DI_PIN
#    define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#    define RGBLIGHT_LIMIT_VAL 180 // Limit to vendor-recommended value
#endif
#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180 // Limit to vendor-recommended value
#endif