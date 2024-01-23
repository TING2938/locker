/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int N = nums.size();
        if (N == 0) {
            return {-1, -1};
        }
        int b = 0;
        int e = N;
        int m = (b + e) / 2;
        while (true) {
            if (nums[m] > target) {
                e = m;
                m = (b + e) / 2;
            } else if (nums[m] < target) {
                b = m;
                m = (b + e) / 2;
            } else {
                return {
                    find_left_equal(nums, b, m, target),
                    find_right_equal(nums, m, e, target),
                };
            }
            if (b == m) {
                if (nums[b] == target) {
                    return {b, b};
                } else {
                    return {-1, -1};
                }
            }
        }
    }
    int find_left_equal(vector<int>& nums, int b, int e, int target)
    {
        if (nums[b] == target) {
            return b;
        }
        int m = (b + e) / 2;
        while (b != m) {
            if (nums[m] < target) {
                b = m;
                m = (b + e) / 2;
            } else {
                e = m;
                m = (b + e) / 2;
            }
        }
        return e;
    }

    int find_right_equal(vector<int>& nums, int b, int e, int target)
    {
        int m = (b + e) / 2;
        while (b != m) {
            if (nums[m] > target) {
                e = m;
                m = (b + e) / 2;
            } else {
                b = m;
                m = (b + e) / 2;
            }
        }
        return b;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums{};
    cout << s.searchRange(nums, 1) << endl;
}