#include <iostream>
#include <bitset>

void bitwiseOpsDemo1()
{
  unsigned int x = 5;
  unsigned int y = 10;

  printf("x || y = %u (0x%x)\n", x || y, x || y);
  printf("x | y = %u (0x%x)\n", x | y, x | y);

  printf("x && y = %u (0x%x)\n", x && y, x && y);
  printf("x & y = %u (0x%x)\n", x & y, x & y);

  printf("x ^ y = %u (0x%x)\n", x ^ y, x ^ y);
  printf("~x = %u (0x%x)\n", ~x, ~x);

  printf("y << 1 = %u (0x%x)\n", y << 1, y << 1);
  printf("y >> 1 = %u (0x%x)\n", y >> 1, y >> 1);
}

void bitwiseOpsDemo2()
{
  using std::cout;
  using std::endl;
  using std::bitset;

  unsigned int x = 5;
  unsigned int y = 10;

  constexpr auto sizeOfUInt = 8 * sizeof(unsigned int); // in bits

  cout << "x = " << bitset<sizeOfUInt>(x) << endl;
  cout << "y = " << bitset<sizeOfUInt>(y) << endl;

  cout << "x || y = " << bitset<sizeOfUInt>(x || y) << endl;
  cout << "x | y = " << bitset<sizeOfUInt>(x | y) << endl;
  cout << "x && y = " << bitset<sizeOfUInt>(x && y) << endl;
  cout << "x & y = " << bitset<sizeOfUInt>(x & y) << endl;
  cout << "x ^ y = " << bitset<sizeOfUInt>(x ^ y) << endl;
  cout << "~x = " << bitset<sizeOfUInt>(~x) << endl;

  cout << "y << 1 = " << bitset<sizeOfUInt>(y << 1) << endl;
  cout << "y >> 1 = " << bitset<sizeOfUInt>(y >> 1) << endl;
}

int main()
{
  bitwiseOpsDemo1();
  return 0;
}
