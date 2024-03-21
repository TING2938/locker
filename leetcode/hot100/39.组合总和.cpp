/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include "vector_utils.h"

/*

1. sort
2.
    num[i] > t   ==> m[0..i-1, t]
    num[i] == t  ==> m[0..i-1, t] + [i]
    num[i] < t   ==> {m[0..i, t-num[i]] + num[i]} + {m[0..i-1, t]}
*/

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        return bt(candidates, candidates.size() - 1, target);
    }

    vector<vector<int>> bt(vector<int>& cand, int e, int target)  // get result from [0, e]
    {
        if (e < 0 || target < 2) {
            return {};
        }
        if (e == 0) {
            if (cand[0] <= target) {
                if (target % cand[0] == 0) {
                    return {vector<int>(target / cand[0], cand[0])};
                } else
                    return {};
            } else
                return {};
        }

        if (cand[e] > target) {
            return bt(cand, e - 1, target);
        } else if (cand[e] == target) {
            auto ret = bt(cand, e - 1, target);
            ret.push_back({target});
            return ret;
        } else {
            auto ret = bt(cand, e, target - cand[e]);
            if (!ret.empty()) {
                for (auto&& r : ret)
                    r.push_back(cand[e]);
            }
            auto ret2 = bt(cand, e - 1, target);
            for (auto&& r : ret2) {
                ret.push_back(move(r));
            }
            return ret;
        }
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> cand{2, 3, 6, 7};
    cout << s.combinationSum(cand, 7) << endl;
}
