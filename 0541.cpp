#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    // Author��Kai Chen
    string reverseStr(string s, int k) 
    {
        int size = s.size();
        if (size < k)
        {
            reverseSubstring(s, 0, size - 1);
            return s;
        }
        // ��¼�ڼ�����ĸ
        // ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ�
        // ���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
        // ���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
        int number = 0;
        for (int i = 0; i < size; i++)
        {
            number++;
            if (number == 2 * k)
            {
                reverseSubstring(s, i - 2 * k + 1, i - k);
                // ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ�
                // ��ת֮�� number ��Ҫ�� 0
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
    // ����ұ�
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
        // i ��Ϊÿ 2 * k ��������
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            // 1. ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ�
            // 2. ���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
            if (i + k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            // 3. ���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
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