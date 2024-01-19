#include "pch.h"

// url:

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    vector<int> reversePrint(ListNode* head)
    {
        vector<int> ret;
        ListNode* it = head;
        while (it) {
            ret.push_back(it->val);
            it = it->next;
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main()
{
    Solution s;

    auto head        = new ListNode(1);
    head->next       = new ListNode(3);
    head->next->next = new ListNode(2);
    std::vector<int> ret{2, 3, 1};

    assert(s.reversePrint(head) == ret);
}
