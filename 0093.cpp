#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    vector<string> ans;
    string path;
    vector<string> restoreIpAddresses(string s) 
    {
        backtracking(s, 0, 0);

        return ans;
    }
    // 1. ȷ�������ͷ�������
    void backtracking(string& s, int startIndex, int count)
    {
        // 2. ȷ����ֹ����
        if (startIndex == s.size() && count == 4)
        {
            ans.push_back(path);
            return;
        }
        else if (count == 4)
            return;
        // 3. ���εݹ鴦��
        for (int len = 1; len <= 3 && startIndex + len <= s.size(); len++)
        {
            string s1(s.begin() + startIndex, s.begin() + startIndex + len);
            if (isValid(s1))
            {
                if (path.empty())
                    path += s1;
                else
                    path = path + "." + s1;
                ++count;
                backtracking(s, startIndex + len, count);
                --count;
                path.resize(path.size() - s1.size());
                if (!path.empty())
                    path.pop_back();
            }
            else
                break;
        }
    }

    bool isValid(string& s)
    {
        if (s[0] == '0' && s.size() == 1)
            return true;
        else if (s[0] == '0' && s.size() > 1)
            return false;
        else
        {
            int num = stoi(s);
            if (num >= 0 && num <= 255)
                return true;
            else
                return false;
        }
    }
};

int main()
{
    string s = "101023";
    Solution S;
    S.restoreIpAddresses(s);

    return 0;
}