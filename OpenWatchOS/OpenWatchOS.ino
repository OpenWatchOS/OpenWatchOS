#include "display.hpp"
#include "bitmaps.hpp"

int displaytimeold = 0;
int apptimeold = 0;

void setup() {
  //screen init and splash screen
  display_init();
  draw_bmp(0, 0, splash, 128, 64);
  update_screen();
}

void loop() {
  int time = millis();
  if (time - displaytimeold >= 100) {
    displaytimeold = time;
    update_screen();
  }
  if(time - apptimeold >= 1){
    //when app support implemented
  }
}
