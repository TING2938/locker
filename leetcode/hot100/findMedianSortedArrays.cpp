#include "pch.h"

// TODO
// url: https://leetcode.cn/problems/median-of-two-sorted-arrays/

class Solution
{
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
    {
        int p1           = 0;
        int p2           = 0;
        auto m           = nums1.size();
        auto n           = nums2.size();
        bool p1_finished = m == 0;
        bool p2_finished = n == 0;
        int midPos       = (m + n) / 2;
        int curPos       = 0;

        while (curPos < midPos) {
            if (p1_finished) {
                p2 += (midPos - curPos);
                curPos = midPos;
                break;
            }
            if (nums1[p1] < nums2[p2]) {
                p1++;
                p1_finished = p1 > m;
            } else {
                p2++;
                p2_finished = p2 > n;
            }
            curPos++;
        }
        if ((m + n) % 2 != 0) {
            return ::min(nums1[p1], nums2[p2]);
        }

        return 0;
    }
};

TEST(leetcode, findMedianSortedArrays)
{
    Solution s;
    cout << s.findMedianSortedArrays({1, 3, 5}, {4, 6});
}
