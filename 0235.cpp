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
	// 从上到下遍历 不涉及深度优先遍历
	// 1. 确定形参和返回类型
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		// 2. 确定终止条件
		if (root == nullptr)
			return nullptr;
		// 3. 单次递归处理
		// 遇到最近公共祖先
		if ((p->val <= root->val && root->val <= q->val) || (q->val <= root->val && root->val <= p->val))
			return root;
		// 只需搜索合适的一条路径
		else if (root->val > p->val && root->val > q->val)
		{
			TreeNode *left = lowestCommonAncestor(root->left, p, q);
			if(left != nullptr)
				return left;
		}
		else if (root->val < p->val && root->val < q->val)
		{
			TreeNode *right = lowestCommonAncestor(root->right, p, q);
			if (right != nullptr)
				return right;
		}

		return nullptr;
	}
};