#include <iostream>
#include <vector>
#include <queue>

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
	// ������� ����
	int minDepth(TreeNode* root) 
	{
		if (root == nullptr)
			return 0;
		queue<TreeNode*> que;
		que.push(root);
		int level = 0;
		while (!que.empty())
		{
			auto size = que.size();
			++level;
			for(decltype(size) i = 0; i < size; i++)
			{
				TreeNode* cur = que.front();
				que.pop();
				if (cur->left == nullptr && cur->right == nullptr)
					return level;
				if (cur->left != nullptr)
					que.push(cur->left);
				if (cur->right != nullptr)
					que.push(cur->right);
			}
		}
		return level;
	}
	*/
	/*
	// �������
	int ans = INT_MAX;
	int minDepth(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		
		traversal(root, 1);

		return ans;
	}

	// 1. ȷ���βκͷ�������
	void traversal(TreeNode* node, int level)
	{
		// 2. ȷ����ֹ���� Ҷ�ӽڵ�
		if (node->left == nullptr && node->right == nullptr)
		{
			ans = min(ans, level);			// ��
			return;
		}
		// 3. ���εݹ鴦��
		if (node->left != nullptr)			// ��
		{
			level++;
			traversal(node->left, level);
			level--;
		}
		if (node->right != nullptr)			// ��
		{
			level++;
			traversal(node->right, level);
			level--;
		}
		return;
	}
	*/
	/*
	// �������
	int minDepth(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		return traversal(root);
	}

	// 1. ȷ���βκͷ�������
	int traversal(TreeNode* node)
	{
		// 2. ȷ����ֹ����
		if (node == nullptr)
			return 0;
		// 3. ���εݹ鴦��
		int level1 = traversal(node->left);
		int level2 = traversal(node->right);
		if (node->left != nullptr && node->right == nullptr)
			return 1 + level1;
		if (node->left == nullptr && node->right != nullptr)
			return 1 + level2;
		return 1 + min(level1, level2);
	}
	*/
};