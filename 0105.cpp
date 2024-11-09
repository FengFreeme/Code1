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
	// 1. 确定形参和返回类型
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		// 2. 确定终止条件
		if (preorder.size() == 0)
			return nullptr;
		// 3. 单次递归处理
		int rootVal = preorder[0];
		TreeNode* root = new TreeNode(rootVal);
		int index = GetIndex(inorder, rootVal);
		// 分割
		vector<int> LeftInorder(inorder.begin(), inorder.begin() + index);
		vector<int> RightInorder(inorder.begin() + index + 1, inorder.end());
		vector<int> LeftPreorder(preorder.begin() + 1, preorder.begin() + 1 + LeftInorder.size());
		vector<int> RightPreorder(preorder.begin() + 1 + LeftInorder.size(), preorder.end());
		root->left = buildTree(LeftPreorder, LeftInorder);
		root->right = buildTree(RightPreorder, RightInorder);

		return root;
	}
	int GetIndex(vector<int>& inorder, int num)
	{
		for (int i = 0; i < inorder.size(); i++)
		{
			if (inorder[i] == num)
				return i;
		}
		return -1;
	}
};