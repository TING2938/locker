#include "pch.h"

// url: https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

/**
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
*/

class Solution
{
public:
    vector<string> letterCombinations2(string digits)
    {
        if (digits.empty()) {
            return {};
        }
        vector<string> ret;
        vector<string> origin;
        for (auto c : digits) {
            origin.push_back(digitMap[c]);
        }
        vector<int> index(digits.size(), 0);
        int cur = 0;
        while (true) {
            ret.push_back(makeEle(origin, index));
            index[cur]++;
            if (index[cur] == origin[cur].size()) {
                while (true) {
                    cur++;
                    if (cur == index.size())
                        return ret;
                    index[cur]++;
                    if (index[cur] != origin[cur].size())
                        break;
                }
                std::fill(index.begin(), index.begin() + cur, 0);
                cur = 0;
            }
        }
        return ret;
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;
        string ele;
        if (digits.empty()) {
            return ret;
        }
        backtrace(ret, ele, 0, digits);
        return ret;
    }

private:
    string makeEle(const vector<string>& origin, const vector<int>& index)
    {
        string ret = "";
        for (int i = 0; i < index.size(); i++) {
            ret += origin[i][index[i]];
        }
        return ret;
    }

    void backtrace(vector<string>& ret, string& ele, int ndx, const string& digits)
    {
        if (ndx == digits.size()) {
            ret.push_back(ele);
            return;
        }
        for (auto& d : digitMap[digits[ndx]]) {
            ele.push_back(d);
            backtrace(ret, ele, ndx + 1, digits);
            ele.pop_back();
        }
    }

    map<char, string> digitMap{
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
};

TEST(leetcode, letterCombinations)
{
    Solution s;
    EXPECT_EQ(s.letterCombinations("23"), vector<string>{});
}
