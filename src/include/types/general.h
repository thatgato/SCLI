/**
 * ==========================================================
 * @file        general.h
 * @brief       Type definitions file for general, multi-purpose things
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * Type definitions for memory, string and vectors.
 *
 * ==========================================================
 */

#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <vector>


using str = std::string;

template <typename T>
using uptr = std::unique_ptr<T>;

template <typename T>
using sptr = std::shared_ptr<T>;

template <typename T>
using wptr = std::weak_ptr<T>;

template <typename T>
using vec = std::vector<T>;

using u8 = uint8_t;