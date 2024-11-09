#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		vector<int> ans;
		deque<pair<int, int>> que;
		que.push_back({ 0, nums[0] });
		// 先求前 k 个中的最大值 按递减序列存入队列
		for (int i = 1; i < k; i++)
		{
			if (nums[i] >= que.front().second)
			{
				while (!que.empty())
					que.pop_front();
				que.push_back({ i, nums[i] });
			}
			else
			{
				while (que.back().second <= nums[i])
				{
					que.pop_back();
				}
				que.push_back({ i, nums[i] });
			}
		}
		ans.push_back(que.front().second);
		// 处理剩余的元素
		for (int i = k; i < nums.size(); i++)
		{
			// 处理队列
			if (nums[i] >= que.front().second)
			{
				while (!que.empty())
					que.pop_front();
				que.push_back({ i, nums[i] });
			}
			else
			{
				while (que.back().second <= nums[i])
				{
					que.pop_back();
				}
				que.push_back({ i, nums[i] });
			}
			// 处理不在滑动窗口范围内的元素
			if (que.front().first < i - k + 1)
				que.pop_front();

			ans.push_back(que.front().second);
		}
		return ans;
	}
};

int main()
{
	vector<int> ans = { 1, 3, -1, -3, 5, 3, 6, 7 };
	int k = 3;

	Solution S;
	S.maxSlidingWindow(ans, k);

	return 0;
}