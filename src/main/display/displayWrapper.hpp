#pragma once

#include <Wire.h>
#include "shared/displayDriver/SSD1306/SSD1306.hpp"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

extern SSD1306 oled;
class DisplayWrapper
{
public:
    bool init();
    void displayClear();
    void log(String text);
    void print(String text);
    void setCursor(int x, int y);
    void update();
    void drawPixel(int x, int y);
    void drawBmp(int x, int y, const uint8_t *bitmap, int w, int h);
    void printCenteredText(int x, int y, String text, int textSize = 1);
};
extern DisplayWrapper displayWrapper;