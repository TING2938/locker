/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include "pch.h"
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        if (nums.empty()) {
            return 0;
        }
        auto p1 = nums.begin();
        auto p2 = nums.end() - 1;
        while (true) {
            if (*p1 == val) {
                for (;;) {
                    if (p2 == p1) {
                        return p1 - nums.begin();
                    }
                    if (*p2 != val) {
                        break;
                    }
                    --p2;
                }
                swap(*p1, *p2);
            }
            ++p1;
            if (p1 == nums.end()) {
                return p1 - nums.begin();
            }
        }
    }
};
// @lc code=end


int main()
{
    Solution s;
    vector<int> input{};
    cout << s.removeElement(input, 4) << endl;
    cout << input << endl;
}