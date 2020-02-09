#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int fibR(int n)
{
  if (n <= 0) { return 0;}
  else if (n == 1) { return 1; }
  else { return fibR(n - 2) + fibR(n - 1); }
}


int main()
{
   int n=6;
   int f0=0, f1=1;
   for(int i=0;i<n;++i){
       f1+=f0;
       f0=f1-f0;

    }
  // cout<<"Ciag fib z n ="<<n-1<<" wynosi "<<f1<<endl;
   cout<<"Ciag fib z n ="<<n-1<<" wynosi "<<f1<<endl;

   std::chrono::steady_clock::time_point start, end;

     int n4Fib = 45;
     start = std::chrono::steady_clock::now();
     fibR(n4Fib);
     end = std::chrono::steady_clock::now();

     cout << "fibR(" << n4Fib << ") took "
          << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
          << "us.\n";
       return 0;
}

