#include "display/display.hpp"
#include "display/bitmaps.hpp"
#include "shared/configs/configs.hpp"
#include "shared/debug/debug.hpp"
#include "shared/displayDriver/SSD1306/SSD1306.hpp"
#include "fileStructure/fileStructure.hpp"
#define VERBOSE 1
int displaytimeold = 0;
int apptimeold = 0;
void setup()
{
    setCpuFrequencyMhz(160);
    set_cursor(0,0);
    display_init();
    Debug.print("main entered");
    draw_bmp(0, 0, splash, 128, 64);
    update_screen();
    if (!FSinit())
    {
        display_clear();
        // draw_bmp(0, 0, drive_err, 128, 64);
        Debug.print("fs init fail");
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