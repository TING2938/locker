#pragma once

#include <type_traits>

#include "pch.h"
// struct ListNode
// {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

template <typename List>
concept Listable = requires(List l) {
    l.val;
    l.next;
};


template <Listable List, typename T>
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

template <Listable List>
void print_list(List* head)
{
    auto cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
