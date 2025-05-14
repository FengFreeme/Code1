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
	// 1. ȷ���βκͷ������� �������
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
	{
		// 2. ȷ����ֹ����
		if (root1 == nullptr && root2 != nullptr)
			return root2;
		else if (root1 != nullptr && root2 == nullptr)
			return root1;
		else if (root1 == NULL && root2 == nullptr)
			return nullptr;
		// 3. ���εݹ鴦�� ����root1
		root1->val = root1->val + root2->val;	// ��
		root1->left = mergeTrees(root1->left, root2->left);		// ��
		root1->right = mergeTrees(root1->right, root2->right);	// ��

		return root1;
	}
	*/
	// �������
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