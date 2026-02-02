#pragma once
#include "Arduino.h"
#include <string.h>
#include "shared/configs/configs.hpp"
#include "shared/displayDriver/SSD1306/SSD1306.hpp"
class debug{
    public:
        debug();
        bool displayVerbose;
        void print(String in);
    private:
    bool verbose = true;
    int line = 0;
};
extern debug Debug;