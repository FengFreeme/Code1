#include <iostream>
#include <vector>

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
    // ����ͷ���
    ListNode* removeElements(ListNode* head, int val) 
    {
        // ������Ҫ��������head
        while (head != NULL && head->val == val)
        {
            ListNode* q = head;
            head = head->next;
            delete q;
        }
        if (head == NULL)
            return head;
        ListNode* pre = head;
        ListNode* p = head->next;
        // ����ʣ��ڵ�
        while (p != NULL)
        {
            if (p->val == val)
            {
                ListNode* q = p;
                pre->next = p->next;
                p = p->next;
                delete q;
            }
            else
            {
                p = p->next;
                pre = pre->next;
            }
        }
        return head;
    }
    // ��ͷ���
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = dummy->next;
        while (p != NULL)
        {
            if (p->val == val)
            {
                ListNode* q = p;
                pre->next = p->next;
                p = p->next;
                delete q;
            }
            else
            {
                pre = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
    // �ݹ� ��ͷ���
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        Remove(dummy, dummy->next, val);

        return dummy->next;
    }
    // 1. ȷ�������ͷ�������
    void Remove(ListNode* pre, ListNode* p, int val)
    {
        // 2. ȷ����ֹ����
        if (p == NULL)
            return;
        // 3. ���εݹ鴦��
        if (p->val == val)
        {
            ListNode* tmp = p;
            pre->next = p->next;
            p = p->next;
            delete tmp;
            Remove(pre, p, val);
        }
        else
        {
            pre = pre->next;
            p = p->next;
            Remove(pre, p, val);
        }
        return;
    }
};