#pragma once

#include "SPI.h"
#include "Arduino.h"
#include "boards/boards.hpp"

class Display {
    private:
        int8_t _cs, _dc, _rst;
        SPIClass *hspi;

        void writeCommand(uint8_t cmd) {
            digitalWrite(_dc, LOW);
            digitalWrite(_cs, LOW);
            hspi->transfer(cmd);
            digitalWrite(_cs, HIGH);
        }

        void writeData(uint8_t data) {
            digitalWrite(_dc, HIGH);
            digitalWrite(_cs, LOW);
            hspi->transfer(data);
            digitalWrite(_cs, HIGH);
        }

    public:
        void init();
        void drawPixel(uint16_t x, uint16_t y, uint16_t color);
};