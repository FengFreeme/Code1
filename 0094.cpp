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
    // 1. ȷ�����������ͷ�������
    void traversal(vector<int> &ans, TreeNode *root)
    {
        // 2. ȷ����ֹ����
        if (root == nullptr)
            return;
        // 3. ���εݹ鴦��
        traversal(ans, root->left);
        ans.push_back(root->val);
        traversal(ans, root->right);

        return;
    }
    */
    /*
    // ��ͨ������
    vector<int> inorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> st;
        vector<int> ans;
        // ��Ҫʹ�ñ���ָ�� cur ��������˳�����
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty())
        {
            if (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;            // ��
            }
            else
            {
                cur = st.top();             // ��
                st.pop();
                ans.push_back(cur->val);
                cur = cur->right;           // ��
            }
        }
    }
    */
    // ͳһ������
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
                // �� �� ��
                // ���ʵ�ǰ�ڵ�����ҽڵ�
                if (cur->right != nullptr)
                    st.push(cur->right);

                st.push(cur);
                st.push(nullptr);       // ��ǵ�ǰ�ڵ��Ѿ����ʹ�

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