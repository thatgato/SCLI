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

#pragma once
#include "scli/classes/Command.h"

namespace Commands::CoGeo::Vectors {
class CVecLen : public Command {
   public:
    CVecLen();
    ECommandResult Run(bool isFirst) override;
};
};  // namespace Commands::CoGeo::Vectors