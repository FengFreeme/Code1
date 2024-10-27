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
	// 普通方法
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		ListNode* DummyHead = new ListNode();
		DummyHead->next = head;
		int size = 0;
		ListNode* p = DummyHead->next;
		while (p != NULL)
		{
			size++;
			p = p->next;
		}
		int moveDis = size - n;
		ListNode* pre = DummyHead;
		while (moveDis--)
		{
			pre = pre->next;
		}
		p = pre->next;
		pre->next = p->next;
		delete p;
		p = nullptr;

		return DummyHead->next;
	}
	// 双指针
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* DummyHead = new ListNode();
		DummyHead->next = head;
		ListNode* p = DummyHead;
		while (n--)
		{
			p = p->next;
		}
		ListNode* pre = DummyHead;
		while (p->next != NULL)
		{
			p = p->next;
			pre = pre->next;
		}
		p = pre->next;
		pre->next = p->next;
		delete p;
		p = nullptr;
	}
};