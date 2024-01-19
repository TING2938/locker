#include "pch.h"

// url: https://leetcode.cn/problems/generate-parentheses/

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;

        string str;
        gens(ans, str, n, n);
        return ans;
    }

    void gens(vector<string>& ans, const string& str, int left, int right)
    {
        if (left == 0 && right == 0) {
            ans.push_back(str);
            return;
        }

        if (left > 0) {
            gens(ans, str + '(', left - 1, right);
        }
        if (right > left) {
            gens(ans, str + ')', left, right - 1);
        }
    }
};

int main()
{
    Solution s;
    auto ret = s.generateParenthesis(2);
    for (auto&& r : ret) {
        cout << r << " ";
    }
    cout << endl;
}
