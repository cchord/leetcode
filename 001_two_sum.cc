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
#include <set>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> m;

        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (m.find(target - *it) != m.end()) {
                return vector<int> {*it, target-*it};
            }
            m.insert(*it);
        }

        return vector<int> {};
    }
};

TEST(TwoSum, 1) {
    Solution s;
    auto v = vector<int> {1,2,7,6};
    auto r = s.twoSum(v , 9);
    EXPECT_EQ(r.size(), 2);
    EXPECT_EQ(r[0],7);
    EXPECT_EQ(r[1],2);
}
