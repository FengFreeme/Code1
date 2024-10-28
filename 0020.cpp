#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				st.push(s[i]);
			}
			else
			{
				if (st.empty())
					return false;
				char c = st.top();
				switch (s[i])
				{
				case ')':
					if (c == '(')
					{
						st.pop();
						break;
					}
					else
						return false;
				case '}':
					if (c == '{')
					{
						st.pop();
						break;
					}
					else
						return false;
				case ']':
					if (c == '[')
					{
						st.pop();
						break;
					}
					else
						return false;
				}
			}
		}
		if (st.empty())
			return true;
		else
			return false;
	}
};