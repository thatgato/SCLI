#pragma once
#include "classes/Command.h"

namespace Commands::CoGeo::Vectors {
class CVecLen : public Command {
   public:
    CVecLen();
    ECommandResult Run() override;
};
};  // namespace Commands::CoGeo::Vectors