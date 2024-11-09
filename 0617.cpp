#include <iostream>
#include <vector>
#include <queue>

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
	// 1. 确定形参和返回类型 先序遍历
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
	{
		// 2. 确定终止条件
		if (root1 == nullptr && root2 != nullptr)
			return root2;
		else if (root1 != nullptr && root2 == nullptr)
			return root1;
		else if (root1 == NULL && root2 == nullptr)
			return nullptr;
		// 3. 单次递归处理 返回root1
		root1->val = root1->val + root2->val;	// 中
		root1->left = mergeTrees(root1->left, root2->left);		// 左
		root1->right = mergeTrees(root1->right, root2->right);	// 右

		return root1;
	}
	*/
	// 层序遍历
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
	{
		if (root1 == nullptr && root2 != nullptr)
			return root2;
		else if (root1 != nullptr && root2 == nullptr)
			return root1;
		else if (root1 == nullptr && root2 == nullptr)
			return nullptr;
		queue<TreeNode*> que;
		que.push(root1);
		que.push(root2);
		while (!que.empty())
		{
			TreeNode* node1 = que.front();
			que.pop();
			TreeNode* node2 = que.front();
			que.pop();
			node1->val += node2->val;

			if (node1->left != nullptr && node2->left != nullptr)
			{
				que.push(node1->left);
				que.push(node2->left);
			}
			if (node1->right != nullptr && node2->right != nullptr)
			{
				que.push(node1->right);
				que.push(node2->right);
			}

			if (node1->left == nullptr && node2->left != nullptr)
				node1->left = node2->left;
			if (node1->right == nullptr && node2->right != nullptr)
				node1->right = node2->right;
		}
		return root1;
	}
};