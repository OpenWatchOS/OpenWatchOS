#include "configs.hpp"
bool save() {
  File f = fileSystem.open(ConfigsLocation, "w", true);
  if (!f) return false;
  f.write((const uint8_t*)&packedConfigs, sizeof(packedConfigs));
  f.close();
  return true;
}
bool load(){
  File f = fileSystem.open(ConfigsLocation, "r", false);
  if (!f) return false;
  f.read((uint8_t*)&packedConfigs, sizeof(packedConfigs));
  f.close();
  return true;
}