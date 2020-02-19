#include <iostream>

using std::cout;
using std::endl;

void cStyleStructDemo(){
    cout<< "CStyleStructDemo(): "<<endl;
    struct S1 {
        long l1;
        double d1;
    } s{1,1.5};

    cout<<"s.l1 = "<<s.l1<<", s.d1= "<<s.d1<<endl;

    typedef struct S2{
        long l2;
        double d2;

    } S2_T;

    S2_T *pS2 = new S2_T;
    pS2 -> l2 = 2; //= (*pS2).i2 = 2
    (*pS2).d2 = 2.5;
    cout<< "pS2 -> l2 = "<<pS2 ->l2<<", (*pS2).d2= "<< (*pS2).d2<<endl;
    delete pS2;
}

int main ()
{
    cStyleStructDemo();
    return 0;
}
