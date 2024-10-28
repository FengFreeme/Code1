#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution 
{
public:
    string removeDuplicates(string s) 
    {
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() || s[i] != st.top())
            {
                st.push(s[i]);
            }
            else if (!st.empty() && s[i] == st.top())
            {
                st.pop();
            }
        }
        // ¼ÇÂ¼´ð°¸
        string t;
        while (!st.empty())
        {
            t = st.top() + t;
            st.pop();
        }
        return t;
    }
};