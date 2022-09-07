#include "pch.h"

// url:

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& s)
    {
        sort(s.begin(), s.end());
        vector<vector<int>> ret;
        for (auto itk = s.begin(); itk != s.end(); ++itk) {
            if (*itk > 0) {
                break;
            }

            auto itm = itk + 1;
            auto itn = s.end() - 1;
            while (itm < itn) {
                auto it_sum = *itk + *itm + *itn;
                if (it_sum > 0) {
                    --itn;
                } else if (it_sum < 0) {
                    ++itm;
                } else {
                    ret.push_back({*itk, *itm, *itn});
                    break;
                }
            }
        }
        return ret;
    }
};

TEST(leetcode, threeSum)
{
    Solution s;

    vector<int> vec;
    vector<vector<int>> ret;

    vec = {-1, 0, 1, 0, 2, -2};
    ret = {{-2, 0, 2}, {-1, 0, 1}};
    EXPECT_EQ(s.threeSum(vec), ret);

    vec = {-1, 0, 1, 2, -1, -4};
    ret = {{-1, -1, 2}, {-1, 0, 1}};
    EXPECT_EQ(s.threeSum(vec), ret);

    vec = {0, 0, 0};
    ret = {{0, 0, 0}};
    EXPECT_EQ(s.threeSum(vec), ret);

    vec = {0, 1, 1};
    ret = {};
    EXPECT_EQ(s.threeSum(vec), ret);
}
