/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */
#include <bitset>
#include "vector_utils.h"
// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        int m = 0b0101'0101'0101'0101'0101'0101'0101'0101;
        return (n > 0) && ((n & (n - 1)) == 0) && ((n & m) != 0);
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.isPowerOfFour(16777216);
}