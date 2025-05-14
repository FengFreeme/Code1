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
    // 1. ȷ���βκͷ�������
    void backtracking(vector<int>& candidates, vector<bool>& used, int startIndex, int target)
    {
        // 2. ȷ����ֹ����
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        // 3. ���εݹ鴦��
        for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            // used[i - 1] == true��˵��ͬһ��֦candidates[i - 1]ʹ�ù�
            // used[i - 1] == false��˵��ͬһ����candidates[i - 1]ʹ�ù�
            // Ҫ���ͬһ����ʹ�ù���Ԫ�ؽ�������
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
        // 2. ȷ����ֹ����
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }
        // 3. ���εݹ鴦��
        for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++)
        {
            // used[i - 1] == true��˵��ͬһ��֦candidates[i - 1]ʹ�ù�
            // used[i - 1] == false��˵��ͬһ����candidates[i - 1]ʹ�ù�
            // Ҫ���ͬһ����ʹ�ù���Ԫ�ؽ�������
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