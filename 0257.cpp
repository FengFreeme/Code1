#include <iostream>
#include <vector>
#include <string>
#include <stack>

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
	vector<string> ans;
	string s;
	/*
	// �ݹ�
	vector<string> binaryTreePaths(TreeNode* root) 
	{
		if (root == nullptr)
			return ans;
		s = s + to_string(root->val);

		traversal(root);

		return ans;
	}

	// 1. ȷ���βκͷ������� �������
	void traversal(TreeNode* node)
	{
		// 2. ȷ����ֹ����		
		if (node->left == nullptr && node->right == nullptr)		// ��
		{
			ans.push_back(s);
			return;
		}
		// 3. ���εݹ鴦��
		if (node->left != nullptr)
		{
			s = s + "->" + to_string(node->left->val);
			traversal(node->left);
			s.resize(s.size() - to_string(node->left->val).size() - 2);
		}
		if (node->right != nullptr)
		{
			s = s + "->" + to_string(node->right->val);
			traversal(node->right);
			s.resize(s.size() - to_string(node->right->val).size() - 2);
		}
		return;
	}
	*/
	// ͳһ������ ǰ����� �� �� ��
	
	vector<string> binaryTreePaths(TreeNode* root)
	{
		stack<TreeNode*> st;
		st.push(root);
		vector<string> ans;
		stack<string> pathSt;
		pathSt.push(to_string(root->val));
		while (!st.empty())
		{
			TreeNode* cur = st.top();
			st.pop();
			
			if (cur != nullptr)
			{
				string path = pathSt.top();
				pathSt.pop();
				if (cur->left == nullptr && cur->right == nullptr)
				{
					ans.push_back(path);
				}
				if (cur->right != nullptr)
				{
					st.push(cur->right);
					pathSt.push(path + "->" + to_string(cur->right->val));
				}
				if (cur->left != nullptr)
				{
					st.push(cur->left);
					pathSt.push(path + "->" + to_string(cur->left->val));
				}
				
				st.push(cur);
				st.push(nullptr);
			}
			else
			{
				cur = st.top();
				st.pop();
			}
		}
		return ans;
	}
	
	
};