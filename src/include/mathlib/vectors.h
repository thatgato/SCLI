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
#include <stdexcept>
#include <string>

template <typename T>

class NVector {
private:
  vec<T> m_coords;

public:
  NVector(vec<T> &coords) : m_coords(coords) {}

  vec<T> &GetCoords() { return m_coords; }

  // Math
  T Length() {
    T sum = 0;
    for (T coord : m_coords) {
      sum += pow(coord, 2);
    }
    return sqrtf(sum);
  };

  int ComponentLength() { return m_coords; }
  NVector<T> Lerp(NVector<T> &other, float alpha) {
    return (1 - alpha) * (*this) + alpha * other;
  }

  // Ok so GPT came in clutch with these, i dont fully understand the friend
  // keyword, research later pls

  friend NVector operator*(float scalar, const NVector &vec) {
    std::vector<T> multiplied;
    for (const auto &val : vec.m_coords) {
      multiplied.push_back(scalar * val);
    }
    return NVector<T>(multiplied);
  }
  NVector operator*(const NVector<T> &other) const {
    std::vector<T> multiplied;
    const std::vector<T> &otherCoords = other.GetCoords();
    for (size_t i = 0; i < m_coords.size(); i++) {
      multiplied.push_back(m_coords[i] * otherCoords[i]);
    }
    return NVector<T>(multiplied);
  }
  friend NVector operator*(const NVector &vec, float scalar) {
    return scalar * vec; // Reuse previous function
  }
  friend NVector operator+(const NVector &v1, const NVector &v2) {
    if (v1.m_coords.size() != v2.m_coords.size()) {
      throw std::runtime_error("Vector sizes must match for addition");
    }
    std::vector<T> sum;
    for (size_t i = 0; i < v1.m_coords.size(); i++) {
      sum.push_back(v1.m_coords[i] + v2.m_coords[i]);
    }
    return NVector<T>(sum);
  }

  str toString() const {
    str components = "";
    for (T item : m_coords) {
      components += std::to_string(item) + " ";
    }
    return components;
  }
};
