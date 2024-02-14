/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }
        int N1 = num1.size();
        int N2 = num2.size();

        string ret;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int res = 0;
        int v1  = 0;
        int v2  = 0;
        int v3  = 0;
        for (int i = 0; i < N1; i++) {
            v1 = num1[i] - '0';
            if (i >= N2) {
                v2 = 0;
            } else {
                v2 = num2[i] - '0';
            }
            v3 = v1 + v2 + res;
            ret.push_back(v3 % 10 + '0');
            res = v3 / 10;
        }
        if (res != 0) {
            ret.push_back(res + '0');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.addStrings("79", "9898") << endl;
}