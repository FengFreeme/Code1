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
	Quote& operator=(const Quote&) = default;		// ������ֵ
	Quote& operator=(Quote&&) = default;			// �ƶ���ֵ
	Quote(const string& book, double sale_price) :bookNo(book), price(sale_price) {}
	// ������Ա���� �����޸Ķ����״̬
	string isbn() const
	{
		return bookNo;
	}
	
	virtual double net_price(size_t n) const
	{
		return n * price;
	}
	// �鿽������
	// ���� clone ����ֵ����ֵ�汾
	virtual Quote* clone() const &
	{
		return new Quote(*this);
	}
	virtual Quote* clone()&&
	{
		return new Quote(std::move(*this));
	}
	// �������������ж�̬��
	virtual ~Quote() = default;
private:
	// ISBN
	string bookNo;
protected:
	// ��ͨ״̬�²������۵ļ۸�
	double price = 0.0;
};
/* ��һ�汾*/
/*
class Bulk_quote :public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) :Quote(book, p), min_qty(qty), discount(disc) {}
	double net_price(size_t cnt) const override;
private:
	// ʹ���ۿ����ߵ���͹�����
	size_t min_qty = 0;
	// ��С����ʾ���ۿ۶�
	double discount = 0.0;
};
*/
// ������
class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double price, size_t qty, double disc) {}
	// ���麯��
	double net_price(size_t n) const = 0;
	pair<size_t, double> discount_policy() const
	{
		return { quantity, discount };
	}
protected:
	// �ۿ�ʹ�õĹ�����
	size_t quantity = 0;
	// ��ʾ�ۿ۵�С��ֵ
	double discount = 0.0;
};
/* �ڶ��� */
class Bulk_quote :public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) :Disc_quote(book, p, qty, disc) {}
	double net_price(size_t cnt) const override;
	// �鿽������
	virtual Bulk_quote* clone() const&
	{
		return new Bulk_quote(*this);
	}
	virtual Bulk_quote* clone()&&
	{
		return new Bulk_quote(std::move(*this));
	}
private:
	// ʹ���ۿ����ߵ���͹�����
	size_t min_qty = 0;
	// ��С����ʾ���ۿ۶�
	double discount = 0.0;
};

class Basket
{
public:
	// Basket ʹ�úϳɵ�Ĭ�Ϲ��캯���Ϳ������Ƴ�Ա
	// ���������Ķ���
	void add_item(const Quote& sale)
	{
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale)
	{
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}
	// ����
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
/// ��̬��
double print_total(ostream& os, const Quote& item, size_t n)
{
	// ���ݴ��� item �βεĶ������͵���Quote::net_price����Bulk_quote::net_price 
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;

	return ret;
}

double Basket::total_receipt(ostream& os) const
{
	double sum = 0.0;
	// upper_bound �������������������뵱ǰ�ؼ�����ͬ������Ԫ�� ���ص�������ָ��������iter�ؼ�����ȵ�Ԫ�������һ��Ԫ�ص���һ��λ��
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		// **iter ��һ��Quote���� multiset�� count ��Ա��ͳ����multiset�ж���Ԫ�صļ�ֵ��ͬ
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}