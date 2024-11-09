#include <iostream>
#include <vector>
#include <stack>

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
	// 递归
	/*
	TreeNode* invertTree(TreeNode* root) 
	{
		if (root == nullptr)
			return root;

		preTraversal(root);

		return root;
	}
	// 前序遍历
	// 1. 确定参数和返回类型
	void preTraversal(TreeNode* node)
	{
		// 2. 确定终止条件
		if (node == nullptr)
			return;
		// 3. 单次递归处理
		// 处理 中 节点
		if (node->left != nullptr || node->right != nullptr)
		{
			TreeNode *tmp = node->left;
			node->left = node->right;
			node->right = tmp;
		}
		preTraversal(node->left);
		preTraversal(node->right);

		return;
	}
	*/
	// 统一迭代法 
	TreeNode* invertTree(TreeNode* root)
	{
		if (root == nullptr)
			return nullptr;
		// 使用先序遍历 中 左 右
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			if (cur != nullptr)
			{
				if (cur->right != nullptr)
					st.push(cur->right);
				if (cur->left != nullptr)
					st.push(cur->left);

				st.push(cur);
				st.push(nullptr);
			}
			else
			{
				cur = st.top();
				st.pop();
				if (cur->left != nullptr || cur->right != nullptr)
				{
					TreeNode* tmp = cur->right;
					cur->right = cur->left;
					cur->left = tmp;
				}
			}
		}
		return root;
	}
};