/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> ret(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    ret[i] = max(ret[i], ret[j] + 1);
                }
            }
        }
        return *max_element(ret.begin(), ret.end());
    }
};
// @lc code=end
