// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7

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
    typedef vector<int>::const_iterator iter;
  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    TreeNode* build(iter ps, iter pe, iter is, iter ie) {
        if (ps == pe)
            return nullptr;
        TreeNode* n = new TreeNode(*ps);
        auto im = find(is, ie, *ps);
        n->left = build(ps+1, ps+1+(im-is), is, im);
        n->right = build(ps+1+(im-is), pe, im+1, ie);
        return n;
    }
};
