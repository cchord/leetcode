// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#include "gtest/gtest.h"

#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    typedef vector<ListNode*>::iterator iter;
  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeK(lists.begin(), lists.end());
    }

    ListNode* mergeK(iter b, iter e) {
        if (b == e)
            return nullptr;
        if (e - b == 1)
            return *b;
        auto m = b + (e - b) / 2;
        return merge2Lists(mergeK(b, m), mergeK(m, e));
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0);
        auto l = h;
        while(l1 && l2) {
            if (l1->val < l2->val) {
                l->next = l1;
                l1 = l1->next;
            } else {
                l->next = l2;
                l2 = l2->next;
            }
            l = l->next;
        }
        l->next = !l1 ? l2 : l1;
        return h->next;
    }
};

TEST(MergeKLists, 1) {
    Solution s;
    vector<ListNode*> v;
    cout << s.mergeKLists(v) << endl;

    auto l1 = new ListNode(2);
    l1->next = new ListNode(4);
    auto l2 = new ListNode(1);
    l2->next = new ListNode(3);
    
    auto l = s.merge2Lists(l1, l2);
    for (;l; l= l->next)
        cout << l->val << " ";
}
