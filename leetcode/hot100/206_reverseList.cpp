#include "list_utils.h"
#include "pch.h"
#include "vector_utils.h"

// problem 0
// url:

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* tmp  = nullptr;
        auto cur       = head;

        while (cur) {
            tmp       = cur->next;
            cur->next = prev;
            prev      = cur;
            cur       = tmp;
        }
        return prev;
    }
};

TEST(leetcode, reverseList)
{
    Solution s;

    auto head = create_list<ListNode>({1, 2, 3, 4, 5});
    cout << head << endl;

    cout << s.reverseList(head) << endl;
}
