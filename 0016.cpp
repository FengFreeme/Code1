#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > target && (nums[i] >= 0 || target >= 0))
                break;
            // 元素 a 去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                // 元素 b 去重
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                long long int _target = (long long int)target - (long long int)nums[i] - (long long int)nums[j];
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    if ((long long int)nums[left] + (long long int)nums[right] == _target)
                    {
                        ans.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        left++;
                        right--;
                        while (left > j + 1 && left < right && nums[left] == nums[left - 1])
                            left++;
                        while (right < n - 1 && left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if ((long long int)nums[left] + (long long int)nums[right] < _target)
                        left++;
                    else if ((long long int)nums[left] + (long long int)nums[right] > _target)
                        right--;
                }
            }
        }
        return ans;
    }
};