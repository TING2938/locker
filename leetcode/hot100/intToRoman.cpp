#include "pch.h"

// url: https://leetcode.cn/problems/integer-to-roman/

class Solution
{
public:
    string intToRoman(int num)
    {
        string ret = "";

        int a = 0;

#define S_PROCESS(value, sign)  \
    a = num / value;            \
    if (a > 0) {                \
        ret += string(a, sign); \
        num -= a * value;       \
    }

#define M_PROCESS(value, sign) \
    a = num / value;           \
    if (a == 1) {              \
        ret += sign;           \
        num -= value;          \
    }

        S_PROCESS(1000, 'M');
        M_PROCESS(900, "CM");
        S_PROCESS(500, 'D');
        M_PROCESS(400, "CD");
        S_PROCESS(100, 'C');
        M_PROCESS(90, "XC");
        S_PROCESS(50, 'L');
        M_PROCESS(40, "XL");
        S_PROCESS(10, 'X');
        M_PROCESS(9, "IX");
        S_PROCESS(5, 'V');
        M_PROCESS(4, "IV");
        S_PROCESS(1, 'I');
        return ret;
    }
};

int main()
{
    Solution s;

    assert(s.intToRoman(1994) == "MCMXCIV");
    assert(s.intToRoman(58) == "LVIII");
    assert(s.intToRoman(9) == "IX");
    assert(s.intToRoman(4) == "IV");
    assert(s.intToRoman(3) == "III");
}