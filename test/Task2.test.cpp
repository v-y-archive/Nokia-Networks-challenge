#include <map>

#include "catch.hpp"
#include "json.hpp"
#include "../src/Task2.cpp"

using namespace nlohmann;

/**
 * Unit tests.
 */

TEST_CASE("Task 2 test", "[countNumberOfWordsGroupingByLength]") {
    auto counterGroups = countNumberOfWordsGroupingByLength("four four 22");
    REQUIRE(((json)counterGroups).dump() == "[[2,1],[4,2]]");
}