 #pragma once

#include <TFT_eSPI.h>
#include <SPI.h>
#include "alignments.hpp"


struct Button {
    int x, y, w, h;
    const char* label;
    uint16_t color;
    void (*callback)();

    bool isPressed(int tx, int ty)
    {
        return (tx >= x && tx <= (x + w) && ty >= y && ty <= (y + h));
    }

    void draw(TFT_eSPI &tft) {
        tft.fillRect(x, y, w, h, color);
        tft.setTextColor(TFT_WHITE);
        tft.setTextDatum(MC_DATUM);
        tft.drawString(label, x + (w / 2), y + (h / 2));
    }
};