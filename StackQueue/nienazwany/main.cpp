#include <iostream>
#include <vector>
#define SIZE 10

using namespace std;

class StackOfInts
{
public:
  virtual int pop() = 0;
  virtual void push(int x) = 0;
  virtual bool isEmpty() = 0;
  virtual int size() = 0;
  virtual int peek() = 0;
  virtual ~StackOfInts() {}
};

class vectorImplementStack :public StackOfInts{
public:
    vectorImplementStack (int size = SIZE){
        this->capacity =size;
        this->v.reserve(this->capacity);
        this->top = -1;
    }

    int pop () override{
        //check for stack underflow
        if (isEmpty()){
            cout<<"Underflow\n";
            exit(EXIT_FAILURE);
        }
        cout<<"Removing... "<<peek()<<endl;

        //decrease stack size by 1
        return this->v[this->top--];
    }
    void push(int x) override {
        cout <<"Inserting... "<<x<<endl;
         this->v[++this->top] = x;
    }

    bool isEmpty() override {
        return top ==-1;
    }
    int size() override {
        return this->top+1;
    }
    int peek()  {
        if(!isEmpty()){
            return this->v[this->top];
        }
        exit(EXIT_FAILURE);
    }

    // Destructor to free memory allocated to the stack
    ~vectorImplementStack(){}


private:
vector<int>v;
int top;
int capacity;

};


struct Node{
    int stu_no;
    Node *next;
};
Node *top;

class LinkedListImplementStack: public StackOfInts
{

public:
    void push(int n);
    int pop();
    //void display();
    bool isEmpty();
    int peek();
    int size();
private:
    int size_=0;


};

void LinkedListImplementStack :: push(int n)
{
    struct Node *newNode=new Node;
    //fill data part
    newNode->stu_no=n;
    //link part
    newNode->next=top;
    //make newnode as top/head
    top=newNode;
    size_++;
    cout<< top->stu_no<<" is inserting ..."<<endl;
}
int LinkedListImplementStack ::pop()
{
    if(top==NULL){
        cout<<"List is empty!"<<endl;
        exit(EXIT_FAILURE);
    }

    cout<<top->stu_no<<" is removed."<<endl;
    size_--;
    top=top->next;
    return top->stu_no;
}
//void LinkedListImplementStack:: display()
//{
//if(top==NULL){
//        cout<<"List is empty!"<<endl;
//        return;
//    }
//    struct Node *temp=top;
//    while(temp!=NULL){
//        cout<<temp->stu_no<<" ";
//        cout<<endl;
//        temp=temp->next;
//    }
//    cout<<endl;
//}

int LinkedListImplementStack::peek(){
    if(top==NULL){
        cout<<"List is empty!"<<endl;
        exit(EXIT_FAILURE);
    }
    return top->stu_no;
}

bool LinkedListImplementStack::isEmpty(){
    return top ==NULL;
}
int LinkedListImplementStack::size(){
    return size_;
}
int main(){

    StackOfInts *pL =new LinkedListImplementStack;

    pL->push(1);
    pL->push(2);

    pL->pop();
    //pL->pop();

    pL->push(3);

    cout << "Top element is: " << pL->peek() << endl;
    cout << "Stack size is " << pL->size() << endl;

    pL->pop();

    if (pL->isEmpty())
        cout << "Stack Is Empty\n";
    else
        cout << "Stack Is Not Empty\n";
    delete pL;
    return 0;
}
