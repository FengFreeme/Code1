#include <iostream>
#include <vector>

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
	// 普通求法
	int ans = 0;
	int countNodes(TreeNode* root) 
	{
		traversal(root);

		return ans;
	}

	// 1. 确定形参和返回类型 先序遍历
	void traversal(TreeNode* node)
	{
		// 2. 确定终止条件
		if (node == nullptr)
			return;
		// 单次递归处理
		ans++;
		traversal(node->left);
		traversal(node->right);

		return;
	}
	*/
	// 利用完全二叉树性质 后序遍历
	// 1. 确定形参和返回类型
	int countNodes(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		int leftDepth = 1, rightDepth = 1;
		// 求左子树深度
		while (left)
		{
			left = left->left;
			++leftDepth;
		}
		while (right)
		{
			right = right->right;
			++rightDepth;
		}
		if (leftDepth == rightDepth)
			return ((2 << (leftDepth - 1)) - 1);		// 2 << 1 相当于2^2

		int leftNum = countNodes(root->left);				// 左
		int rightNum = countNodes(root->right);				// 右
			
		return	1 + leftNum + rightNum;						// 中 节点本身 + 节点左子树节点数量 + 节点右子树节点数量
	}
};