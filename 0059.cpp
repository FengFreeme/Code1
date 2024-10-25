#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int dir[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
    /*
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        // 定义每一个圈的起始位置
        int startx = 0, starty = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
        // 控制每一条边遍历长度，每次循环有边界收缩一位
        int offset = 1;

        int i, j;
        while (loop--)
        {
            i = startx;
            j = starty;
            // 4 个 for 模拟转一圈
            for (j; j < n - offset; j++)
            {
                ans[i][j] = count++;
            }
            for (i; i < n - offset; i++)
            {
                ans[i][j] = count++;
            }
            for (j; j > starty; j--)
            {
                ans[i][j] = count++;
            }
            for (i; i > startx; i--)
            {
                ans[i][j] = count++;
            }
            // 下一圈开始，起始位置要各自 + 1
            startx++;
            starty++;

            offset += 1;
        }
        if (n % 2 == 1)
        {
            ans[mid][mid] = count;
        }
        return ans;
    }
    */
    // 行走模式
    vector<vector<int>> generateMatrix(int n)
    {
        int count = 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int mode = 0;
        int x = 0, y = 0;
        while (1)
        {
            ans[x][y] = count;
            if (count == n * n)
                break;
            int nextx = x + dir[mode][0];
            int nexty = y + dir[mode][1];
            if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && ans[nextx][nexty] == 0)
            {
                x = nextx;
                y = nexty;
                count++;
            }
            else
            {
                mode = (mode + 1) % 4;
            }
        }
        return ans;
    }
};

int main()
{
    int n = 3;
    Solution S;
    S.generateMatrix(n);

    return 0;
}