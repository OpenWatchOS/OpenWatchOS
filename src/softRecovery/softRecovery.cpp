#include "softRecovery.hpp"
#include "fileSystem/FS.hpp"
#include "display/display.hpp"
softRecovery SoftRecovery;
void softRecovery::init()
{
    display_init();
    display_log("recovery entered");
    update_screen();
    const char *path = "/recovery/passed";
    File f = fileSystem.open(path, "w", true);
    if (!f)
    {
        display_log("Failed to create empty file");
        return;
    }
    f.close();
    ESP.restart();
}