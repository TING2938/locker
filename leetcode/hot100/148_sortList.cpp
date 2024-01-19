#include "list_utils.h"
#include "pch.h"
#include "tree_utils.h"
#include "vector_utils.h"

// problem 148
// url: https://leetcode.cn/problems/sort-list/

class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode* fast     = head;
        ListNode* pre_slow = head;
        ListNode* slow     = head;
        while (fast) {
            fast = fast->next;
            if (fast) {
                fast     = fast->next;
                pre_slow = slow;
                slow     = slow->next;
            }
        }
        pre_slow->next = nullptr;
        return mergeTwoLists(sortList(head), sortList(slow));
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        ListNode* ret        = new ListNode();
        ListNode* ret_header = ret;

        while (p1 && p2) {
            int v1 = p1->val;
            int v2 = p2->val;
            if (v1 < v2) {
                ret->next = p1;
                p1        = p1->next;
                ret       = ret->next;
            } else {
                ret->next = p2;
                p2        = p2->next;
                ret       = ret->next;
            }
        }
        ret->next = p1 ? p1 : p2;
        return ret_header->next;
    }
};

int main()
{
    Solution s;

    auto head = create_list<ListNode>({3, 5, 2, 1, 5, 8, 4});
    cout << head << endl;
    cout << s.sortList(head) << endl;
}
/*
1  1  1
s  s
f     f
      s f
*/