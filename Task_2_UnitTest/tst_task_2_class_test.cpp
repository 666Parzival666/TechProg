#include <QtTest>
#include "C:\Users\Oveni\Documents\Nepomnyashchikh\task_2.h"

// add necessary includes here

class task_2_class_test : public QObject
{
    Q_OBJECT

public:
    task_2_class_test();
    ~task_2_class_test();

private slots:
    void test_case_task_2_9();

};

task_2_class_test::task_2_class_test()
{

}

task_2_class_test::~task_2_class_test()
{

}

void task_2_class_test::test_case_task_2_9()
{
    QString ans = "12965";
    QString ansTask1 = task_2("9");
    QCOMPARE(ans, ansTask1);
}

QTEST_APPLESS_MAIN(task_2_class_test)

#include "tst_task_2_class_test.moc"
