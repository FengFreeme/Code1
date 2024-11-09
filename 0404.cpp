#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	TreeNode* left, * right;
	int val;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	/*
	int ans = 0;
	// 先序遍历 递归
	int sumOfLeftLeaves(TreeNode* root) 
	{
		traversal(root);

		return ans;
	}
	// 1. 确定形参和返回类型
	void traversal(TreeNode* node)
	{
		// 2. 确定终止条件
		
		if (node->left != nullptr)		// 左
		{
			// 是左叶节点
			if (node->left->left == nullptr && node->left->right == nullptr)
			{
				ans += node->left->val;
			}
			else
				traversal(node->left);
		}
		if (node->right != nullptr)		// 右
			traversal(node->right);

		return;
	}
	*/
	/*
	// 后序遍历
	int sumOfLeftLeaves(TreeNode* root)
	{
		return traversal(root);
	}
	// 1. 确定参数和返回类型
	int traversal(TreeNode* node)
	{
		// 2. 确定终止条件
		if (node == nullptr)
			return 0;
		// 3. 单次递归处理
		int num1 = 0;
		if (node->left != nullptr)			// 左
		{
			if (node->left->left == nullptr && node->left->right == nullptr)
			{
				num1 = node->left->val;
			}
			else
			{
				num1 = traversal(node->left);
			}
		}
		int num2 = traversal(node->right);	// 右
		return num1 + num2;
	}
	*/
	// 统一迭代法 前序遍历 中 左 右
	int sumOfLeftLeaves(TreeNode* root)
	{
		stack<TreeNode*> st;
		st.push(root);
		int ans = 0;
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			if (cur != nullptr)
			{
				if (cur->right != nullptr)
					st.push(cur->right);

				if (cur->left != nullptr && cur->left->left == nullptr && cur->left->right == nullptr)
					ans += cur->left->val;
				else if (cur->left != nullptr)
					st.push(cur->left);

				st.push(cur);
				st.push(nullptr);
			}
			else
			{
				cur = st.top();
				st.pop();
			}
		}
		return ans;
	}
};