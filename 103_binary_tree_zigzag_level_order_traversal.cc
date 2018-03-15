// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
//

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return vector<vector<int>> {};
        vector<vector<int>> res;
        deque<TreeNode*> q{root};
        bool l_to_r = true;

        while(!q.empty()) {
            vector<int> v;
            auto sz = q.size();
            for (auto i = 0; i < sz; ++i) {
                auto n = q.front();
                q.pop_front();
                v.push_back(n->val);
                if (n->left)
                    q.push_back(n->left);
                if (n->right)
                    q.push_back(n->right);
            }
            res.push_back(l_to_r ? v : vector<int>(v.rbegin(), v.rend()));
            l_to_r = !l_to_r;
        }

        return res;
    }
};
