#include "displayWrapper.hpp"

int line = 0;

bool DisplayWrapper::init()
{
  OLED.init();
  OLED.clear();
  OLED.update();
  return false;
}

void DisplayWrapper::displayClear()
{
  OLED.clear();
}

void DisplayWrapper::log(String text)
{

}

void DisplayWrapper::print(String text)
{
  OLED.println(text);
}

void DisplayWrapper::setCursor(int x, int y)
{
  OLED.setCursor(x, y);
}

void DisplayWrapper::update()
{
  OLED.update();
}

void DisplayWrapper::drawPixel(int x, int y)
{
  OLED.putPixel(x, y);
}

void DisplayWrapper::drawBmp(int x, int y, const uint8_t *bitmap, int w, int h)
{
  OLED.putBitmap(x, y, bitmap, w, h);
}

void DisplayWrapper::printCenteredText(int x, int y, String text, int textSize)
{
  int textLength = text.length();
  int textWidth = textLength * 6 * textSize;
  int cursorX = x - textWidth / 2;
  OLED.setCursor(cursorX, y);
  OLED.print(text);
}

DisplayWrapper displayWrapper;
