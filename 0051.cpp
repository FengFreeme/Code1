#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> queen(n, string(n, '.'));

        backtracking(queen, 0);

        return ans;
    }
private:
    // 1. 确定形参和返回类型
    void backtracking(vector<string>& queen, int row)
    {
        // 2. 确定终止条件
        if (row == queen.size())
        {
            ans.push_back(queen);
            return;
        }
        // 3. 单次递归处理
        for (int col = 0; col < queen.size(); col++)
        {
            if (isValid(queen, row, col))
            {
                queen[row][col] = 'Q';
                backtracking(queen, row + 1);
                queen[row][col] = '.';
            }
        }
        return;
    }
    bool isValid(vector<string>& queen, int x, int y)
    {
        // 同一列是否重复 因为是按行放置的 所以同一行不会重复
        for (int i = 0; i < x; i++)
        {
            if (queen[i][y] == 'Q')
                return false;
        }
        // 对角线
        // 右对角线
        int i = x - 1, j = y - 1;
        while (i >= 0 && j >= 0)
        {
            if (queen[i][j] == 'Q')
                return false;
            --i, --j;
        }
        // 左对角线
        i = x - 1, j = y + 1;
        while (i >= 0 && j < queen.size())
        {
            if (queen[i][j] == 'Q')
                return false;
            --i, ++j;
        }
        return true;
    }
};