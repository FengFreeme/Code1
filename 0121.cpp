#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() == 1)
            return 0;
        vector<int> profit(prices.size() - 1, 0);
        for (int i = 1; i < prices.size(); ++i)
            profit[i - 1] = prices[i] - prices[i - 1];

        vector<int> dp(profit.size(), 0);
        dp[0] = profit[0];
        int ans = 0;
        ans = max(dp[0], ans);
        for (int i = 1; i < profit.size(); ++i)
        {
            dp[i] = dp[i - 1] + profit[i];

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    vector<int> prices = { 7,1,5,3,6,4 };

    Solution S;
    S.maxProfit(prices);

    return 0;
}