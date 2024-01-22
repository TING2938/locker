/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](auto& v1, auto& v2) { return v1[0] < v2[0]; });
        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size();) {
            ret.push_back(intervals[i]);
            for (i = i + 1; i < intervals.size(); i++) {
                if (ret.back()[1] >= intervals[i][0]) {
                    ret.back()[1] = max(ret.back()[1], intervals[i][1]);
                } else {
                    break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

int main()
{
    Solution s;

    vector<vector<int>> inputs{
        {2, 6},
        {1, 3},

        {8, 10},
        {15, 18},
    };
    cout << s.merge(inputs) << endl;
}