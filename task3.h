#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <QCoreApplication>

QByteArray task3(QString num);

class Expression
{
public:
    Expression(QString value);
    QString getValue();
private:
    QString value;

};

#endif // EXPRESSION_H
