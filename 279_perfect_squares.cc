// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
//
// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

#include "gtest/gtest.h"

#include <vector>
#include <climits>

using namespace std;

class Solution {
  public:
    int numSquares(int n) {
        vector<int> v(n+1, numeric_limits<int>::max());
        for (auto i = 1; i*i <= n; ++i)
            v[i*i] = 1;

        for (auto i = 2; i <= n; ++i) {
            if (v[i] != numeric_limits<int>::max())
                continue;
            for (auto j = 1; j*j <= i; ++j)
                v[i] = min(v[i], v[j*j] + v[i - j*j]);
        }

        return v[n];
    }
};

TEST(NumSquares, 1) {
    Solution s;
    cout << s.numSquares(12);
    cout << s.numSquares(13);
}
