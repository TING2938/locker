/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res(rowIndex + 1, 1);
        int N = rowIndex;

        long long tmp = 1;
        for (int i = 1; i <= rowIndex / 2; i++) {
            tmp *= (N - i + 1);
            tmp /= i;
            res[i]     = tmp;
            res[N - i] = res[i];
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.getRow(4) << endl;
}