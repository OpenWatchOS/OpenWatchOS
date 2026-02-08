#include "display/displayWrapper.hpp"
#include "display/bitmaps.hpp"
#include "shared/configs/configs.hpp"
#include "shared/debug/debug.hpp"
#include "shared/displayDriver/SSD1306/SSD1306.hpp"
#include "fileStructure/fileStructure.hpp"
#include "shared/buttons/buttons.hpp"
#define VERBOSE 1
int displaytimeold = 0;
int apptimeold = 0;
int handlerTest(void){

}
void setup()
{
    setCpuFrequencyMhz(160);
    displayWrapper.init();
    displayWrapper.setCursor(0, 0);
    displayWrapper.displayClear();
    displayWrapper.drawBmp(0, 0, splash, 128, 64);
    Debug.print("main entered");
    displayWrapper.update();
    if (!FSinit())
    {
        displayWrapper.displayClear();
        displayWrapper.drawBmp(0, 0, drive_err, 128, 64);
        Debug.print("fs init fail");
        displayWrapper.update();
        return;
    }
    LittleFS.format();
    if (!fileStructure.rebuild())
    {
        Debug.print("rebuild failed");
    }
    Configs.load();
    Debug.print("init complete");
    buttons.installBtnPressHandler(handlerTest);
}
void loop()
{
    int time = millis();
    if (time - displaytimeold >= 100)
    {
        displaytimeold = time;
        displayWrapper.update();

    }
    if (time - apptimeold >= 1)
    {
        // when app support implemented
    }
}