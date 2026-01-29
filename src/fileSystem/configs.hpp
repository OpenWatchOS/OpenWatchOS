#pragma once

#include <string>
#include "FS.hpp"
#define ConfigsLocation "/configs.bin"
class configs {
public:
  struct internalConf {
    char appDir[64] = "/sd/apps";
    bool doFactoryReset = false;
    bool wasConfigured = false;
  } __attribute__((packed));
  struct userConf {
    bool DevMode = false;
  } __attribute__((packed));
  struct devModeConf {
    bool verbose = true;
  } __attribute__((packed));
  struct __attribute__((packed)) {
    internalConf internalConfig;
    userConf userConfig;
    devModeConf devModeConfig;
  } packedConfigs;
  bool save();
  bool load();
};
extern configs Configs;