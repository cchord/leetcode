// Given a binary tree, determine if it is height-balanced.
//
// For this problem, a height-balanced binary tree is defined as: //
// a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example 1:
//
// Given the following tree [3,9,20,null,null,15,7]:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.
//
// Example 2:
//
// Given the following tree [1,2,2,3,3,null,null,4,4]:
//
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// Return false.

#include <algorithm>

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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        height(root, balanced);
        return balanced;
    }

    int height(TreeNode* x, bool& balanced) {
        if (!x || !balanced)
            return 0;

        auto lh = height(x->left, balanced);
        auto hh = height(x->right, balanced);
        if (abs(hh-lh) > 1) {
            balanced = false;
            return 0;
        }
        return max(lh, hh) + 1;
    }
};
