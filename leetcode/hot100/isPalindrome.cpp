#include "pch.h"

// url: https://leetcode.cn/problems/palindrome-number/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }
        vector<int> v;
        while (x > 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        auto ib = v.begin();
        auto ie = v.end() - 1;
        while (ib <= ie) {
            if (*ib != *ie) {
                return false;
            }
            ++ib;
            --ie;
        }
        return true;
    }
};

int main()
{
    Solution s;

    assert(s.isPalindrome(121));
    assert(s.isPalindrome(123321));
    assert(s.isPalindrome(122));
    assert(s.isPalindrome(123421));
}
