/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> rets{{1}};
        for (int i = 1; i < numRows; i++) {
            vector<int> ret(i + 1, 1);
            for (int j = 0; j < rets[i - 1].size() - 1; j++) {
                ret[j + 1] = rets[i - 1][j] + rets[i - 1][j + 1];
            }
            rets.push_back(std::move(ret));
        }
        return rets;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.generate(4) << endl;
}