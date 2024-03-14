/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int m = sqrt(area);
        while (area % m != 0) {
            m--;
        }
        return {area / m, m};
    }
};
// @lc code=end
