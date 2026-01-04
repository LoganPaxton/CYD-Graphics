#pragma once

// COMMON DISPLAY CONFIGURATIONS 
#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 240
#define TFT_BACKLIGHT_ON 1
#define TFT_INVERSION_ON 1
#define CLEAR_COLOR 0xffff // White

// DISPLAY PIN CONFIGURATION
#ifndef TFT_MISO
#define TFT_MISO 12
#endif
#ifndef TFT_MOSI
#define TFT_MOSI 13
#endif
#ifndef TFT_SCLK
#define TFT_SCLK 14
#endif
#ifndef TFT_CS
#define TFT_CS 15
#endif
#ifndef TFT_DC
#define TFT_DC 2
#endif
#ifndef TFT_RST
#define TFT_RST 12
#endif
#ifndef TFT_BL
#define TFT_BL 21
#endif

// TOUCH PIN CONFIGURATION
#ifndef TOUCH_CS
#define TOUCH_CS 25
#endif

/*
ROTATIONS:
0 - Portrait (0 degrees)
1 - Landscape (90 degrees)
2 - Upside down portrait (180 degrees)
3 - Upside down landscape (270 degrees)
*/
#define DISPLAY_ROTATION 0

// DISPLAY DRIVERS
#define ILI9341
//#define ILI9488
//#define ILI9486
//#define ILI9481
//#define ILI9163
//#define ILI9342
