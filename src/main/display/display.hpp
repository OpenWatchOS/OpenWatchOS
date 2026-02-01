#pragma once

#include <Wire.h>
#include "shared/displayDriver/SSD1306/SSD1306.hpp"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

extern SSD1306 oled;
void display_init();
void print_text(String text);
void set_cursor(int x, int y);
void update_screen();
void draw(int x , int y);
void draw_bmp(int x, int y,const uint8_t *bitmap, int w, int h);
void print_centered_text(int x, int y, String text,int textSize = 1);
void display_clear();
void display_log(String text);