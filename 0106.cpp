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
	// 引用 避免拷贝 减少资源浪费
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
	{
		return build(inorder, postorder);
	}
	// 1. 确定形参和返回类型
	TreeNode* build(vector<int>& inorder, vector<int>& postorder)
	{
		// 2. 确定终止条件
		if (inorder.size() == 0)
			return nullptr;
		// 3. 单次递归处理
		int rootVal = postorder[postorder.size() - 1];
		// 类内的构造函数一般是内联函数
		TreeNode* root = new TreeNode(rootVal);
		int index = getIndex(inorder, root->val);
		// 左闭右开
		vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
		vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
		vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
		vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end() - 1);
		root->left = build(leftInorder, leftPostorder);
		root->right = build(rightInorder, rightPostorder);

		return root;
	}
	// 获取中序相应下标
	int getIndex(vector<int>& inorder, int num)
	{
		for (int i = 0; i < inorder.size(); i++)
		{
			if (inorder[i] == num)
				return i;
		}
		return -1;
	}
};

int main()
{
	vector<int> inorder = { 9,3,15,20,7 }, postorder = { 9,15,7,20,3 };
	// 创建一个实例对象
	Solution S;
	S.buildTree(inorder, postorder);

	return 0;
}