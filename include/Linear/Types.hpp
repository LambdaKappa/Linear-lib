#pragma once

#include <iostream>
#include <type_traits>
#include <limits>
#include <algorithm>

/// @tparam N - Data type to check for 
/// @return Whether or not a data type has numeric representation
/// @example isNumeric<double>() -> true 
/// @example isNumeric<const char*>() -> false 
template <typename N>
constexpr bool isNumeric() {
    if (std::is_same_v<N, char>) return false;
    return std::is_integral_v<N> || std::is_floating_point_v<N>;
} 