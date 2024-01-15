#pragma once
#include "pch.h"

// struct TreeNode
// {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };


template <typename Tree>
concept TreeLike = requires(Tree t) {
    t.val;
    t.left;
    t.right;
};

template <TreeLike Tree>
ostream& operator<<(ostream& os, Tree* node)
{
    if (node) {
        os << node->val << " ";
        os << node->left;
        os << node->right;
    }
    return os;
}
