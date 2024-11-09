#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue 
{
public:
    // ��ʼ��
    MyQueue() 
    {
        
    }

    void push(int x) 
    {
        stIn.push(x);
    }

    int pop() 
    {
        /*
        // s2 ��Ϊ��
        if (!stOut.empty())
        {
            int num = stOut.top();
            stOut.pop();

            return num;
        }
        // s2 Ϊ��
        else
        {
            while (!stIn.empty())
            {
                int num = stIn.top();
                stIn.pop();
                stOut.push(num);
            }
            int num = stOut.top();
            stOut.pop();

            return num;
        }
        */
        peek();
        int num = stOut.top();
        stOut.pop();

        return num;
    }

    int peek() 
    {
        // s2 ��Ϊ��
        if (!stOut.empty())
        {
            return stOut.top();
        }
        // Ϊ��
        else
        {
            while (!stIn.empty())
            {
                int num = stIn.top();
                stIn.pop();
                stOut.push(num);
            }
            return stOut.top();
        }
    }

    bool empty() 
    {
        if (!stIn.empty() || !stOut.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
private:
    stack<int> stIn;
    stack<int> stOut;
};

int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    int param_2 = obj->pop();
    obj->push(2);
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
}
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */