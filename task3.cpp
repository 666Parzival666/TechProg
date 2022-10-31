#include <QCoreApplication>
#include "iostream"
#include "task3.h"
#include <QDebug>

using namespace std;

QByteArray task3(QString num){

    qDebug() << "start";

    QString input = "0110100101001011";
    QList<int> numbers;
    QList<int> M0;
    QList<int> M1;

    for (int i = 0; i < input.size(); i++) {
        QChar c = input[i];
        int a = c.digitValue();
        numbers.push_back(a);
        if (a == 0) {
            M0.push_back(i);
        } else {
            M1.push_back(i);
        }
    }

    QHash<QString, int> matches;

    for (int i = 0; i < numbers.size(); i++) {
        QString binary = QString::number(i, 2);
        while (binary.size() != 4) {
            binary = "0" + binary;
        }
        QString hex = "";
        if (i < 10) {
            hex = QString::number(i, 10);
        } else if (i == 10) {
            hex = "A";
        } else if (i == 11) {
            hex = "B";
        } else if (i == 12) {
            hex = "C";
        } else if (i == 13) {
            hex = "D";
        } else if (i == 14) {
            hex = "E";
        } else if (i == 15) {
            hex = "F";
        }
        matches.insert(binary, numbers[i]);

        qDebug() << hex << "   " << binary << "   " << numbers[i];
    }

    qDebug() << "";

    for (int i = 0; i < 4; i++) {
        QString str;
        for (int j = 0; j < 4; j++) {
            int a = i;
            int b = j;
            if (i == 2) {
                a = 3;
            } else if (i == 3) {
                a = 2;
            }

            if (j == 2) {
                b = 3;
            } else if (j == 3) {
                b = 2;
            }

            QString aBin = QString::number(a, 2);
            QString bBin = QString::number(b, 2);

            while (aBin.size() < 2) {
                aBin = "0" + aBin;
            }
            while (bBin.size() < 2) {
                bBin = "0" + bBin;
            }
            // "stroka" + 1
            str += QString::number(matches.value(aBin + bBin)) + " ";
        }
        qDebug() << str;
    }

    qDebug() << "";


    QString sM0 = "M0: ";
    foreach (int n, M0) {
        sM0 += QString::number(n) + " ";
    }

    qDebug() << sM0;

    QString sM1 = "M1: ";
    foreach(int n, M1) {
        sM1 += QString::number(n) + " ";
    }

    qDebug() << sM1;

    return sM0.toUtf8();
}
// (x->(y->z))->((x->y)->(x->z))
