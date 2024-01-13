#include "pch.h"

// https://leetcode.cn/problems/roman-to-integer/

class Solution
{
    int charset(char c)
    {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }

public:
    int romanToInt(string s)
    {
        int cur = 0;
        int pre = charset(s[0]);
        int ret = 0;
        for (int i = 1; i < s.size(); i++) {
            cur = charset(s[i]);
            if (pre < cur) {
                ret -= pre;
            } else {
                ret += pre;
            }
            pre = cur;
        }
        ret += pre;
        return ret;
    }
};

TEST(leetcode, romanToInt)
{
    Solution s;

    EXPECT_EQ(s.romanToInt("III"), 3);
    EXPECT_EQ(s.romanToInt("IV"), 4);
    EXPECT_EQ(s.romanToInt("IX"), 9);
    EXPECT_EQ(s.romanToInt("LVIII"), 58);
    EXPECT_EQ(s.romanToInt("MCMXCIV"), 1994);
}
