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
	vector<vector<int>> levelOrderBottom(TreeNode* root) 
	{
		vector<vector<int>> ans;
		if (root == nullptr)
			return ans;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			auto size = que.size();
			vector<int> nodes;
			for (decltype(size) i = 0; i < size; i++)
			{
				TreeNode *cur = que.front();
				que.pop();
				nodes.push_back(cur->val);
				if (cur->left != nullptr)
					que.push(cur->left);
				if (cur->right != nullptr)
					que.push(cur->right);
			}
			ans.push_back(nodes);
		}
		reverse(ans.begin(), ans.end());

		return ans;
	}
};