#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left, * right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	int rob(TreeNode* root) 
	{
		vector<int> res = backtracking(root);

		return max( res[0], res[1] );
	}
	// 1. ȷ���βκͷ�������
	vector<int> backtracking(TreeNode* node)
	{
		// 2. ȷ����ֹ����
		if (node == nullptr)
			return { 0, 0 };
		// 3. ���εݹ鴦��
		vector<int> left = backtracking(node->left);
		vector<int> right = backtracking(node->right);
		// left ��ڵ㲻͵������Ǯ right �ҽڵ㲻͵������Ǯ
		// ��͵��ǰ�ڵ�
		int val1 = max(left[0], left[1]) + max(right[0], right[1]);
		// ͵��ǰ�ڵ�
		int val2 = node->val + left[0] + right[0];

		return {val1, val2};
	}
};

int main()
{
	Solution S;
	TreeNode* a = new TreeNode(3);
	a->left = new TreeNode(2);
	a->right = new TreeNode(3);
	a->left->right = new TreeNode(3);
	a->right->right = new TreeNode(1);

	S.rob(a);

	return 0;
}