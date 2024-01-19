#include "list_utils.h"
#include "pch.h"
#include "tree_utils.h"
#include "vector_utils.h"

// problem 297
// url: https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (root) {
            auto left  = serialize(root->left);
            auto right = serialize(root->right);
            if (left == "_" && right == "_") {
                return to_string(root->val);
            }
            return "(" + to_string(root->val) + ":" + left + "," + right + ")";
        } else {
            return "_";
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        // cout << data << endl;
        return deser(data, 0, data.size());
    }

    TreeNode* deser(const string& data, int b, int e)
    {
        // cout << "bbb: " << b << ", eee: " << e << ", data: " << data.substr(b, e - b) << endl;
        if (data[b] == '_') {
            return nullptr;
        }
        if (data[b] != '(') {
            return new TreeNode(stoi(data.substr(b, e - b)));
        }

        auto b1     = data.find_first_of(':', b + 1);
        auto root   = new TreeNode(stoi(data.substr(b + 1, b1 - b - 1)));
        auto b2     = find_quote(data, b1 + 1);
        root->left  = deser(data, b1 + 1, b2);
        root->right = deser(data, b2 + 1, e - 1);
        return root;
    }

    int find_quote(const string& data, int b)
    {
        int count = 0;
        for (int i = b;; i++) {
            if (data[i] == '(')
                count++;
            if (data[i] == ')')
                count--;
            if (count == 0 && data[i] == ',')
                return i;
        }
    }
};


int main()
{
    auto root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)),
                             new TreeNode(3, new TreeNode(6, new TreeNode(9), nullptr), new TreeNode(7)));
    // root      = new TreeNode(2, nullptr, new TreeNode(5));
    // root      = new TreeNode(1);
    cout << root << endl;

    Codec ser, deser;
    TreeNode* ans = deser.deserialize(ser.serialize(root));
    cout << ans << endl;
}

/*
        1
   2          3
    5     6     7

(1, ((2, (4,5)), (3, (6,7))))
(#)
(1, ((2, ((4),(5))), (3, ((6),(#)))))
*/