
#include "scli/classes/cmds/cogeo/vectors/CVecLerp.h"

// #include "mathlib/vectors.h"
// #include "scli/Core.h"
#include "scli/Utils.h"
#include "scli/classes/Command.h"
#include "types/general.h"

using namespace Commands::CoGeo::Vectors;

static Utils::Logger Logger("cmds/cogeo/vectors/CVecLen");

// Constructor
CVecLerp::CVecLerp()
    : Command(
          "veclerp", "Lerp between two vectors.",
          "Get a point between two vectors depending on an alpha value. 0.5 "
          "alpha means you get a point in the middle of the two vectors.") {};

ECommandResult CVecLerp::Run(bool isFirst) {
  Logger.Out("I do nothing currently. Get out.");
  Logger.In();
  return SUCCESS;
}