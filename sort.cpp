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
public:
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
    //void quickSort(vector<int>& nums, int low, int high)
    //{
    //    // 2. 确定终止条件
    //    if (low >= high)
    //        return;
    //    // 3. 单次递归处理
    //    int pivot = Paritition(nums, low, high);
    //    quickSort(nums, low, pivot - 1);
    //    quickSort(nums, pivot + 1, high);
    //}
    // 快排划分函数
    /*int Paritition(vector<int>& nums, int low, int high)
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
    }*/
    // 1. 确定形参和返回类型
    void quickSort(vector<int>& nums, int low, int high)
    {
        // 2. 确定终止条件
        if (low >= high)
            return;
        // 3. 单次递归处理
        // 划分函数
        int pivot = Paritition(nums, low, high);
        quickSort(nums, low, pivot - 1);
        quickSort(nums, pivot + 1, high);

        return;
    }
    int Paritition(vector<int>& nums, int low, int high)
    {
        int val = nums[low];
        while (low < high)
        {
            if (low < high && nums[high] >= val)
                --high;
            nums[low] = nums[high];
            if (low < high && nums[low] <= val)
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
    //void mergeSort(vector<int>& nums, int low, int high)
    //{
    //    // 2. 确定终止条件
    //    if (low >= high)
    //        return;
    //    // 3. 单次递归处理
    //    int mid = low + (high - low) / 2;
    //    mergeSort(nums, low, mid);
    //    mergeSort(nums, mid + 1, high);
    //    Merge(nums, low, mid, high);

    //    return;
    //}
    // 二路归并排序
    // 1. 确定参数和形参
    void mergeSort(vector<int>& nums, int low, int high)
    {
        // 2. 确定终止条件
        if (low >= high)
            return;
        int mid = (high - low) / 2 + low;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);

        Merge(nums, low, mid, high);
    }
    /*void Merge(vector<int>& nums, int low, int mid, int high)
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
    }*/
    void Merge(vector<int>& nums, int low, int mid, int high)
    {
        vector<int> leftNums(nums.begin() + low, nums.begin() + mid + 1);
        vector<int> rightNums(nums.begin() + mid + 1, nums.begin() + high + 1);
        int leftIndex = 0, rightIndex = 0;
        for (int i = low; i <= high; ++i)
        {
            if (leftNums[leftIndex] < rightNums[rightIndex])
            {
                nums[i] = leftNums[leftIndex];
                ++leftIndex;
            }
            else
            {
                nums[i] = rightNums[rightIndex];
                ++rightIndex;
            }
        }
        return;
    }
    void heapSort(vector<int>& nums)
    {
        // 1. 首先将数组调整为大根堆 实现从小到大的排序
        // 从最后一个非叶子节点开始调整
        int n = nums.size() - 1;
        for (int i = (n - 1) / 2; i >= 0; --i)
        {
            ShiftDown(nums, i, nums.size());
        }
        // 开始堆排序
        for (int i = n; i > 0; --i)
        {
            // 堆顶元素（最大元素）和当前堆尾元素进行交换
            swap(nums[0], nums[i]);
            ShiftDown(nums, 0, i);
        }
    }

    /*
    * - 功能: 堆的下沉调整
    * - i: 要进行下沉调整的元素
    * - size: 堆的大小
    */
    
    void ShiftDown(vector<int>& nums, int i, int size)
    {
        int val = nums[i];
        while (i <= (size - 2) / 2)
        {
            int child = 2 * i + 1;
            if (child >= size)
                break;
            if (child + 1 < size && nums[child + 1] > nums[child])
                child = child + 1;
            if (nums[child] > val)
            {
                nums[i] = nums[child];
                i = child;
            }
            else
            {
                break;
            }
        }
        nums[i] = val;
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
    S.qSort(nums);

    for (int i = 0; i < 10; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
//    Solution S;
//
//    const int COUNT = 50000000;
//    vector<int> nums1(COUNT, 0);
//    vector<int> nums2(COUNT, 0);
//    vector<int> nums3(COUNT, 0);
//    vector<int> nums4(COUNT, 0);
//
//    srand(time(NULL));
//
//    for (int i = 0; i < COUNT; ++i)
//    {
//        int val = rand() % COUNT;
//        nums1[i] = val;
//        nums2[i] = val;
//        nums3[i] = val;
//        nums4[i] = val;
//    }
//    /*
//    * lock()函数​​：
//    *   - 这是C/C++标准库 <ctime> 或 <time.h> 中的函数，返回程序启动到当前时刻的​​CPU时钟周期数​​（类型为 clock_t）。
//​​    * CLOCKS_PER_SEC宏​​：
//    *   - 表示​​每秒的时钟周期数​​，用于将时钟周期差值转换为秒。
//    */
//    clock_t begin, end;
//    begin = clock();
//    S.qSort(nums1);
//    end = clock();
//    // 转为浮点数
//    cout << "QuickSort Spend: " << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
//
//    begin = clock();
//    S.mSort(nums2);
//    end = clock();
//    cout << "MergeSort Spend: " << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
//
//    begin = clock();
//    S.shellSort(nums3);
//    end = clock();
//    cout << "ShellSort Spend: " << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
//
//    begin = clock();
//    S.heapSort(nums4);
//    end = clock();
//    cout << "HeapSort Spend: " << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
}