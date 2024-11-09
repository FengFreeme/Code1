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
	vector<int> largestValues(TreeNode* root) 
	{
		vector<int> ans;
		if (root == nullptr)
			return ans;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			int maxNum = INT_MIN;
			
			auto size = que.size();
			for (decltype(size) i = 0; i < size; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				maxNum = max(maxNum, cur->val);
				if (cur->left != nullptr)
					que.push(cur->left);
				if (cur->right != nullptr)
					que.push(cur->right);
			}
			ans.push_back(maxNum);
		}
		return ans;
	}
};