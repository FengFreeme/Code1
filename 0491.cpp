#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        backtracking(nums, 0);

        return ans;
    }
    // 1. 确定参数和返回类型
    void backtracking(vector<int>& nums, int startIndex)
    {
        // 先加入集合
        if (path.size() >= 2)
            ans.push_back(path);
        // 2. 确定终止条件
        if (startIndex == nums.size())
            return;
        // 使用uset去重
        // 每次都会重新定义而清空
        unordered_set<int> uset;
        // 3. 单次递归处理
        for (int i = startIndex; i < nums.size(); i++)
        {
            // 使用 uset 对本层元素去重
            if ((uset.find(nums[i]) != uset.end()) || (path.size() > 0 && nums[i] < path[path.size() - 1]))
                continue;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
};