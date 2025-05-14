#include <iostream>
#include <vector>
#include <string>
using namespace std;

int DP(string s, string t)
{
    // ����Ϊ 1 �����
    if (s.size() == 1)
    {
        if (s[0] == t[0])
            return 0;
        else
            return -1;
    }
    // ������β�ַ�����ͬ�����
    if (s[0] != t[0] || s[s.size() - 1] != t[t.size() - 1])
        return -1;

    vector<int> dp(s.size(), 0);

    for (int i = 1; i < s.size() - 1; ++i)
    {
        if (s[i] == t[i])
            dp[i] = dp[i - 1];
        else
        {
            if (s[i - 1] == s[i + 1] && s[i - 1] != s[i] && s[i - 1] == t[i - 1])
                dp[i] = dp[i - 1] + 1;
        }
    }
    return dp[s.size() - 2];
}

int main()
{
    // ���ڴ��������Ĵ���
    int D;
    cin >> D;
    string T;
    string S;

    for (int i = 0; i < D; ++i)
    {
        cin >> T;
        cin >> S;
        cout << DP(S, T) << endl;
    }
    return 0;
}