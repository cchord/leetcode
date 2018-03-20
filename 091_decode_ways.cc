// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.
//
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
// The number of ways decoding "12" is 2.

#include <string>
#include <vector>
#include <iostream>

#include "gtest/gtest.h"

using namespace std;

class Solution {
  public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        auto sz = s.size();
        vector<int> dp(sz + 1, 0);
        dp[0] = 1;
        for(auto i = 1; i <= sz; ++i) {
            int c = s[i-1] - '0';
            if (c >= 1 && c <= 26)
                dp[i] = dp[i-1];
            if(i > 1) {
                c = (s[i-2] - '0')*10 + (s[i-1] - '0');
                if (c >= 10 && c <= 26)
                    dp[i] += dp[i-2];
            }
        }

        return dp[sz];
    }
};

TEST(NumDecodings, 1) {
    Solution s;
    cout << s.numDecodings("12") << endl;
}
