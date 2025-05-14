#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T> string debug_rep(const T& t);
template <typename T> string debug_rep(T* p);
string debug_rep(const string&);
template <typename T> string debug_rep(const T& t)
{
	ostringstream ret;
	ret << t;
	return ret.str();
}
// ָ��
template <typename T> string debug_rep(T* p)
{
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);		// ��ӡָ��ָ���ֵ
	else
		ret << " null pointer";
	// ���� ret �󶨵� string ��һ������
	return ret.str();
}

string debug_rep(const string& s)
{
	return '"' + s + '"';
}

string debug_rep(char* p)
{
	return debug_rep(string(p));
}

string debug_rep(const char* p)
{
	return debug_rep(string(p));
}
int main()
{
	string s("hi");

	cout << debug_rep(s) << endl;

	return 0;
}