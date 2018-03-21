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

#include "gtest/gtest.h"

#include <iostream>
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
        int first = 0, last = m*n, count = last - first;
        while(count) {
            int step = count / 2;
            int i = first + step;
            if (matrix[i/n][i%n] < target) {
                first = ++i;
                count -= step + 1;
            } else {
                count = step;
            }
        }
        if (first >= last)
            return false;
        return matrix[first/n][first%n] == target;
    }
};

TEST(SearchMatrix, 2) {
    Solution1 s;
    vector<vector<int>> v{{1,1}};
    cout << s.searchMatrix(v, 0) << endl;
}
