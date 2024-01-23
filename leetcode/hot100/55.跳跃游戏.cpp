/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <unordered_set>
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int max_jump = 0;
        int N        = nums.size();
        for (int i = 0; i < N; i++) {
            if (max_jump < i) {
                return false;
            }
            max_jump = max(max_jump, i + nums[i]);
            if (max_jump >= N - 1) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums{4, 3, 2, 1, 1, 4};
    cout << s.canJump(nums) << endl;
}