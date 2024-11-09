#include <iostream>
#include <vector>

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
// 指针
template <typename T> string debug_rep(T* p)
{
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);		// 打印指针指向的值
	else
		ret << " null pointer";
	// 返回 ret 绑定的 string 的一个副本
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

template <typename T> ostream& print(ostream& os, const T& t)
{
	return os << t;
}

template <typename T, typename ...Args> ostream& print(ostream& os, const T& t, const Args... rest)
{
	os << t << ", ";
	return print(os, rest...);
}

template <typename... Args> ostream& errorMsg(ostream& os, const Args&... rest)
{
	return print(os, debug_rep(rest)...);
}
int main()
{
	int i = 1;
	string s("hi");
	print(cout, i, s, 42);

	return 0;
}