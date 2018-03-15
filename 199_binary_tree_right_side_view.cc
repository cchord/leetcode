// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].

#include <vector>
#include <deque>

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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return vector<int> {};

        vector<int> res;
        deque<TreeNode*> q;
        q.push_back(root);

        while(!q.empty()) {
            res.push_back(q.back()->val);
            auto sz = q.size();
            for (auto i = 0; i < sz; ++i) {
                auto n = q.front();
                q.pop_front();
                if (n->left)
                    q.push_back(n->left);
                if (n->right)
                    q.push_back(n->right);
            }
        }

        return res;
    }
};
