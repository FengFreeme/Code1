#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution 
{
public:
    /*
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        // 1. ��¼���ֵ�Ƶ��
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        // 2. ʹ�����ȼ�����
        // 
        // umap�ĵײ�ṹ ��pair<int, int>
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;

        // ��ʼ������л�ȡk����ƵԪ��
        // nordered_map<int, int>::iterator
        for (auto iter = umap.begin(); iter != umap.end(); iter++)
        {
            // �Ե�����������
            que.push(*iter);
            // ά�� k ����Ƶ��������
            if (que.size() > k)
                // ����С��Ԫ�ص���
                que.pop();
        }
        vector<int> ans;
        for (int i = k - 1; i >= 0; i--)
        {
            ans.push_back(que.top().first);
            que.pop();
        }
        return ans;
    }

    class compare
    {
    public:
        bool operator()(const pair<int, int> lhs, const pair<int, int> rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    */
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> umap;
        for (decltype(nums.size()) i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;
        for (auto i : umap)
        {
            que.push(i);
            // ά�� k ��Ԫ�ص���������
            if (que.size() > k)
                que.pop();
        }
        vector<int> ans;
        for (int i = k - 1; i >= 0; i--)
        {
            auto num = que.top();
            que.pop();
            ans.push_back(num.first);
        }
        return ans;
    }
    class compare
    {
    public:
        // С����
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
};