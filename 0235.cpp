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
	// ���ϵ��±��� ���漰������ȱ���
	// 1. ȷ���βκͷ�������
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		// 2. ȷ����ֹ����
		if (root == nullptr)
			return nullptr;
		// 3. ���εݹ鴦��
		// ���������������
		if ((p->val <= root->val && root->val <= q->val) || (q->val <= root->val && root->val <= p->val))
			return root;
		// ֻ���������ʵ�һ��·��
		else if (root->val > p->val && root->val > q->val)
		{
			TreeNode *left = lowestCommonAncestor(root->left, p, q);
			if(left != nullptr)
				return left;
		}
		else if (root->val < p->val && root->val < q->val)
		{
			TreeNode *right = lowestCommonAncestor(root->right, p, q);
			if (right != nullptr)
				return right;
		}

		return nullptr;
	}
};