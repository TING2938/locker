#include "pch.h"

// url: https://leetcode.cn/problems/zigzag-conversion/

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) {
            return s;
        }
        int T = 2 * numRows - 2;
        vector<int> index(T, 0);
        iota(index.begin(), index.begin() + numRows, 0);
        for (int i = numRows; i < T; i++) {
            index[i] = index[i - 1] - 1;
        }
        vector<string> rows(numRows);
        for (int i = 0; i < s.size(); i++) {
            rows[index[i % T]].push_back(s[i]);
        }
        return accumulate(rows.begin(), rows.end(), string());
    }
};

TEST(leetcode, convert)
{
    Solution s;

    EXPECT_EQ(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    EXPECT_EQ(s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
    EXPECT_EQ(s.convert("A", 1), "A");
}
