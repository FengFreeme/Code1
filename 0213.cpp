#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);

        int res1 = robExample(nums, 0, nums.size() - 2);
        int res2 = robExample(nums, 1, nums.size() - 1);

        return max(res1, res2);
    }

    int robExample(vector<int>& nums, int start, int end)
    {
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start + 1] = max(dp[start], nums[start + 1]);
        for (int i = start + 2; i <= end; ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return nums[end];
    }
};

int main()
{
    vector<int> nums = { 1,2,3,1 };
    Solution S;
    S.rob(nums);

    return 0;
}