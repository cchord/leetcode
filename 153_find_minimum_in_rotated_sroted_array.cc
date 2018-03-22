// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.

#include "gtest/gtest.h"

#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int findMin(vector<int>& nums) {
        int start=0,end=num.size()-1;

        while (start<end) {
            if (num[start]<num[end])
                return num[start];

            int mid = (start+end)/2;

            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }

        return num[start];
    }
};

TEST(FindMin, 1) {
    Solution s;
    vector<int> v{4,6,0,1,2};
    cout << s.findMin(v) << endl;
}
