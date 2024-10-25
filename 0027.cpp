#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int cur = 0;
        for (int next = 0; next < nums.size(); next++)
        {
            if (nums[next] == val)
                continue;
            else if (nums[next] != val)
            {
                nums[cur] = nums[next];
                cur++;
            }
        }
        return cur;
    }
    int removeElement(vector<int>& nums, int val)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == val)
            {
                for (int j = i + 1; j < size; j++)
                    nums[j - 1] = nums[j];
                i--;
                size--;
            }
        }
        return size;
    }
};