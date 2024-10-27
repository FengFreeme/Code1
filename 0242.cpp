#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	// 数组作为哈希表
	bool isAnagram(string s, string t) 
	{
		vector<int> hash(26, 0);
		for (int i = 0; i < s.size(); i++)
		{
			hash[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++)
		{
			if (hash[t[i] - 'a'] > 0)
				hash[t[i] - 'a']--;
			else
				return false;
		}
		for (int i = 0; i < 26; i++)
		{
			if (hash[i] != 0)
				return false;
		}
		return true;
	}
};

int main()
{
	char s = 'a';

	cout << (int)'a' << endl;

	return 0;
}