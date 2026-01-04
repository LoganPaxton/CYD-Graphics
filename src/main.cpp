#include <Arduino.h>
#include <ezgraphics.hpp>

ezgraphics graphics;

void setup()
{
    Serial.begin(115200);
    graphics.init();
    Serial.println("Setup loop completed.");
    
    graphics.create_button(120, 160, 120, 60, TFT_BLUE, "Click Me", ALIGN_MID_MID, []() { Serial.println("Button Pressed!"); });
}

void loop()
{
    graphics.update();
}