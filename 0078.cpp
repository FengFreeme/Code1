#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums)
    {
        backtracking(nums, 0);

        return ans;
    }
    // 1. 确定形参和返回类型
    void backtracking(vector<int>& nums, int startIndex)
    {
        // 写在终止条件前面，避免出现没有加入集合的情况
        ans.push_back(path);
        // 2. 确定终止条件
        if (startIndex == nums.size())
        {
            return;
        }
        // 3. 单次递归处理
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
};