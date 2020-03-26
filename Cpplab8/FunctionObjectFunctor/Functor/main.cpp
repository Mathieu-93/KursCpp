#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
 * Objects that behave like functions are called 'function objects' or 'functors'.
 * They are instances of classes that provide a function call operator.
 *
 * Note1: since C++11, the standard uses the term 'function object' for every
 * object that can be used as a function call. Thus, function pointers,
 * objects of classes with operator () or with a conversion to a pointer
 * to function, and lambdas are ALL function objects.
 *
 * Note2: a function object is a 'function with state' (other languages,
 * especially functional, use for this concept the term 'closure').
 *
 * Note3: each function object has its own type. Ordinary functions have different
 * types only when their signatures differ. However, function objects can have
 * different types even when their signatures are the same.
 * In fact, each functional behavior defined by a function object has its own type.
 * This is a significant improvement for generic programming using templates
 * because you can pass functional behavior as a template parameter.
 */

template <typename T>
class LinearFunction;

template <typename T>
ostream& operator<<(ostream&, const LinearFunction<T>&);

// f(x) = a * x + b
template <typename T>
class LinearFunction
{
public:
   LinearFunction(const char* name, T a, T b = 0) : name_{name}, a_{a}, b_{b} {}
   T operator()(T x) { return a_ * x + b_; }

private:
   const char* name_;
   T a_;
   T b_;

   friend ostream& operator<< <>(ostream&, const LinearFunction<T>&);
};

template <typename T>
ostream& operator<<(ostream& out, const LinearFunction<T>& f)
{
   T b = (f.b_ < 0) ? (-f.b_) : (f.b_);
   if (f.b_ < 0) {
      out << f.name_ << "(x) = " << f.a_ << " * x - " << b;
   } else if (fabs(f.b_) < 1e-15) {
      out << f.name_ << "(x) = " << f.a_ << " * x";
   } else { // f.b_ > 0
      out << f.name_ << "(x) = " << f.a_ << " * x + " << b;
   }

   return out;
}

void funcObjectDemo1()
{
   cout << "funcObjectDemo1()...\n";
   LinearFunction<int> f1("f1", 2, 1);// f1(x) = 2 * x + 1
   cout << f1 << endl;
   for (int i = 0; i < 5; ++i) {
      cout << "f1(" << i << ") = " << f1(i) << endl;
   }

   LinearFunction<double> f2("f2", M_PI, M_E);// f1(x) = pi * x + e
   cout << "\n" << f2 << endl;
   for (double d = 0; d < 5; d += 1) {
      cout << "f2(" << d << ") = " << f2(d) << endl;
   }
}

/*
 * 'generator' - a functor that can be called with no argument.
 * 'unary function' - a functor that can be called with one argument.
 * 'binary function' - a functor that can be called with two arguments.
 * 'predicate class' - a functor class whose operator() function is a predicate,
 *                     i.e., its operator() returns true or false
 *
 * Note: a unary function that returns a boolean value is a 'predicate',
 *       a binary function that returns a boolean value is a 'binary predicate'.
 */
template<typename T>
class Less_than {
   const T val;
public:
   Less_than(const T& v) :val(v) { }
   // {'function call' | 'call' | 'application'} operator
   bool operator()(const T& x) const { return x<val; } // call operator
};

/*
 * The ability to carry data (compare it to closures) plus their efficiency
 * make function objects particularly useful as arguments to algorithms.
 * Note: 'lambda expressions' is a notation for implicitly generating function objects
 */
template<typename Cont, typename P>
int count(const Cont& c, P pred)
{
   int cnt = 0;
   for (const auto& x : c) {
      if (pred(x)) ++cnt;
   }
   return cnt;
}

template<typename Cont, typename Oper>
void for_all(const Cont& xs, Oper op)
{
   for (auto x : xs) {
      op(x);
   }
}

template <typename T>
void print_it(T elem)
{
   cout << elem << ' ';
}

inline bool isOdd(int num)
{
   return num % 2 != 0;
}
typedef  bool (* isOddT)(int);

template <typename iterT>
void remove_if(iterT begin, iterT end, isOddT check){
    cout << "[";
    if (end > begin) {
        iterT it = begin; iterT lastButOne = end - 1;
        for (it = begin; it != lastButOne; ++it) {
            if(check(*it)){cout << (*it) << ",";}
            else{continue;}

        }
        cout << *(it);
    }
    cout << "]";
}


void funcObjectDemo2()
{
   cout << "funcObjectDemo2()...\n";
   //int v1[]{1,2,3,4,5};
   vector<int> v1{1,2,3,4,5,6,7,8,9};
   cout << "v1 = [ ";
   for_all(v1, print_it<int>);
   cout << "]";

   cout << "\nNumber of values in v1 that are smaller than " << 6 << " = "
       << count(v1, Less_than<int>{6});

   cout << "\nRemoving all odd values...";
   /*auto it =*/ remove_if(v1.begin(), v1.end(), isOdd);
//   cout << "\nv1 = [ ";
//   for_each(v1.begin(), it, print_it<int>);
//   cout << "]";
}

void funcObjectDemo3()
{
   cout << "funcObjectDemo3()...\n";
   vector<int> v1{5,6,9,4,7,2,1,8,3};
   cout << "v1 = [ ";
   for_all(v1, print_it<int>);
   cout << "]";

   cout << "\nSorting v1 in increasing order...";
   sort(v1.begin(), v1.end(), std::less<int>());
   cout << "\nv1 = [ ";
   for_all(v1, print_it<int>);
   cout << "]";

   cout << "\nSorting v1 in decreasing order...";
   sort(v1.begin(), v1.end(), std::greater<int>());
   cout << "\nv1 = [ ";
   for_all(v1, print_it<int>);
   cout << "]";
}

int main()
{
   //funcObjectDemo1(); cout << "\n";
   //funcObjectDemo2(); cout << "\n\n";
   funcObjectDemo3(); cout << "\n";

   return 0;
}

