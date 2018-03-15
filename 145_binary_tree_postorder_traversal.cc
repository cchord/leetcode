// Given a binary tree, return the postorder traversal of its nodes' values.
//
// For example:
// Given binary tree [1,null,2,3],
//
//    1
//     \
//      2
//     /
//    3
//
//
// return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode *x, vector<int> &res) {
        if (!x)
            return;
        traverse(x->left, res);
        traverse(x->right, res);
        res.push_back(x->val);
    }
};

#include <stack>

class Solution1 {
  public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode *cur = root;
        vector<int> res;
        stack<pair<TreeNode*, int>> s;

        while(cur || !s.empty()) {
            if (!cur) {
                auto p = s.top();
                cur = p.first;
                s.pop();
                if (!cur->right || p.second > 0) {
                    res.push_back(cur->val);
                    cur = nullptr;
                } else {
                    p.second = 1;
                    s.push(p);
                    cur = cur->right;
                }
            }
            while (cur) {
                s.push({cur, 0});
                cur = cur->left;
            }
        }

        return res;
    }
};


class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode rr = TreeNode(0);
        TreeNode *cur = &rr, *pred = nullptr;
        rr.left = root;
        vector<int> res;

        while(cur) {
            if (!cur->left) {
                cur = cur->right;
            } else {
                pred = cur->left;
                while(pred->right && pred->right != cur) {
                    pred = pred->right;
                }
                if (pred->right == nullptr) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    pred->right = nullptr;
                    reverse(cur->left);
                    for (TreeNode* n = pred; n; n = n->right) {
                        res.push_back(n->val);
                    }
                    reverse(pred);
                    cur = cur->right;
                }
            }
        }

        return res;
    }

    void reverse(TreeNode *s) {
        TreeNode *p = nullptr, *c = s;
        while (c) {
            TreeNode *n = c->right;
            c->right = p;
            p = c;
            c = n;
        }
    }
};
