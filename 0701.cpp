#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int num) :val(num), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	/*
	// 递归
	// 直接插入到最后一个节点后面
	TreeNode* insertIntoBST(TreeNode* root, int val) 
	{
		if (root == nullptr)
		{
			return new TreeNode(val);
		}
		traversal(root, val);

		return root;
	}
	// 1. 确定参数和返回类型 这里是为了确定已经找到了插入的地方，不用继续递归
	TreeNode* traversal(TreeNode* root, int val)
	{
		// 2. 确定终止条件
		
		// 3. 单次递归处理
		if (val > root->val)
		{
			if (root->right != nullptr)
			{
				TreeNode *right = traversal(root->right, val);
				if (right != nullptr)
					return right;
			}
			else
			{
				TreeNode* cur = new TreeNode(val);
				root->right = cur;
				return cur;
			}
		}
		else if (val < root->val)
		{
			if (root->left != nullptr)
			{
				TreeNode *left = traversal(root->left, val);
				if (left != nullptr)
					return left;
			}
			else
			{
				TreeNode* cur = new TreeNode(val);
				root->left = cur;
				return cur;
			}
		}
		return nullptr;
	}
	*/
	// 迭代法
	TreeNode* insertIntoBST(TreeNode* root, int val)
	{
		if (root == nullptr)
			return new TreeNode(val);
		TreeNode* cur = root;
		TreeNode* parent = nullptr;
		while (cur != nullptr)
		{
			if (val < cur->val)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (val > cur->val)
			{
				parent = cur;
				cur = cur->right;
			}
		}
		cur = new TreeNode(val);
		if (val < parent->val)
			parent->left = cur;
		else if (val > parent->val)
			parent->right = cur;

		return root;
	}
};