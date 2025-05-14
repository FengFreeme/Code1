#include <iostream>
#include <vector>

using namespace std;

// ��ģ��
template <typename T> class Blob
{
	// ����ģ��
	template <typename It> Blob(It b, It e);
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	// ���캯��
	Blob();
	// initializer_list �� C++11 �����һ����׼�����ͣ����ڱ�ʾ��ʼ���б��������� {} �ڵ�һ��ֵ
	Blob(initializer_list<T> li);
	// Blob �е�Ԫ����Ŀ
	size_type size()
	{
		return data->size();
	}
	bool empty() const
	{
		return data->empty();
	}
	// ��Ӻ�ɾ��Ԫ��
	void push_back(const T& t)
	{
		data->push_back(t);
	}
	// �ƶ��汾
	// ��������ֵ����
	void push_back(T&& t)
	{
		data->push_back(std::move(t));
	}
	void pop_back();
	// Ԫ�ط���
	// ��������Ԫ������
	T& back();
	T& operator[](size_type i);
private:
	shared_ptr<vector<T>> data;
	// �� data[i] ��Ч�����׳�msg
	// ������Ա����
	void check(size_type i, const string& msg) const;
};

template <typename T> template <typename It> Blob<T>::Blob(It b, It e) :data(make_shared<vector<T>>(b, e)) {}
// make_shared ����һ�� shared_ptr ����
template <typename T> Blob<T>::Blob() : data(make_shared<vector<T>>()) {}
// template <typename T> Blob<T>::Blob(initializer_list<T> li) : data(make_shared<vector<T>>(li)) {}
template <typename T> Blob<T>::Blob(initializer_list<T> il) try : data(make_shared<vector<T>>(il)) 
{
}
catch (const std::bad_alloc& e) 
{
	handle_out_of_memory(e);
}

template <typename T> void Blob<T>::check(size_type i, const string& msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

template <typename T> T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}
// ���ص��� data ָ��� vector<T> ����������Ϊ i ��Ԫ�ص�����
// �������÷����޸�Ԫ��
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
		// *p Ϊ������ָ��� vector
		return (*p)[curr];
	}
	// �����͵ݼ�
	BlobPtr<T>& operator++();		// ǰ��
	BlobPtr<T>& operator--();
	BlobPtr<T> operator++(int);
private:
	// �����ɹ� check ����һ��ָ�� vector �� shared_ptr
	shared_ptr<vector<T>> check(size_t, string&) const;
	// ����ÿһ�� weak_ptr, ��ʾ�ײ� vector ���ܱ�����
	weak_ptr<vector<T>> wptr;
	// �����е�ǰλ��
	size_t curr;
};
// ���ã����� �� ����ԭֵ
template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;
	++*this;				// ǰ�� ++ �������Ƿ�Ϸ�
	return ret;				// ���ر����״̬
}

int main()
{

	return 0;
}