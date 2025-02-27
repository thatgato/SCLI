/**
 * ==========================================================
 * @file        CVecLen.cpp
 * @brief       CoordinateGeometry/CVecLen --> Command to calculate the length
 * of an n-dimensional vector
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * This is a command under coordinate geometry, that calculates the length of an
 * n-dimensional vector.
 *
 * ==========================================================
 */

#include "scli/classes/cmds/cogeo/vectors/CVecLen.h"

#include "mathlib/vectors.h"
#include "scli/Core.h"
#include "scli/Utils.h"
#include "scli/classes/Command.h"
#include "types/general.h"

using namespace Commands::CoGeo::Vectors;

static Utils::Logger Logger("cmds/cogeo/vectors/CVecLen");

// Constructor
CVecLen::CVecLen()
    : Command("veclen", "Compute the length of a vector",
              "Takes in 2 or more arguments, all separated by spaces. Each "
              "argument must be a valid floating point number, that will "
              "represent one of the coordinates of the vector. This "
              "command calculates the length of the vector, using the "
              "provided coordinates and the pythagorean theorem.") {};

/* -------------------------------- Internal -------------------------------- */

vec<double> getCoords(vec<str> &splitStr) {
  vec<double> coords;

  for (auto &element : splitStr) {
    std::pair<bool, double> res = Utils::TryConvertStrToDouble(element);
    if (!res.first) {
      Logger.Log("Failed to convert one of the coordinates into a double!",
                 LogLevel::WARN);
      Logger.In();
      coords.clear();
      return coords;
    }
    coords.push_back(res.second);
  }
  return coords;
}

/* -------------------------------- external -------------------------------- */

ECommandResult CVecLen::Run(bool isFirst) {
  if (isFirst) {
    system("cls"); // purge!

    Utils::DisplayCmdDataOnRun(*this);
  }

  Logger.Out("Gib me vector!");

  str inp = Logger.In();

  // Internals
  EPostCmdAction res = Core::GET_INTERNAL_CMD_RESULT(inp);
  if (res == EXIT_CMD_CTX) {
    return SUCCESS;
  }

  // TODO: prob move this to utils
  vec<str> splitStr = Utils::SplitStrByDelimiter(inp, ' ');

  vec<double> coords = getCoords(splitStr);
  if (coords.empty())
    this->Run(false);

  NVector VecClass(coords);

  vec<float> a{11, 2, 3};
  vec<float> b{2, 5, 4};
  NVector A(a);
  NVector B(b);
  Logger.Out("Btw the lerp of the two vectors is " + A.Lerp(B, 0.5).toString());

  Logger.Out(std::format(
      "The vector's length is: {}{}{}\n\n", SStyle::green + SStyle::italic,
      Utils::RemoveTrailingZeroesFromNum(VecClass.Length()), SStyle::reset));
  this->Run(false);
  return SUCCESS;
}