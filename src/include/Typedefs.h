#pragma once
#include <memory>
#include <string>
#include <vector>

using str = std::string;

template <typename T>
using uptr = std::unique_ptr<T>;

template <typename T>
using sptr = std::shared_ptr<T>;

template <typename T>
using vec = std::vector<T>;