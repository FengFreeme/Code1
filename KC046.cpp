#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> weight(m, 0);
    vector<int> value(m, 0);
    vector<vector<int>> dp(m, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i)
        cin >> weight[i];
    for (int i = 0; i < m; ++i)
        cin >> value[i];

    for (int j = weight[0]; j <= n; ++j)
    {
        dp[0][j] = value[0];
    }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    cout << dp[m - 1][n] << endl;

    return 0;
}