#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<string> letters = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> ans;
    string path;
    vector<string> letterCombinations(string digits) 
    {
        if (digits.size() == 0)
            return ans;
        backtracking(digits, 0);

        return ans;
    }
    // 1. 确定形参和返回类型
    void backtracking(string &digits, int startIndex)
    {
        // 2. 确定终止条件
        if (path.size() == digits.size())
        {
            ans.push_back(path);
            return;
        }
        // 3. 单次递归处理
        // 剪枝优化
        for (int i = startIndex; i < path.size() + 1; i++)
        {
            string letter = letters[digits[i] - '0'];
            for(int j = 0; j < letter.size(); j++)
            {
                path.push_back(letter[j]);
                backtracking(digits, i + 1);
                path.pop_back();
            }
        }
        return;
    }
};

int main()
{
    Solution S;
    S.letterCombinations("23");

    return 0;
}