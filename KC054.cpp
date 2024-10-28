#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int size = s.size();
	// 记录数字字符的数量
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
			count++;
	}
	s.resize(size + 5 * count);
	for (int i = size - 1, j = s.size() - 1; i >= 0; i--)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			s[j] = 'r';
			s[j - 1] = 'e';
			s[j - 2] = 'b';
			s[j - 3] = 'm';
			s[j - 4] = 'u';
			s[j - 5] = 'n';
			j = j - 6;
		}
		else
		{
			s[j] = s[i];
			j--;
		}
	}
	cout << s << endl;

	return 0;
}