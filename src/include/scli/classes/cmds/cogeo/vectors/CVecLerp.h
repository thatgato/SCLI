/**
 * ==========================================================
 * @file        CVecLerp.h
 * @brief       Vector Lerping
 *
 * @author      thatgato
 * @date        2025-02-27
 * ==========================================================
 *
 * @details
 * Literally just lerps two vectors. Nothing special.
 *
 * ==========================================================
 */

#pragma once
#include "scli/classes/Command.h"

namespace Commands::CoGeo::Vectors {
class CVecLerp : public Command {
public:
  CVecLerp();
  ECommandResult Run(bool isFirst) override;
};
}; // namespace Commands::CoGeo::Vectors