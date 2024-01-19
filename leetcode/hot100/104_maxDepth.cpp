#include "list_utils.h"
#include "pch.h"
#include "tree_utils.h"
#include "vector_utils.h"

// problem 104
// url: https://leetcode.cn/problems/maximum-depth-of-binary-tree/

class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if (!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{
    Solution s;

    auto root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)),
                             new TreeNode(3, new TreeNode(6, new TreeNode(9), nullptr), new TreeNode(7)));
    cout << s.maxDepth(root) << endl;
}
