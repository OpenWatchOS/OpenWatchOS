#include "display/display.hpp"
#include "display/bitmaps.hpp"
#include "fileSystem/FS.hpp"
#include "fileSystem/configs.hpp"
#define VERBOSE 1
int displaytimeold = 0;
int apptimeold = 0;

void setup() {
  //screen init and splash screen
  Serial.begin(9600);
  display_init();
  draw_bmp(0, 0, splash, 128, 64);
  update_screen();
  SPI.begin();
  if (!FSinit()) {
    Serial.println("fs init fail");
    display_clear();
    draw_bmp(0, 0, drive_err, 128, 64);
    update_screen();
    return;
  }
  // LittleFS.format();
  if(!fileStructure.rebuild()){
    Serial.println("rebuild failed");
  }
  Configs.load();
  Serial.println("init complete");
}

void loop() {
  int time = millis();
  if (time - displaytimeold >= 100) {
    displaytimeold = time;
    update_screen();
  }
  if (time - apptimeold >= 1) {
    //when app support implemented
  }
}
