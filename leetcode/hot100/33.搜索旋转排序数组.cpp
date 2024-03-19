/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int N = nums.size();
        if (N == 1)
            return nums[0] == target ? 0 : -1;
        int b = 0;
        int e = N - 1;
        int m = (b + e) / 2;

        while (b <= e) {
            if (nums[m] == target)
                return m;
            if (nums[b] <= nums[m]) {  // [b-m]有序
                if (nums[b] <= target && target < nums[m]) {
                    e = m - 1;
                    m = (b + e) / 2;
                } else {
                    b = m + 1;
                    m = (b + e) / 2;
                }
            } else {  // [m-e]有序
                if (nums[m] < target && target <= nums[e]) {
                    b = m + 1;
                    m = (b + e) / 2;
                } else {
                    e = m - 1;
                    m = (b + e) / 2;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> v{3, 1};
    s.search(v, 0);
}