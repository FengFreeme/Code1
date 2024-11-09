#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int num0 = count0(strs[0]);
        int num1 = strs[0].size() - num0;
        for (int i = num0; i <= m; ++i)
        {
            for (int j = num1; j <= n; ++j)
            {
                dp[i][j] = 1;
            }
        }
        for (int i = 1; i < strs.size(); ++i)
        {
            num0 = count0(strs[i]);
            num1 = strs[i].size() - num0;
            for (int j = m; j >= num0; --j)
            {
                for (int k = n; k >= num1; --k)
                {
                    dp[j][k] = max(dp[j][k], dp[j - num0][k - num1] + 1);
                }
            }
        }
        return dp[m][n];
    }
private:
    int count0(string& strs)
    {
        int counts = 0;
        for (auto s : strs)
        {
            if (s == '0')
                ++counts;
        }
        return counts;
    }
};

int main()
{
    vector<string> strs = { "10", "0001", "111001", "1", "0" };
    int m = 5, n = 3;

    Solution S;
    S.findMaxForm(strs, m, n);

    return 0;
}