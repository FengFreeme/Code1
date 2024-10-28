#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    string reverseWords(string s) 
    {
        int j = 0;
        // 去掉多余空格
        // 1. 处理前导空格
        while (j < s.size() && s[j] == ' ')
            j++;
        // 2. 处理中间空格 i 为赋值指针，j为遍历指针
        // 记录有效长度
        int count = 0;
        for (int i = 0; j < s.size(); j++)
        {
            if (s[j] != ' ' || (s[j] == ' ' && s[j - 1] != ' '))
            {
                s[i++] = s[j];
                count++;
            }
            else if (s[j] == ' ' && s[j - 1] == ' ')
                continue;
        }
        // 3. 处理尾随空格
        if (s[count - 1] == ' ')
        {
            count--;
        }
        s.resize(count);
        // 全局反转
        reverse(s.begin(), s.end());
        // 将单词反转回来
        for (int i = 0, j = 0; i < count && j < count; j++)
        {
            if (s[j] == ' ')
            {
                // 该函数是左闭有开
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
            else if (j == count - 1)
            {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main()
{
    string s = "  hello world  ";
    Solution S;
    S.reverseWords(s);

    return 0;
}