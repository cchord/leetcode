// Write a program to find the n-th ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
// Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

#include "gtest/gtest.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int nthUglyNumber(int n) {
        vector<int> v(n, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        for (auto i = 1; i < n; ++i) {
            v[i] = min(min(v[i2]*2, v[i3]*3), v[i5]*5);
            if (v[i] == v[i2]*2)
                i2++;
            if (v[i] == v[i3]*3)
                i3++;
            if (v[i] == v[i5]*5)
                i5++;
        }

        return v[n-1];
    }
};

TEST(UglyNumber, 1) {
    Solution s;
    cout << s.nthUglyNumber(1) << endl;
    cout << s.nthUglyNumber(9) << endl;
}
