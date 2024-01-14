#include "pch.h"

// url: https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    ListNode* add(int value)
    {
        this->next = new ListNode(value);
        return this->next;
    }
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
    auto head = new ListNode(1);
    head->add(2);
    //->add(3)->add(4)->add(5);

    auto cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;


    Solution s;
    head = s.removeNthFromEnd(head, 2);

    cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 双指针法