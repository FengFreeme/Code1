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
	/*
	// 递归
	bool isSymmetric(TreeNode* root) 
	{
		return traversal(root->left, root->right);
	}
	// "后序遍历" 左右中
	// 1. 确定函数形参和返回类型
	bool traversal(TreeNode* left, TreeNode* right)
	{
		// 2. 确定终止条件
		if (left == nullptr && right == nullptr)
			return true;
		else if (left == nullptr && right != nullptr)
			return false;
		else if (left != nullptr && right == nullptr)
			return false;
		else if (left->val != right->val)
			return false;
		// 3. 单次递归处理
		bool isSame1 = traversal(left->left, right->right);		// 左 右
		bool isSame2 = traversal(left->right, right->left);		// 右 左
		return isSame1 && isSame2;								// 中 中
	}
	*/
	/*
	// 不属于任何遍历方法
	bool isSymmetric(TreeNode* root)
	{
		stack<TreeNode*> st;
		st.push(root->left);
		st.push(root->right);
		while (!st.empty())
		{
			TreeNode* left = st.top();
			st.pop();
			TreeNode* right = st.top();
			st.pop();

			if (left == nullptr && right == nullptr)
				continue;
			if (left == nullptr || right == nullptr || left->val != right->val)
				return false;

			st.push(left->left);
			st.push(right->right);
			st.push(left->right);
			st.push(right->left);
		}
		return true;
	}
	*/
	
};