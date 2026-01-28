#pragma once
#include <SPI.h>
#include <SD.h>
#include <FS.h>
#include <LittleFS.h>
#include "HardwareSerial.h"
#include <LittleFS.h>
#include "SD.h"
#include "configs.hpp"

bool FSinit();
class FileSystem {
public:
  File open(const char* path, const char* mode = "r", bool create = false);
  bool exists(const char* path);
  bool mkdir(String path);
  bool mkdirp(String path);
private:
  File f;
};
extern FileSystem fileSystem;
class FileStructure{
  public:
  bool exists();
  bool rebuild();
};


extern FileStructure fileStructure;
