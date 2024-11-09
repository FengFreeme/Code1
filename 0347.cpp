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
        // 1. 记录数字的频率
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        // 2. 使用优先级队列
        // 
        // umap的底层结构 是pair<int, int>
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;

        // 开始加入队列获取k个高频元素
        // nordered_map<int, int>::iterator
        for (auto iter = umap.begin(); iter != umap.end(); iter++)
        {
            // 对迭代器解引用
            que.push(*iter);
            // 维护 k 个高频数字序列
            if (que.size() > k)
                // 将最小的元素弹出
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
            // 维护 k 个元素的有序序列
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
        // 小顶堆
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second > rhs.second;
        }
    };
};