// Given a binary tree, return the inorder traversal of its nodes' values.
//
// For example:
// Given binary tree [1,null,2,3],
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].
//
// Note: Recursive solution is trivial, could you do it iteratively?

#include "gtest/gtest.h"

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(res, root);
        return res;
    }

    void traverse(vector<int>& res, TreeNode* node) {
        if (node == nullptr)
            return;
        traverse(res, node->left);
        res.push_back(node->val);
        traverse(res, node->right);
    }
};

TEST(BTInorderTravesal, Recursive) {
    TreeNode root(1);
    root.right = new TreeNode(2);
    root.right->left = new TreeNode(3);
    Solution s;
    auto res = s.inorderTraversal(&root);
    EXPECT_EQ(res.size(), 3);
    EXPECT_EQ(res[0],1);
    EXPECT_EQ(res[1],3);
    EXPECT_EQ(res[2],2);
}

#include <stack>

class Solution1 {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* x = root;

        while (x != nullptr || !s.empty()) {
            if (x == nullptr || x->left == nullptr) {
                if (x == nullptr) {
                    x = s.top();
                    s.pop();
                }
                res.push_back(x->val);
                x = x->right;
                continue;
            }
            s.push(x);
            x = x->left;
        }

        return res;
    }
};

TEST(BTInorderTravesal, NonRecursiveUsingStack) {
    TreeNode root(1);
    root.right = new TreeNode(2);
    root.right->left = new TreeNode(3);
    Solution1 s;
    auto res = s.inorderTraversal(&root);
    EXPECT_EQ(res.size(), 3);
    EXPECT_EQ(res[0],1);
    EXPECT_EQ(res[1],3);
    EXPECT_EQ(res[2],2);
}

class Solution2 {
  public:
    // morris traversal
    // 1. if cur->left is null, print cur->val, cur = cur->right
    //    else, find predecessor_of(cur->left)
    //    a) if pred is null, pred->right = cur, cur = cur->left
    //    b) else, print cur->val, cur = cur->right
    // 2. iterate until cur is null.
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *cur = root, *pred = nullptr;
        vector<int> res;

        while (cur != nullptr) {
            if (cur->left == nullptr) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                pred = cur->left;
                while (pred->right != nullptr && pred->right != cur) {
                    pred = pred->right;
                }
                if (pred->right == nullptr) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    pred->right = nullptr;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};

TEST(BTInorderTravesal, MorrisTraversal) {
    TreeNode root(1);
    root.right = new TreeNode(2);
    root.right->left = new TreeNode(3);
    Solution2 s;
    auto res = s.inorderTraversal(&root);
    EXPECT_EQ(res.size(), 3);
    EXPECT_EQ(res[0],1);
    EXPECT_EQ(res[1],3);
    EXPECT_EQ(res[2],2);
}
