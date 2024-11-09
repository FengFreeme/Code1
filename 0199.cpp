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
	vector<int> rightSideView(TreeNode* root) 
	{
		vector<int> ans;
		if (root == nullptr)
			return ans;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			auto size = que.size();
			for (decltype(size) i = 0; i < size; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				if (i == size - 1)
					ans.push_back(cur->val);
				if (cur->left != nullptr)
					que.push(cur->left);
				if (cur->right != nullptr)
					que.push(cur->right);
			}
		}
		return ans;
	}
};