// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// For example,
//
// Consider the following matrix:
//
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
// Given target = 5, return true.
//
// Given target = 20, return false.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        typedef vector<int>::size_type size_type;
        size_type m = matrix.size();
        if(!m)
            return false;
        size_type n = matrix[0].size();
        if(!n)
            return false;
        size_type i = 0, j = 0;
        while (j < n) {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                return false;
            if (i == m - 1)
                j++;
            else
                matrix[i+1][j] < matrix[i][j+1] ? i++ : j++;
        }
        return false;
    }
};
