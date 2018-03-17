#include "gtest/gtest.h"

#include <iostream>
#include <vector>

using namespace std;

namespace {

class Solution {
  public:
    void sort(vector<int> nums) {
        build_heap(nums);
        for(int i = nums.size()-1; i > 0; --i) {
            swap(nums[0], nums[i]);
            max_heapify(nums, 0, i);
        }

        cout << "heap: " << nums.size() << endl;
        for (auto n : nums)
            cout << n << ", ";
        cout << endl;
    }

    void build_heap(vector<int> &nums) {
        int heap_size = nums.size();
        for (auto i = heap_size/2; i >= 0; i--) {
            max_heapify(nums, i, heap_size);
        }
    }

    void max_heapify(vector<int> &nums, int i, int heap_size) {
        auto l = left(i);
        auto r = right(i);
        int max = 0;
        if (l < heap_size && nums[l] > nums[i])
            max = l;
        else
            max = i;
        if (r < heap_size && nums[r] > nums[max])
            max = r;

        if (max != i) {
            swap(nums[i], nums[max]);
            max_heapify(nums, max, heap_size);
        }
    }

    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return i*2 + 1;
    }

    int right(int i) {
        return i*2 + 2;
    }
};

TEST(HeapSort, 1) {
    Solution s;
    s.sort(vector<int> {9,8,7,6,5,4,3,2,1});
    s.sort(vector<int> {1,2,3,4,9,8,7,6});
    s.sort(vector<int> {9,9,10,1,3,4,-1});
    s.sort(vector<int> {});
    s.sort(vector<int> {1});
}

}
