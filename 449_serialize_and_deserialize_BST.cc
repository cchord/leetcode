// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
// The encoded string should be as compact as possible.
//
// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

#include "gtest/gtest.h"

#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>

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
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        vector<int> v;
        copy(istream_iterator<int>(iss), istream_iterator<int>(), insert_iterator<vector<int>>(v, v.begin()));
        for (auto n : v)
            cout << n << " ";
        return deserialize(v.begin(), v.end());
    }
  private:
    void serialize(TreeNode *x, ostringstream &oss) {
        if(!x)
            return;
        oss << x->val << " ";
        serialize(x->left, oss);
        serialize(x->right, oss);
    }

    TreeNode* deserialize(vector<int>::iterator b, vector<int>::iterator e) {
        if (b == e)
            return nullptr;
        auto n = new TreeNode(*b);
        auto m = find_if(b, e, [&b](int num) {
            return num > *b;
        });
        n->left = deserialize(b+1, m);
        n->right = deserialize(m, e);
        return n;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

void prt(TreeNode *x) {
    if(!x)
        return;
    prt(x->left);
    cout << x->val;
    prt(x->right);
}

TEST(Serialize, 2) {
    Codec c;
    auto root = TreeNode(0);
    root.left = new TreeNode(1);
    root.right = new TreeNode(2);
    root.right->left = new TreeNode(3);
    root.right->right = new TreeNode(4);
    cout << c.serialize(&root) << endl;
    auto t = c.deserialize(c.serialize(&root));
    prt(t);
}
