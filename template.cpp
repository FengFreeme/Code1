#include <iostream>
#include <vector>

using namespace std;
// 函数模板 类型参数
template <typename T> int compare(const T& v1, const T& v2)
{
	if (v1 < v2)
		return -1;
	if (v1 > v2)
		return 1;
	return 0;
}
// 函数模板 非类型参数
template <unsigned N, unsigned M> int compare(const char(&p1)[N], const char(&p2)[M])
{
	return strcmp(p1, p2);
}

template <typename T, typename F = less<T>> int compare(const T& v1, const T& v2, F f = F())
{
	if (f(v1, v2))
		return -1;
	if (f(v2, v1))
		return 1;
	return 0;
}

template <> int compare(const char* const& p1, const char* const& p2)
{
	return strcmp(p1, p2);
}
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);


// 类模板
template <typename T> class Blob
{
	// 函数模板
	template <typename It> Blob(It b, It e);
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	// 构造函数
	Blob();
	// initializer_list 是 C++11 引入的一个标准库类型，用于表示初始化列表，即花括号 {} 内的一组值
	Blob(initializer_list<T> li);
	// Blob 中的元素数目
	size_type size()
	{
		return data->size();
	}
	bool empty() const
	{
		return data->empty();
	}
	// 添加和删除元素
	void push_back(const T& t)
	{
		data->push_back(t);
	}
	// 移动版本
	// 参数是右值引用
	void push_back(T&& t)
	{
		data->push_back(std::move(t));
	}
	void pop_back();
	// 元素访问
	// 返回容器元素引用
	T& back();
	T& operator[](size_type i);
private:
	shared_ptr<vector<T>> data;
	// 若 data[i] 无效，则抛出msg
	// 常量成员函数
	void check(size_type i, const string& msg) const;
};

template <typename T> template <typename It> Blob<T>::Blob(It b, It e) :data(make_shared<vector<T>>(b, e)) {}
// make_shared 创建一个 shared_ptr 对象
template <typename T> Blob<T>::Blob() :data(make_shared<vector<T>>()) {}
template <typename T> Blob<T>::Blob(initializer_list<T> li) : data(make_shared<vector<T>>(li)) {}
template <typename T> void Blob<T>::check(size_type i, const string &msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

template <typename T> T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}
// 返回的是 data 指向的 vector<T> 对象中索引为 i 的元素的引用
// 返回引用方便修改元素
template <typename T> T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T> void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T> class BlobPtr
{
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T>& a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		// *p 为本对象指向的 vector
		return (*p)[curr];
	}
	// 递增和递减
	BlobPtr<T>& operator++();		// 前置
	BlobPtr<T>& operator--();
	BlobPtr<T> operator++(int);
private:
	// 若检查成功 check 返回一个指向 vector 的 shared_ptr
	shared_ptr<vector<T>> check(size_t, string&) const;
	// 保存每一个 weak_ptr, 表示底层 vector 可能被销毁
	weak_ptr<vector<T>> wptr;
	// 数组中当前位置
	size_t curr;
};
// 后置：递增 但 返回原值
template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;				// 前置 ++ 检查递增是否合法
	return ret;				// 返回保存的状态
}

int main()
{
	cout << compare("hi", "mom") << endl;

	return 0;
}