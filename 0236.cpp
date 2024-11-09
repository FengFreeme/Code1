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
	// 后序遍历 左 右 中
	// 1. 确定形参和返回类型
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		// 2. 确定终止条件
		if (root == nullptr || root == p || root == q)
			return root;
		// 3. 单次递归处理
		TreeNode* left = lowestCommonAncestor(root->left, p, q);	// 左
		TreeNode* right = lowestCommonAncestor(root->right, p, q);	// 右
		// 存在公共祖先 返回公共祖先
		// 1. 情况一 左子树和右子树中有 p 和 q
		// /返回最近公共祖先
		if (left != nullptr && right != nullptr)		// 中
			return root;
		// 2. 此时left可能是p或者q，也可能是已经找到了最近公共祖先
		else if (left != nullptr && right == nullptr)
			return left;
		else if (left == nullptr && right != nullptr)
			return right;
		// 不存在 返回 nullptr
		return nullptr;
	}
	*/
	// 后序遍历
	// 左 右 中
	// 1. 确定参数和返回类型
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		// 2. 确定终止条件
		if (root == nullptr || root == q || root == p)
			return root;
		// 3. 单次递归处理
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left != nullptr && right == nullptr)
			return left;
		else if (left == nullptr && right != nullptr)
			return right;
		else if (left != nullptr && right != nullptr)
			return root;

		return nullptr;
	}
};