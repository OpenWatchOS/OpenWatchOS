#include "display.hpp"
#include "bitmaps.hpp"
#include "WILInterpreter.hpp"
#include <SPI.h>
#include <SD.h>

#define SD_CS 7

int displaytimeold = 0;
int apptimeold = 0;

void setup() {
  //screen init and splash screen
  display_init();
  draw_bmp(0, 0, splash, 128, 64);
  update_screen();
  SPI.begin();
  if (!SD.begin(SD_CS)) {
    display_clear();
    draw_bmp(0, 0, file_err, 128, 64);
    update_screen();
    return;
  }
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
