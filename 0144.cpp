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
    vector<int> preorderTraversal(TreeNode* root)
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
        ans.push_back(root->val);
        traversal(ans, root->left);
        traversal(ans, root->right);

        return;
    }
    */
    /*
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();           // top 处理
            ans.push_back(cur->val);
            st.pop();
            if (cur->right != nullptr)
                st.push(cur->right);            // push 访问
            if (cur->left != nullptr)
                st.push(cur->left);
        }
        return ans;
    }
    */
    vector<int> preorderTraversal(TreeNode* root)
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
                // 右 左 中
                if (cur->right != nullptr)
                    st.push(cur->right);
                if (cur->left != nullptr)
                    st.push(cur->left);

                st.push(cur);
                st.push(nullptr);
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