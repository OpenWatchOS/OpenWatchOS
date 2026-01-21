#include <vector>
enum FunctionType {
  INST_DISPLAY_CLEAR,
  INST_PRINT_TEXT,
  INST_DRAW_LINE,
  INST_UNKNOWN
};
struct Function {
  FunctionType type;
  int args[6];
};
struct Event {
  String name;
  std::vector<Function> functions;
};
struct App {
  String Name;
};