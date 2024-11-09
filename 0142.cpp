#include <iostream>

using namespace std;

struct ListNode
{
	ListNode *next;
	int val;
	ListNode() :next(nullptr), val(0) {}
};

class Solution 
{
public:
	ListNode* detectCycle(ListNode *head) 
	{
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
			return nullptr;
		ListNode *slow = head, *fast = head;
		// �ж��Ƿ��л�
		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast)
				break;
		}
		if (slow != fast)
			return nullptr;
		// Ѱ�һ������
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};