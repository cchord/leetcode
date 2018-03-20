// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// For example,
//
// Consider the following matrix:
//
// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// Given target = 3, return true.

#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto m = matrix.size();
        if (!m)
            return false;
        auto n = matrix[0].size();
        if (!n)
            return false;
        int i = 0, j = 0;
        while(j < n) {
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] > target)
                return false;
            if (i == m - 1)
                j++;
            else
                matrix[i+1][j] <= target ? i++ : j++;
        }
        return false;
    }
};

class Solution1 {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m)
            return false;
        int n = matrix[0].size();
        if (!n)
            return false;
        auto l = 0, r = m * n;
        while(r - l > 1) { 
            auto mid = (l + r) >> 1;
            if (matrix[mid/m][mid%m] < target) 
                r = m;
            else
                l = m;
        }
        return matrix[l/m][l%m] == target;
    }
};
