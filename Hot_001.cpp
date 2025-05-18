#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // ʱ�临�Ӷ� O(n) �ռ临�Ӷ� O(n)
    // ���� sort Ҫ�����±�
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> umap;       
        for (int i = 0; i < nums.size(); ++i)       // O(n)
        {
            int num = target - nums[i];
            // Ԫ�ز����� ���� umap
            if (umap.find(num) == umap.end())
            {
                umap[nums[i]] = i;
            }
            // ����
            else
            {
                return { umap[num], i };
            }
        }
        return { -1, -1 };
    }
};

int main()
{
    Solution S;
    vector<int> nums = { 3,2,4 };
    S.twoSum(nums, 6);

    return 0;
}