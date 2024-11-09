#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int val;
	vector<Node*> children;
	
};

class Solution 
{
public:
	vector<vector<int>> levelOrder(Node* root) 
	{
		vector<vector<int>> ans;
		if (root == nullptr)
			return ans;
		queue<Node*> que;
		que.push(root);

		while (!que.empty())
		{
			vector<int> nodes;
			auto size = que.size();
			for (decltype(size) i = 0; i < size; i++)
			{
				Node* cur = que.front();
				que.pop();
				nodes.push_back(cur->val);
				for (auto node : cur->children)
				{
					que.push(node);
				}
			}
			ans.push_back(nodes);
		}
		return ans;
	}
};