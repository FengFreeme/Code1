#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        vector<bool> used(10, false);
        backtracking(board, used, 0, 0);

        return;
    }
private:
    // 1. ȷ���βκͷ�������
    bool backtracking(vector<vector<char>>& board, vector<bool>& used, int row, int col)
    {
        // 2. ȷ����ֹ����
        if (row == 9)
        {
            return true;
        }
        // 3. ���εݹ鴦��
        if (board[row][col] != '.')
        {
            used[board[row][col] - '0'] = true;
            if (col < 8)
            {
                if (backtracking(board, used, row, col + 1))
                    return true;
            }
            else
            {
                used = vector<bool>(10, false);
                if (backtracking(board, used, row + 1, 0))
                    return true;
            }
        }
        else
        {
            for (char c = '1'; c <= '9'; c++)
            {
                if (isValid(board, row, col, c) && used[c - '0'] == false)
                {
                    board[row][col] = c;
                    used[c - '0'] = true;
                    if (col < 8)
                    {
                        if (backtracking(board, used, row, col + 1))
                            return true;
                    }
                    else
                    {
                        used = vector<bool>(10, false);
                        if (backtracking(board, used, row + 1, 0))
                            return true;;
                    }
                    used[c - '0'] = false;
                    board[row][col] = '.';
                }
            }
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board, int x, int y, char c)
    {
        // ͬһ��
        for (int i = 0; i < 9; i++)
        {
            if (i == x)
                continue;
            if (board[i][y] == c)
                return false;
        }
        // ͬһ��
        for (int j = 0; j < 9; j++)
        {
            if (j == y)
                continue;
            if (board[x][j] == c)
                return false;
        }
        // ͬһ 3x3 ��
        int a = x / 3;
        int b = y / 3;
        for (int i = 3 * a; i < 3 * (a + 1); i++)
        {
            for (int j = 3 * b; j < 3 * (b + 1); j++)
            {
                if (i == x && j == y)
                    continue;
                if (board[i][j] == c)
                    return false;
            }
        }
        return true;
    }
};