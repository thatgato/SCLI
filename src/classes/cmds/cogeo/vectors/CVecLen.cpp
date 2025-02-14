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

#include <string>

#include "mathlib/vectors.h"
#include "scli/Utils.h"
#include "scli/classes/Command.h"


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

ECommandResult CVecLen::Run() {
    system("cls");  // purge

    Logger.Out("Gib me vector!");

    str inp = Logger.In();

    // TODO: prob move this to utils
    std::stringstream stream(inp);

    std::vector<float> coords;
    std::string cur_str;

    while (std::getline(stream, cur_str, ' ')) {
        if (!cur_str.empty()) {
            std::pair<bool, int> res = Utils::TryConvertStrToInt(inp);
            if (!res.first) {
                Logger.Log(
                    "Failed to convert one of the coordinates into a float!",
                    LogLevel::WARN);
                Logger.In();
                return FAIL;
            }
            coords.push_back(res.second);
        }
    }

    NVector VecClass(coords);
    Logger.Out("Length is " + std::to_string(VecClass.Length()));
    Logger.In();
    return SUCCESS;
}