#pragma once
#include <cstdint>

struct TouchPoint {
    uint16_t x;
    uint16_t y;
    uint16_t pressure;
    bool pressed;
};