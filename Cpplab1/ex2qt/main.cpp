#include <iostream>
#include"add.h"

extern int g_int;

int main(){
    std::cout<<"add(1,2) ="<<add(1,2)<< std::endl;
    std::cout<<"SQR(2+3) ="<<SQR(2+3)<< std::endl;
    std::cout<<"g_int= " <<g_int <<std::endl;
    return 0;



}
