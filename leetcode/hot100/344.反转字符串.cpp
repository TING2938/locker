/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            s[i] = s[i] ^ s[j];
            s[j] = s[i] ^ s[j];
            s[i] = s[i] ^ s[j];
        }
    }
};
// @lc code=end
