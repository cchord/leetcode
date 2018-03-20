// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
// For example,
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//
// Your algorithm should run in O(n2) complexity.
//
// Follow up: Could you improve it to O(n log n) time complexity?

#include "gtest/gtest.h"

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        int m = 1;
        for(auto i = 1; i < nums.size(); ++i) {
            for(auto j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            m = max(m, dp[i]);
        }
        return m;
    }
};

TEST(LIS, 1) {
    vector<int> v{10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution().lengthOfLIS(v) << endl;
}
