#include "stateSwitcher.hpp"
#include "debug/debug.hpp"
#include "fileSystem/FS.hpp"
#include "sysMain/sysMain.hpp"
#include "softRecovery/softRecovery.hpp"
#ifdef USE_SOFT_RECOVERY
bool checkRecoveryExit(){
    const char *path = "/recovery/passed";
    if(fileSystem.exists(path)){
        fileSystem.remove(path);
        return true;
    }
    else{
        return false;
    }
}
#endif

void initSS()
{
    if(!FSinit()){
        while(true);//make diffrent later
    }
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