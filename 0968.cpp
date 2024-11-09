#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
	int ans = 0;
	int minCameraCover(TreeNode* root) 
	{
		// 如果头结点没有被覆盖，需要加一个摄像头
		if (traversal(root) == 0)
			++ans;
		return ans;
	}
	// 胡须遍历 递归
	int traversal(TreeNode* cur)
	{
		if (cur == nullptr)
			return 2;
		int left = traversal(cur->left);	// 左
		int right = traversal(cur->right);	// 右
		// 左右节点都有覆盖 所以由其父节点覆盖
		if (left == 2 && right == 2)
			return 0;
		// 无覆盖
		if(left == 0 || right == 0)
		{
			++ans;
			return 1;		//	本节点有摄像头
		}
		// 已被覆盖
		if (left == 1 || right == 1)
			return 2;

		return -1;
	}
};