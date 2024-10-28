#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        int ans = 0;
        int n = nums1.size();
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                umap[nums1[i] + nums2[j]]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int target = 0 - (nums3[i] + nums4[j]);
                if (umap.find(target) != umap.end())
                    ans += umap[target];
            }
        }
        return ans;
    }
};