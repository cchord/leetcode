// Follow up for problem "Populating Next Right Pointers in Each Node".
//
// What if the given tree could be any binary tree? Would your previous solution still work?
//
// Note:
//
// You may only use constant extra space.
// For example, // Given the following binary tree,
//          1
//        /  \
//       2    3
//      / \    \
//     4   5    7
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \    \
//     4-> 5 -> 7 -> NULL

/**
 * Definition for binary tree with next pointer.
 */

#include <stdlib.h>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
  public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;

        TreeLinkNode *line_head = root;
        while(line_head) {
            auto cur = line_head;
            TreeLinkNode *prev = nullptr, *new_head = nullptr;
            while (cur) {
                if (!cur->left && !cur->right) {
                    cur = cur->next;
                    continue;
                }

                if (cur->left && cur->right) {
                    if (prev)
                        prev->next = cur->left;
                    cur->left->next = cur->right;
                    prev = cur->right;
                    if (!new_head)
                        new_head = cur->left;
                } else if (cur->left) {
                    if (prev)
                        prev->next = cur->left;
                    prev = cur->left;
                    if (!new_head)
                        new_head = cur->left;
                } else if (cur->right) {
                    if (prev)
                        prev->next = cur->right;
                    prev = cur->right;
                    if (!new_head)
                        new_head = cur->right;
                }

                cur = cur->next;
            }

            line_head = new_head;
        }
    }
};
