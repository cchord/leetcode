#include "gtest/gtest.h"

#include <vector>
#include <iostream>
#include <utility>

using namespace std;

// return the pos.
int lower_bound(vector<int> &nums, int value) {
    int first = 0, last = nums.size(), count = last - first;
    while(count) {
        auto step = count / 2;
        auto i = first + step;
        if (nums[i] < value) {
            first = ++i;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}

int upper_bound(vector<int> &nums, int value) {
    int first = 0, last = nums.size(), count = last - first;
    while (count) {
        auto step = count / 2;
        auto i = first + step;
        if (nums[i] <= value) {
            first = ++i;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}

TEST(LowerBound, 1) {
    vector<int> nums{1,3,5,7,9};
    cout << lower_bound(nums, 1) << endl;
    cout << lower_bound(nums, 4) << endl;
    cout << lower_bound(nums, 10) << endl;
}
