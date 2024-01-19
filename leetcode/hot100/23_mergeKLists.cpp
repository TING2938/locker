#include "list_utils.h"
#include "pch.h"
#include "vector_utils.h"

// problem 23
// url: https://leetcode.cn/problems/merge-k-sorted-lists/


class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int mid = (l + r) / 2;
        return mergeTwo(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeTwo(ListNode* l1, ListNode* l2)
    {
        ListNode* cur = nullptr;
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            cur = l1;
            l1  = l1->next;
        } else {
            cur = l2;
            l2  = l2->next;
        }
        auto head = cur;

        for (;;) {
            if (l1 == nullptr) {
                cur->next = l2;
                break;
            }
            if (l2 == nullptr) {
                cur->next = l1;
                break;
            }
            if (l1->val < l2->val) {
                cur->next = l1;
                l1        = l1->next;
            } else {
                cur->next = l2;
                l2        = l2->next;
            }
            cur = cur->next;
        }
        return head;
    }
};

int main()
{
    Solution s;

    auto lists = std::vector{
        create_list<ListNode>({1, 4, 5}),
        create_list<ListNode>({1, 3, 4}),
        create_list<ListNode>({2, 6}),
    };
    cout << s.mergeKLists(lists) << endl;
}
