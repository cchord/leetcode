// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
//
// You have the following 3 operations permitted on a word:
//
// a) Insert a character
// b) Delete a character
// c) Replace a character

#include "gtest/gtest.h"

#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int minDistance(string word1, string word2) {
        auto m = word1.size();
        auto n = word2.size();
        if (m*n == 0)
            return m ? m : n;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto i = 0; i <= m; ++i)
            dp[i][0] = i;
        for(auto j = 0; j <= n; ++j)
            dp[0][j] = j;

        for(auto i = 1; i <= m; ++i)
            for(auto j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j] + 1, dp[i][j-1] + 1));
            }

        return dp[m][n];
    }
};

TEST(Edit, 1) {
    Solution s;
    cout << s.minDistance("a", "b");
}
