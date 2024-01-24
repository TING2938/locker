/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int N = nums.size();
        if (N < 2) {
            return;
        }
        int i = N - 1;

        for (; i >= 1; i--) {
            if (nums[i - 1] < nums[i]) {
                break;
            }
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = N - 1;
        for (; j >= i; j--) {
            if (nums[j] > nums[i - 1]) {
                swap(nums[j], nums[i - 1]);
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums{2, 3, 1};
    // do {
    //     cout << nums << endl;
    // } while (std::next_permutation(nums.begin(), nums.end()));

    s.nextPermutation(nums);
    cout << nums << endl;
}