// Given a binary tree, flatten it to a linked list in-place.
//
// For example,
// Given
//
//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6

#include <stdlib.h>

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
    void flatten(TreeNode* root) {
        flat(root);
    }

    TreeNode* flat(TreeNode* x)  {
        if (!x)
            return nullptr;

        auto left = flat(x->left);
        auto right = flat(x->right);

        x->left = nullptr;
        if (left && right) {
            x->right = left;
            endOf(left)->right = right;
        } else if (left) {
            x->right = left;
        } else if (right) {
            x->right = right;
        }
        return x;
    }

    TreeNode* endOf(TreeNode* x) {
        TreeNode *prev = nullptr;
        while (x) {
            prev = x;
            x = x->right;
        }
        return prev;
    }
};

// reverse order of preorder
// process the tree from last list node to the begining.
class Solution1 {
    TreeNode *prev;
  public:
    void flatten(TreeNode* root) {
        if (!root)
            return;

        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = prev;
        prev = root;
    }
};
