#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const Quote&) = default;
	Quote(Quote&&) = default;
	Quote& operator=(const Quote&) = default;		// 拷贝赋值
	Quote& operator=(Quote&&) = default;			// 移动赋值
	Quote(const string& book, double sale_price) :bookNo(book), price(sale_price) {}
	// 常量成员函数 不会修改对象的状态
	string isbn() const
	{
		return bookNo;
	}
	
	virtual double net_price(size_t n) const
	{
		return n * price;
	}
	// 虚拷贝函数
	// 定义 clone 的左值和右值版本
	virtual Quote* clone() const &
	{
		return new Quote(*this);
	}
	virtual Quote* clone()&&
	{
		return new Quote(std::move(*this));
	}
	// 对析构函数进行动态绑定
	virtual ~Quote() = default;
private:
	// ISBN
	string bookNo;
protected:
	// 普通状态下不被打折的价格
	double price = 0.0;
};
/* 第一版本*/
/*
class Bulk_quote :public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) :Quote(book, p), min_qty(qty), discount(disc) {}
	double net_price(size_t cnt) const override;
private:
	// 使用折扣政策的最低购买量
	size_t min_qty = 0;
	// 以小数表示的折扣额
	double discount = 0.0;
};
*/
// 抽象类
class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price, size_t qty, double disc) {}
	// 纯虚函数
	double net_price(size_t n) const = 0;
	pair<size_t, double> discount_policy() const
	{
		return { quantity, discount };
	}
protected:
	// 折扣使用的购买量
	size_t quantity = 0;
	// 表示折扣的小数值
	double discount = 0.0;
};
/* 第二版 */
class Bulk_quote :public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) :Disc_quote(book, p, qty, disc) {}
	double net_price(size_t cnt) const override;
	// 虚拷贝函数
	virtual Bulk_quote* clone() const&
	{
		return new Bulk_quote(*this);
	}
	virtual Bulk_quote* clone()&&
	{
		return new Bulk_quote(std::move(*this));
	}
private:
	// 使用折扣政策的最低购买量
	size_t min_qty = 0;
	// 以小数表示的折扣额
	double discount = 0.0;
};

class Basket
{
public:
	// Basket 使用合成的默认构造函数和拷贝控制成员
	// 拷贝给定的对象
	void add_item(const Quote& sale)
	{
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale)
	{
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}
	// 声明
	double total_receipt(ostream&) const;
	
private:
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(compare)*>items{ compare };
};

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
/// 动态绑定
double print_total(ostream& os, const Quote& item, size_t n)
{
	// 根据传入 item 形参的对象类型调用Quote::net_price或者Bulk_quote::net_price 
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;

	return ret;
}

double Basket::total_receipt(ostream& os) const
{
	double sum = 0.0;
	// upper_bound 函数可以令我们跳过与当前关键字相同的所有元素 返回迭代器：指向左右与iter关键字相等的元素中最后一个元素的下一个位置
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		// **iter 是一个Quote对象 multiset的 count 成员来统计在multiset有多少元素的键值相同
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}