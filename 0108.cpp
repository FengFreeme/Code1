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
	// 1. 递归 确定形参和返回类型
	TreeNode* sortedArrayToBST(vector<int>& nums) 
	{
		// 2. 确定终止条件
		if (nums.size() == 0)
			return nullptr;
		// 循环不变量 左闭右闭
		int mid = (nums.size() - 1) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		vector<int> leftnums(nums.begin(), nums.begin() + mid);
		vector<int> rightnums(nums.begin() + mid + 1, nums.end());
		root->left = sortedArrayToBST(leftnums);
		root->right = sortedArrayToBST(rightnums);

		return root;
	}
};

int main()
{
	vector<int> nums = { -10, -3, 0, 5, 9 };

	Solution S;
	S.sortedArrayToBST(nums);

	return 0;
}