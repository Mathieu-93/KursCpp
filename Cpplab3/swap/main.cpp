#include<iostream>
using namespace std;

void swap2(int *px, int *py)
{
  int tmp = *px;
  *px = *py;
  *py = tmp;

}

void swap22(int &x, int &y){
    int tmp =x;
    x= y ;
    y = tmp;
}

int main()
{
  int x = 1, y = 2;
  cout << "x = " << x << ", y = " << y << endl;
  swap22(x, y);
  cout << "x = " << x << ", y = " << y << endl;
}
