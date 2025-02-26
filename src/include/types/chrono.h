/**
 * ==========================================================
 * @file        chrono.h
 * @brief       Simple type definition header.
 *
 * @author      thatgato
 * @date        2025-02-07
 * ==========================================================
 *
 * @details
 * Contains type definitions related to std::chrono
 *
 * ==========================================================
 */

#pragma once
#include <chrono>

template <typename T>
using time_point_t = std::chrono::time_point<T>;

template <typename T, typename J>
using duration_t = std::chrono::duration<T, J>;

using high_res_clock = std::chrono::high_resolution_clock;