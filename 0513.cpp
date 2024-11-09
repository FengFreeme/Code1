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
	int maxDepth = 0;
	int ans;
	// 先序遍历
	int findBottomLeftValue(TreeNode* root) 
	{
		traversal(root, 1);
		return ans;
	}
	// 1. 确定参数和返回类型
	void traversal(TreeNode* node, int depth)
	{
		// 2. 确定终止条件 叶子节点
		if (node->left == nullptr && node->right == nullptr)	// 中
		{
			if (maxDepth < depth)
			{
				maxDepth = depth;
				ans = node->val;
			}
		}
		// 3. 单次递归处理
		if (node->left != nullptr)
		{
			depth++;
			traversal(node->left, depth);
			depth--;
		}
		if (node->right != nullptr)
		{
			depth++;
			traversal(node->right, depth);
			depth--;
		}
	}
};