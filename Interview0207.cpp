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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode* p = headA;
        int sizeA = 0;
        while (p != NULL)
        {
            sizeA++;
            p = p->next;
        }
        p = headB;
        int sizeB = 0;
        while (p != NULL)
        {
            sizeB++;
            p = p->next;
        }
        if (sizeA - sizeB >= 0)
        {
            int dis = sizeA - sizeB;
            p = headA;
            while (dis--)
            {
                p = p->next;
            }
            ListNode* q = headB;
            while (p != NULL)
            {
                if (p == q)
                    return p;
                p = p->next;
                q = q->next;
            }
        }
        else
        {
            int dis = sizeB - sizeA;
            p = headB;
            while (dis--)
            {
                p = p->next;
            }
            ListNode* q = headA;
            while (p != NULL)
            {
                if (p == q)
                    return p;
                p = p->next;
                q = q->next;
            }
        }
        return NULL;
    }
};