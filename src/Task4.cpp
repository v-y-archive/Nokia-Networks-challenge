/**
 * Write a function that takes a 32-bit unsigned integer number and returns the
 * maximum and minimum 32-bit unsigned integer numbers which can be obtained
 * using the same number of bits set to 1 as in the taken number.
 */

#include <inttypes.h>
#include <tuple>

std::tuple <uint32_t, uint32_t> squeezeOutEverythingOfThisBits(uint32_t n) {
    uint32_t popcount = static_cast<uint32_t>(__builtin_popcount(n));

    uint32_t min = ~(~0u << popcount);
    uint32_t max = min << (32 - popcount);
    return { max, min };
}