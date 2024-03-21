/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <unordered_set>
#include "vector_utils.h"
// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        std::unordered_set<int> hash{nums.begin(), nums.end()};

        int ret  = 0;
        for (int i = 0; i < nums.size(); i++) {
            int r = 1;
            if (hash.contains(nums[i] - 1)) {
                continue;
            }
            for (int j = 1;; j++) {
                if (hash.contains(nums[i] + j)) {
                    r++;
                } else {
                    break;
                }
            }
            ret = max(ret, r);
        }
        return ret;
    }
};
// @lc code=end
