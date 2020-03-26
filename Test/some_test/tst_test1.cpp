#include <QtTest>

// add necessary includes here

class test1 : public QObject
{
    Q_OBJECT

public:
    test1();
    ~test1();

private slots:
    void test_case1();

};

test1::test1()
{

}

test1::~test1()
{

}

void test1::test_case1()
{

}

QTEST_APPLESS_MAIN(test1)

#include "tst_test1.moc"
