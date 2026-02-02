#include "debug.hpp"
debug Debug;
debug::debug()
{
    Serial.begin(9600);
}
void debug::print(String in)
{
    Serial.println(in);
    if (verbose)
    {
        OLED.setCursor(0, line);
        OLED.println(in);
        line += 8;
        if (line == SCREEN_HEIGHT - 8)
        {
            line = 0;
            OLED.clear();
        }
        OLED.update();
    }
}