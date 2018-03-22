// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// For example,
// Given the following matrix:
//
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].

#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (!m)
            return res;

        int r1 = 0, r2 = m-1;
        int c1 = 0, c2 = matrix[0].size()-1;
        while(r1 <= r2 && c1 <= c2) {
            for(int c = c1; c <= c2; ++c) res.push_back(matrix[r1][c]);
            for(int r = r1+1; r <= r2; ++r) res.push_back(matrix[r][c2]);

            if(r1 < r2 && c1 < c2) {
                for(int c = c2-1; c > c1; --c) res.push_back(matrix[r2][c]);
                for(int r = r2; r > r1; --r) res.push_back(matrix[r][c1]);
            }
        }

        return res;
    }
};
