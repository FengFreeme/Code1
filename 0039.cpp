#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    // 属于类对象数据成员
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, target);

        return ans;
    }

    // 1. 确定形参和返回类型
    void backtracking(vector<int>& candidates, int startIndex, int target)
    {
        // 2. 确定终止条件
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        // 3. 单次递归处理
        // 加了剪枝优化
        for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            target -= candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, i, target);
            path.pop_back();
            target += candidates[i];
        }
        return;
    }
};

int main()
{
    vector<int> candidates = { 8,7,4,3 };
    int target = 11;
    Solution S;
    S.combinationSum(candidates, target);

    return 0;
}