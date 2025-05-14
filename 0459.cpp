#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    //// ��һ �ƶ�ƥ��
    //bool repeatedSubstringPattern(string s) 
    //{
    //    string t = s + s;
    //    // ��ͷȥβ
    //    t.erase(t.begin()); 
    //    t.erase(t.end() - 1);
    //    // std::string::npos �� C++ �� std::string ���һ����̬��Ա����������ʾһ����Ч������ֵ��
    //    // npos ��ֵͨ���� 4294967295���� unsigned int �����ֵ���������ֵ������Ҫ����Ҫ��������ʾһ����Ч��λ�á�
    //    if (t.find(s) != std::string::npos)
    //        return true;
    //    else
    //        return false;
    //}
    // ���� ʹ��next����
    /*
    bool repeatedSubstringPattern(string s)
    {
        vector<int> next(s.size(), 0);
        getnext(next, s);
        // ����ǰ��׺
        int len = next[s.size() - 1];
        // 1. û������ǰ��׺
        if (len == 0)
            return false;
        // 2. ����ǰ��׺���������ַ����ĳ��ȳ��� s ��һ��
        else if (s.size() - len > s.size() / 2)
            return false;
        // 3. ����ǰ��׺���������ַ����ĳ��Ȳ�����һ�뵫�ǲ��ܱ� s �ĳ�������
        else if (s.size() % (s.size() - len) != 0)
            return false;
        // 4. ����ǰ��׺���������ַ����ĳ��ȳ���һ���ҿ��Ա� s �ĳ�������
        // else if (s.size() % (s.size() - len) == 0) Ҳ����ʡ��
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
        // next ��ʼ��
        // j ָ��ǰ׺���һ���ַ�
        int j = 0;
        // i ָ���׺���һ���ַ�
        for (int i = 1; i < s.size(); i++)
        {
            // ��ƥ�����
            while (j >= 1 && s[i] != s[j])
            {
                j = next[j - 1];
            }
            // ƥ��
            if (s[i] == s[j])
            {
                j++;
            }
            next[i] = j;
        }
    }
    */
};