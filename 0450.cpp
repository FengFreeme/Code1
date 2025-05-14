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
	// ������
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
		// �ж�cur��parent������������������
		// ���curû����������ֱ��ɾ��
		// curû��������������������
		// ������������Ժϲ�
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
		// cur ��������
		TreeNode* right = cur->right;
		// ��������������߽ڵ�
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
	// �ݹ鷨
	// 1. ȷ���βκͷ�������
	TreeNode* deleteNode(TreeNode* root, int key)
	{
		// 2. ȷ����ֹ����
		// ��һ����� û�ҵ�ɾ���Ľڵ� ֱ�ӷ���
		if (root == nullptr)
			return root;
		if (root->val == key)
		{
			// �ڶ�����������Һ��Ӷ�Ϊ�� ֱ��ɾ���ڵ�
			if (root->left == nullptr && root->right == nullptr)
			{
				delete root;
				root = nullptr;
				return root;
			}
			// ��������� ����Ϊ�� �Һ��Ӳ�Ϊ�� ɾ���ڵ� �Һ��Ӳ�λ
			else if (root->left == nullptr)
			{
				auto retNode = root->right;
				delete root;
				return retNode;
			}
			// ��������� ���Ӳ�Ϊ�� �Һ���Ϊ�� ɾ���ڵ� ���Ӳ�λ
			else if (root->right == nullptr)
			{
				auto retNode = root->left;
				delete root;
				return retNode;
			}
			// ��������� ���Һ��Ӷ���Ϊ��
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