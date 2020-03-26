#ifndef STACKOFINT_H
#define STACKOFINT_H

class StackOfInts
{
public:
   int pop() ;
   void push(int );
   bool isEmpty() ;
   int size() = 0;
   int peek() const;
   ~StackOfInts() {}
};
#endif // STACKOFINT_H
