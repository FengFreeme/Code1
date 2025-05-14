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
	// �ݹ�
	/*
	TreeNode* invertTree(TreeNode* root) 
	{
		if (root == nullptr)
			return root;

		preTraversal(root);

		return root;
	}
	// ǰ�����
	// 1. ȷ�������ͷ�������
	void preTraversal(TreeNode* node)
	{
		// 2. ȷ����ֹ����
		if (node == nullptr)
			return;
		// 3. ���εݹ鴦��
		// ���� �� �ڵ�
		if (node->left != nullptr || node->right != nullptr)
		{
			TreeNode *tmp = node->left;
			node->left = node->right;
			node->right = tmp;
		}
		preTraversal(node->left);
		preTraversal(node->right);

		return;
	}
	*/
	// ͳһ������ 
	TreeNode* invertTree(TreeNode* root)
	{
		if (root == nullptr)
			return nullptr;
		// ʹ��������� �� �� ��
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			if (cur != nullptr)
			{
				if (cur->right != nullptr)
					st.push(cur->right);
				if (cur->left != nullptr)
					st.push(cur->left);

				st.push(cur);
				st.push(nullptr);
			}
			else
			{
				cur = st.top();
				st.pop();
				if (cur->left != nullptr || cur->right != nullptr)
				{
					TreeNode* tmp = cur->right;
					cur->right = cur->left;
					cur->left = tmp;
				}
			}
		}
		return root;
	}
};