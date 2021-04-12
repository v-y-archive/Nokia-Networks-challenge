#include "../libs/catch.hpp"
#include "../libs/json.hpp"
#include "Task2.cpp"
#include <map>
using namespace nlohmann;

/**
 * Unit tests.
 */

TEST_CASE("Task 2 test", "[countNumberOfWordsGroupingByLength]") {
    auto counterGroups = countNumberOfWordsGroupingByLength("four four 22");
    REQUIRE(((json)counterGroups).dump() == "[[2,1],[4,2]]");
}