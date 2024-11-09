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
	TreeNode* searchBST(TreeNode* root, int val) 
	{
		TreeNode* node = root;
		while (node != nullptr)
		{
			if (node->val == val)
				return node;
			else if (val < node->val)
				node = node->left;
			else if (val > node->val)
				node = node->right;
		}
		return nullptr;
	}
};