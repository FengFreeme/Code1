#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    //int strStr(string haystack, string needle) 
    //{
    //    // 1. 先求 next 数组
    //    vector<int> next(needle.size(), 0);
    //    getNext(next, needle);
    //    // 2. 开始子字符串匹配
    //    int j = 0;
    //    for (int i = 0; i < haystack.size(); i++)
    //    {
    //        // 不匹配 需要回退至匹配的时候
    //        while (j >= 1 && haystack[i] != needle[j])
    //        {
    //            j = next[j - 1];
    //        }
    //        // 匹配 i j 都加 1，其中 i 在for循环中加
    //        if (haystack[i] == needle[j])
    //        {
    //            j++;
    //        }
    //        if (j == needle.size())
    //            return i - needle.size() + 1;
    //    }
    //    return -1;
    //}
    int strStr(string haystack, string needle)
    {
        vector<int> next(needle.size());
        // 求 next 数组
        getNext(next, needle);
        // 1. j 指向needle
        int j = 0;
        // 2. i 指向 haystack
        for (int i = 0; i < haystack.size(); i++)
        {
            // 不匹配的情况
            while (j >= 1 && haystack[i] != needle[j])
            {
                // j 回退直到匹配或者不能再回退
                j = next[j - 1];
            }
            // 匹配的情况
            if (haystack[i] == needle[j])
            {
                // i++ 和 j++ 同时增 1 
                j++;
            }
            if (j == needle.size())
                return i - needle.size() + 1;
        }
        return -1;
    }
private:
    //void getNext(vector<int>& next, string needle)
    //{
    //    // j 指向前缀末尾
    //    int j = 0;
    //    // next初始化
    //    next[0] = j;
    //    // i 指向后缀末尾 因为 next[0]已经初始化，所以 i 从 1 开始
    //    for (int i = 1; i < needle.size(); i++)
    //    {
    //        // 前后缀不匹配的情况 回退到匹配的时候
    //        while (j >= 1 && needle[i] != needle[j])
    //            j = next[j - 1];
    //        // 前后缀匹配的情况 j 和 i 都加 1， 其中 i 在 for 中加 1
    //        if (needle[i] == needle[j])
    //            j++;
    //        // 赋值 next[i]
    //        next[i] = j;
    //    }
    //}
    void getNext(vector<int>& next, string needle)
    {
        // j 指向前缀的最后一个字符
        int j = 0;
        // 1. 初始化next数组
        next[0] = j;
        // 2. i 指向后缀的最后一个字符
        for (int i = 1; i < needle.size(); i++)
        {
            // 3. 不匹配的情况
            while (j >= 1 && needle[i] != needle[j])
            {
                j = next[j - 1];
            }
            // 4. 匹配的情况
            if (needle[i] == needle[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
};

int main()
{
    string haystack = "aabaabaafa", needle = "aabaaf";
    Solution S;
    S.strStr(haystack, needle);

    return 0;
}