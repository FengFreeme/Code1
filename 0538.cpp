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
	int sum = 0;
	// 1. ȷ���������ͺ��β�
	TreeNode* convertBST(TreeNode* root) 
	{
		// 2. ȷ����ֹ����
		if (root == nullptr)
			return nullptr;
		// 3. ���εݹ鴦��
		root->right = convertBST(root->right);		// ��
		root->val = root->val + sum;				// ��
		sum = root->val;
		root->left = convertBST(root->left);		// ��

		return root;
	}
};

int main()
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(2);
	// root->left->right->left = new TreeNode(1);
	root->right = new TreeNode(4);
	// root->right->right = new TreeNode(7);

	Solution S;
	TreeNode* no = S.convertBST(root);

	return 0;
}