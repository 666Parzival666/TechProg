#ifndef TASK7_H
#define TASK7_H
#include <QString>
#include <QVector>
#include <QDebug>

QString print(QVector<QPair<int, int>> source1);
bool sortStringSize(QString str1, QString str2);
QVector<QString> findCycle(QVector<QPair<int, int>>);
void getVertDeg(QSet<int> *setOfVerts, QVector<QPair<int, int>> source);
QString getMax(QVector<QString> source);
void print(QVector<QString> source);
void buildToEiler(QVector<int> verticalsPower, QVector<QPair<int, int>> *source);

#endif // TASK7_H
