#include <iostream>
#include<memory>

using namespace std;

class Box
{
public:
    Box(int v): value_{v}{cout<<"Box::Box()"<<endl;}
    ~Box() {cout<<"Box::~Box()"<<endl;}
    int value() const{return value_;}
private:
    int value_;
};

template <typename T>

class SmartPointer
{
public:
    SmartPointer(T *p): p_{p}{}
    ~SmartPointer(){
        cout<<"About to delete the mem pointer by p_"<<endl;
        if(p_ != nullptr) delete p_;
        p_ = nullptr;
    }
private:
    T *p_ = nullptr;
};

void f1(){
    cout<<"f1() working..."<<endl;
    Box *p1 = new Box{1};
    delete p1;
}

void f2(){
    {
        cout<<"f2() working..."<<endl;
        Box b1{1};
    }
}

void f3(){
    cout<<"f3() working..."<<endl;
    SmartPointer<Box> sp1 {new Box{1}};

}

void f4(){
    cout<<"f4() working..."<<endl;
    unique_ptr<Box> up{new Box{1}};

}

template<typename T>
class Less_than
{
public:
    Less_than(const T& v) : val_(v) {}
    bool operator()(const T &x){ return x<val_;}
private:
    T val_;
};
int main()
{
    Less_than<int> less_than5{5};
    constexpr int x = 3;
    if(less_than5(x)){
        cout<<"x=<5"<<endl;
    }


    return 0;
}
