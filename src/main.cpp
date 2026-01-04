#include <Arduino.h>
#include <ezgraphics.hpp>

void setup() {
    Serial.begin(115200);
    ezgraphics graphics;
    graphics.init();
    Serial.println("Setup loop completed.");
}

void loop() {
    // nothing to put here at the moment.
}