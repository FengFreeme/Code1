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
    // 1. ȷ�����������ͷ�������
    void traversal(vector<int> &ans, TreeNode *root)
    {
        // 2. ȷ����ֹ����
        if (root == nullptr)
            return;
        // 3. ���εݹ鴦��
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
            TreeNode *cur = st.top();           // top ����
            ans.push_back(cur->val);
            st.pop();
            if (cur->right != nullptr)
                st.push(cur->right);            // push ����
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
                // �� �� ��
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