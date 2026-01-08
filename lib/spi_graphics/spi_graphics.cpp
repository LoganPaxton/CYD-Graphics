#include "spi_graphics.hpp"
#include "boards/boards.hpp"

void Display::init() {
    this->_cs = SPI_CS;
    this->_dc = SPI_DC;
    this->_rst = SPI_RST;

    // Enable backlight
    pinMode(SPI_BL, OUTPUT);
    digitalWrite(SPI_BL, HIGH);

    #ifndef SPI_SPEED
        #define SPI_SPEED 20000000 // Default to this
    #endif

    pinMode(_cs, OUTPUT);
    pinMode(_dc, OUTPUT);

    if (_rst >= 0) {
        pinMode(_rst, OUTPUT);
        digitalWrite(_rst, LOW); 
        delay(100); 
        digitalWrite(_rst, HIGH); 
        delay(100);
    }

    hspi->begin(SPI_SCLK, SPI_MISO, SPI_MOSI, _cs);

    writeCommand(0x01); // Software RST
    delay(150);
    writeCommand(0x11); // Wakeup
    delay(500);
    writeCommand(0x29); // Turn display on
}

void Display::drawPixel(uint16_t x, uint16_t y, uint16_t color) {
    // Set column (X)
    writeCommand(0x2A);
    writeData(x >> 8); writeData(x & 0xFF);
    writeData(x >> 8); writeData(x & 0xFF);
    
    // Set row (Y)
    writeCommand(0x2B);
    writeData(y >> 8); writeData(y & 0xFF);
    writeData(y >> 8); writeData(y & 0xFF);
    
    // Write color
    writeCommand(0x2C);
    writeData(color >> 8);
    writeData(color & 0xFF);
}