#include <iostream>

using std::cout;
using std::endl;

struct IA
{
  virtual void f1() = 0; //purely virtual function
  virtual ~IA();
};

IA::~IA() {}

struct A : IA
{
  void f1() override { cout << "A::f1()" << endl; }
  void f2() { cout << "A::f2()" << endl; } //not virtual !
  void f3() { cout << "A::f3()" << endl; } //not virtual !

  A() { cout << "A::A()" << endl; }
  ~A() override;
};

A::~A() { cout << "~A::A()" << endl; }

struct B : A
{
  void f1() override { cout << "B::f1()" << endl; }
  virtual void f2() { cout << "B::f2()" << endl; } // <- !!!

  B() { cout << "B::B()" << endl; }
  virtual ~B() override;
};

B::~B() { cout << "~B::B()" << endl; }

struct C : B
{
  void f1() override { cout << "C::f1()" << endl; }
  void f2() override { cout << "C::f2()" << endl; }
  void f3() { cout << "C::f3()" << endl; } // <- hiding not overriding !

  C() { cout << "C::C()" << endl; }
  ~C() override;
};

C::~C() { cout << "~C::C()" << endl; }

struct D {
  void f1() { cout << "D::f1()" << endl; }
  void f2() { cout << "D::f2()" << endl; }
  void f3() { cout << "D::f3()" << endl; }

  D() { cout << "D::D()" << endl; }
  ~D() { cout << "~D::D()" << endl; }
};

void demo1()
{
  cout << "demo1()..." << endl;

  A a; cout << endl;
  B b; cout << endl;
  C c; cout << endl;

  cout << "calling f1(), f2(), f3() for object A a ..." << endl;
  a.f1(); a.f2(); a.f3();
  cout << endl;

  cout << "calling f1(), f2(), f3() for object B b ..." << endl;
  b.f1(); b.f2(); b.f3();
  cout << endl;

  cout << "calling f1(), f2(), f3() for object C c ..." << endl;
  c.f1(); c.f2(); c.f3();
  cout << endl;
}

void demo2()
{
  cout << "demo2()..." << endl;

  cout << "constructing A..." << endl;
  A *pAA = new A; cout << endl;
  cout << "calling methods with the use of 'A * pAA = new A'" << endl;
  pAA->f1(); pAA->f2(); pAA->f3();
  cout << endl;

  cout << "constructing B..." << endl;
  A *pAB = new B; cout << endl;
  cout << "calling methods with the use of 'A * pAB = new B'" << endl;
  pAB->f1(); pAB->f2(); pAB->f3();
  cout << endl;

  cout << "constructing C..." << endl;
  A *pAC = new C; cout << endl;
  cout << "calling methods with the use of 'A * pAC = new C'" << endl;
  pAC->f1(); pAC->f2(); pAC->f3();
  cout << endl;

  cout << "constructing B..." << endl;
  B *pBB = new B; cout << endl;
  cout << "calling methods with the use of 'B * pBB = new B'" << endl;
  pBB->f1(); pBB->f2(); pBB->f3();
  cout << endl;

  cout << "constructing C..." << endl;
  B *pBC = new C; cout << endl;
  cout << "calling methods with the use of 'B * pBC = new C'" << endl;
  pBC->f1(); pBC->f2(); pBC->f3();
  cout << endl;

  cout << "deleting objects..." << endl;
  delete pAA; cout << endl;
  delete pAB; cout << endl;
  delete pAC; cout << endl;
  delete pBB; cout << endl;
  delete pBC; cout << endl;
}

int main()
{
  demo1();
  cout << endl;
  demo2();
}
