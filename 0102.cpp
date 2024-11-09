#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<pair<TreeNode*, int>> que;
        que.push({ root, 1 });
        while (!que.empty())
        {   
            auto cur = que.front();
            que.pop();
            int level = cur.second;
            if (ans.size() < level)
                ans.push_back({});
            TreeNode *curNode = cur.first;
            ans[level - 1].push_back(curNode->val);

            if (curNode->left != nullptr)
                que.push({ curNode->left, level + 1 });
            if (curNode->right != nullptr)
                que.push({ curNode->right, level + 1 });
        }
        return ans;
    }
};