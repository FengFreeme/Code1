#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class A
{
public:
    void virtual print()
    {
        cout << "A" << endl;
    }
};

class B : public A
{
public:
    void virtual print()
    {
        cout << "B" << endl;
    }
};

int main()
{

    A* pA = new A();
    pA->print();
    B* pB = (B*)pA;
    pB->print();
    delete pA, pB;
    pA = new B();
    pA->print();
    pB = (B*)pA;
    pB->print();
}