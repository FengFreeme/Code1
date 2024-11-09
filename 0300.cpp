#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int ans = dp[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int max_len = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    max_len = max(max_len, dp[j] + 1);
                }
            }
            dp[i] = max_len;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 1,3,6,7,9,4,10,5,6 };

    Solution S;
    S.lengthOfLIS(nums);

}