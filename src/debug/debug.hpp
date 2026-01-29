#pragma once
#include "Arduino.h"
#include <string.h>
#include "fileSystem/configs.hpp"
#include "display/display.hpp"
class debug{
    public:
        debug();
        bool displayVerbose = Configs.packedConfigs.devModeConfig.verbose;
        void print(String in);
};
extern debug Debug;