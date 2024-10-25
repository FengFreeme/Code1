#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        return BinarySearch(nums, 0, nums.size() - 1, target);
    }

    int BinarySearch(vector<int> nums, int low, int high, int target)
    {
        int mid;
        while (low <= high)
        {
            mid = (high - low) / 2 + low;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid - 1;
        }
        return -1;
    }
};

int main()
{

}