#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        backtracking(1, k, n);

        return ans;
    }
    // 1. ȷ���βκͷ�������
    void backtracking(int startIndex, int k, int n)
    {
        // 2. ȷ����ֹ����
        if (path.size() == k)
        {
            if (n == 0)
            {
                ans.push_back(path);
                return;
            }
            else
                return;
        }
        else if (n <= 0)
            return;
        // 3. ���εݹ鴦��
        // n �ǿ����õ����ָ�����k - path.size()�ǻ���Ҫ�����ָ��� ʣ�����ֲ���Ҳû��Ҫ����������
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
        {
            n -= i;
            path.push_back(i);
            backtracking(i + 1, k, n);
            path.pop_back();
            n += i;
        }
        return;
    }
};

int main()
{
    Solution S;
    S.combinationSum3(3, 9);

    return 0;
}