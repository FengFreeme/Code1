#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /*
    // 快慢指针
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int ans = INT_MAX;
        int sum = nums[0];

        for (int slow = 0, fast = 0; slow < nums.size() && fast < nums.size(); )
        {
            if (sum < target)
            {
                fast++;
                if(fast < nums.size())
                    sum += nums[fast];
            }
            else if (sum >= target)
            {
                ans = min(ans, fast - slow + 1);
                sum -= nums[slow];
                slow++;
            }
        }
        if (ans == INT_MAX)
            return 0;
        else
            return ans;
    }
    */
    // 暴力解法
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int ans = INT_MAX;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum = sum + nums[j];
                if (sum >= target)
                {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        if (ans == INT_MAX)
            return 0;
        else
            return ans;
    }
};

int main()
{
    int target = 11;
    vector<int> nums = { 1,1,1,1,1,1,1,1 };
    Solution S;
    S.minSubArrayLen(target, nums);

    return 0;
}