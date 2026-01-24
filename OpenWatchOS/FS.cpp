#include "FS.hpp"
#define SD_CS 7
bool FSinit(){
  if(!SD.begin(SD_CS)){
    return false;
  }
  if(!LittleFS.begin(true)){
    return false;
  }
  return true;
}
String 