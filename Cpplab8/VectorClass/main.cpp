#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

template< typename T>

ostream& operator<<(ostream &out, const vector<T> &v)
{
    out <<"[";
    const auto vs = v.size();
    if (vs>0){
        for (size_t i =0; i<vs -1; ++i){
            out<<v[i]<<",";
        }
        out<<v.at(vs-1); //out << v[vs-1];
    }
    out<<"]";
    return out;
}

template<typename T>
void printVec(const vector<T> &v, const char* name ="")
{
    const char* v_name= (strlen(name) == 0)? "v":name;
    cout <<v_name<< " = "<<v
         <<", "<<v_name<<".size() = "<<v.size()
         <<", "<<v_name<<".capacity() ="<<v.capacity()<<endl;
}

void vectorDemo()
{
    cout<<"vectorDemo1() ..."<<endl;
    vector<int> v1{};
    cout<< "The initial state of v1 is:"<<endl;
    printVec(v1, "v1");cout <<endl;

    cout<<"Calling v1.reserve(5)" <<endl;
    v1.reserve(5);
    printVec(v1, "v1");cout<<endl;

    cout<<"Adding 1 at the end"<<endl;
    v1.push_back((1));
    printVec(v1, "v1");cout<<endl;

    cout<<"Calling v1.clear()"<<endl;
    v1.clear();
    printVec(v1, "v1");cout<<endl;

    cout<<"Adding two elements at the end"<<endl;
    v1.push_back(1);
    v1.emplace_back(2);
    printVec(v1, "v1");cout<<endl;

    cout<<"Calling v1.shrink_to_fit()"<<endl;
    v1.shrink_to_fit();
    printVec(v1, "v1");cout<<endl;

    cout<<"Trying to use operator[] to add one elem at the end"<<endl;
    v1[2] = 99;//no error, although 2 is aot of range!
    printVec(v1, "v1");cout<<endl;

    cout<<"Checking the content of (v1+2) memory address"<<endl;
    cout<<"v1[2] = "<<v1[2]<<endl<<endl<<endl;// v1[2] = 99

    cout<<"Trying to use 'at' function to add one elem at the end"<<endl;
    try{
        v1.at(2) = 999;
    } catch (std::out_of_range){
        cout<<"std::out_of_range exception caught!"<< endl;
        cout<<"v1[2] = "<<v1[2]<<endl<<endl;
    }
    cout<<"The final state of v1 is:"<<endl;
    printVec(v1, "v1");

    cout<<endl;
    cout<<"Analysis: size vs. capacity..."<<endl;
    vector<int> v2;
    for(int i = 0; i<20; ++i){
        v2.push_back(i);
        printVec(v2,"v2");
    }
}


int main(){

    vectorDemo();
    return 0;
}
