#pragma once

#include "CONFIG.hpp"
#include <TFT_eSPI.h>
#include "buttons/button.hpp"
#include "touch/touch_handler.hpp"
#include <vector>

class ezgraphics
{
private:
    TFT_eSPI tft;
    std::vector<Button> buttons;
    bool lastTouchState = false;

public:
    ezgraphics();
    void init();
    TouchPoint getTouchPoint();
    void update();

    void fill_screen(uint16_t color)
    {
        tft.fillScreen(color);
    }

    void create_button(int x, int y, int w, int h, uint16_t color, const char* label, int align, void (*callback)(void))
    {
        Button btn;
        btn.x = x;
        btn.y = y;
        btn.w = w;
        btn.h = h;
        btn.color = color;
        btn.label = label;
        btn.callback = callback;

        switch (align) {
        case ALIGN_TOP_LEFT:
            break;
        case ALIGN_TOP_MID:
            btn.x -= w / 2;
            break;
        case ALIGN_TOP_RIGHT:
            btn.x -= w;
            break;
        case ALGIN_MID_LEFT:
            btn.y -= h / 2;
            break;
        case ALIGN_MID_MID:
            btn.x -= w / 2;
            btn.y -= h / 2;
            break;
        case ALIGN_MID_RIGHT:
            btn.x -= w;
            btn.y -= h / 2;
            break;
        case ALIGN_BOT_LEFT:
            btn.y -= h;
            break;
        case ALIGN_BOT_MID:
            btn.x -= w / 2;
            btn.y -= h;
            break;
        case ALIGN_BOT_RIGHT:
            btn.x -= w;
            btn.y -= h;
            break;
        default:
            break;
        }

        btn.draw(tft);
        buttons.push_back(btn);
    }
};