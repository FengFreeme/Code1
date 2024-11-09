#include <iostream>
#include <vector>

using namespace std;

class DebugDelete
{
public:
	DebugDelete(ostream& s = std::cerr) :os(s) {}
	// 与任何函数模板相同，T的类型由编译器推断
	template <typename T> void operator()(T* p) const
	{
		os << "deleing unique_ptr" << endl;
		delete p;
	}
private:
	ostream& os;
};