#include "stateSwitcher.hpp"
#include "debug/debug.hpp"
#include "fileSystem/FS.hpp"
#include "sysMain/sysMain.hpp"
#include "softRecovery/softRecovery.hpp"
#ifdef USE_SOFT_RECOVERY
bool checkRecoveryExit(){
    if(fileSystem.exists("recovery/passed")){
        fileSystem.remove("recovery/passed");
        return true;
    }
    else{
        return false;
    }
}
#endif

void initSS()
{
    FSinit();
    if(checkRecoveryExit()){
        SysInit();
    }
    else{
        enterRecovery();
    }


}
void enterRecovery(){
    #ifdef USE_SOFT_RECOVERY
    enterSysRecovery();
    #else
    enterHardRecovery();
    #endif
}
void enterSysRecovery(){
    SoftRecovery.init();
}