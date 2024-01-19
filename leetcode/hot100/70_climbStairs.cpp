#include "list_utils.h"
#include "pch.h"
#include "tree_utils.h"
#include "vector_utils.h"

// problem 70
// url:

class Solution
{
public:
    map<int, int> mem;
    int climbStairs(int n)
    {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        auto p = mem.find(n);
        if (p != mem.end()) {
            return p->second;
        }
        int ret = climbStairs(n - 1) + climbStairs(n - 2);
        mem[n]  = ret;
        return ret;
    }
};

int main()
{
    Solution s;

    cout << s.climbStairs(3) << endl;
}