// Write a program to find the nth super ugly number.
//
// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
//
// Note:
// (1) 1 is a super ugly number for any given primes.
// (2) The given numbers in primes are in ascending order.
// (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
// (4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
#include "gtest/gtest.h"

#include <iostream>

#include <vector>

using namespace std;

class Solution {
  public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> p(primes.size(), 0);
        vector<int> v(n, numeric_limits<int>::max());
        v[0] = 1;

        for (auto i = 1; i < n; ++i) {
            for (auto j = 0; j < primes.size(); ++j)
                v[i] = min(v[i], primes[j]*v[p[j]]);
            for (auto j = 0; j < primes.size(); ++j)
                if(v[i] == primes[j]*v[p[j]])
                    p[j]++;
        }

        return v[n-1];
    }
};

TEST(SuperUglyNumber, 1) {
    Solution s;
    vector<int> v{2,3,5};
    cout << s.nthSuperUglyNumber(1, v) << endl;
    cout << s.nthSuperUglyNumber(9, v) << endl;
}
