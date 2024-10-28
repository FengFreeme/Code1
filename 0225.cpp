#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MyStack 
{
public:
    MyStack() 
    {

    }

    void push(int x) 
    {
        if (!que1.empty())
            que1.push(x);
        else
            que2.push(x);
    }
    // 将除最后一个元素的其它元素压入另一个队列 然后输出最后一个元素
    int pop() 
    {
        if (!que1.empty())
        {
            int num;
            while (que1.size() > 1)
            {
                num = que1.front();
                que1.pop();
                que2.push(num);
            }
            num = que1.front();
            que1.pop();

            return num;
        }
        else
        {
            int num;
            while (que2.size() > 1)
            {
                num = que2.front();
                que2.pop();
                que1.push(num);
            }
            num = que2.front();
            que2.pop();

            return num;
        }
    }
    // 将除最后一个元素的其它元素压入另一个队列 然后输出最后一个元素
    int top() 
    {
        /*
        if (!que1.empty())
        {
            int num;
            while (que1.size() > 1)
            {
                num = que1.front();
                que1.pop();
                que2.push(num);
            }
            num = que1.front();
            que1.pop();
            que2.push(num);

            return num;
        }
        else
        {
            int num;
            while (que2.size() > 1)
            {
                num = que2.front();
                que2.pop();
                que1.push(num);
            }
            num = que2.front();
            que2.pop();
            que1.push(num);

            return num;
        }
        */
        int num = pop();
        if (!que1.empty())
            que1.push(num);
        else
            que2.push(num);

        return num;
    }

    bool empty() 
    {
        if (!que1.empty() || !que2.empty())
            return false;
        else
            return true;
    }
private:
    queue<int> que1;
    queue<int> que2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */