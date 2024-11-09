#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());

        backtracking(candidates, 0, target);

        return ans;
    }
    /*
    // 1. 确定形参和返回类型
    void backtracking(vector<int>& candidates, vector<bool>& used, int startIndex, int target)
    {
        // 2. 确定终止条件
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        // 3. 单次递归处理
        for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要求对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
                continue;
            target -= candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, used, i + 1, target);
            used[i] = false;
            path.pop_back();
            target += candidates[i];
        }
    }
    */
    void backtracking(vector<int>& candidates, int startIndex, int target)
    {
        // 2. 确定终止条件
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        // 3. 单次递归处理
        for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要求对同一树层使用过的元素进行跳过
            if (i > startIndex && candidates[i] == candidates[i - 1])
                continue;
            target -= candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, i + 1, target);
            path.pop_back();
            target += candidates[i];
        }
    }
};

int main()
{
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    int target = 8;

    Solution S;
    S.combinationSum2(candidates, target);

    return 0;
}