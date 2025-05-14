#include <iostream>
#include <vector>
#include <functional>
#include <time.h>

using namespace std;

class PriorityQueue
{
public:
	// ​​通用函数包装器 用于存储、管理和调用任何符合 bool(int, int) 签名（即接受两个 int 参数并返回 bool 值）的 ​​可调用对象
	using Comp = function<bool(int, int)>;
	PriorityQueue(int cap = 20, Comp comp = greater<int>())
		:size_(0), cap_(cap), comp_(comp)
	{
		que_ = new int[cap_];
	}
	PriorityQueue(Comp comp)
		:size_(0), cap_(20), comp_(comp)
	{
		que_ = new int[cap_];
	}
	~PriorityQueue()
	{
		delete[]que_;
		que_ = nullptr;
	}
public:
	// 入堆操作
	void push(int val)
	{
		if (size_ == cap_)
		{
			int* p = new int[2 * cap_];
			memcpy(p, que_, cap_ * sizeof(int));
			delete[]que_;
			que_ = p;
			cap_ = 2 * cap_;
		}

		if (size_ == 0)
		{
			que_[size_] = val;
		}
		else
		{
			shiftUp(size_, val);
		}
		++size_;
	}
	// 出堆操作
	void pop()
	{
		if (size_ == 0)
			throw "container is empty";
		--size_;
		if (size_ > 0)
		{
			// 删除堆顶元素，还有剩余元素，要进行堆的下沉调整
			shiftDown(0, que_[size_]);
		}

	}

	bool empty() const
	{
		return size_ == 0;
	}

	int top() const
	{
		if (size_ == 0)
			throw "container is empty";
		return que_[0];
	}

	int size()
	{
		return size_;
	}
private:
	// 入堆上浮调整
	void shiftUp(int i, int val)
	{
		// 最多计算到根节点
		while (i > 0)
		{
			int father = (i - 1) / 2;
			if (comp_(val, que_[father]))
			{
				que_[i] = que_[father];
				i = father;
			}
			else
			{
				break;
			}
		}
		que_[i] = val;
	}
	// 出堆下沉调整
	void shiftDown(int i, int val)
	{
		// size_ - 1 是最后一个元素下标，(n - 1) / 2
		while (i <= (size_ - 2) / 2)
		{
			int child = 2 * i + 1;
			if (child + 1 < size_ && comp_(que_[child + 1], que_[child]))
			{
				// 如果 i 节点右孩子的值大于左孩子，child 记录右孩子的下标
				child = child + 1;
			}

			if (comp_(que_[child], val))
			{
				que_[i] = que_[child];
				i = child;
			}
			else
			{
				// 满足大根堆的属性 提前结束
				break;
			}
		}
		que_[i] = val;
	}
private:
	int* que_;		// 指向动态扩容的数组
	int size_;		// 数组元素的个数
	int cap_;		// 数组的总空间的大小
	Comp comp_;		// 比较器对象
};

int main()
{
	PriorityQueue que;
	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
	{
		que.push(rand() % 100);
	}

	while (!que.empty())
	{
		cout << que.top() << " ";
		que.pop();
	}
	cout << endl;
}