#include "CONFIG.hpp"
#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include "ezgraphics.hpp"
#include "touch/touch_handler.hpp"

ezgraphics::ezgraphics() : tft(TFT_eSPI())
{
}

void ezgraphics::init()
{
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

TouchPoint ezgraphics::getTouchPoint() {
    TouchPoint pt = {0, 0, 0, false};

    pt.pressed = tft.getTouch(&pt.x, &pt.y);

    if (pt.pressed) {
        pt.pressure = tft.getTouchRawZ();
    }

    return pt;
}

void ezgraphics::update() {
    for (Button& btn : buttons) {
        btn.draw(tft);
    }

    TouchPoint touch = getTouchPoint();

    if (touch.pressed && !lastTouchState) {
        for (Button& btn : buttons) {
            if (btn.isPressed(touch.x, touch.y)) {
                if (btn.callback) {
                    btn.callback();
                }
                break;
            }
        }
    }

    lastTouchState = touch.pressed;
}