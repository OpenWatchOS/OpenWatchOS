#include "display.hpp"

SSD1306 oled(SCREEN_ADDRESS);
int line = 0;
void display_init() {
  oled.init();
  oled.clear();
  oled.update();
}
void display_clear(){
  oled.clear();
}
void print_text(String text) {
  oled.println(text);
}
void print_centered_text(int x, int y, String text, int textSize) {
  int textLength = text.length();
  int textWidth = textLength * 6 * textSize;
  int cursorX = x - textWidth / 2;
  oled.setCursor(cursorX, y);
  oled.print(text);
}
void draw_bmp(int x, int y, const uint8_t *bitmap, int w, int h) {
  oled.putBitmap(x, y, bitmap, w, h);
}
void draw(int x, int y) {
  oled.putPixel(x, y);
}
void set_cursor(int x, int y) {
  oled.setCursor(x, y);
}
void update_screen() {
  oled.update();
}
void display_log(String text){
  set_cursor(0,line);
  print_text(text);
  line += 8;
  if(line == SCREEN_HEIGHT - 8){
    line = 0;
    display_clear();
  }
  update_screen();
}