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
	// 1. ȷ���βκͷ�������
	TreeNode* trimBST(TreeNode* root, int low, int high) 
	{
		// 2. ȷ����ֹ����
		if (root == nullptr)
			return root;
		// 3. ���εݹ�
		// �����䷶Χ
		if (root->val <= high && root->val >= low)
		{
			root->left = trimBST(root->left, low, high);
			root->right = trimBST(root->right, low, high);
		}
		// �����ұ߽�ֵ
		else if (root->val > high)
		{
			TreeNode *left = trimBST(root->left, low, high);
			return left;
		}
		// С����߽�ֵ
		else if (root->val < low)
		{
			TreeNode* right = trimBST(root->right, low, high);
			return right;
		}
		return root;
	}
	*/
	// ����
	TreeNode* trimBST(TreeNode* root, int low, int high)
	{
		if (root == nullptr)
			return root;
		// ����ͷ��� ��root�ƶ���[L, R]��Χ��
		while (root != nullptr && (root->val < low || root->val > high))
		{
			if (root->val < low)
				root = root->right;
			else
				root = root->left;
		}
		TreeNode* cur = root;
		// ����������
		while (cur != nullptr)
		{
			while (cur->left && cur->left->val < low)
				cur->left = cur->left->right;
			cur = cur->left;
		}
		cur = root;
		while (cur != nullptr)
		{
			while (cur->right && cur->right->val > high)
			{
				cur->right = cur->right->left;
			}
			cur = cur->right;
		}
		return root;
	}
};

int main()
{
	TreeNode* root = new TreeNode(1);
	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(2);
	// root->left->right = new TreeNode(2);
	// root->left->right->left = new TreeNode(1);
	root->right = new TreeNode(2);
	// root->right->right = new TreeNode(7);

	Solution S;
	TreeNode *no = S.trimBST(root, 2, 4);

	return 0;
}