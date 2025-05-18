#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    void moveZeroes(vector<int>& nums)
    {
        // int end = nums.size() - 1;
        /*for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == 0 && i != end)
            {
                for (int j = i; j < end; ++j)
                {
                    nums[j] = nums[j + 1];
                }
                nums[end] = 0;
            }
        }*/
        // ��Ч������±����һ��Ԫ��
        int index = 0;
        for (int i = 0; i < nums.size(); ++i)           // ʱ�临�Ӷ� O(n)
        {
            // ������ 0 Ԫ�� �ƶ�
            if (nums[i] != 0)
            {
                nums[index] = nums[i];
                ++index;
            }
        }
        for (int i = index; i < nums.size(); ++i)
            nums[i] = 0;
        return;
    }
};

int main()
{

}