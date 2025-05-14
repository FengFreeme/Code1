#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left, * right;
	// ���캯��
	TreeNode() :left(nullptr), right(nullptr), val(0) {}
	TreeNode(int num) :left(nullptr), right(nullptr), val(num) {}
};

class Solution 
{
public:
	/*
	// �������
	TreeNode* pre = nullptr;
	int count = 0;
	int max_count = INT_MIN;
	vector<int> ans;
	vector<int> findMode(TreeNode* root) 
	{
		traversal(root);

		return ans;
	}
	// �ݹ� �������
	// 1. ȷ�������ͷ�������
	void traversal(TreeNode* node)
	{
		// 2. ȷ����ֹ����
		if (node == nullptr)
		{
			return;
		}
		// 3. ���εݹ鴦��
		traversal(node->left);		// ��
		// �� pre Ϊ nullptrʱ��˵���ǱȽϵĵ�һ��Ԫ��
		if (pre == nullptr)			// ��
			count = 1;
		else if (pre->val == node->val)
			count++;
		else if (pre->val < node->val)
		{
			count = 1;
		}
		// ����ֿ�����
		if (count > max_count)
		{
			ans.clear();
			ans.push_back(node->val);
			max_count = count;
		}
		else if (count == max_count)
		{
			ans.push_back(node->val);
		}
		pre = node;
		traversal(node->right);		// ��

		return;
	}
	*/
	/*
	// �������
	vector<int> findMode(TreeNode* root)
	{
		vector<int> ans;
		stack<TreeNode*> st;
		st.push(root);
		TreeNode* pre = nullptr;
		int count = 0;
		int max_count = INT_MIN;
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
				if (pre == nullptr)
					count = 1;
				else if (pre->val == cur->val)
					count++;
				else if (pre->val < cur->val)
					count = 1;

				if (count > max_count)
				{
					max_count = count;
					ans.clear();
					ans.push_back(cur->val);
				}
				else if (count == max_count)
					ans.push_back(cur->val);

				pre = cur;
			}
		}
		return ans;
	}
	*/
	
	// ������� �ݹ�
	vector<int> ans;
	int max_count = INT_MIN;
	int count = 0;
	TreeNode* pre = nullptr;
	vector<int> findMode(TreeNode* root)
	{
		traversal(root);

		return ans;
	}
	// 1. ȷ���βοɷ�������
	void traversal(TreeNode* node)
	{
		// 2. ȷ����ֹ����
		if (node == nullptr)
			return;
		// 3. ���εݹ鴦��
		traversal(node->left);		// ��

		if (pre == nullptr)			// ��
			count = 1;
		else if (pre->val < node->val)
			count = 1;
		else if (pre->val == node->val)
			count++;

		if (max_count < count)
		{
			max_count = count;
			ans.clear();
			ans.push_back(node->val);
		}
		else if (max_count == count)
			ans.push_back(node->val);

		pre = node;
		traversal(node->right);		// ��

		return;
	}
};

int main()
{
	TreeNode* node = new TreeNode(1);
	node->right = new TreeNode(2);
	node->right->left = new TreeNode(2);

	Solution S;
	S.findMode(node);

	return 0;
}