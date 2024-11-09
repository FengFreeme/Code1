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
	// 1. 确定形参和返回类型
	vector<int> backtracking(TreeNode* node)
	{
		// 2. 确定终止条件
		if (node == nullptr)
			return { 0, 0 };
		// 3. 单次递归处理
		vector<int> left = backtracking(node->left);
		vector<int> right = backtracking(node->right);
		// left 左节点不偷的最大金钱 right 右节点不偷的最大金钱
		// 不偷当前节点
		int val1 = max(left[0], left[1]) + max(right[0], right[1]);
		// 偷当前节点
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