#include <iostream>

using namespace std;

/*
 * A class is  a user-frendly type provided to represent
 * a concept in the code program
 * -The basic idea of concentrate classes is that they behave just like buil-in type
 * -The defining characteristic of a concentrate type is that its represenatation
 *  is part of its definition
 */

class ConcreteClassDemo
{
public:
    //in-class function definition
    void pubFun1() {
        cout<< "pubFun1()"<<endl;
        pubField1++;protField2++;privField3++;//full access to data members
        protFun2(); privFun3(); //full access to function members

    }
    //for demonstration only; data members almost always SHOULD NOT be public
    int pubField1 = 1;

protected:
    void protFun2();
    int protField2 = 2;

private:
    void privFun3();
    int privField3 =3;
    /*
     *The 'friend' declaration appearsin a class body and grants a function
     *or another class access to private and protected members of the class
     *where the friend declaration appears.
     *
     * Note: this line can be added any where insside the class
     */
    friend void gFriendFun1(ConcreteClassDemo&);

};

class AbstractClassDemo
{
public:
    virtual void vFun1() =0; //purely virtual function
    void fun2() {cout <<"fun2()"<<endl;} //normal (i.e. non-virtual)
    virtual ~AbstractClassDemo();

};


AbstractClassDemo::~AbstractClassDemo(){}
//the end of AbstractClassDemo definitions

//ConcentrarteClassDemo definitions
void ConcreteClassDemo::protFun2()
{
    cout<<"protFun2()"<<endl;
    //full access to all data members
    pubField1++;
    protField2++;
    privField3++;

    // full access to all function members
      privFun3();
}
void ConcreteClassDemo::privFun3()
{
  cout << "privFun3()" << endl;
  // as above: full access to all data and function members
  pubField1++;
  protField2++;
  privField3++;
}


void gFriendFun1(ConcreteClassDemo& cCD)
{
    cout<<"gFriendFun1()"<<endl;
    //full access to all function members

    cCD.pubField1++;
    cCD.protField2++;
    cCD.privField3++;
    // as above: full access to all function members
    cCD.pubFun1();
    cCD.protFun2();
    cCD.privFun3();
}

void gNonFriendFun2(ConcreteClassDemo& cCD)
{
    cout<<"gNonFiendlFun2()"<<endl;
    //access to public data members only
    cCD.pubField1++;
    //cCD.protFun2();
    //cCD.privFun3();

}

int main()
{
    ConcreteClassDemo ccd; //(named) object = instance of class ConcreteClassDemo&

    gFriendFun1(ccd);
    gNonFriendFun2(ccd);

    //AbstrationClassDemo acd; //cannot creata instance of abstract classes
    return 0;
}
