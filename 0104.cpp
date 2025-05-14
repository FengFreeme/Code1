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
    // �������
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
    // �ݹ� ����ڵ�ĸ߶�
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        return traversal(root);
    }
    // 1. ȷ���βκͷ������� ������� �� �� ��
    int traversal(TreeNode* node)
    {
        // 2. ȷ����ֹ����
        if (node == nullptr)
            return 0;
        // 3. ���εݹ鴦��
        int level1 = 1 + traversal(node->left);     // ��
        int level2 = 1 + traversal(node->right);    // ��
        return max(level1, level2);                 // ��
    }
    */
    /*
    int ans;
    // ������� �ݹ� �������������� �� �� ��
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        ans = 1;
        traversal(root, ans);

        return ans;
    }

    // 1. ȷ���βκͷ�������
    void traversal(TreeNode* node, int level)
    {       
        // 2. ȷ����ֹ����
        if (node->left == nullptr && node->right == nullptr)
        {
            ans = ans > level ? ans : level;    // ��
            return;
        }
        // 3. ���εݹ鴦��
        if (node->left != nullptr)          // ��
        {
            level++;
            traversal(node->left, level);
            level--;
        }
        if (node->right != nullptr)          // ��
        {
            level++;
            traversal(node->right, level);
            level--;
        }
        return;
    }
    */
};