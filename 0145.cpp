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
    // 1. ȷ�����������ͷ�������
    void traversal(vector<int> &ans, TreeNode *root)
    {
        // 2. ȷ����ֹ����
        if (root == nullptr)
            return;
        // 3. ���εݹ鴦��
        traversal(ans, root->left);
        traversal(ans, root->right);
        ans.push_back(root->val);

        return;
    }
    */
    /*
    // ����������
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
    // ͳһ����
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
                // ������
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