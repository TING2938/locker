#include "list_utils.h"
#include "pch.h"
#include "tree_utils.h"
#include "vector_utils.h"

// problem 101
// url: https://leetcode.cn/problems/symmetric-tree/

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (!root) {
            return true;
        }
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* left, TreeNode* right)
    {
        if ((left && !right) || (!left && right)) {
            return false;
        }
        if (!left && !right) {
            return true;
        }
        if (left->val != right->val) {
            return false;
        }
        return compare(left->left, right->right) && compare(left->right, right->left);
    }
};

TEST(leetcode, isSymmetric)
{
    Solution s;
    auto tree = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                             new TreeNode(2, new TreeNode(5), new TreeNode(4)));
    cout << tree << endl;
    cout << s.isSymmetric(tree) << endl;
}
/*
        1
   2           2
4    5      5     4

*/