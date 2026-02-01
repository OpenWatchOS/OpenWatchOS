#pragma once
#include <Wire.h>
#include "glcdfont.hpp"
class SSD1306
{
public:
    void command(uint8_t cmd);
    void putPixel(int x, int y, bool on = true);
    void data(uint8_t dat);
    void printChar(int x, int y, char c);
    void clear();
    void update();
    SSD1306(uint8_t i2cAddress);

private:
    uint8_t addr;
    static constexpr int WIDTH = 128;
    static constexpr int HEIGHT = 64;
    static constexpr int PAGES = HEIGHT / 8;          // 8
    static constexpr int BUFFER_SIZE = WIDTH * PAGES; // 1024

    uint8_t frameBuffer[BUFFER_SIZE]{}; // the 1 KB buffer
};