// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

#include "gtest/gtest.h"

#include <iostream>

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
    void recoverTree(TreeNode* root) {
        recover(root);
    }

    void recover(TreeNode* x) {
        if (x == nullptr)
            return;

        TreeNode* lmax = nullptr;
        TreeNode* rmin = nullptr;
        traverse(x->left, nullptr, &lmax);
        traverse(x->right, &rmin, nullptr);

        if (lmax != nullptr && rmin != nullptr ) {
            if (lmax->val > x->val && rmin->val < x->val) {
                swap(rmin->val, lmax->val);
                return;
            } else if (lmax->val > x->val) {
                swap(x->val, lmax->val);
                return;
            } else if (rmin->val < x->val) {
                swap(x->val, rmin->val);
                return;
            }
        } else if (lmax != nullptr && lmax->val > x->val) {
            swap(x->val, lmax->val);
            return;
        } else if (rmin != nullptr && rmin->val < x->val) {
            swap(x->val, rmin->val);
            return;
        }

        recover(x->left);
        recover(x->right);
    }

    void traverse(TreeNode* x, TreeNode** min, TreeNode** max) {
        if (x == nullptr)
            return;

        traverse(x->left, min, max);
        if (max != nullptr && (*max == nullptr || x->val > (*max)->val))
            *max = x;
        if (min != nullptr && (*min == nullptr || x->val < (*min)->val))
            *min = x;
        traverse(x->right, min, max);
    }
};

TEST(RecoverTree, 1) {
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    Solution s;
    s.recoverTree(&root);
    EXPECT_EQ(root.val, 2);
    EXPECT_EQ(root.left->val,1);
    EXPECT_EQ(root.right->val,3);

    root.val = 2;
    root.left->val = 1;
    root.right->val = 3;
    s.recoverTree(&root);
    EXPECT_EQ(root.val, 2);
    EXPECT_EQ(root.left->val,1);
    EXPECT_EQ(root.right->val,3);

    root.val = 2;
    delete(root.left);
    delete(root.right);
    root.left = root.right = nullptr;
    s.recoverTree(&root);
    EXPECT_EQ(root.val, 2);
}

class Solution2 {
  private:
    TreeNode *prev, *n1, *n2;
  public:
    Solution2():prev(nullptr), n1(nullptr), n2(nullptr) {}

  public:
    void recoverTree(TreeNode* root) {
        morrisInorderTraverse(root);
        if (n1 && n2)
            swap(n1->val, n2->val);
    }

    void morrisInorderTraverse(TreeNode* root) {
        TreeNode *cur = root, *pred = nullptr;
        while(cur) {
            if (cur->left) {
                pred = cur->left;
                while(pred->right && pred->right != cur) {
                    pred = pred->right;
                }
                if (pred->right) {
                    pred->right = nullptr;

                    if (prev && prev->val > cur->val) {
                        if (!n1) {
                            n1 = prev;
                        }
                        n2 = cur;
                    }

                    prev = cur;
                    cur = cur->right;
                } else {
                    pred->right = cur;
                    cur = cur->left;
                }
            } else {
                if (prev && prev->val > cur->val) {
                    if (!n1) {
                        n1 = prev;
                    }
                    n2 = cur;
                }

                prev = cur;
                cur = cur->right;
            }
        }
    }
};

TEST(RecoverTree, 2) {
    TreeNode root(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    Solution2 s;
    s.recoverTree(&root);
    EXPECT_EQ(root.val, 2);
    EXPECT_EQ(root.left->val,1);
    EXPECT_EQ(root.right->val,3);

    //root.val = 2;
    //root.left->val = 1;
    //root.right->val = 3;
    //s.recoverTree(&root);
    //EXPECT_EQ(root.val, 2);
    //EXPECT_EQ(root.left->val,1);
    //EXPECT_EQ(root.right->val,3);

    //root.val = 2;
    //delete(root.left);
    //delete(root.right);
    //root.left = root.right = nullptr;
    //s.recoverTree(&root);
    //EXPECT_EQ(root.val, 2);
}
