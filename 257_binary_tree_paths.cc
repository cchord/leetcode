// Given a binary tree, return all root-to-leaf paths.
//
// For example, given the following binary tree:
//
//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:
//
// ["1->2->5", "1->3"]

#include <vector>
#include <string>

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
    vector<string> res;
  public:
    vector<string> binaryTreePaths(TreeNode* root) {
        traverse("", root);
        return res;
    }

    void traverse(string s, TreeNode *x) {
        if (!x)
            return;
        if (s.empty())
            s = to_string(x->val);
        else
            s += "->" + to_string(x->val);
        if (!x->left && !x->right) {
            res.push_back(s);
            return;
        }
        if (x->left)
            traverse(s, x->left);
        if (x->right)
            traverse(s, x->right);
    }
};
