// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
// Note:
// You are not suppose to use the library's sort function for this problem.
//
// click to show follow up.
//
// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
//
// Could you come up with an one-pass algorithm using only constant space?

#include <vector>
#include <iostream>
#include <iterator>

#include "gtest/gtest.h"

using namespace std;

namespace {

class Solution {
  public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0)
            return;
        int i = 0, j = 0, n = nums.size(), k = n - 1;
        while (i <= k) {
            if (nums[i] == 0)
                swap(nums[j++], nums[i++]);
            else if (nums[i] == 1)
                i++;
            else if (nums[i] == 2)
                swap(nums[i], nums[k--]);
        }
    }
};

TEST(SortColors, 1) {
    vector<int> v{1,0,0,2,1,0,2};
    Solution().sortColors(v);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

}
