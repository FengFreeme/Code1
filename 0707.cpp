#include <iostream>

using namespace std;

class MyLinkedList 
{
public:
    struct ListNode
    {
        ListNode* next;
        int val;
        ListNode() :next(NULL), val(0) {}
    };

private:
    ListNode* dummyHead;
    int size;
public:
    // 统一加虚拟头结点
    MyLinkedList() 
    {
        dummyHead = new ListNode();
        size = 0;
    }

    int get(int index) 
    {
        if (index < 0 || index > size - 1)
            return -1;
        ListNode* p = dummyHead->next;
        while (index--)
        {
            p = p->next;
        }
        return p->val;
    }

    void addAtHead(int val) 
    {
        ListNode* p = new ListNode();
        p->val = val;
        p->next = dummyHead->next;
        dummyHead->next = p;
        size++;
    }

    void addAtTail(int val) 
    {
        int index = size - 1;
        ListNode* cur = dummyHead;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        ListNode* p = new ListNode();
        p->val = val;
        cur->next = p;
        size++;
    }

    void addAtIndex(int index, int val) 
    {
        if (index > size || index < 0)
            return;
        else
        {
            ListNode* cur = dummyHead->next;
            ListNode* preCur = dummyHead;
            while (index--)
            {
                preCur = preCur->next;
                cur = cur->next;
            }
            ListNode* p = new ListNode();
            p->val = val;
            p->next = cur;
            preCur->next = p;
        }
        size++;
    }

    void deleteAtIndex(int index) 
    {
        if (index < 0 || index > size - 1)
            return;
        else
        {
            ListNode* cur = dummyHead->next;
            ListNode* preCur = dummyHead;
            while (index--)
            {
                preCur = preCur->next;
                cur = cur->next;
            }
            preCur->next = cur->next;
            delete cur;
        }
        size--;
    }
};

int main()
{
    // Your MyLinkedList object will be instantiated and called as such:
    MyLinkedList* obj = new MyLinkedList();
    
    // obj->addAtHead(1);
    obj->addAtTail(1);
    // obj->addAtIndex(1,2);
    int param_1 = obj->get(0);
    // obj->deleteAtIndex(1);
    // param_1 = obj->get(0);

    return 0;
}