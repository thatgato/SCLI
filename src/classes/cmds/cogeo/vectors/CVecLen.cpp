#include "SCLIUtils.h"
#include "classes/Command.h"

namespace Commands::CoGeo::Vectors {

class CVecLen : public Command {
   public:
    CVecLen()
        : Command("veclen", "Compute the length of a vector",
                  "Takes in 2 or more arguments, all separated by spaces. Each "
                  "argument must be a valid floating point number, that will "
                  "represent one of the coordinates of the vector. This "
                  "command calculates the length of the vector, using the "
                  "provided coordinates and the pythagorean theorem.") {}

    ECommandResult Run() override {
        Utils::Log(
            "This log was called from the CVecLen.cpp command file. This is "
            "for testing.");
        return SUCCESS;
    }
};

};  // namespace Commands::CoGeo::Vectors