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
	vector<vector<int>> ans;
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
	{
		if (root == nullptr)
			return ans;
		vector<int> path;
		path.push_back(root->val);
		traversal(root, path, root->val, targetSum);

		return ans;
	}
	// 1. ȷ���βκͷ�������
	void traversal(TreeNode* node, vector<int> path, int sum, int targetSum)
	{
		// 2. ȷ����ֹ����
		if (node->left == nullptr && node->right == nullptr)		// ��
		{
			if (sum == targetSum)
			{
				ans.push_back(path);
			}
		}
		// 3. ���εݹ鴦��
		if (node->left != nullptr)		// ��
		{
			path.push_back(node->left->val);
			sum += node->left->val;
			traversal(node->left, path, sum, targetSum);
			sum -= node->left->val;
			path.pop_back();
		}
		if (node->right != nullptr)		// ��
		{
			path.push_back(node->right->val);
			sum += node->right->val;
			traversal(node->right, path, sum, targetSum);
			sum -= node->right->val;
			path.pop_back();
		}
		return;
	}
};