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
    vector<vector<int>> levelOrder2(TreeNode* root)
    {
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            ret.push_back({});
            int level = q.size();
            for (int i = 0; i < level; i++) {
                auto node = q.front();
                q.pop();
                ret.back().push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;

    auto tree = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                             new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    cout << tree << endl;

    cout << s.levelOrder2(tree) << endl;
}
