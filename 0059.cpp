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
        // ����ÿһ��Ȧ����ʼλ��
        int startx = 0, starty = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
        // ����ÿһ���߱������ȣ�ÿ��ѭ���б߽�����һλ
        int offset = 1;

        int i, j;
        while (loop--)
        {
            i = startx;
            j = starty;
            // 4 �� for ģ��תһȦ
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
            // ��һȦ��ʼ����ʼλ��Ҫ���� + 1
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
    // ����ģʽ
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