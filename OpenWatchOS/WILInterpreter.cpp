#include "WILInterpreter.hpp"

Function parseLine(String line) {
    Function inst;
    inst.type = INST_UNKNOWN;

    line.trim();

    if (line == "clear") {
        inst.type = INST_DISPLAY_CLEAR;
        return inst;
    }

    if (line.startsWith("drawText")) {
        int firstSpace = line.indexOf(' ');
        int secondSpace = line.indexOf(' ', firstSpace + 1);
        int thirdSpace = line.indexOf(' ', secondSpace + 1);

        inst.type = INST_PRINT_TEXT;
        inst.args[0] = line.substring(firstSpace + 1, secondSpace).toInt();
        inst.args[1] = line.substring(secondSpace + 1, thirdSpace).toInt();
        inst.strArg = line.substring(thirdSpace + 1);

        return inst;
    }

    return inst;
}
void runEvent(Event& e, App& app) {
    for (auto& inst : e.instructions) {
        if (inst.type == INST_DISPLAY_CLEAR && app.caps.display) display_clear();
        else if (inst.type == INST_PRINT_TEXT && app.caps.display)
            print_centered_text(inst.args[0], inst.args[1], inst.strArg);
    }
}

