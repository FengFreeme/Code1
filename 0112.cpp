#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	/*
	bool hasPathSum(TreeNode* root, int targetSum) 
	{
		if (root == nullptr)
			return false;

		return traversal(root, root->val, targetSum);
	}
	// 前序遍历
	// 1. 确定形参和返回类型
	bool traversal(TreeNode* node, int sum, int target)
	{
		// 2. 确定终止条件
		if (node->left == nullptr && node->right == nullptr)		// 中
		{
			if (sum == target)
				return true;
		}
		// 单次递归处理
		if (node->left != nullptr)									// 左
		{
			sum += node->left->val;
			if (traversal(node->left, sum, target))
				return true;
			sum -= node->left->val;		// 回溯
		}
		if (node->right != nullptr)									// 右
		{
			sum += node->right->val;
			if (traversal(node->right, sum, target))
				return true;
			sum -= node->right->val;
		}
		return false;
	}
	*/
	// 统一迭代 前序遍历 中左右
	bool hasPathSum(TreeNode* root, int targetSum)
	{
		if (root == nullptr)
			return false;
		stack<pair<TreeNode*, int>> st;
		st.push({root, root->val});
		while (!st.empty())
		{
			auto cur = st.top();
			st.pop();
			if (cur.first != nullptr)
			{
				if (cur.first->left == nullptr && cur.first->right == nullptr && cur.second == targetSum)
					return true;
				if (cur.first->right != nullptr)
				{
					st.push({ cur.first->right, cur.second + cur.first->right->val });
				}
				if (cur.first->left != nullptr)
					st.push({ cur.first->left, cur.second + cur.first->left->val });

				st.push(cur);
				st.push({ nullptr, 0 });
			}
			else
			{
				cur = st.top();
				st.pop();
			}
		}
		return false;
	}
};