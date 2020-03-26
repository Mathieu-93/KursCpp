#include<iostream>
#include"rational.h"

using namespace std;

void demoCheck();

int main(){

    demoCheck();
    return 0;
}

void demoCheck(){

    Rational r2(2, 11), r3(1, -3), r5(18, 6);
    Rational res1 = 3 + r2 * r3;
    //Rational ires1 =Rational::normalize(res1);
    Rational res2 = (3 + r2) * r3;
    Rational res3 = 3 + r3 * (r2 + 2) / (r5 - r3);
   // Rational ires3 = Rational::normalized(res3.numerator(),res3.denominator());

    cout << 3 << " + " << r2 << " * " <<  r3 << " = " << Rational::normalize(res1) << endl;
    cout << "(" << 3 << " + " << r2 << ")" << " * " <<  r3 << " = " << Rational::normalize(res2) << endl;
    cout << 3 << " + " << r3 << " * " << "(" << r2 << " + " << 2 << ")" << "/"
         << "(" << r5 << " - " << r3 << ")" << " = " << Rational ::normalized(res3.numerator(),res3.denominator()) << endl;
}
