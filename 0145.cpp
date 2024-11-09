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
    vector<int> postorderTraversal(TreeNode *root) 
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
        traversal(ans, root->right);
        ans.push_back(root->val);

        return;
    }
    */
    /*
    // 中右左逆序
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            if (cur->left != nullptr)
                st.push(cur->left);
            if (cur->right != nullptr)
                st.push(cur->right);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
    */
    // 统一迭代
    vector<int> postorderTraversal(TreeNode* root)
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
                // 中右左
                st.push(cur);
                st.push(nullptr);

                if (cur->right != nullptr)
                    st.push(cur->right);

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