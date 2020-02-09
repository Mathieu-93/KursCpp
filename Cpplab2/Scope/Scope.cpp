#include<iostream>

namespace MyLib{
    int add(int x, int y){return x+y ;}
    int sub(int x, int y);
    extern int v;
}

int MyLib::v =1;

int MyLib::sub(int x, int y)
{
    return x-y;
}

namespace MyLib{
    int mul(int x, int y){return x*y;}
    int aToB(int a, int b);
}

int g_counter = 0;

int MyLib::aToB(int a, int b){
    int r = 1;
    static int sl_aToBCallCounter =0;
    for (int i =1; i<=b; ++i) {r *=a;}
    sl_aToBCallCounter++;
    {
        using namespace std;
        cout<<"sl_aToBCallCounter =" <<sl_aToBCallCounter<<endl;
    }
    return r;
}

using MyLib::add;

int main()
{
    using namespace std;
    using MyLib::mul;
    cout<< "add(1,2)= " <<add(1,2)<<endl;
    cout<< "mul(3,5)= " <<mul(3,5)<<endl;
    cout<< "MyLib::sub(5,2)= " <<MyLib::sub(5,2)<<endl;

    {
        using MyLib::aToB;
        cout <<"aToB(5,2) =" << aToB(5,2)<<endl;
        cout <<"aTob(3,3) =" << aToB(3,3)<<endl;
        //to access the global function aToB we use "::" prefix
        cout <<"::aTOB(3,4) = "<<MyLib::aToB(3,4)<<endl;

    }
   cout<<"MyLib::aToB(2,6) ="<<MyLib::aToB(2,6)<<endl;

    int *p = new int;
    *p =5;
    cout<<" *p= " <<*p <<endl;
    delete p;

    return 0;
}
