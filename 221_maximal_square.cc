// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
// For example, given the following matrix:
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Return 4.

#include "gtest/gtest.h"

#include <vector>

using namespace std;

class Solution {
  public:
    int maximalSquare(vector<vector<char>>& matrix) {
        auto m = matrix.size();
        if(!m)
            return 0;
        auto n = matrix[0].size();
        if(!n)
            return 0;
        int res = 0;

        vector<vector<int>> v(m+1, vector<int>(n+1, 0));
        for(auto i = 1; i <= m; ++i)
            for(auto j = 1; j <= n; ++j) {
                v[i][j] = matrix[i-1][j-1] - '0';
                if(v[i-1][j-1] && v[i][j]) {
                    for(auto k = 1; k <= v[i-1][j-1] && matrix[i-k-1][j-1] == '1' && matrix[i-1][j-k-1] == '1'; ++k)
                        v[i][j]++;
                }
                res = max(res, v[i][j]);
            }

        return res*res;
    }
};

class Solution1 {
  public:
    int maximalSquare(vector<vector<char>>& matrix) {
        auto m = matrix.size();
        if(!m)
            return 0;
        auto n = matrix[0].size();
        if(!n)
            return 0;
        int res = 0;

        vector<vector<int>> v(m+1, vector<int>(n+1, 0));
        for(auto i = 1; i <= m; ++i)
            for(auto j = 1; j <= n; ++j) {
                if(matrix[i-1][j-1] == '1') {
                    v[i][j] = min(min(v[i-1][j], v[i][j-1]), v[i-1][j-1]) + 1;
                    res = max(res, v[i][j]);
                }
            }

        return res*res;
    }
};


TEST(MaxSquare, 1) {
    Solution1 s;
    vector<vector<char>> m{{'1','0','1','0','0'}, {'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << s.maximalSquare(m) << endl;;
}
