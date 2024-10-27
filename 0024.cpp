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
	ListNode* swapPairs(ListNode* head) 
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* DummyHead = new ListNode();
		DummyHead->next = head;
		ListNode* p = DummyHead;
		while (p->next != NULL && p->next->next != NULL)
		{
			ListNode* tmp1 = p->next;
			ListNode* tmp2 = p->next->next;
			tmp1->next = tmp2->next;
			tmp2->next = tmp1;
			p->next = tmp2;
			p = p->next->next;
		}
		return DummyHead->next;
	}
	// 递归法
	ListNode* swapPairs(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* DummyHead = new ListNode();
		DummyHead->next = head;
		ListNode* p = DummyHead;
		Swap(p);

		return DummyHead->next;
	}
	// 1. 确定参数和返回类型
	void Swap(ListNode* p)
	{
		// 2. 终止条件
		if (p->next == NULL || p->next->next == NULL)
			return;
		// 3. 单次递归处理
		ListNode* tmp1 = p->next;
		ListNode* tmp2 = p->next->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		p->next = tmp2;
		p = p->next->next;
		Swap(p);

		return;
	}
};