// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//
// Example:
//
// Given the sorted array: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5

#include "gtest/gtest.h"

#include <vector>
#include <iostream>

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
    typedef vector<int>::iterator iter;
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traverse(nums.begin(), nums.end());
    }

    TreeNode *traverse(iter b, iter e) {
        if (b >= e)
            return nullptr;
        auto m = b + (e-b)/2;
        auto n = new TreeNode(*m);
        n->left = traverse(b, m);
        n->right = traverse(m+1, e);
        return n;
    }
};
