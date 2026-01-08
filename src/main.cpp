#include <Arduino.h>
#include "spi_graphics.hpp"
#include "utils/colors.hpp"

Display screen;

void setup() {
    Serial.begin(115200);
    screen.init(); // Initalize the screen
    
    for (int i = 0; i < 100; i++) {
        screen.drawPixel(i, 20, SPI_RED);
    }
}

void loop() {
    // Nothing here yet.
}