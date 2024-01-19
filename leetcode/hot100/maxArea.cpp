#include "pch.h"

// url: https://leetcode.cn/problems/container-with-most-water/submissions/

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        auto ib  = height.begin();
        auto ie  = height.end() - 1;
        int area = 0;
        while (ib < ie) {
            area = max<int>(area, min(*ib, *ie) * (ie - ib));
            if (*ib > *ie) {
                --ie;
            } else {
                ++ib;
            }
        }
        return area;
    }
};

int main()
{
    Solution s;
    vector<int> height;


    height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(s.maxArea(height) == 49);

    height = {1, 1};
    assert(s.maxArea(height) == 1);
}