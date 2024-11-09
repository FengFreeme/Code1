#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        unordered_set<int> uset;
        // ʱ�临�Ӷ� O(m)
        for (int i = 0; i < nums1.size(); i++)
        {
            uset.insert(nums1[i]);
        }
        // ʱ�临�Ӷ� O(n + logn)
        sort(nums2.begin(), nums2.end());
        // ʱ�临�Ӷ� O(n)
        for (int i = 0; i < nums2.size(); i++)
        {
            // �ڼ�����˵���н���
            if (i == 0 && uset.find(nums2[i]) != uset.end())
            {
                ans.push_back(nums2[i]);
            }
            // �ظ���Ԫ�ز����ٴ��ж�
            else if(i > 0 && nums2[i] != nums2[i - 1])
            {
                if (uset.find(nums2[i]) != uset.end())
                {
                    ans.push_back(nums2[i]);
                }
            }
        }
        return ans;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        // ��¼ nums1 Ԫ�صļ���
        unordered_set<int> uset(nums1.begin(), nums1.end());
        unordered_set<int> ans_uset;
        for (int i = 0; i < nums2.size(); i++)
        {
            // ˵�������и�Ԫ��
            if (uset.find(nums2[i]) != uset.end())
            {
                // ���Զ�ȥ��
                ans_uset.insert(nums2[i]);
            }
        }
        return vector<int>(ans_uset.begin(), ans_uset.end());
    }
};

int main()
{
    vector<int> nums1 = { 4,7,9,7,6,7 };
    vector<int> nums2 = { 5,0,0,6,1,6,2,2,4 };

    Solution S;
    S.intersection(nums1, nums2);

    return 0;
}