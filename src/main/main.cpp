#include "display/display.hpp"
#include "display/bitmaps.hpp"
#include "fileSystem/configs.hpp"
#include "debug/debug.hpp"
#define VERBOSE 1
int displaytimeold = 0;
int apptimeold = 0;
void setup()
{
    display_init();
    Debug.print("main entered");
    draw_bmp(0, 0, splash, 128, 64);
    update_screen();
    SPI.begin();
    if (!FSinit())
    {
        Debug.print("fs init fail");
        display_clear();
        draw_bmp(0, 0, drive_err, 128, 64);
        update_screen();
        return;
    }
    // LittleFS.format();
    if (!fileStructure.rebuild())
    {
        Debug.print("rebuild failed");
    }
    Configs.load();
    Debug.print("init complete");
}
void loop()
{
    int time = millis();
    if (time - displaytimeold >= 100)
    {
        displaytimeold = time;
        update_screen();
    }
    if (time - apptimeold >= 1)
    {
        // when app support implemented
    }
}