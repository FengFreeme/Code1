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
    /*
    // 层序遍历
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while (!que.empty())
        {
            auto size = que.size();
            ++level;
            for (decltype(size) i = 0; i < size; i++)
            {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->left != nullptr)
                    que.push(cur->left);
                if (cur->right != nullptr)
                    que.push(cur->right);
            }
        }
        return level;
    }
    */
    /*
    // 递归 求根节点的高度
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        return traversal(root);
    }
    // 1. 确定形参和返回类型 后序遍历 左 右 中
    int traversal(TreeNode* node)
    {
        // 2. 确定终止条件
        if (node == nullptr)
            return 0;
        // 3. 单次递归处理
        int level1 = 1 + traversal(node->left);     // 左
        int level2 = 1 + traversal(node->right);    // 右
        return max(level1, level2);                 // 中
    }
    */
    /*
    int ans;
    // 先序遍历 递归 真正的求最大深度 中 左 右
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        ans = 1;
        traversal(root, ans);

        return ans;
    }

    // 1. 确定形参和返回类型
    void traversal(TreeNode* node, int level)
    {       
        // 2. 确定终止条件
        if (node->left == nullptr && node->right == nullptr)
        {
            ans = ans > level ? ans : level;    // 中
            return;
        }
        // 3. 单次递归处理
        if (node->left != nullptr)          // 左
        {
            level++;
            traversal(node->left, level);
            level--;
        }
        if (node->right != nullptr)          // 右
        {
            level++;
            traversal(node->right, level);
            level--;
        }
        return;
    }
    */
};