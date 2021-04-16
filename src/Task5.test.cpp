#include "../libs/catch.hpp"
#include "Task5.cpp"
#include "TreeNode.hpp"
#include <vector>
using Catch::Matchers::Equals;

/**
 * Unit tests.
 */

TEST_CASE("Task 5 test", "[getXLongPaths]") {

    /**
     *                            #
     *                           / \
     *                          #   #
     *                         /   / \
     *                        #   #   #
     *                           /   /
     *                          #   #
     */
    TreeNode* tree = new TreeNode();                            // ""
    tree->leftChild = new TreeNode();                           // "L"
    tree->rightChild = new TreeNode();                          // "R"
    tree->leftChild->leftChild = new TreeNode();                // "LL"
    tree->rightChild->leftChild = new TreeNode();               // "RL"
    tree->rightChild->rightChild = new TreeNode();              // "RR"
    tree->rightChild->rightChild->leftChild = new TreeNode();   // "RRL"
    tree->rightChild->leftChild->leftChild = new TreeNode();    // "RLL"

    REQUIRE_THAT(getXLongPaths(tree, 1), Catch::Matchers::Equals((std::vector<std::string>){  }));
    REQUIRE_THAT(getXLongPaths(tree, 2), Catch::Matchers::Equals((std::vector<std::string>){ "LL" }));
    REQUIRE_THAT(getXLongPaths(tree, 3), Catch::Matchers::Equals((std::vector<std::string>){ "RLL", "RRL" }));
}
