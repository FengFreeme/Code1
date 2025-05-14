#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	TreeNode* left, * right;
	int val;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	/*
	int ans = 0;
	// ������� �ݹ�
	int sumOfLeftLeaves(TreeNode* root) 
	{
		traversal(root);

		return ans;
	}
	// 1. ȷ���βκͷ�������
	void traversal(TreeNode* node)
	{
		// 2. ȷ����ֹ����
		
		if (node->left != nullptr)		// ��
		{
			// ����Ҷ�ڵ�
			if (node->left->left == nullptr && node->left->right == nullptr)
			{
				ans += node->left->val;
			}
			else
				traversal(node->left);
		}
		if (node->right != nullptr)		// ��
			traversal(node->right);

		return;
	}
	*/
	/*
	// �������
	int sumOfLeftLeaves(TreeNode* root)
	{
		return traversal(root);
	}
	// 1. ȷ�������ͷ�������
	int traversal(TreeNode* node)
	{
		// 2. ȷ����ֹ����
		if (node == nullptr)
			return 0;
		// 3. ���εݹ鴦��
		int num1 = 0;
		if (node->left != nullptr)			// ��
		{
			if (node->left->left == nullptr && node->left->right == nullptr)
			{
				num1 = node->left->val;
			}
			else
			{
				num1 = traversal(node->left);
			}
		}
		int num2 = traversal(node->right);	// ��
		return num1 + num2;
	}
	*/
	// ͳһ������ ǰ����� �� �� ��
	int sumOfLeftLeaves(TreeNode* root)
	{
		stack<TreeNode*> st;
		st.push(root);
		int ans = 0;
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			if (cur != nullptr)
			{
				if (cur->right != nullptr)
					st.push(cur->right);

				if (cur->left != nullptr && cur->left->left == nullptr && cur->left->right == nullptr)
					ans += cur->left->val;
				else if (cur->left != nullptr)
					st.push(cur->left);

				st.push(cur);
				st.push(nullptr);
			}
			else
			{
				cur = st.top();
				st.pop();
			}
		}
		return ans;
	}
};