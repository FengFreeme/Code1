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
	ListNode* detectCycle(ListNode* head) 
	{
		if (head == NULL || head->next == NULL || head->next->next == NULL)
			return NULL;
		ListNode* slow = head, * fast = head;
		// 判断是否有环
		while (fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast)
				break;
		}
		if (slow != fast)
			return NULL;
		// 寻找环的入口
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};