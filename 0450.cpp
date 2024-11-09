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
	/*
	// 迭代法
	TreeNode* deleteNode(TreeNode* root, int key) 
	{
		if (root == nullptr)
			return root;
		else if (root->val == key)
		{
			if (root->right == nullptr)
			{
				TreeNode* newRoot = root->left;
				delete root;
				root = nullptr;
				return newRoot;
			}
			else if (root->right != nullptr)
			{
				TreeNode* newRoot = root->right;
				TreeNode* right = root->right;
				while (right->left != nullptr)
					right = right->left;
				right->left = root->left;
				delete root;
				root = nullptr;
				return newRoot;
			}
		}
		TreeNode* cur = root;
		TreeNode* parent = nullptr;
		while (cur != nullptr)
		{
			if (key < cur->val)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (key > cur->val)
			{
				parent = cur;
				cur = cur->right;
			}
			else
				break;
		}
		if (cur == nullptr)
			return root;
		// 判断cur是parent的左子树还是右子树
		// 如果cur没有左右子树直接删除
		// cur没有有右子树，有左子树
		// 这两个情况可以合并
		if(cur->right == nullptr)
		{
			if (cur->val < parent->val)
			{
				parent->left = cur->left;
				delete cur;
				cur = nullptr;
				return root;
			}
			else
			{
				parent->right = cur->left;
				delete cur;
				cur = nullptr;
				return root;
			}
		}
		// cur 有右子树
		TreeNode* right = cur->right;
		// 找右子树的最左边节点
		while (right->left != nullptr)
			right = right->left;
		right->left = cur->left;
		if (cur->val < parent->val)
		{
			parent->left = cur->right;
			delete cur;
			cur = nullptr;
			return root;
		}
		else
		{
			parent->right = cur->right;
			delete cur;
			cur = nullptr;
			return root;
		}
		return root;
	}
	*/
	// 递归法
	// 1. 确定形参和返回类型
	TreeNode* deleteNode(TreeNode* root, int key)
	{
		// 2. 确定终止条件
		// 第一种情况 没找到删除的节点 直接返回
		if (root == nullptr)
			return root;
		if (root->val == key)
		{
			// 第二种情况：左右孩子都为空 直接删除节点
			if (root->left == nullptr && root->right == nullptr)
			{
				delete root;
				root = nullptr;
				return root;
			}
			// 第三种情况 左孩子为空 右孩子不为空 删除节点 右孩子补位
			else if (root->left == nullptr)
			{
				auto retNode = root->right;
				delete root;
				return retNode;
			}
			// 第四种情况 左孩子不为空 右孩子为空 删除节点 左孩子补位
			else if (root->right == nullptr)
			{
				auto retNode = root->left;
				delete root;
				return retNode;
			}
			// 第五种情况 左右孩子都不为空
			else
			{
				TreeNode* cur = root->right;
				while (cur->left != nullptr)
					cur = cur->left;
				cur->left = root->left;
				TreeNode* tmp = root;
				root = root->right;
				delete tmp;
				tmp = nullptr;
				return root;
			}
		}
		if (root->val > key)
			root->left = deleteNode(root->left, key);
		else
			root->right = deleteNode(root->right, key);
		return root;
	}
};

int main()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(6);
	root->right->right = new TreeNode(7);

	Solution S;
	S.deleteNode(root, 7);

	return 0;
}