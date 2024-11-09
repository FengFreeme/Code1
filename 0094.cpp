#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;

        traversal(ans, root);

        return ans;
    }
    // 1. 确定函数参数和返回类型
    void traversal(vector<int> &ans, TreeNode *root)
    {
        // 2. 确定终止条件
        if (root == nullptr)
            return;
        // 3. 单次递归处理
        traversal(ans, root->left);
        ans.push_back(root->val);
        traversal(ans, root->right);

        return;
    }
    */
    /*
    // 普通迭代法
    vector<int> inorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> st;
        vector<int> ans;
        // 需要使用遍历指针 cur 按左中右顺序遍历
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;            // 左
            }
            else
            {
                cur = st.top();             // 中
                st.pop();
                ans.push_back(cur->val);
                cur = cur->right;           // 右
            }
        }
    }
    */
    // 统一迭代法
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            if (cur != nullptr)
            {
                // 右 中 左
                // 访问当前节点的左右节点
                if (cur->right != nullptr)
                    st.push(cur->right);

                st.push(cur);
                st.push(nullptr);       // 标记当前节点已经访问过

                if (cur->left != nullptr)
                    st.push(cur->left);
            }
            else
            {
                cur = st.top();
                st.pop();
                ans.push_back(cur->val);
            }
        }
        return ans;
    }
};