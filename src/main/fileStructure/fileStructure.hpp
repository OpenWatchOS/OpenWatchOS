#include "shared/fileSystem/FS.hpp"
#include "shared/configs/configs.hpp"

class FileStructure{
  public:
  bool exists();
  bool rebuild();
};
extern FileStructure fileStructure;