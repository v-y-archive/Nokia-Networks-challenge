/**
 * There is a binary tree:
 *
 * struct TreeNode {
 *     struct TreeNode* leftChild;
 *     struct TreeNode* rightChild;
 * }
 *
 * Write a function that calculates the depth of the tree (the maximum number of
 * nodes in the path from the root to the leaf). The solution shall return all
 * paths in the tree that have such depth.
 */

#include "TreeNode.hpp"
#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> getXLongPaths(TreeNode* node, int x) {
    if (!node->leftChild && !node->rightChild) {
        if (x == 0) {
            return {""};
        } else {
            return {};
        }
    }

    std::vector<std::string> paths = {};

    if (node->leftChild != nullptr) {
        for (std::string path : getXLongPaths(node->leftChild, x - 1)) {
            paths.push_back("L" + path);
        }
    }

    if (node->rightChild != nullptr) {
        for (std::string path : getXLongPaths(node->rightChild, x - 1)) {
            paths.push_back("R" + path);
        }
    }

    return paths;
}