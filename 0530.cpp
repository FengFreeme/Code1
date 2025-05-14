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
	int min_Dis = INT_MAX;
	TreeNode* pre = nullptr;
	int getMinimumDifference(TreeNode* root) 
	{
		traversal(root);

		return min_Dis;
	}
	// 1. ������� ȷ���βκͷ�������
	void traversal(TreeNode* node)
	{
		// 2. ȷ����ֹ����
		if (node == nullptr)
			return;
		// 3. ���εݹ鴦��
		traversal(node->left);
		if (pre != nullptr && node->val - pre->val < min_Dis)
		{
			min_Dis = node->val - pre->val;
		}
		pre = node;
		traversal(node->right);

		return;
	}
};