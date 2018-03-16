// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    vector<vector<int>> res;

  public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return res;
        vector<int> v;
        traverse(root, v, sum);
        return res;
    }

    void traverse(TreeNode* x, vector<int>& v, int sum) {
        if (!x->left && !x->right) {
            if (sum == x->val) {
                v.push_back(x->val);
                res.push_back(v);
                v.pop_back();
            }
            return;
        }

        v.push_back(x->val);
        if (x->left)
            traverse(x->left, v, sum-x->val);
        if (x->right)
            traverse(x->right, v, sum-x->val);
        v.pop_back();
    }
};
