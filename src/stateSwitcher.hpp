#pragma once
#include "softRecovery/softRecovery.hpp"
#ifdef USE_SOFT_RECOVERY
    #define USE_SOFT_RECOVERY 1
#else
    #define USE_SOFT_RECOVERY 0
#endif

void handle_switch();
void initSS();
void enterRecovery();
void enterHardRecovery();
void enterSysRecovery();