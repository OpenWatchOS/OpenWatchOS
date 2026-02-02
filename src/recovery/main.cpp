#include <Arduino.h>
#include <esp_ota_ops.h>
#include <esp_partition.h>
#include "shared/buttons/buttons.hpp"
#include <SD.h>
#include <FS.h>
#include <LittleFS.h>
#include "shared/displayDriver/SSD1306/SSD1306.hpp"

#define SD_CS 7
void switchToMain()
{
  const esp_partition_t *part = esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_APP_OTA_1, NULL);
  if (part == NULL)
  {
    return;
  }
  esp_err_t err = esp_ota_set_boot_partition(part);
  if (err == ESP_OK)
  {
    ESP.restart();
  }
}
void setup()
{
  setCpuFrequencyMhz(160);
  OLED.init();
  OLED.clear();
  OLED.update();
  OLED.println("recovery env entered");
  OLED.update();
  switchToMain();
}

void loop()
{
  // recovery logic
}
