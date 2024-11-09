#include <functional>
#include <string>

using namespace std;

struct Sales_data
{

};
namespace std
{
	template <> struct hash<Sales_data>
	{
		// 用来散列一个无序容器的类型必须定义以下类型
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data& s) const;
	};
}

size_t hash<Sales_data>::operator()(const Sales_data& s) const
{
	return hash<string>()(s.bookNo) ^
		hash<unsigned>()(s.units_sold) ^
		hash<double>()(s.revenu);
}