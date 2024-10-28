#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		vector<int> hash(26, 0);
		for (int i = 0; i < magazine.size(); i++)
		{
			hash[magazine[i] - 'a']++;
		}
		for (int i = 0; i < ransomNote.size(); i++)
		{
			if (hash[ransomNote[i] - 'a'] > 0)
			{
				hash[ransomNote[i] - 'a']--;
			}
			else
				return false;
		}
		return true;
	}
};