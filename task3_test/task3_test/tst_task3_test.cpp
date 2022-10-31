#include <QtTest>
#include "C:\Users\lisaf\Documents\echoServerT\server\task3.h"

class task3_test : public QObject
{
    Q_OBJECT

public:
    task3_test();
    ~task3_test();

private slots:
    void test_task3_0110100101001011_03568101113_12479121415();

};

task3_test::task3_test()
{

}

task3_test::~task3_test()
{

}

void task3_test::test_task3_0110100101001011_03568101113_12479121415()
{
    QString ans = "M0: 0 3 5 6 8 10 11 13 ";
    QCOMPARE(task3("0110100101001011"), ans);


}

QTEST_APPLESS_MAIN(task3_test)

#include "tst_task3_test.moc"
