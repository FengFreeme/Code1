#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    //// 法一 移动匹配
    //bool repeatedSubstringPattern(string s) 
    //{
    //    string t = s + s;
    //    // 掐头去尾
    //    t.erase(t.begin()); 
    //    t.erase(t.end() - 1);
    //    // std::string::npos 是 C++ 中 std::string 类的一个静态成员常量，它表示一个无效的索引值。
    //    // npos 的值通常是 4294967295（即 unsigned int 的最大值），但这个值并不重要，重要的是它表示一个无效的位置。
    //    if (t.find(s) != std::string::npos)
    //        return true;
    //    else
    //        return false;
    //}
    // 法二 使用next数组
    /*
    bool repeatedSubstringPattern(string s)
    {
        vector<int> next(s.size(), 0);
        getnext(next, s);
        // 最长相等前后缀
        int len = next[s.size() - 1];
        // 1. 没有最长相等前后缀
        if (len == 0)
            return false;
        // 2. 最长相等前后缀不包含的字符串的长度超过 s 的一半
        else if (s.size() - len > s.size() / 2)
            return false;
        // 3. 最长相等前后缀不包含的字符串的长度不超过一半但是不能被 s 的长度整除
        else if (s.size() % (s.size() - len) != 0)
            return false;
        // 4. 最长相等前后缀不包含的字符串的长度超过一半且可以被 s 的长度整除
        // else if (s.size() % (s.size() - len) == 0) 也可以省略
        else
            return true;

    }
    */
    bool repeatedSubstringPattern(string s)
    {

    }
private:
    /*
    void getnext(vector<int>& next, string s)
    {
        // next 初始化
        // j 指向前缀最后一个字符
        int j = 0;
        // i 指向后缀最后一个字符
        for (int i = 1; i < s.size(); i++)
        {
            // 不匹配情况
            while (j >= 1 && s[i] != s[j])
            {
                j = next[j - 1];
            }
            // 匹配
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    */
};