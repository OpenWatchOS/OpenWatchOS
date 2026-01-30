#include <Arduino.h>
#include <esp_ota_ops.h>
#include <esp_partition.h>

void setup()
{
  esp_ota_set_boot_partition(esp_partition_find_first(ESP_PARTITION_TYPE_APP, ESP_PARTITION_SUBTYPE_ANY, "app"));
  esp_restart();
}

void loop()
{
  // recovery logic
}
