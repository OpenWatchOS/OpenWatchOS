#include "display.hpp"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void display_init() {
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  set_text_size(1);
  display.display();
}

void print_text(String text) {
  display.println(text);
}
void print_centered_text(int x, int y, String text, int textSize) {
  int textLength = text.length();
  int textWidth = textLength * 6 * textSize;
  int cursorX = x - textWidth / 2;
  display.setCursor(cursorX, y);
  display.print(text);
}
void draw_bmp(int x, int y, const uint8_t *bitmap, int w, int h) {
  display.drawBitmap(x, y, bitmap, w, h, SSD1306_WHITE);
}
void draw(int x, int y) {
  display.drawPixel(x, y, SSD1306_WHITE);
}
void set_text_size(int size) {
  display.setTextSize(size);
}
void set_cursor(int x, int y) {
  display.setCursor(x, y);
}
void update_screen() {
  display.display();
}