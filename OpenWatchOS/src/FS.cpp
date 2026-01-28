#include "LittleFS.h"
#include "FS.hpp"
#define SD_CS 7

FileSystem fileSystem;
FileStructure fileStructure;

bool FSinit() {
  if (!SD.begin(SD_CS)) {
    return false;
  }
  if (!LittleFS.begin()) {
    return false;
  }
  if (SD.exists("test.txt")) {
    Serial.print("test works");
  }
  return true;
}

File FileSystem::open(const char* path, const char* mode, bool create) {
  String sPath = path;  // convert to String
  if (sPath.startsWith("/sd")) {
    sPath.replace("/sd", "");
    return SD.open(sPath.c_str(), mode, create);  // SD accepts const char*
  } else {
    return LittleFS.open(path, mode, create);
  }
}
bool FileSystem::exists(const char* path) {
  String sPath = path;  // convert to String
  if (sPath.startsWith("/sd")) {
    sPath.replace("/sd", "");
    return SD.exists(sPath.c_str());
  } else {
    return LittleFS.exists(path);
  }
}
bool FileSystem::mkdir(String path) {
  String sPath = path;  // convert to String
  if (sPath.startsWith("/sd")) {
    sPath.replace("/sd", "");
    return SD.mkdir(sPath);
  } else {
    return LittleFS.mkdir(path);
  }
}
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
