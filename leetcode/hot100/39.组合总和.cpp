/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        auto p = find_if(candidates.begin(), candidates.end(), [target](int v) { return v > target; });
        candidates.erase(p, candidates.end());
        vector<vector<int>> rets;
        vector<int> ret;
        bt(rets, ret, 0, 0, candidates, target);
        return rets;
    }

    void bt(vector<vector<int>>& rets, vector<int>& ret, int cur_sum, int beg, vector<int>& cond, int target)
    {
        for (int i = beg; i < cond.size(); i++) {
            int tmp_sum = cur_sum + cond[i];
            if (tmp_sum > target) {
                return;
            } else if (tmp_sum == target) {
                rets.push_back(ret);
            } else {
                auto r = ret;
                r.push_back(cond[i]);
                bt(rets, r, cur_sum, beg, cond, target);
            }
        }
    }
};
// @lc code=end

int main() {}
