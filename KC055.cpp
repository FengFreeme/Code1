#include <iostream>
#include <string>

using namespace std;
// ×ó±ÕÓÒ±Õ
void ReverseStr(string& s, int low, int high)
{
	while (low < high)
	{
		char tmp = s[high];
		s[high] = s[low];
		s[low] = tmp;
		low++;
		high--;
	}
}
int main()
{
	int k;
	string s;
	cin >> k >> s;
	ReverseStr(s, 0, s.size() - 1);
	ReverseStr(s, 0, k - 1);
	ReverseStr(s, k, s.size() - 1);

	cout << s << endl;
	return 0;
}