#include "pch.h"

// url: https://leetcode.cn/problems/3sum/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& s)
    {
        sort(s.begin(), s.end());
        int N = s.size();
        vector<vector<int>> ret;
        // i, j, k
        for (int i = 0; i < N - 2; increase(i, s)) {
            int k = N;
            for (int j = i + 1; j < k; increase(j, s)) {
                for (; k > j; k--) {
                    int tsum = s[i] + s[j] + s[k];
                    if (tsum > 0) {
                        continue;
                    }
                    if (tsum == 0) {
                        ret.push_back({s[i], s[j], s[k]});
                    }
                    break;
                }
            }
        }
        return ret;
    }

private:
    void increase(int& idx, const vector<int>& s)
    {
        int origin = s[idx];
        idx++;
        while (idx < s.size() && s[idx] == origin) {
            idx++;
        }
    }
};

int main()
{
    Solution s;

    vector<int> vec;
    vector<vector<int>> ret;

    vec = {-1, 0, 1, 0, 2, -2};
    ret = {{-2, 0, 2}, {-1, 0, 1}};
    assert(s.threeSum(vec) == ret);

    vec = {-1, 0, 1, 2, -1, -4};
    ret = {{-1, -1, 2}, {-1, 0, 1}};
    assert(s.threeSum(vec) == ret);

    vec = {0, 0, 0};
    ret = {{0, 0, 0}};
    assert(s.threeSum(vec) == ret);

    vec = {0, 1, 1};
    ret = {};
    assert(s.threeSum(vec) == ret);
}
