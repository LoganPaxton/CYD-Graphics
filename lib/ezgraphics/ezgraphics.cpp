#include "CONFIG.hpp"
#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include "ezgraphics.hpp"

ezgraphics::ezgraphics() {
}

void ezgraphics::init() {
    tft.init();
    tft.setRotation(DISPLAY_ROTATION);
    tft.fillScreen(CLEAR_COLOR);
    #if TFT_BACKLIGHT_ON
        pinMode(TFT_BL, OUTPUT);
        digitalWrite(TFT_BL, HIGH);
    #endif
    #if TFT_INVERSION_ON
        tft.invertDisplay(true);
    #endif
}