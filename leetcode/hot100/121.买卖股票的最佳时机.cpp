/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "pch.h"

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int min_price = INT_MAX;
        int ret       = 0;
        for (int i = 0; i < prices.size(); i++) {
            min_price = min(min_price, prices[i]);
            ret       = max(ret, prices[i] - min_price);
        }
        return ret;
    }
};
// @lc code=end

int main()
{
    Solution s;

    vector input{3, 3, 5, 0, 0, 3, 1, 4};
    cout << s.maxProfit(input) << endl;
}