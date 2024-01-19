#include "pch.h"

// url: https://leetcode.cn/problems/longest-palindromic-substring/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int max_length = 1;
        auto it_beg    = s.begin();
        auto it_end    = s.begin() + 1;

        for (auto it = s.begin(); it < s.end() - 1;) {
            auto it1 = find_if(it + 1, s.end(), [=](char c) { return c != *it; });
            auto ib  = it - 1;
            auto ie  = it1;
            while (ib >= s.begin() && ie < s.end() && *ib == *ie) {
                --ib;
                ++ie;
            }
            ++ib;
            auto cur_length = ie - ib;
            if (max_length < cur_length) {
                max_length = cur_length;
                it_beg     = ib;
                it_end     = ie;
            }
            it = it1;
        }
        return {it_beg, it_end};
    }
};

int main()
{
    Solution s;

    assert(s.longestPalindrome("bbbbb") == "bbbbb");
    assert(s.longestPalindrome("babad") == "bab");
    assert(s.longestPalindrome("cbbd") == "bb");
}
