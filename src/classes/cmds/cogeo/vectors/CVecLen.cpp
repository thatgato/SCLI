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

#include "classes/cmds/cogeo/vectors/CVecLen.h"

#include "scli/Utils.h"
using namespace Commands::CoGeo::Vectors;
// Constructor
CVecLen::CVecLen()
    : Command("veclen", "Compute the length of a vector",
              "Takes in 2 or more arguments, all separated by spaces. Each "
              "argument must be a valid floating point number, that will "
              "represent one of the coordinates of the vector. This "
              "command calculates the length of the vector, using the "
              "provided coordinates and the pythagorean theorem.") {};

ECommandResult CVecLen::Run() {
    Utils::Log("AOJKSSSSSSSSSSSSSSSSSSSSS testingggggggggggg");
    return SUCCESS;
}