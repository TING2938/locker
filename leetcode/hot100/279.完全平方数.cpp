/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> all_results(n + 1, 0);  // n=i时，所需要的步数
        for (int i = 1; i <= n; i++) {
            all_results[i] = n;
            for (int j = 1; j <= sqrt(i); j++) {
                all_results[i] = min(all_results[i], all_results[i - j * j] + 1);
            }
        }
        return all_results[n];
    }
};
// @lc code=end
int main()
{
    Solution s;
    cout << s.numSquares(5);
}