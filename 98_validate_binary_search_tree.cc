// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Example 1:
//     2
//    / \
//   1   3
// Binary tree [2,1,3], return true.
// Example 2:
//     1
//    / \
//   2   3
// Binary tree [1,2,3], return false.

#include <limits>

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
    bool isValidBST(TreeNode* root) {
        return validate(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }

    bool validate(TreeNode *x, long min, long max) {
        if(!x)
            return true;
        if (x->val <= min || x->val >= max)
            return false;
        if (!validate(x->left, min, x->val))
            return false;
        if (!validate(x->right, x->val, max))
            return false;
        return true;
    }
};
