// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
//
//         _______3______
//        /              \
//     ___5__          ___1__
//    /      \        /      \
//    6      _2       0       8
//          /  \
//          7   4
// For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

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
    TreeNode *lca = nullptr;
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find(root, p, q);
        return lca;
    }

    void find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return;
        if (isChild(root, p) && isChild(root, q)) {
            lca = root;
        }
        find(root->left, p, q);
        find(root->right, p, q);
    }

    bool isChild(TreeNode* r, TreeNode* x) {
        return r && (r == x || r->left == x || r->right == x || isChild(r->left, x) || isChild(r->right, x));
    }
};

#include <vector>
using namespace std;

class Solution1 {
    vector<TreeNode*> ppath;
    vector<TreeNode*> qpath;
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        vector<TreeNode*> v;
        walk(v, root, p, q);
        TreeNode *lca = nullptr;
        for(auto i = 0; i < ppath.size() && i < qpath.size(); ++i) {
            if(ppath[i] != qpath[i])
                break;
            lca = ppath[i];
        }
        return lca;
    }

    void walk(vector<TreeNode*> &v, TreeNode *r, TreeNode *p, TreeNode *q) {
        if (!r)
            return;
        v.push_back(r);
        if (r == p) {
            ppath = v;
        }
        if (r == q) {
            qpath = v;
        }
        walk(v, r->left, p, q);
        walk(v, r->right, p, q);
        v.pop_back();
    }
};
