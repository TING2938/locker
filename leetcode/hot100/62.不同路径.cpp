/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include "vector_utils.h"

// @lc code=start
class Solution
{
public:
    unordered_map<int, int> memory;
    int uniquePaths(int m, int n)
    {
        return get_path(m - 1, n - 1);
    }

    int get_path(int p, int q)
    {
        if (p == 0 && q == 0) {
            return 1;
        }
        if (p > q) {
            swap(p, q);
        }
        if (auto it = memory.find(p * 100 + q); it != memory.end()) {
            return it->second;
        }
        int res = 0;
        if (p > 0) {
            res += get_path(p - 1, q);
        }
        if (q > 0) {
            res += get_path(p, q - 1);
        }

        memory[p * 100 + q] = res;
        return res;
    }
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
}