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
        // n - 1 ��ð��
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            // ����Ƿ񽻻���
            bool flag = false;
            // ����Ԫ�ؽ��бȽ� 
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
            // ���û�н�������˵�������Ѿ�������ǰ�˳�ѭ��
            if (!flag)
                break;
        }
    }
    void selectSort(vector<int>& nums)
    {
        // n - 1 ��ѡ��
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            // ��¼��СԪ�ص��±�λ��
            int index = i;
            // ����������ѡ����СԪ�� ��Ϊ�Ѿ����� index = i �ˣ�ֱ�Ӵ� i + 1 ��ʼ
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
        // �ٶ���һ��Ԫ�����������У�i �� 1 ��ʼ
        for (int i = 1; i < nums.size(); ++i)
        {
            int temp = nums[i];
            // Ѱ�Ҳ���λ�� �Ӻ���ǰ�� ��һ��С�� nums[i] ��λ�� 
            int j;
            for (j = i - 1; j >= 0; --j)
            {
                // �ȶ��Ե�����
                if (nums[j] <= temp)
                    break;
                // �ƶ�Ԫ�أ��� nums[i] �ڳ�λ��
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = temp;
        }
        return;
    }
    void shellSort(vector<int>& nums)
    {
        // gap ��Ϊ gap �飬���� gap �β�������
        for (int gap = nums.size() / 2; gap >= 1; gap /= 2)
        {
            // ��ÿ�������еĵ�һ��Ԫ�ؿ�ʼ����
            for (int i = gap; i < nums.size(); ++i)
            {
                int j;
                int temp = nums[i];
                for (j = i - gap; j >= 0; j -= gap)
                {
                    // �ҵ����ʵĲ���λ�� ���뵽��ǰλ�õ��¸� gap λ��
                    if (nums[j] <= temp)
                        break;
                    else
                        // �ƶ�Ԫ�� ��Ŀ��Ԫ���ڳ�λ��
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
    // 1. ȷ�������ͷ�������
    void quickSort(vector<int>& nums, int low, int high)
    {
        // 2. ȷ����ֹ����
        if (low >= high)
            return;
        // 3. ���εݹ鴦��
        int pivot = Paritition(nums, low, high);
        quickSort(nums, low, pivot - 1);
        quickSort(nums, pivot + 1, high);
    }
    // ���Ż��ֺ���
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
    // 1. ȷ���βκͷ�������
    void mergeSort(vector<int>& nums, int low, int high)
    {
        // 2. ȷ����ֹ����
        if (low >= high)
            return;
        // 3. ���εݹ鴦��
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