#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    // Author：Kai Chen
    string reverseStr(string s, int k) 
    {
        int size = s.size();
        if (size < k)
        {
            reverseSubstring(s, 0, size - 1);
            return s;
        }
        // 记录第几个字母
        // 每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符
        // 如果剩余字符少于 k 个，则将剩余字符全部反转。
        // 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
        int number = 0;
        for (int i = 0; i < size; i++)
        {
            number++;
            if (number == 2 * k)
            {
                reverseSubstring(s, i - 2 * k + 1, i - k);
                // 每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符
                // 翻转之后 number 需要置 0
                number = 0;
            }
            else if (i == size - 1)
            {
                if (number < k)
                    reverseSubstring(s, i - number + 1, size - 1);
                else if(number >= k && number < 2 * k)
                    reverseSubstring(s, i - number + 1, i - (number - k));
            }
        }
        return s;
    }
    // 左闭右闭
    void reverseSubstring(string &s, int low, int high)
    {
        while (low < high)
        {
            char temp = s[low];
            s[low] = s[high];
            s[high] = temp;
            low++;
            high--;
        }
    }
    // Author: Carl.
    string reverseStr(string s, int k)
    {
        // i 作为每 2 * k 区间的起点
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            // 1. 每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符
            // 2. 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
            if (i + k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            // 3. 如果剩余字符少于 k 个，则将剩余字符全部反转。
            else
            {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main()
{
    string s = "abcdefg";
    int k = 8;
    Solution S;
    S.reverseStr(s, k);

    return 0;
}