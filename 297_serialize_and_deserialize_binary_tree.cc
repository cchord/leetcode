// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
// For example, you may serialize the following tree
//
//     1
//    / \
//   2   3
//      / \
//     4   5
// as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

#include "gtest/gtest.h"

#include <string>
#include <deque>
#include <sstream>

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

class Codec {
  public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        string s;
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()) {
            auto sz = q.size();
            for (auto i = 0; i < sz; ++i) {
                auto n = q.front();
                q.pop_front();
                if (n) {
                    q.push_back(n->left);
                    q.push_back(n->right);
                    if (s.empty()) {
                        s = to_string(n->val);
                    } else {
                        s += " " + to_string(n->val);
                    }
                } else {
                    s += " #";
                } }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        istringstream ss(data);
        TreeNode *root = nullptr;
        deque<TreeNode**> q;
        q.push_back(&root);

        while(!q.empty() && !ss.eof()) {
            auto sz = q.size();
            for (auto i = 0; i < sz; ++i) {
                auto n = q.front();
                q.pop_front();
                string s;
                ss >> s;
                if (s != "#") {
                    *n = new TreeNode(stoi(s));
                    q.push_back(&((*n)->left));
                    q.push_back(&((*n)->right));
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

//TEST(Serialize, 1) {
//    Codec c;
//    auto root = TreeNode(0);
//    root.left = new TreeNode(1);
//    root.right = new TreeNode(2);
//    root.right->left = new TreeNode(3);
//    root.right->right = new TreeNode(4);
//    auto t = c.deserialize(c.serialize(&root));
//    prt(t);
//}
