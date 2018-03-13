// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//

#include "gtest/gtest.h"

#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;

        for (auto i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                vector<int> res{i, m[target - nums[i]]};
                sort(res.begin(), res.end());
                return res;
            }
            m.emplace(nums[i], i);
        }

        return vector<int> {-1, -1};
    }
};

TEST(TwoSum, 1) {
    Solution s;
    auto v = vector<int> {1,2,7,6};
    auto r = s.twoSum(v, 9);
    EXPECT_EQ(r.size(), 2);
    EXPECT_EQ(r[0],1);
    EXPECT_EQ(r[1],2);
}
