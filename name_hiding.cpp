#include<iostream>
using namespace std;

class B
{
    public:

     void f(int a)
     {
         cout<<"i am in B";
     }
};

class D : public B
{
    public:
     using B::f;
     void f()
     {
         cout<<"i am in D";
     }
     void f(int a)
     {
         cout<<"i am in D "<<a;
     }
};

int main()
{
    D d;
    d.f(8);
    return 0;
}