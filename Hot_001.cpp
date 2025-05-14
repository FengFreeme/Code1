#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // 时间复杂度 O(n) 空间复杂度 O(n)
    // 不能 sort 要返回下标
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> umap;       
        for (int i = 0; i < nums.size(); ++i)       // O(n)
        {
            int num = target - nums[i];
            // 元素不存在 加入 umap
            if (umap.find(num) == umap.end())
            {
                umap[nums[i]] = i;
            }
            // 存在
            else
            {
                return { umap[num], i };
            }
        }
        return { -1, -1 };
    }
};

int main()
{
    Solution S;
    vector<int> nums = { 3,2,4 };
    S.twoSum(nums, 6);

    return 0;
}