#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);

        return ans;
    }
    // 1. ȷ���βκͷ�������
    void backtracking(vector<int>& nums, int startIndex)
    {
        // д����ֹ����ǰ�� ������©
        ans.push_back(path);
        // 2. ȷ����ֹ����
        if (startIndex == nums.size())
            return;
        // 3. ���εݹ鴦��
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > startIndex && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
};