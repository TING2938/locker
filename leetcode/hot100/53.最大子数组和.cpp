/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        vector<int> mem(nums.size());
        mem[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (mem[i - 1] < 0) {
                mem[i] = nums[i];
            } else {
                mem[i] = mem[i - 1] + nums[i];
            }
        }
        return *max_element(mem.begin(), mem.end());
    }
};
// @lc code=end
