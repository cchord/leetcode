// Given a binary tree, return the preorder traversal of its nodes' values.
//
// For example:
// Given binary tree [1,null,2,3],
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].

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
  public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode* x, vector<int>& res) {
        if (!x) {
            return;
        }

        res.push_back(x->val);
        traverse(x->left, res);
        traverse(x->right, res);
    }
};

#include <stack>

class Solution1 {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;

        while (cur || !s.empty()) {
            if (!cur) {
                cur = s.top();
                s.pop();
            }
            while (cur) {
                res.push_back(cur->val);
                if (cur->right)
                    s.push(cur->right);
                cur = cur->left;
            }
        }

        return res;
    }
};

class Solution2 {
  public:
    // morris traversal
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *cur = root, *pred = nullptr;
        vector<int> res;

        while(cur) {
            if (cur->left) {
                pred = cur->left;
                while(pred->right && pred->right != cur) {
                    pred = pred->right;
                }
                if (pred->right == cur) {
                    pred->right = nullptr;
                    cur = cur->right;
                } else {
                    res.push_back(cur->val);
                    pred->right = cur;
                    cur = cur->left;
                }
            } else {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }

        return res;
    }
};
