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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
	{
		return build(nums);
	}
	// 1. 确定形参和返回类型
	TreeNode* build(vector<int>& nums)
	{
		// 2. 确定终止条件
		if (nums.size() == 0)
			return nullptr;

		int index = getIndex(nums);
		TreeNode* root = new TreeNode(nums[index]);
		vector<int> leftNums(nums.begin(), nums.begin() + index);
		vector<int> rightNums(nums.begin() + index + 1, nums.end());
		root->left = build(leftNums);
		root->right = build(rightNums);

		return root;
	}
	int getIndex(vector<int>& nums)
	{
		int maxNum = INT_MIN;
		int index = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (maxNum < nums[i])
			{
				maxNum = nums[i];
				index = i;
			}
		}
		return index;
	}
};