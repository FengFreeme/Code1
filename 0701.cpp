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
	// �ݹ�
	// ֱ�Ӳ��뵽���һ���ڵ����
	TreeNode* insertIntoBST(TreeNode* root, int val) 
	{
		if (root == nullptr)
		{
			return new TreeNode(val);
		}
		traversal(root, val);

		return root;
	}
	// 1. ȷ�������ͷ������� ������Ϊ��ȷ���Ѿ��ҵ��˲���ĵط������ü����ݹ�
	TreeNode* traversal(TreeNode* root, int val)
	{
		// 2. ȷ����ֹ����
		
		// 3. ���εݹ鴦��
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
	// ������
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