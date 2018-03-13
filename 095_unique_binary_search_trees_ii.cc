// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include "gtest/gtest.h"

#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*> {};
        return generate(0, n);
    }

    vector<TreeNode*> generate(int p, int q) {
        if (p >= q)
            return vector<TreeNode*> {nullptr};

        vector<TreeNode*> res;
        for (auto i = p; i < q; ++i) {
            auto l = generate(p, i);
            auto r = generate(i+1, q);
            for (auto lnode : l)
                for (auto rnode : r) {
                    auto n = new TreeNode(i+1);
                    n->left = lnode;
                    n->right = rnode;
                    res.push_back(n);
                }
        }

        return res;
    }
};
