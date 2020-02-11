#include <iostream>
#include <vector>

using namespace std;
float fun2();
float meanOfA(int[] , size_t );

int main()
{
    int a1[] ={1,2,3,4,5};
    constexpr size_t sizeArray =sizeof(a1)/sizeof(a1[0]);

    cout << "Mean of a1 = [1,2,3,4,5]: "<<meanOfA(a1,sizeArray) << endl;
    return 0;
}

//never ending loop x will will never totall 1.0f
//This is result of a rounding error
float fun2(){
    float x = 0.0f;
    while(x != 1.0f){
        x += 0.1f;
    }
    return x;
}

float meanOfA(int elem[], size_t size){
    float sum;
    for(size_t i =0; i<size; ++i){
        sum += elem[i];
    }
    return sum/size;
}
