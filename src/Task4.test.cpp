#include "../libs/catch.hpp"
#include "../libs/json.hpp"
#include "Task4.cpp"
#include <vector>
using namespace nlohmann;

/**
 * Unit tests.
 */

TEST_CASE("Task 4 test", "[squeezeOutEverythingOfThisBits]") {
    auto result = squeezeOutEverythingOfThisBits(0b10101);
    REQUIRE(((json)result).dump() == "[3758096384,7]");
}