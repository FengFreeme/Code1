#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> ans = vector<int>(nums.size());
        int left = 0, right = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int res1 = nums[left] * nums[left];
            int res2 = nums[right] * nums[right];
            if(res1 <= res2)
            {
                ans[i] = res2;
                right--;
            }
            else if (res1 > res2)
            {
                ans[i] = res1;
                left++;
            }
        }
        return ans;
    }
};