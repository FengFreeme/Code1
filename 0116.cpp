#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int val;
	Node *left, *right, *next;
	Node() :val(0), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution 
{
public:
	Node* connect(Node* root) 
	{
		if (root == nullptr)
			return nullptr;
		queue<Node*> que;
		que.push(root);
		while (!que.empty())
		{
			auto size = que.size();
			Node *pre;
			for (decltype(size) i = 0; i < size; i++)
			{
				Node *cur = que.front();
				que.pop();
				if (cur->left != nullptr)
					que.push(cur->left);
				if (cur->right != nullptr)
					que.push(cur->right);

				if (size < 2)
					continue;
				if (i == 0)
					pre = cur;
				else
				{
					pre->next = cur;
					pre = cur;
				}
			}
		}
		return root;
	}
};