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

#include "mathlib/vectors.h"

#include <cmath>


vec<float>& NVector::GetCoords() { return m_coords; }

float NVector::Length() {
    float sum = 0;
    for (float coord : m_coords) {
        sum += pow(coord, 2);
    }
    return sqrtf(sum);
}