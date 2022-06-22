/********************************************************************************
** Form generated from reading UI file 'tasks.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKS_H
#define UI_TASKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tasks
{
public:
    QLabel *label;
    QPushButton *task1;
    QPushButton *task2;
    QPushButton *task3;
    QPushButton *task4;
    QLabel *solution;

    void setupUi(QWidget *Tasks)
    {
        if (Tasks->objectName().isEmpty())
            Tasks->setObjectName(QString::fromUtf8("Tasks"));
        Tasks->resize(600, 500);
        label = new QLabel(Tasks);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 20, 131, 17));
        task1 = new QPushButton(Tasks);
        task1->setObjectName(QString::fromUtf8("task1"));
        task1->setGeometry(QRect(30, 70, 89, 25));
        task2 = new QPushButton(Tasks);
        task2->setObjectName(QString::fromUtf8("task2"));
        task2->setGeometry(QRect(30, 110, 89, 25));
        task3 = new QPushButton(Tasks);
        task3->setObjectName(QString::fromUtf8("task3"));
        task3->setGeometry(QRect(30, 150, 89, 25));
        task4 = new QPushButton(Tasks);
        task4->setObjectName(QString::fromUtf8("task4"));
        task4->setGeometry(QRect(30, 190, 89, 25));
        solution = new QLabel(Tasks);
        solution->setObjectName(QString::fromUtf8("solution"));
        solution->setGeometry(QRect(250, 70, 311, 391));
        solution->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        solution->setWordWrap(true);

        retranslateUi(Tasks);

        QMetaObject::connectSlotsByName(Tasks);
    } // setupUi

    void retranslateUi(QWidget *Tasks)
    {
        Tasks->setWindowTitle(QCoreApplication::translate("Tasks", "Form", nullptr));
        label->setText(QCoreApplication::translate("Tasks", "\320\240\320\265\321\210\320\265\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207", nullptr));
        task1->setText(QCoreApplication::translate("Tasks", "\320\227\320\260\320\264\320\260\321\207\320\260 1", nullptr));
        task2->setText(QCoreApplication::translate("Tasks", "\320\227\320\260\320\264\320\260\321\207\320\260 2", nullptr));
        task3->setText(QCoreApplication::translate("Tasks", "\320\227\320\260\320\264\320\260\321\207\320\260 3", nullptr));
        task4->setText(QCoreApplication::translate("Tasks", "\320\227\320\260\320\264\320\260\321\207\320\260 4", nullptr));
        solution->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tasks: public Ui_Tasks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKS_H
