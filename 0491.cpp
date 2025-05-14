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
    // 1. ȷ�������ͷ�������
    void backtracking(vector<int>& nums, int startIndex)
    {
        // �ȼ��뼯��
        if (path.size() >= 2)
            ans.push_back(path);
        // 2. ȷ����ֹ����
        if (startIndex == nums.size())
            return;
        // ʹ��usetȥ��
        // ÿ�ζ������¶�������
        unordered_set<int> uset;
        // 3. ���εݹ鴦��
        for (int i = startIndex; i < nums.size(); i++)
        {
            // ʹ�� uset �Ա���Ԫ��ȥ��
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