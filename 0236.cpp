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
	// ������� �� �� ��
	// 1. ȷ���βκͷ�������
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		// 2. ȷ����ֹ����
		if (root == nullptr || root == p || root == q)
			return root;
		// 3. ���εݹ鴦��
		TreeNode* left = lowestCommonAncestor(root->left, p, q);	// ��
		TreeNode* right = lowestCommonAncestor(root->right, p, q);	// ��
		// ���ڹ������� ���ع�������
		// 1. ���һ ������������������ p �� q
		// /���������������
		if (left != nullptr && right != nullptr)		// ��
			return root;
		// 2. ��ʱleft������p����q��Ҳ�������Ѿ��ҵ��������������
		else if (left != nullptr && right == nullptr)
			return left;
		else if (left == nullptr && right != nullptr)
			return right;
		// ������ ���� nullptr
		return nullptr;
	}
	*/
	// �������
	// �� �� ��
	// 1. ȷ�������ͷ�������
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		// 2. ȷ����ֹ����
		if (root == nullptr || root == q || root == p)
			return root;
		// 3. ���εݹ鴦��
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left != nullptr && right == nullptr)
			return left;
		else if (left == nullptr && right != nullptr)
			return right;
		else if (left != nullptr && right != nullptr)
			return root;

		return nullptr;
	}
};