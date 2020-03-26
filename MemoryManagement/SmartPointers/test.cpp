#include "test.h"

test::test(QObject *parent) : QObject(parent)
{

}

void test::useWidget()
{
    //use if it a pointer

    if(!widget.data()){
        qInfo()<<"No pointer!!";
        return;
    }
    qInfo() <<"Widget = "<<widget.data();
    //Access the pointer
    widget.data()->setObjectName("Used widget!");
}
