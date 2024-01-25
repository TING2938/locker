/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include "vector_utils.h"
// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.empty()) {
            return true;
        }
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (!norm(s[i]) && i < j) {
                i++;
            }
            while (!norm(s[j]) && i < j) {
                j--;
            }
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }

    bool norm(char& c)
    {
        if (c >= 'a' && c <= 'z') {
            return true;
        }
        if (c >= '0' && c <= '9') {
            return true;
        }
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
            return true;
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.isPalindrome("0P") << endl;
}