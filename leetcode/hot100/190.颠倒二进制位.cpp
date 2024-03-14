/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

#include <bitset>
#include "vector_utils.h"
// @lc code=start

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        bitset<32> b(n);
        int i = 0;
        int j = 31;
        for (; i < j;) {
            b[i] = b[i] ^ b[j];
            b[j] = b[i] ^ b[j];
            b[i] = b[i] ^ b[j];
            i++;
            j--;
        }
        return b.to_ullong();
    }
};
// @lc code=end
