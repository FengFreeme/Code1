#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);

        return ans;
    }
    // 1. ȷ���βκͷ�������
    void backtracking(vector<int>& nums, vector<bool>& used)
    {
        // 2. ȷ����ֹ����
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }
        unordered_set<int> uset;
        // 3. ���εݹ鴦��
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == true || uset.find(nums[i]) != uset.end())
                continue;
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
        return;
    }
};