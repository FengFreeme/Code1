#include <iostream>
#include <vector>

using namespace std;

class DebugDelete
{
public:
	DebugDelete(ostream& s = std::cerr) :os(s) {}
	// ���κκ���ģ����ͬ��T�������ɱ������ƶ�
	template <typename T> void operator()(T* p) const
	{
		os << "deleing unique_ptr" << endl;
		delete p;
	}
private:
	ostream& os;
};