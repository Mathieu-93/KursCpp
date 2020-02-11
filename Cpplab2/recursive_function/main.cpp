#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>

int sum5(int elems[], size_t size)
{
    if (size ==0){return 0;}
    else{return  sum5(elems, size-1) + elems[size -1];}
}

int sumOfSquare(int elems[],size_t size){
    if(size == 0){ return 0;}
    else{return product(elems,size-1) + pow(elems[size -1],2);}
}
long factR(int n)
{
    if (n<=1) {return 1;}
    else{ return n * factR(n-1); }
}

int fibR(int n)
{
    if(n<=0){ return 0;}
    else if (n ==1) {return 1;}
    else{ return fibR(n-2)+fibR(n-1);}
}

int fib(int n)
{
    size_t f0=0,f1 =1;
    if(n<=0){ return 0;}
    else if(n ==1){ return 1;}
    else{
        for(int i = 0; i < n; ++i){
            f1 = f0+f1;
            f0 = f1-f0;
        }
        return f0;
    }
}
void test(int number){
    using namespace std;

    std::chrono::steady_clock::time_point start, end;

      int n4Fib = number;
      start = std::chrono::steady_clock::now();
      fibR(n4Fib);

      end = std::chrono::steady_clock::now();

      cout << "fibR(" << n4Fib << ") took "
           << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
           << "us.\n";

      start = std::chrono::steady_clock::now();
      fib(n4Fib);

      end = std::chrono::steady_clock::now();
      cout << "fib(" << n4Fib << ") took "
           << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
           << "us.\n";

}


int main()
{
    using namespace std;

    int a1[] = {0,1,2,3,4};
    constexpr size_t a1Size =sizeof(a1)/sizeof(a1[0]);

    cout<<"factR(20) = "<<factR(20)<<endl;
    cout<<"sum5(10) = "<<sum5(a1,a1Size)<<endl;
    cout<<"sumOfSquare(5) = "<<sumOfSquare(a1,a1Size)<<endl;
    cout<<"fib(5) = "<<fib(5)<<endl;
    cout<<"fibR(5) = "<<fibR(5)<<endl;
    test(30);





}
