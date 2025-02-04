#pragma once
#include <chrono>
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

template <typename T>
using time_point_t = std::chrono::time_point<T>;

template <typename T, typename J>
using duration_t = std::chrono::duration<T, J>;

using high_res_clock = std::chrono::high_resolution_clock;
