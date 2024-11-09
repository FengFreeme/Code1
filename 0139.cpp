#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int j = 1; j <= s.size(); ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                string str = s.substr(i, j - i);
                if (wordSet.find(str) != wordSet.end() && dp[i] == true)
                    dp[j] = true;
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    Solution S;
    vector<string> wordDict = { "leet", "code" };
    string s = "leetcode";
    string str = s.substr(0, 4);
    cout << str << endl;
    S.wordBreak("leetcode", wordDict);

    return 0;
}