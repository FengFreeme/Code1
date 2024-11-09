#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    //int strStr(string haystack, string needle) 
    //{
    //    // 1. ���� next ����
    //    vector<int> next(needle.size(), 0);
    //    getNext(next, needle);
    //    // 2. ��ʼ���ַ���ƥ��
    //    int j = 0;
    //    for (int i = 0; i < haystack.size(); i++)
    //    {
    //        // ��ƥ�� ��Ҫ������ƥ���ʱ��
    //        while (j >= 1 && haystack[i] != needle[j])
    //        {
    //            j = next[j - 1];
    //        }
    //        // ƥ�� i j ���� 1������ i ��forѭ���м�
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
        // �� next ����
        getNext(next, needle);
        // 1. j ָ��needle
        int j = 0;
        // 2. i ָ�� haystack
        for (int i = 0; i < haystack.size(); i++)
        {
            // ��ƥ������
            while (j >= 1 && haystack[i] != needle[j])
            {
                // j ����ֱ��ƥ����߲����ٻ���
                j = next[j - 1];
            }
            // ƥ������
            if (haystack[i] == needle[j])
            {
                // i++ �� j++ ͬʱ�� 1 
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
    //    // j ָ��ǰ׺ĩβ
    //    int j = 0;
    //    // next��ʼ��
    //    next[0] = j;
    //    // i ָ���׺ĩβ ��Ϊ next[0]�Ѿ���ʼ�������� i �� 1 ��ʼ
    //    for (int i = 1; i < needle.size(); i++)
    //    {
    //        // ǰ��׺��ƥ������ ���˵�ƥ���ʱ��
    //        while (j >= 1 && needle[i] != needle[j])
    //            j = next[j - 1];
    //        // ǰ��׺ƥ������ j �� i ���� 1�� ���� i �� for �м� 1
    //        if (needle[i] == needle[j])
    //            j++;
    //        // ��ֵ next[i]
    //        next[i] = j;
    //    }
    //}
    void getNext(vector<int>& next, string needle)
    {
        // j ָ��ǰ׺�����һ���ַ�
        int j = 0;
        // 1. ��ʼ��next����
        next[0] = j;
        // 2. i ָ���׺�����һ���ַ�
        for (int i = 1; i < needle.size(); i++)
        {
            // 3. ��ƥ������
            while (j >= 1 && needle[i] != needle[j])
            {
                j = next[j - 1];
            }
            // 4. ƥ������
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