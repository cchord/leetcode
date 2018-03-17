#include "gtest/gtest.h"

#include <iostream>
#include <vector>

using namespace std;

namespace {

class Solution {
  public:
    void sort(vector<int> nums) {
        merge_sort(nums, 0, nums.size());
        for (auto n: nums)
            cout << n << ", ";
        cout << endl;
    }

    void merge_sort(vector<int> &nums, int s, int e) {
        if (e - s <= 1)
            return;
        int m = s + (e-s)/2;
        merge_sort(nums, s, m);
        merge_sort(nums, m, e);
        merge(nums, s, m, e);
    }

    void merge(vector<int> &nums, int s, int m, int e) {
        vector<int> v;
        v.reserve(e-s);
        int i = s, j = m;
        while(i < m && j < e)
            v.push_back(nums[i] < nums[j] ? nums[i++] : nums[j++]);
        while (i < m)
            v.push_back(nums[i++]);
        while (j < e)
            v.push_back(nums[j++]);
        copy(v.begin(), v.end(), nums.begin()+s);
    }
};

TEST(MergeSort, 1) {   
    Solution s;
    s.sort(vector<int>{9,8,7,6,5,4,3,2,1});
    s.sort(vector<int>{1,2,3,4,9,8,7,6});
    s.sort(vector<int>{9,9,10,1,3,4,-1});
    s.sort(vector<int>{});
    s.sort(vector<int>{1});
}

}
