#include "list_utils.h"
#include "pch.h"
#include "tree_utils.h"
#include "vector_utils.h"

// problem 226
// url: https://leetcode.cn/problems/invert-binary-tree/

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root) {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};

int main()
{
    Solution s;

    auto tree = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                             new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    cout << tree << endl;
    cout << s.invertTree(tree) << endl;
}

/*
        1
   2           3
4    5      6     7

left: 1 2 4 5 3 6 7
cent: 4 2 5 1 6 3 7
*/
