#include "pch.h"

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val = 0) : value(val), left(nullptr), right(nullptr) {}
};

auto makeTree()
{
    TreeNode* tmp;
    auto root = new TreeNode(1);

    tmp = root->left = new TreeNode(2);
    tmp = tmp->left = new TreeNode(4);
    tmp->right      = new TreeNode(8);

    tmp = root->right = new TreeNode(3);
    tmp = tmp->left = new TreeNode(5);
    tmp->left       = new TreeNode(6);
    tmp->right      = new TreeNode(7);

    return root;
}

void preorderTraversal(const TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    std::cout << root->value << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void midorderTraversal(const TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    midorderTraversal(root->left);
    std::cout << root->value << " ";
    midorderTraversal(root->right);
}

void postorderTraversal(const TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->value << " ";
}

TEST(basic_binaryTree, pre)
{
    auto root = makeTree();
    preorderTraversal(root);
}

TEST(basic_binaryTree, mid)
{
    auto root = makeTree();
    midorderTraversal(root);
}

TEST(basic_binaryTree, post)
{
    auto root = makeTree();
    postorderTraversal(root);
}