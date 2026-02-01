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
    void print(String s);
    void println(String s);
    void setCursor(int x, int y);
    void putBitmap(int x, int y, const uint8_t *bitmap, int w, int h, bool invert = false);
    void clear();
    void update();
    void init();
    SSD1306(uint8_t i2cAddress);

private:
    int x = 0;
    int y = 0;
    uint8_t addr;
    static constexpr int WIDTH = 128;
    static constexpr int HEIGHT = 64;
    static constexpr int PAGES = HEIGHT / 8;          // 8
    static constexpr int BUFFER_SIZE = WIDTH * PAGES; // 1024

    uint8_t frameBuffer[BUFFER_SIZE]{}; // the 1 KB buffer
};