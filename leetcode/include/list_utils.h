#pragma once

#include <type_traits>

#include "pch.h"
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

template <typename List>
concept ListLike = requires(List l) {
    l.val;
    l.next;
};


template <ListLike List = ListNode, typename T>
auto create_list(initializer_list<T> init)
{
    auto pre = new List();
    auto cur = pre;
    for (auto&& v : init) {
        cur->next = new List(v);
        cur       = cur->next;
    }
    cur = pre->next;
    delete pre;
    return cur;
}

template <ListLike List>
ostream& operator<<(ostream& os, List* head)
{
    auto cur = head;
    os << "{";
    if (cur != nullptr) {
        os << cur->val;
        cur = cur->next;
    }
    while (cur != nullptr) {
        os << ", " << cur->val;
        cur = cur->next;
    }
    os << "}";
    return os;
}
