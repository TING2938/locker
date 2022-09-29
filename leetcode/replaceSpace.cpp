#include "pch.h"

// url:

class Solution
{
public:
    string replaceSpace(string s)
    {
        string ret;
        for (auto&& c : s) {
            if (c == ' ') {
                ret += "%20";
            } else {
                ret += c;
            }
        }
        return ret;
    }
};

TEST(leetcode, replaceSpace)
{
    Solution s;

    EXPECT_EQ(s.replaceSpace("hello, world"), "hello,%20world");
}
