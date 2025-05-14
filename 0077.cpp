#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> path;
        backtracking(1, n, k, path);

        return ans;
    }
    // 1. ȷ���βκͷ�������
    void backtracking(int m, int n, int k, vector<int>& path)
    {
        // 2. ȷ����ֹ����
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }
        // 3. ���εݹ鴦�� ��֦�Ż�
        for(int i = m; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            backtracking(i + 1, n, k, path);
            path.pop_back();
        }
        return;
    }
};

int main()
{
    int n = 4, k = 2;
    Solution S;
    S.combine(n, k);

    return 0;
}