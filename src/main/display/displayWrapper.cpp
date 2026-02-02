#include "displayWrapper.hpp"

SSD1306 oled(SCREEN_ADDRESS);
int line = 0;

bool DisplayWrapper::init()
{
  oled.init();
  oled.clear();
  oled.update();
  return false;
}

void DisplayWrapper::displayClear()
{
  oled.clear();
}

void DisplayWrapper::log(String text)
{

}

void DisplayWrapper::print(String text)
{
  oled.println(text);
}

void DisplayWrapper::setCursor(int x, int y)
{
  oled.setCursor(x, y);
}

void DisplayWrapper::update()
{
  oled.update();
}

void DisplayWrapper::drawPixel(int x, int y)
{
  oled.putPixel(x, y);
}

void DisplayWrapper::drawBmp(int x, int y, const uint8_t *bitmap, int w, int h)
{
  oled.putBitmap(x, y, bitmap, w, h);
}

void DisplayWrapper::printCenteredText(int x, int y, String text, int textSize)
{
  int textLength = text.length();
  int textWidth = textLength * 6 * textSize;
  int cursorX = x - textWidth / 2;
  oled.setCursor(cursorX, y);
  oled.print(text);
}

DisplayWrapper displayWrapper;
