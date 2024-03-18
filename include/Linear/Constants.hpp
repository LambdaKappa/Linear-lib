#pragma once
/// @brief Constants definitions
namespace ln {
    // Constants used in the source code of the project.
    #define ARRAY_OPEN "["
    #define ARRAY_CLOSE "]"


    // Mathematical constants.
    const double pi =  3.14159265358;
    const double tau = 6.28318530718;
    const double e =   2.71828182845;

    #define PI pi
    #define E e
    #define TAU tau

    template <typename N>
    constexpr N EPSILON() {
        return std::numeric_limits<N>::epsilon();
    }
}
