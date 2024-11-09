#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    string reverseWords(string s) 
    {
        int j = 0;
        // ȥ������ո�
        // 1. ����ǰ���ո�
        while (j < s.size() && s[j] == ' ')
            j++;
        // 2. �����м�ո� i Ϊ��ֵָ�룬jΪ����ָ��
        // ��¼��Ч����
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
        // 3. ����β��ո�
        if (s[count - 1] == ' ')
        {
            count--;
        }
        s.resize(count);
        // ȫ�ַ�ת
        reverse(s.begin(), s.end());
        // �����ʷ�ת����
        for (int i = 0, j = 0; i < count && j < count; j++)
        {
            if (s[j] == ' ')
            {
                // �ú���������п�
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