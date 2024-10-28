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
        // 时间复杂度 O(m)
        for (int i = 0; i < nums1.size(); i++)
        {
            uset.insert(nums1[i]);
        }
        // 时间复杂度 O(n + logn)
        sort(nums2.begin(), nums2.end());
        // 时间复杂度 O(n)
        for (int i = 0; i < nums2.size(); i++)
        {
            // 在集合里说明有交集
            if (i == 0 && uset.find(nums2[i]) != uset.end())
            {
                ans.push_back(nums2[i]);
            }
            // 重复的元素不用再次判断
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
        // 记录 nums1 元素的集合
        unordered_set<int> uset(nums1.begin(), nums1.end());
        unordered_set<int> ans_uset;
        for (int i = 0; i < nums2.size(); i++)
        {
            // 说明集合有该元素
            if (uset.find(nums2[i]) != uset.end())
            {
                // 会自动去重
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