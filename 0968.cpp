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
		// ���ͷ���û�б����ǣ���Ҫ��һ������ͷ
		if (traversal(root) == 0)
			++ans;
		return ans;
	}
	// ������� �ݹ�
	int traversal(TreeNode* cur)
	{
		if (cur == nullptr)
			return 2;
		int left = traversal(cur->left);	// ��
		int right = traversal(cur->right);	// ��
		// ���ҽڵ㶼�и��� �������丸�ڵ㸲��
		if (left == 2 && right == 2)
			return 0;
		// �޸���
		if(left == 0 || right == 0)
		{
			++ans;
			return 1;		//	���ڵ�������ͷ
		}
		// �ѱ�����
		if (left == 1 || right == 1)
			return 2;

		return -1;
	}
};