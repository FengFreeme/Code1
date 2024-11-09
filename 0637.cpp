#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	vector<double> averageOfLevels(TreeNode* root) 
	{
		vector<double> ans;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			auto size = que.size();
			long long int sum = 0;
			for (decltype(size) i = 0; i < size; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				sum += cur->val;
				if (cur->left != nullptr)
					que.push(cur->left);
				if (cur->right != nullptr)
					que.push(cur->right);
			}
			double avg = static_cast<double>(sum) / static_cast<double>(size);
			ans.push_back(avg);
		}
		return ans;
	}
};