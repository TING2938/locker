#include "list_utils.h"
#include "pch.h"
#include "tree_utils.h"
#include "vector_utils.h"

// problem 102
// url: https://leetcode.cn/problems/binary-tree-level-order-traversal/

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        make_order(ret, root, 0);
        return ret;
    }

    void make_order(vector<vector<int>>& vec, TreeNode* root, int order)
    {
        if (root) {
            if (vec.size() == order) {
                vec.push_back({});
            }
            vec[order].push_back(root->val);
            make_order(vec, root->left, order + 1);
            make_order(vec, root->right, order + 1);
        }
    }
};

TEST(leetcode, levelOrder)
{
    Solution s;

    auto tree = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                             new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    cout << tree << endl;

    cout << s.levelOrder(tree) << endl;
}
