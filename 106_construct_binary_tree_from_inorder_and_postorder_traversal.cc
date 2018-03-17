//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//inorder = [9,3,15,20,7]
//postorder = [9,15,7,20,3]
//Return the following binary tree:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7

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
    typedef vector<int>::const_reverse_iterator riter;
  public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder.begin(), inorder.end(), postorder.rbegin(), postorder.rend());
    }

    TreeNode* build(iter is, iter ie, riter ps, riter pe) {
        if (is == ie)
            return nullptr;
        TreeNode* n = new TreeNode(*ps);
        auto im = find(is, ie, *ps);
        n->left = build(is, im, pe-(im-is), pe);
        n->right = build(im+1, ie, ps+1, pe-(im-is));
        return n;
    }
};
