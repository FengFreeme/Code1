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
    // 1. ȷ���βκͷ�������
    void backtracking(vector<string>& queen, int row)
    {
        // 2. ȷ����ֹ����
        if (row == queen.size())
        {
            ans.push_back(queen);
            return;
        }
        // 3. ���εݹ鴦��
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
        // ͬһ���Ƿ��ظ� ��Ϊ�ǰ��з��õ� ����ͬһ�в����ظ�
        for (int i = 0; i < x; i++)
        {
            if (queen[i][y] == 'Q')
                return false;
        }
        // �Խ���
        // �ҶԽ���
        int i = x - 1, j = y - 1;
        while (i >= 0 && j >= 0)
        {
            if (queen[i][j] == 'Q')
                return false;
            --i, --j;
        }
        // ��Խ���
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