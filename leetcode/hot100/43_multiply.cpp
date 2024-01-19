#include "list_utils.h"
#include "pch.h"
#include "tree_utils.h"
#include "vector_utils.h"

// problem 43
// url: https://leetcode.cn/problems/multiply-strings/description/

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int n1 = num1.size();
        int n2 = num2.size();

        string ret = "0";
        for (int i = n1 - 1; i >= 0; i--) {
            int x = num1[i] - '0';
            string tmp;
            int res = 0;
            for (int j = n2 - 1; j >= 0; j--) {
                int y = num2[j] - '0';
                int z = x * y + res;
                tmp.push_back(z % 10 + '0');
                res = z / 10;
            }
            if (res != 0) {
                tmp.push_back(res + '0');
            }
            // reverse(tmp.begin(), tmp.end());
            cout << n1 - i - 1 << ": " << tmp << endl;
            ret = string_add(ret, tmp, n1 - i - 1);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    string string_add(string s1, string s2, int offset)
    {
        s2 = string(offset, '0') + s2;
        if (s1 == "0")
            return s2;
        if (s2 == "0")
            return s1;

        int m = s1.size();
        int n = s2.size();
        if (m < n) {
            s1.append(n - m, '0');
            m = n;
        } else {
            s2.append(m - n, '0');
            n = m;
        }
        int res = 0;
        string ans;
        for (int i = 0; i < m; i++) {
            int x = s1[i] - '0';
            int y = s2[i] - '0';
            int z = x + y + res;
            ans.push_back(z % 10 + '0');
            res = z / 10;
        }
        if (res != 0) {
            ans.push_back(res + '0');
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.multiply("990", "0") << endl;
}

/*
    3 4
    6 7
-----------
  2 3 8
2 0 4
-----------
2 2 7 8


    9 9
    9 9
-----------
  8 9 1
8 9 1
-----------
9 8 0 1

*/