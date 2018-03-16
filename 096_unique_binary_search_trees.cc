// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
// For example,
// Given n = 3, there are a total of 5 unique BST's.
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

#include <vector>

using namespace std;

class Solution {
  public:
    int numTrees(int n) {
        vector<int> m(n+1, 1);
        for (auto i = 1; i <=n; ++i) {
            for (auto j = 0; j < i; ++j) {
                m[i] += m[j] * m[i-j-1];
            }
        }
        return m[n];
    }
};
