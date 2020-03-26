#include <QCoreApplication>
#include <QDebug>
#include <QScopedPointer>
#include "test.h"

void useit(test* obj){
    if(obj) return;

    qInfo() <<"Using" <<obj;
}

void doStuff(){
    //test *t = new test(); //dangling pointer!!
    QScopedPointer<test> mypointer(new test());
    mypointer->myTest();
    useit(mypointer.data());
    //pointer is automatically deleted!!
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    doStuff();
    return a.exec();
}
