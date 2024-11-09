#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	/*
	bool ans = true;
	bool isBalanced(TreeNode* root)
	{
		traversal(root);

		return ans;
	}

	// 1. 后序遍历 确定形参和返回类型 返回高度比较
	int traversal(TreeNode* node)
	{
		// 2. 确定终止条件
		if (node == nullptr)
			return 0;
		// 3. 单次递归处理
		int level1 = traversal(node->left);		// 左 返回左子树高度
		int level2 = traversal(node->right);	// 右 返回右子树高度
		ans = ans && (abs(level1 - level2) <= 1);		// 中 判断是否为平衡二叉树
		return 1 + max(level1, level2);
	}
	*/
	// 后序遍历 求高度差判断平衡二叉树
	bool ans = true;
	bool isBalanced(TreeNode* root)
	{
		traversal(root);

		return ans;
	}
	// 1. 确定形参和返回类型
	int traversal(TreeNode* node)
	{
		// 2. 确定终止条件
		if (node == nullptr)
			return 0;
		int leftLevel = traversal(node->left);		// 左
		int rightLevel = traversal(node->right);	// 右
		ans = ans && (abs(leftLevel - rightLevel) <= 1);	// 中

		return 1 + max(leftLevel, rightLevel);
	}
};