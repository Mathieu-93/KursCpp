#include <iostream>

void referanceDemo(){
    double x = 2.71;
    double &rx = x;
    //double &ry; //!!! declaration of reference 'ry' requiers an initialization
    printf(" x = %f\n", x);
    printf("rx= %f\n", rx);

    double *px =&x;
    double *& rpx = px;
    printf(" &x = %p, px = %p\n", &x, px);
    printf("rpx = %p\n", rpx);

    //double &* prx = &rx; // !!! you cannot create a pointer to a referance


}

int main()
{
    referanceDemo();
    return 0;
}
