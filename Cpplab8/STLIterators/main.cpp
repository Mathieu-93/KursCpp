#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

//Violation of DRY (Do not Repeat Yourself) principle/rule below!
template <typename T>
void print_array_elems_from_to(T* arr, size_t fromIdx, size_t toIdx, size_t size)
{
  cout << "[";
  if (toIdx < size && toIdx - fromIdx > 0) {
    for (size_t i = fromIdx; i < toIdx; ++i) {
      cout << arr[i] << ",";
    }
    cout << arr[toIdx];
  }
  cout << "]";
}

template <typename T>
void print_vec_elems_from_to(const vector<T>& vec, size_t fromIdx, size_t toIdx)
{
  cout << "[";
  if (toIdx - fromIdx > 0) {
    for (size_t i = fromIdx; i < toIdx; ++i) {
      cout << vec[i] << ",";
    }
    cout << vec[toIdx];
  }
  cout << "]";
}

void preIteratorsDemo()
{
  cout << "preIteratorsDemo()..." << endl;
  int a[] {0,1,2,3,4};
  constexpr size_t a_size = sizeof (a)/sizeof (int);

  cout << "Printing elems of array 'a'..." << endl;
  cout << "Printing all elems: ";
  print_array_elems_from_to(a, 0, a_size - 1, a_size); cout << endl;

  cout << "Printing elems (fromIdx: 0, toIdx: 1): ";
  print_array_elems_from_to(a, 0, 1, a_size); cout << endl;

  cout << "Printing elems (fromIdx: 0, toIdx: 4): ";
  print_array_elems_from_to(a, 0, a_size-1, a_size); cout << endl;

  cout << "Printing elems (fromIdx: 1, toIdx: 3): ";
  print_array_elems_from_to(a, 1, a_size-2, a_size); cout << endl;

  cout << endl;
  vector<int> v{0,1,2,3,4};
  cout << "Printing elems of vector 'v'..." << endl;

  cout << "Printing all elems: ";
  print_vec_elems_from_to(v, 0, a_size - 1); cout << endl;

  cout << "Printing elems (fromIdx: 0, toIdx: 1): ";
  print_vec_elems_from_to(v, 0, 1); cout << endl;

  cout << "Printing elems (fromIdx: 0, toIdx: 4): ";
  print_vec_elems_from_to(v, 0, a_size-1); cout << endl;

  cout << "Printing elems (fromIdx: 1, toIdx: 3): ";
  print_vec_elems_from_to(v, 1, a_size-2); cout << endl;
}

template <typename T>
class SimpleIterator
{
public:
  explicit SimpleIterator(T* p = nullptr) : ptr_{p} {}

  const T operator*() { return *ptr_; }

  SimpleIterator& operator+=(int i) { ptr_ += i; return *this; }
  SimpleIterator& operator-=(int i) { ptr_ -= i; return *this; }

  SimpleIterator& operator++() { return (*this += 1); } // for ++it
  SimpleIterator operator++(int) { SimpleIterator tmp{*this}; *this += 1; return tmp; } //for it++

  bool operator==(const SimpleIterator& other) const { return ptr_ == other.ptr_; }
  bool operator!=(const SimpleIterator& other) const { return !(*this == other); }

  const T* operator->() const { return ptr_; }
  //and maybe?: operator=, operator+, operator-, operator<, operator<=, operator-- ...

private:
  T *ptr_;
};

// One function (template) to rule them all :)
template <typename IterT>
void print_elems_from_to(IterT begin, IterT end)
{
  cout << "[";
  if (end > begin) {
    IterT it = begin; IterT lastButOne = end - 1;
    for (it = begin; it != lastButOne; ++it) {
      cout << (*it) << ",";
    }
    cout << *(it);
  }
  cout << "]";
}

/*
* TEMPLATES make algorithms independent of the type of DATA STORED, whilst
* ITERATORS make the algorithms independent of the type of CONTAINER used.
*
* Notes:
*  - iterators are used to step through the elements of collections of objects
*   (and this is done independently of the internal structure of the collection)
*  - they can be seen as a generalization of pointers; a kind of smart pointer
*   that translates the call "go to the next element" into whatever is appropriate
*  - the major advantage of iterators is that they offer a small
*   but common interface for any arbitrary container type
*  - the concept of the STL (Standard Template Library) is based on the separation
*   of data and operations; the data is managed by container classes,
*   and the operations are defined by configurable algorithms;
*   iterators are the glue between these two components.
*/
void iteratorsDemo1()
{
  cout << "iteratorsDemo1()..." << endl;
  int a[] {0,1,2,3,4};

  cout << "Printing elems of array 'a'..." << endl;
  cout << "Printing all elems: ";
  //the "past-the-end position": [from,to) and NOT [from,to]
  print_elems_from_to(a, a+5);
  cout << endl;

  cout << "Printing elems [0,2) (=[0,1]): ";
  print_elems_from_to(a, a+2); cout << endl; //[from,to)

  cout << "Printing elems [0,4) (=[0,3]): ";
  print_elems_from_to(a, a+4); cout << endl;

  cout << "Printing elems [1,4) (=[1,3]): ";
  print_elems_from_to(a+1, a+4); cout << endl;

  cout << endl;
  vector<int> v{0,1,2,3,4};

  cout << "Printing elems of vector 'v'..." << endl;

  cout << "Printing all elems: ";
  print_elems_from_to(v.begin(), v.end()); cout << endl;

  cout << "Printing elems [0,2) (=[0,1]): ";
  print_elems_from_to(v.begin(), v.begin()+2); cout << endl;

  cout << "Printing elems [0,4) (=[0,3]): ";
  print_elems_from_to(v.begin(), v.begin()+4); cout << endl;

  cout << "Printing elems [1,4) (=[1,3]): ";
  print_elems_from_to(v.begin()+1, v.begin()+4); cout << endl;
}

void iteratorsDemo2()
{
  cout << "iteratorsDemo2()..." << endl;

  vector<int> v1{1,2,3,4,5,6};
  vector<int> v2{1,10,11,12};

  for (int i = 6; i < 10; i++) {
    v2.push_back(i);
  }

  cout << "v1 = ";
  print_elems_from_to(v1.begin(),v1.end());
  cout<<endl;
  cout<<"v2 = " ;
  print_elems_from_to(v2.begin(),v2.end());
  cout<< endl;
  //Merge v1 and v2 to form [1,2,...,9]
  v2.erase(v2.cbegin() + 1, v2.cbegin() + 4); //v2.erase(v2.cbegin()+1, v2.cend()-4);
  cout << "v2 = ";
  print_elems_from_to(v2.begin(),v2.end());
  cout<< endl;

  v2.insert(v2.begin() + 1, v1.begin() + 1, v1.end() - 1);
  cout << "v2 = ";
  print_elems_from_to(v2.begin(),v2.end());
  cout<< endl;
}

void iteratorsDemo3()
{
  cout << "iteratorsDemo3()..." << endl;
  ostream_iterator<int, char> out_it(cout, ",");

  vector<int> v1{1,2,3,4,5,6};

  cout << "[";
  cout << "Copying elems from v1 to the output stream..." << endl;
  copy(v1.begin(), v1.end()-1, out_it);
  cout << *(v1.end()-1);

  cout << "]";
  cout << endl;
}

int main()
{
//  preIteratorsDemo();
//  cout << endl;

  iteratorsDemo1();
  cout << endl;

//  iteratorsDemo2();
//  cout << endl;

//  iteratorsDemo3();
  return 0;
}
