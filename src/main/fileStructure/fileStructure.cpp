#include "fileStructure.hpp"
FileStructure fileStructure;
bool FileStructure::exists() {
  return fileSystem.exists(ConfigsLocation);
}
bool FileStructure::rebuild() {
  if (fileStructure.exists()) {
    if (!Configs.save()) {
      return false;
    }
    Serial.println("conf created");
  }
  else{
    Serial.println("conf already exists");
  }
  return true;
}