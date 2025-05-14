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
	int maxDepth = 0;
	int ans;
	// �������
	int findBottomLeftValue(TreeNode* root) 
	{
		traversal(root, 1);
		return ans;
	}
	// 1. ȷ�������ͷ�������
	void traversal(TreeNode* node, int depth)
	{
		// 2. ȷ����ֹ���� Ҷ�ӽڵ�
		if (node->left == nullptr && node->right == nullptr)	// ��
		{
			if (maxDepth < depth)
			{
				maxDepth = depth;
				ans = node->val;
			}
		}
		// 3. ���εݹ鴦��
		if (node->left != nullptr)
		{
			depth++;
			traversal(node->left, depth);
			depth--;
		}
		if (node->right != nullptr)
		{
			depth++;
			traversal(node->right, depth);
			depth--;
		}
	}
};