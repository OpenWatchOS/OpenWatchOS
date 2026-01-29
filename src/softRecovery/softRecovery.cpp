#include "softRecovery.hpp"
#include "fileSystem/FS.hpp"
#include "display/display.hpp"
softRecovery SoftRecovery;
void softRecovery::init()
{
    display_init();
    display_log("recovery entered");
    update_screen();
    fileSystem.mkdir("recovery");
    fileSystem.open("recovery/passed", "w", true);
    ESP.restart();
}