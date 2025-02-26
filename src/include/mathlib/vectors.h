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

template <typename T>

class NVector {
   private:
    vec<T> m_coords;

   public:
    NVector(vec<T>& coords) : m_coords(coords) {}

    vec<T>& GetCoords() { return m_coords; }

    // Math
    T Length() {
        T sum = 0;
        for (T coord : m_coords) {
            sum += pow(coord, 2);
        }
        return sqrtf(sum);
    };
};
