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
	// 1. 确定返回类型和形参
	TreeNode* convertBST(TreeNode* root) 
	{
		// 2. 确定终止条件
		if (root == nullptr)
			return nullptr;
		// 3. 单次递归处理
		root->right = convertBST(root->right);		// 右
		root->val = root->val + sum;				// 中
		sum = root->val;
		root->left = convertBST(root->left);		// 左

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