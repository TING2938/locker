#include "list_utils.h"
#include "pch.h"
#include "tree_utils.h"
#include "vector_utils.h"

// problem 58
// url:

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        auto p1 = s.find_last_not_of(' ');
        auto p2 = s.find_last_of(' ', p1);
        return p1 - p2;
    }
};

TEST(leetcode, lengthOfLastWord)
{
    Solution s;

    cout << s.lengthOfLastWord("world ") << endl;
}
