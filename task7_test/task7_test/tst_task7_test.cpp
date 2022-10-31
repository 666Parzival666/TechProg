#include <QtTest>
#include "C:\Users\lisaf\Documents\echoServerT\server\task7.h"

// add necessary includes here

class task7_test : public QObject
{
    Q_OBJECT

public:
    task7_test();
    ~task7_test();

private slots:
    void test_case_findCycle_false();

};

task7_test::task7_test()
{

}

task7_test::~task7_test()
{

}

void task7_test::test_case_findCycle_false()
{
    QVector<QPair<int, int>> emptyVector;
    QCOMPARE(true, findCycle(emptyVector).isEmpty());
}

QTEST_APPLESS_MAIN(task7_test)

#include "tst_task7_test.moc"
