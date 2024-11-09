#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        mSort(nums);

        return nums;
    }
private:
    void bubbleSort(vector<int>& nums)
    {
        // n - 1 趟冒泡
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            // 标记是否交换过
            bool flag = false;
            // 相邻元素进行比较 
            for (int j = 1; j <= nums.size() - i - 1; ++j)
            {
                if (nums[j - 1] > nums[j])
                {
                    int temp = nums[j];
                    nums[j] = nums[j - 1];
                    nums[j - 1] = temp;
                    flag = true;
                }
            }
            // 如果没有交换过，说明数据已经有序，提前退出循环
            if (!flag)
                break;
        }
    }
    void selectSort(vector<int>& nums)
    {
        // n - 1 趟选择
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            // 记录最小元素的下标位置
            int index = i;
            // 从无序序列选择最小元素 因为已经设置 index = i 了，直接从 i + 1 开始
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[j] < nums[index])
                    index = j;
            }
            if (index != i)
            {
                int temp = nums[index];
                nums[index] = nums[i];
                nums[i] = temp;
            }
        }
    }
    void insertSort(vector<int>& nums)
    {
        // 假定第一个元素是有序序列，i 从 1 开始
        for (int i = 1; i < nums.size(); ++i)
        {
            int temp = nums[i];
            // 寻找插入位置 从后往前找 第一个小于 nums[i] 的位置 
            int j;
            for (j = i - 1; j >= 0; --j)
            {
                // 稳定性的体现
                if (nums[j] <= temp)
                    break;
                // 移动元素，给 nums[i] 腾出位置
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = temp;
        }
        return;
    }
    void shellSort(vector<int>& nums)
    {
        // gap 分为 gap 组，进行 gap 次插入排序
        for (int gap = nums.size() / 2; gap >= 1; gap /= 2)
        {
            // 从每个子序列的第一个元素开始遍历
            for (int i = gap; i < nums.size(); ++i)
            {
                int j;
                int temp = nums[i];
                for (j = i - gap; j >= 0; j -= gap)
                {
                    // 找到合适的插入位置 插入到当前位置的下个 gap 位置
                    if (nums[j] <= temp)
                        break;
                    else
                        // 移动元素 给目标元素腾出位置
                        nums[j + gap] = nums[j];
                }
                nums[j + gap] = temp;
            }
        }
        return;
    }
    void qSort(vector<int>& nums)
    {
        quickSort(nums, 0, nums.size() - 1);
    }
    // 1. 确定参数和返回类型
    void quickSort(vector<int>& nums, int low, int high)
    {
        // 2. 确定终止条件
        if (low >= high)
            return;
        // 3. 单次递归处理
        int pivot = Paritition(nums, low, high);
        quickSort(nums, low, pivot - 1);
        quickSort(nums, pivot + 1, high);
    }
    // 快排划分函数
    int Paritition(vector<int>& nums, int low, int high)
    {
        int middle = (high - low) / 2 + low;
        int index = low;
        if ((nums[low] <= nums[middle] && nums[middle] <= nums[high]) || (nums[high] <= nums[middle] && nums[middle] <= nums[low]))
            index = middle;
        else if ((nums[low] <= nums[high] && nums[high] <= nums[middle]) || (nums[middle] <= nums[high] && nums[high] <= nums[low]))
            index = high;
        if (index != low)
        {
            int temp = nums[index];
            nums[index] = nums[low];
            nums[low] = temp;
        }
        int val = nums[low];
        while (low < high)
        {
            while (low < high && nums[high] >= val)
                --high;
            nums[low] = nums[high];
            while (low < high && nums[low] <= val)
                ++low;
            nums[high] = nums[low];
        }
        nums[low] = val;
        return low;
    }
    void mSort(vector<int>& nums)
    {
        mergeSort(nums, 0, nums.size() - 1);

        return;
    }
    // 1. 确定形参和返回类型
    void mergeSort(vector<int>& nums, int low, int high)
    {
        // 2. 确定终止条件
        if (low >= high)
            return;
        // 3. 单次递归处理
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        Merge(nums, low, mid, high);

        return;
    }
    void Merge(vector<int>& nums, int low, int mid, int high)
    {
        vector<int> leftNums(nums.begin() + low, nums.begin() + mid + 1);
        vector<int> rightNums(nums.begin() + mid + 1, nums.begin() + high + 1);
        leftNums.push_back(INT_MAX);
        rightNums.push_back(INT_MAX);
        int leftIndex = 0, rightIndex = 0;
        for (int i = low; i <= high; ++i)
        {
            if (leftNums[leftIndex] <= rightNums[rightIndex])
            {
                nums[i] = leftNums[leftIndex];
                ++leftIndex;
            }
            else if (leftNums[leftIndex] > rightNums[rightIndex])
            {
                nums[i] = rightNums[rightIndex];
                ++rightIndex;
            }
        }
        return;
    }
};

int main()
{
    vector<int> nums(10, 0);
    srand(time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        nums[i] = rand() % 100 + 1;
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution S;
    S.sortArray(nums);

    for (int i = 0; i < 10; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}