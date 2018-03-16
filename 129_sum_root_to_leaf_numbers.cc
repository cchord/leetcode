// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
// Find the total sum of all root-to-leaf numbers.
//
// For example,
//
//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
//
// Return the sum = 12 + 13 = 25.

#include <stdlib.h>

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
    int sum;
  public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return sum;
        traverse(root, 0);
        return sum;
    }

    void traverse(TreeNode *x, int partial) {
        if (!x->left && !x->right) {
            sum += partial + x->val;
            return;
        }
        if (x->left) {
            traverse(x->left, partial*10 + x->val);
        }
        if (x->right) {
            traverse(x->right, partial*10 + x->val);
        }
    }
};
