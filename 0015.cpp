#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    /*
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        unordered_set<int> uset;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                break;
            // 前面使用过的相同的数值直接跳过，避免出现重复的三元组 元素 a 去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                // 前面使用过的相同的数值直接跳过，避免出现重复的三元组 元素 b 去重 不理解
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])
                    continue;
                int target = 0 - nums[i] - nums[j];
                if (uset.find(target) != uset.end())
                {
                    ans.push_back({ nums[i], nums[j], target });
                    // 避免重复使用 元素 c 去重
                    uset.erase(target);
                }
                else
                {
                    uset.insert(nums[j]);
                }
            }
        }
        return ans;
    }
    */
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                break;
            // i 去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = n - 1;
           
            int target = 0 - nums[i];
            while (j < k)
            {
                if (nums[j] + nums[k] == target)
                {
                    ans.push_back({ nums[i], nums[j], nums[k] });
                    j++;
                    k--;
                    // j k 去重
                    while (j > i + 1 && j < k && nums[j] == nums[j - 1])
                        j++;
                    while (k < n - 1 && k < k && nums[k] == nums[k + 1])
                        k--;
                }
                else if (nums[j] + nums[k] > target)
                {
                    k--;
                }
                else if (nums[j] + nums[k] < target)
                {
                    j++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 0,0,0 };
    Solution  S;
    S.threeSum(nums);

    return 0;
}