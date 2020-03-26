#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    qInfo()<<this<<"Constructor";
}

test::~test()
{
    qInfo()<<this<<"Constructor";
}

void test::makeChild(QString name)
{
    test *child = new test(this);
    child->setObjectName(name);
}
