#include <vector>

#include "catch.hpp"
#include "LList.hpp"
#include "../src/Task3.cpp"

using Catch::Matchers::Equals;

/**
 * Test utils.
 */

LList* vectorToLList(std::vector<int> vector) {
    LList* result = nullptr;
    LList* prev = nullptr;
    for (int payload : vector) {
        LList* nodeptr = new LList { nullptr, payload };
        if (!result) result = nodeptr;
        if (prev) prev->next = nodeptr;
        prev = nodeptr;
    }
    return result;
}

auto llistToVector(LList* nodeptr) {
    std::vector<int> result;
    for (; nodeptr; nodeptr = nodeptr->next) {
        result.push_back(nodeptr->payload);
    }
    return result;
}

/**
 * Unit tests.
 */

TEST_CASE("Task 3 test", "[removeEveryFifth]") {
    LList* list = vectorToLList({ 2, 4, 8, 16, 32 });
    std::vector<int> expected = { 2, 4, 8, 16,    };

    removeEveryFifth(list);
    std::vector<int> result = llistToVector(list);

    REQUIRE_THAT(result, Catch::Matchers::Equals(expected));
}

TEST_CASE("Task 3 other test", "[removeEveryFifth]") {
    LList* list = vectorToLList({ 2, 4, 8, 16, 32, 64, 128 });
    std::vector<int> expected = { 2, 4, 8, 16,     64, 128 };

    removeEveryFifth(list);
    std::vector<int> result = llistToVector(list);

    REQUIRE_THAT(result, Catch::Matchers::Equals(expected));
}

TEST_CASE("Task 3 another test", "[removeEveryFifth]") {
    LList* list = vectorToLList({ 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192 });
    std::vector<int> expected = { 2, 4, 8, 16,     64, 128, 256, 512,       2048, 4096, 8192 };

    removeEveryFifth(list);
    std::vector<int> result = llistToVector(list);

    REQUIRE_THAT(result, Catch::Matchers::Equals(expected));
}