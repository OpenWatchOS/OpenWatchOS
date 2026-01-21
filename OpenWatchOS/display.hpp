#pragma once

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

extern Adafruit_SSD1306 display;

void display_init();
void print_text(String text);
void set_text_size(int size);
void set_cursor(int x, int y);
void update_screen();
void draw(int x , int y);
void draw_bmp(int x, int y,const uint8_t *bitmap, int w, int h);
void print_centered_text(int x, int y, String text,int textSize = 1);