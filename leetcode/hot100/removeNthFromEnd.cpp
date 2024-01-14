#include "list_utils.h"
#include "pch.h"
// url: https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/

struct ListNode
{
    double val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int lens = 0;
        auto cur = head;
        while (cur != nullptr) {
            lens++;
            cur = cur->next;
        }
        if (lens == 1) {
            return nullptr;
        }
        if (lens == n) {
            return head->next;
        }
        cur = head;
        for (int i = 0; i < lens - n - 1; i++) {
            cur = cur->next;
        }
        auto cur_next = cur->next;
        if (cur_next != nullptr) {
            cur->next = cur_next->next;
            delete cur_next;
        }
        return head;
    }
};

TEST(leetcode, removeNthFromEnd)
{
    auto head = create_list<ListNode>({1, 2, 3});
    cout << head << endl;

    Solution s;
    head = s.removeNthFromEnd(head, 1);

    cout << head << endl;
}

// 双指针法