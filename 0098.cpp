#include <iostream>
#include <vector>
#include <stack>

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
	TreeNode* pre = nullptr;
	// 1. ������� ȷ���βκͷ�������
	bool isValidBST(TreeNode* root) 
	{
		// 2. ȷ����ֹ����
		if (root == nullptr)
			return true;
		bool left = isValidBST(root->left);

		if (pre != nullptr && pre->val >= root->val)
			return false;
		else
			pre = root;
		bool right = isValidBST(root->right);

		return left && right;
	}
	*/
	// ͳһ������
	bool isValidBST(TreeNode* root)
	{
		stack<TreeNode*> st;
		st.push(root);
		TreeNode* pre = nullptr;
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			if (cur != nullptr)
			{
				if (cur->right != nullptr)
					st.push(cur->right);

				st.push(cur);
				st.push(nullptr);

				if (cur->left != nullptr)
					st.push(cur->left);
			}
			else
			{
				cur = st.top();
				st.pop();
				if (pre != nullptr && pre->val >= cur->val)
					return false;
				else
					pre = cur;
			}
		}
	}
};