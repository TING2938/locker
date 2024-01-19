#include "pch.h"

// url:

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {
        int m   = matrix.front().size();
        int row = matrix.size() - 1;
        int col = 0;
        while (row >= 0 && col < m) {
            int cur = matrix[row][col];
            if (cur == target) {
                return true;
            } else if (cur < target) {
                col++;
            } else {
                row--;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> matrix;

    matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
    };
    assert(s.findNumberIn2DArray(matrix, 18));
}