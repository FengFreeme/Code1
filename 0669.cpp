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
	// 1. 确定形参和返回类型
	TreeNode* trimBST(TreeNode* root, int low, int high) 
	{
		// 2. 确定终止条件
		if (root == nullptr)
			return root;
		// 3. 单次递归
		// 在区间范围
		if (root->val <= high && root->val >= low)
		{
			root->left = trimBST(root->left, low, high);
			root->right = trimBST(root->right, low, high);
		}
		// 大于右边界值
		else if (root->val > high)
		{
			TreeNode *left = trimBST(root->left, low, high);
			return left;
		}
		// 小于左边界值
		else if (root->val < low)
		{
			TreeNode* right = trimBST(root->right, low, high);
			return right;
		}
		return root;
	}
	*/
	// 迭代
	TreeNode* trimBST(TreeNode* root, int low, int high)
	{
		if (root == nullptr)
			return root;
		// 处理头结点 让root移动到[L, R]范围内
		while (root != nullptr && (root->val < low || root->val > high))
		{
			if (root->val < low)
				root = root->right;
			else
				root = root->left;
		}
		TreeNode* cur = root;
		// 处理左子树
		while (cur != nullptr)
		{
			while (cur->left && cur->left->val < low)
				cur->left = cur->left->right;
			cur = cur->left;
		}
		cur = root;
		while (cur != nullptr)
		{
			while (cur->right && cur->right->val > high)
			{
				cur->right = cur->right->left;
			}
			cur = cur->right;
		}
		return root;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(2);
	// root->left->right = new TreeNode(2);
	// root->left->right->left = new TreeNode(1);
	root->right = new TreeNode(2);
	// root->right->right = new TreeNode(7);

	Solution S;
	TreeNode *no = S.trimBST(root, 2, 4);

	return 0;
}