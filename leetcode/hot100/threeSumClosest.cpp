#include "pch.h"

// url: https://leetcode.cn/problems/3sum-closest/

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int length = nums.size();
        sort(nums.begin(), nums.end());
        int ret;

        ret = nums[0] + nums[1] + nums[2];
        if (ret >= target) {
            return ret;
        }
        ret = nums[length - 1] + nums[length - 2] + nums[length - 3];
        if (ret <= target) {
            return ret;
        }

        int it_sum;
        int it_diff = abs(ret - target);
        for (auto itk = nums.begin(); itk != nums.end(); itk++) {
            auto itm = itk + 1;
            auto itn = nums.end() - 1;
            while (itm < itn) {
                it_sum        = *itk + *itm + *itn;
                auto cur_diff = abs(it_sum - target);
                if (cur_diff < it_diff) {
                    ret     = it_sum;
                    it_diff = cur_diff;
                }
                if (it_sum > target) {
                    --itn;
                } else if (it_sum < target) {
                    ++itm;
                } else {
                    return ret;
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;

    vector<int> nums;

    nums = {-1, 2, 1, -4};
    assert(s.threeSumClosest(nums, 1) == 2);

    nums = {0, 0, 0};
    assert(s.threeSumClosest(nums, 1) == 0);
}
