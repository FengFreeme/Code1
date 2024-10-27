#include <iostream>

using namespace std;

struct ListNode
{
	ListNode* next;
	int val;
	ListNode() :next(NULL), val(0) {}
};

class Solution 
{
public:
	// 头插法解决
	ListNode* reverseList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		// 建立虚拟头结点
		ListNode* DummyHead = new ListNode();
		DummyHead->next = head;
		ListNode* p = head->next;
		head->next = NULL;
		while (p != NULL)
		{
			ListNode* tmp = p->next;
			p->next = DummyHead->next;
			DummyHead->next = p;
			p = tmp;
		}
		return DummyHead->next;
	}
	// 递归法
	ListNode* reverseList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* DummyHead = new ListNode();
		DummyHead->next = head;
		ListNode* p = head->next;
		head->next = NULL;

		Reverse(DummyHead, p);

		return DummyHead->next;
	}
	// 1. 确定参数和返回类型
	void Reverse(ListNode* DummyHead, ListNode* p)
	{
		// 2. 确定终止条件
		if (p == NULL)
			return;
		// 3. 单次递归处理
		ListNode* tmp = p->next;
		p->next = DummyHead->next;
		DummyHead->next = p;
		p = tmp;
		Reverse(DummyHead, p);

		return;
	}
};