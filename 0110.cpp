#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	/*
	bool ans = true;
	bool isBalanced(TreeNode* root)
	{
		traversal(root);

		return ans;
	}

	// 1. ������� ȷ���βκͷ������� ���ظ߶ȱȽ�
	int traversal(TreeNode* node)
	{
		// 2. ȷ����ֹ����
		if (node == nullptr)
			return 0;
		// 3. ���εݹ鴦��
		int level1 = traversal(node->left);		// �� �����������߶�
		int level2 = traversal(node->right);	// �� �����������߶�
		ans = ans && (abs(level1 - level2) <= 1);		// �� �ж��Ƿ�Ϊƽ�������
		return 1 + max(level1, level2);
	}
	*/
	// ������� ��߶Ȳ��ж�ƽ�������
	bool ans = true;
	bool isBalanced(TreeNode* root)
	{
		traversal(root);

		return ans;
	}
	// 1. ȷ���βκͷ�������
	int traversal(TreeNode* node)
	{
		// 2. ȷ����ֹ����
		if (node == nullptr)
			return 0;
		int leftLevel = traversal(node->left);		// ��
		int rightLevel = traversal(node->right);	// ��
		ans = ans && (abs(leftLevel - rightLevel) <= 1);	// ��

		return 1 + max(leftLevel, rightLevel);
	}
};