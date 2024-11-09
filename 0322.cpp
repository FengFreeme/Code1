#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0)
            return 0;
        vector<int> dp(amount + 1, INT_MAX - 1);

        dp[0] = 0;
        for (int j = 1; j <= amount; ++j)
        {
            if (j % coins[0] == 0)
                dp[j] = j / coins[0];
        }
        for (int i = 1; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                if (j - coins[i] == 0 && dp[j] == 0 && dp[j - coins[i]] == 0)
                    dp[j] = 1;
                else
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] != INT_MAX - 1)
            return dp[amount];
        else
            return -1;
    }
};

int main()
{
    vector<int> coins = { 2,5,10,1 };
    int amount = 27;

    Solution S;
    S.coinChange(coins, amount);

    return 0;
}