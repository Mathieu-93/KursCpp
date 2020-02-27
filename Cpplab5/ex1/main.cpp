#include <iostream>

using namespace std;

struct A {
    void f() {
        cout<<"f() "<<endl;
    }
    A() {cout <<"A::A()"<<endl;}
    ~A() {cout <<"A::~A()"<<endl;}

};

struct B:A{
    void f(){
        cout<<"B::f()"<<endl;
    }
    B() {cout <<"B::B()"<<endl;}
    ~B() {cout <<"B::~B()"<<endl;}

};
int main()
{
    A a;
    B b;
    a.f();
    b.f();
    return 0;
}
