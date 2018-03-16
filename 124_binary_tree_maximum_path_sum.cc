// Given a binary tree, find the maximum path sum.
//
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
// For example:
// Given the below binary tree,
//
//        1
//       / \
//      2   3
// Return 6.

#include <stdlib.h>
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
    int max_ = numeric_limits<int>::min();
  public:
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return max_;
    }

    int traverse(TreeNode *x) {
        if (!x)
            return 0;
        // cover all cases: this node is max; or left path only (with or without current node); right path only
        auto l = max(0, traverse(x->left));
        auto r = max(0, traverse(x->right));
        max_ = max(max_, l+r+x->val);
        return max(l, r) + x->val;
    }
};
