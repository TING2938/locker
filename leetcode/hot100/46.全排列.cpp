/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> rets;
        add(rets, nums, 0);
        return rets;
    }

    void add(vector<vector<int>>& rets, vector<int>& nums, int k)
    {
        if (k == nums.size()) {
            rets.push_back(nums);
            return;
        }
        for (int i = k; i < nums.size(); i++) {
            swap(nums[i], nums[k]);
            add(rets, nums, k + 1);
            swap(nums[i], nums[k]);
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums{1, 2, 3};
    cout << s.permute(nums) << endl;
}