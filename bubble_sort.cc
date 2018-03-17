#include "gtest/gtest.h"

#include <iostream>
#include <vector>

using namespace std;

namespace {

class Solution {
  public:
    void sort(vector<int> nums) {
        for (auto i = nums.size(); i > 0; --i)
            for (auto j = 0; j < i-1; ++j) {
                if (nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]);
            }

        for (auto n : nums)
            cout << n << ", ";
        cout << endl;
    }
};

TEST(BubbleSort, 1) {   
    Solution s;
    s.sort(vector<int>{9,8,7,6,5,4,3,2,1});
    s.sort(vector<int>{1,2,3,4,9,8,7,6});
    s.sort(vector<int>{9,9,10,1,3,4,-1});
    s.sort(vector<int>{});
    s.sort(vector<int>{1});
}

}
