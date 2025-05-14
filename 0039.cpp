#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    // ������������ݳ�Ա
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, target);

        return ans;
    }

    // 1. ȷ���βκͷ�������
    void backtracking(vector<int>& candidates, int startIndex, int target)
    {
        // 2. ȷ����ֹ����
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        // 3. ���εݹ鴦��
        // ���˼�֦�Ż�
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