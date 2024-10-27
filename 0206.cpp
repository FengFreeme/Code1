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
	// ͷ�巨���
	ListNode* reverseList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		// ��������ͷ���
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
	// �ݹ鷨
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
	// 1. ȷ�������ͷ�������
	void Reverse(ListNode* DummyHead, ListNode* p)
	{
		// 2. ȷ����ֹ����
		if (p == NULL)
			return;
		// 3. ���εݹ鴦��
		ListNode* tmp = p->next;
		p->next = DummyHead->next;
		DummyHead->next = p;
		p = tmp;
		Reverse(DummyHead, p);

		return;
	}
};