#pragma once
#include "classes/Command.h"

namespace Commands::CoGeo::Vectors {
class CVecLen : public Command {
   public:
    CVecLen();
    ECommandResult Run();
};
};  // namespace Commands::CoGeo::Vectors