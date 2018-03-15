//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//

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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;

        auto ld = minDepth(root->left);
        auto rd = minDepth(root->right);
        if (!ld)
            return rd+1;
        if (!rd)
            return ld+1;
        return min(ld, rd) + 1;
    }
};
