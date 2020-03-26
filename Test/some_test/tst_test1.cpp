#include <QtTest>

// add necessary includes here

int add(int x,int y){
    return x+y;
}
class test1 : public QObject
{
    Q_OBJECT

public:
    test1();
    ~test1();

private slots:
    void test_case1();
    //void test_case2();

};

test1::test1()
{

}

test1::~test1()
{

}

void test1::test_case1()
{
    QVERIFY(add(1,2) ==3);
}

QTEST_APPLESS_MAIN(test1)

#include "tst_test1.moc"
