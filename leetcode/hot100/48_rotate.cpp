#include "list_utils.h"
#include "pch.h"
#include "vector_utils.h"

// problem 48
// url: https://leetcode.cn/problems/rotate-image/

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        reverse(matrix.begin(), matrix.end());
        int N = matrix.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main()
{
    Solution s;

    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    cout << matrix << endl;

    s.rotate(matrix);

    cout << matrix << endl;
}
