#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int res = num1 + num2;
                st.push(res);
            }
            else if (tokens[i] == "-")
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int res = num1 - num2;
                st.push(res);
            }
            else if (tokens[i] == "*")
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int res = num1 * num2;
                st.push(res);
            }
            else if (tokens[i] == "/")
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int res = num1 / num2;
                st.push(res);
            }
            else
            {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};

int main()
{
    vector<string> tokens = { "4","13","5","/","+" };
    Solution S;
    S.evalRPN(tokens);

    return 0;
}