#include "list_utils.h"
#include "pch.h"
#include "tree_utils.h"
#include "vector_utils.h"

// problem 94
// url:

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        traver(ret, root);
        return ret;
    }

    void traver(vector<int>& vec, TreeNode* root)
    {
        if (root) {
            traver(vec, root->left);
            vec.push_back(root->val);
            traver(vec, root->right);
        }
    }
};

TEST(leetcode, inorderTraversal)
{
    Solution s;
    auto tree = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                             new TreeNode(2, new TreeNode(5), new TreeNode(4)));
    cout << tree << endl;
    cout << s.inorderTraversal(tree) << endl;
}
