#include "LittleFS.h"
#include "FS.hpp"
#define SD_CS 7

FileSystem fileSystem;

bool FSinit() {
  if (Configs.packedConfigs.devModeConfig.useSD){
    if (!SD.begin(SD_CS)) {
      return false;
      Serial.println("sd failure");
      
    }
  }
  else{
    Debug.print("using no sd mode");
  }
  if (!LittleFS.begin(true)) {
    return false;
    Serial.println("littleFS failure");
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
bool FileSystem::remove(String path){
  String sPath = path;
  if (sPath.startsWith("/sd")) {
    sPath.replace("/sd", "");
    return SD.remove(sPath);
  } else {
    return LittleFS.remove(path);
  }
  
}
