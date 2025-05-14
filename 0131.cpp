#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<string>> ans;
    vector<string> path;
    bool isHuiwen(string& s)
    {
        string t(s);
        reverse(t.begin(), t.end());
        return s == t;
    }
    vector<vector<string>> partition(string s) 
    {
        backtracking(s, 0);

        return ans;
    }
    // 1. ȷ�������ͷ�������
    void backtracking(string& s, int startIndex)
    {
        // 2. ȷ����ֹ����
        if (startIndex == s.size() && !path.empty())
        {
            ans.push_back(path);
            return;
        }
        // 3. ���εݹ鴦��
        for (int len = 1; startIndex + len <= s.size(); len++)
        {
            string s1(s.begin() + startIndex, s.begin() + startIndex + len);
            if (isHuiwen(s1))
            {
                path.push_back(s1);
                backtracking(s, startIndex + len);
                path.pop_back();
            }
        }
    }
};

int main()
{
    string s = "bb";
    Solution S;
    S.partition(s);

    return 0;
}