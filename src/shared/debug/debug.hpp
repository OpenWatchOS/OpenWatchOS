#pragma once
#include "Arduino.h"
#include <string.h>
#include "shared/configs/configs.hpp"
class debug{
    public:
        debug(bool verbose);
        bool displayVerbose;
        void print(String in);
};
extern debug Debug;