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
    // 不加头结点
    ListNode* removeElements(ListNode* head, int val) 
    {
        // 首先需要单独处理head
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
        // 处理剩余节点
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
    // 加头结点
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
    // 递归 加头结点
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        Remove(dummy, dummy->next, val);

        return dummy->next;
    }
    // 1. 确定参数和返回类型
    void Remove(ListNode* pre, ListNode* p, int val)
    {
        // 2. 确定终止条件
        if (p == NULL)
            return;
        // 3. 单次递归处理
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