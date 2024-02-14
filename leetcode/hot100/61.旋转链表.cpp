/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */
#include "list_utils.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (k == 0) {
            return head;
        }
        if (!head) {
            return head;
        }
        auto slow      = head;
        auto fast      = head;
        auto fast_prev = fast;
        auto slow_prev = slow;
        for (int i = 0; i < k; i++) {
            if (fast) {
                fast_prev = fast;
                fast      = fast->next;
            } else {
                return rotateRight(head, k % i);
            }
        }
        while (fast) {
            slow_prev = slow;
            slow      = slow->next;
            fast_prev = fast;
            fast      = fast->next;
        }
        auto new_head = slow;
        if (new_head == head) {
            return head;
        }
        fast_prev->next = head;
        slow_prev->next = nullptr;
        return new_head;
    }
};
// @lc code=end

int main()
{
    Solution s;
    auto head = create_list({1, 2});
    cout << s.rotateRight(head, 2);
}