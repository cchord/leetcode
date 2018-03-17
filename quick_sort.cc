#include "gtest/gtest.h"

#include <iostream>
#include <vector>

using namespace std;

namespace { 

class Solution {
  public:
    void sort(vector<int> nums) {
        partition(nums, 0, nums.size());
        for (auto n : nums)
            cout << n << ", ";
        cout << endl;
    }

    void partition(vector<int> &nums, int p, int q) {
        if (p >= q)
            return;
        int i = p, j = p;
        while (i < q-1) {
            if (nums[i] > nums[q-1])
                i++;
            else
                swap(nums[i++], nums[j++]);
        }
        swap(nums[j], nums[q-1]);
        partition(nums, p, j);
        partition(nums, j+1, q);
    }
};

TEST(QuickSort, 1) {   
    Solution s;
    s.sort(vector<int>{9,8,7,6,5,4,3,2,1});
    s.sort(vector<int>{1,2,3,4,9,8,7,6});
    s.sort(vector<int>{9,9,10,1,3,4,-1});
    s.sort(vector<int>{});
    s.sort(vector<int>{1});
}

}
