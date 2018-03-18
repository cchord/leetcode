// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example 1:
// [[1,3,1],
//  [1,5,1],
//  [4,2,1]]
// Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.

#include "gtest/gtest.h"

#include <vector>

using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid) {
        auto m = grid.size();
        if (m == 0)
            return 0;
        auto n = grid[0].size();
        if (n == 0)
            return 0;

        for(auto i = 1; i < n; ++i)
            grid[0][i] += grid[0][i-1];
        for(auto i = 1; i < m; ++i)
            grid[i][0] += grid[i-1][0];

        for(auto i = 1; i < m; ++i)
            for(auto j = 1; j < n; ++j)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);

        return grid[m-1][n-1];
    }
};

TEST(MinPathSum, 1) {
    Solution s;
    vector<vector<int>> grid{{1,2,5},{3,2,1}};
    EXPECT_EQ(6, s.minPathSum(grid));
}
