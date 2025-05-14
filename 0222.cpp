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
	// ��ͨ��
	int ans = 0;
	int countNodes(TreeNode* root) 
	{
		traversal(root);

		return ans;
	}

	// 1. ȷ���βκͷ������� �������
	void traversal(TreeNode* node)
	{
		// 2. ȷ����ֹ����
		if (node == nullptr)
			return;
		// ���εݹ鴦��
		ans++;
		traversal(node->left);
		traversal(node->right);

		return;
	}
	*/
	// ������ȫ���������� �������
	// 1. ȷ���βκͷ�������
	int countNodes(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		int leftDepth = 1, rightDepth = 1;
		// �����������
		while (left)
		{
			left = left->left;
			++leftDepth;
		}
		while (right)
		{
			right = right->right;
			++rightDepth;
		}
		if (leftDepth == rightDepth)
			return ((2 << (leftDepth - 1)) - 1);		// 2 << 1 �൱��2^2

		int leftNum = countNodes(root->left);				// ��
		int rightNum = countNodes(root->right);				// ��
			
		return	1 + leftNum + rightNum;						// �� �ڵ㱾�� + �ڵ��������ڵ����� + �ڵ��������ڵ�����
	}
};