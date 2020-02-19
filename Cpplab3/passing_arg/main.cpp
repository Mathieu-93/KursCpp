#include <iostream>

int argByValue(int i)
{
  return 2 * i;
}

int argByReference(int &r)
{
  r *= 2;
  return 5 * r;
}

int argByPointer(int *p)
{
  *p *= 2; // = *p = *p * 2;
  return 5 * *p; // = 5 * (*p)
}

int* add(int*px, int *pz)
{
    int *sum = new int;
    *sum = *px + *pz;
    return sum;

}
void swap2Ints(int* px, int* py){
    int temp = *px;
    *px = *py;
    *py = temp;

}

int main()
{
  using std::cout;
  using std::endl;

  int x = 1,z = 3;
  cout << "x = " << x << endl;

  cout << "Calling argByValue(x):" << endl;
  int y = argByValue(x);
  cout << "x = " << x << ", y = " << y << endl;

  cout << "Calling argByReference(x):" << endl;
  y = argByReference(x);
  cout << "x = " << x << ", y = " << y << endl;

  cout << "Calling argByPointer(&x):" << endl;
  y = argByPointer(&x);
  cout << "x = " << x << ", y = " << y << endl;

  cout << "ADD(x,y):" << endl;
  int* suma = add(&x, &z);
  cout << "sum = " << *suma << endl;

  int t = 1, d = 2;
  swap2Ints(&t, &d);
  cout << "t = " << t << ", d = " << d << endl; // should print: x = 2, y = 1
  return 0;
}
