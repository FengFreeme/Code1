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
	/*
	// �ݹ�
	bool isSymmetric(TreeNode* root) 
	{
		return traversal(root->left, root->right);
	}
	// "�������" ������
	// 1. ȷ�������βκͷ�������
	bool traversal(TreeNode* left, TreeNode* right)
	{
		// 2. ȷ����ֹ����
		if (left == nullptr && right == nullptr)
			return true;
		else if (left == nullptr && right != nullptr)
			return false;
		else if (left != nullptr && right == nullptr)
			return false;
		else if (left->val != right->val)
			return false;
		// 3. ���εݹ鴦��
		bool isSame1 = traversal(left->left, right->right);		// �� ��
		bool isSame2 = traversal(left->right, right->left);		// �� ��
		return isSame1 && isSame2;								// �� ��
	}
	*/
	/*
	// �������κα�������
	bool isSymmetric(TreeNode* root)
	{
		stack<TreeNode*> st;
		st.push(root->left);
		st.push(root->right);
		while (!st.empty())
		{
			TreeNode* left = st.top();
			st.pop();
			TreeNode* right = st.top();
			st.pop();

			if (left == nullptr && right == nullptr)
				continue;
			if (left == nullptr || right == nullptr || left->val != right->val)
				return false;

			st.push(left->left);
			st.push(right->right);
			st.push(left->right);
			st.push(right->left);
		}
		return true;
	}
	*/
	
};