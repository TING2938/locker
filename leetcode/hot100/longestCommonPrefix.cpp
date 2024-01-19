#include "pch.h"

// url: https://leetcode.cn/problems/longest-common-prefix/

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        auto str0 = strs[0];
        for (int i = 0; i < str0.size(); i++) {
            for (auto s : strs) {
                if ((i == s.size()) || s[i] != str0[i]) {
                    return str0.substr(0, i);
                }
            }
        }
        return str0;
    }
};

int main()
{
    Solution s;

    vector<string> strs;

    strs = {"flower", "flow", "flight"};
    assert(s.longestCommonPrefix(strs) == "fl");

    strs = {"dog", "racecar", "car"};
    assert(s.longestCommonPrefix(strs) == "");
}
