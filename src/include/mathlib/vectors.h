/**
 * ==========================================================
 * @file        vectors.cpp
 * @brief       Vector calculation related library.
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * Everything that is related to doing calculations with vectors can be found
 * here, as well as the vector classes themselves.
 *
 * ==========================================================
 */

#pragma once

#include "types/general.h"
class NVector {
   private:
    vec<float> m_coords;

   public:
    NVector(vec<float>& coords) : m_coords(coords) {}

    vec<float>& GetCoords();

    // Math
    float Length();
};

namespace VMath {
float GetVecLen(const NVector& vec);
}