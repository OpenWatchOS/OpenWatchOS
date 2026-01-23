#include <vector>
#include <Arduino.h>
#include "display.hpp"
enum FunctionType {
  INST_DISPLAY_CLEAR,
  INST_PRINT_TEXT,
  INST_DRAW_LINE,
  INST_UNKNOWN
};
struct Capabilities {
    bool display;
    bool buttons;
};
struct Function {
  FunctionType type;
  int args[6];
  String strArg;
};
struct Event {
    String name;
    std::vector<Function> instructions;
};

struct App {
  String Name;
  std::vector<Event> events;
  Capabilities caps;
};