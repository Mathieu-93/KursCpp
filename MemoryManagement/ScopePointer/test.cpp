#include "test.h"
#include <QDebug>

test::test(QObject *parent) : QObject(parent)
{
    qInfo() << "Constructor"<< this;
}

test::~test()
{
    qInfo() << "Deconstructor"<< this;
}

void test::myTest()
{
    qInfo()<<this;
}
