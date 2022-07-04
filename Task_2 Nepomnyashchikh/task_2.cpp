#include "task_2.h"

QByteArray task_2(QString num)
{
    qDebug() << num;
    const int SIZE = 9;
    int a[SIZE][SIZE] = {
            { 0, -1, 0, 0, 0, 0, -1, -1, -1 },
            { -1, 0, -1, 0, 0, 0, -1, 0, -1 },
            { 0, -1, 0, -1, 0, -1, 0, 0, -1 },
            { 0, 0, -1, 0, -1, -1, -1, 0, 0 },
            { 0, 0, 0, -1, 0, -1, 0, 0, 0 },
            { 0, 0, -1, -1, -1, 0, -1, -1, -1 },
            { -1, -1, 0, -1, 0, -1, 0, 0, -1 },
            { -1, 0, 0, 0, 0, -1, 0, 0, -1 },
            { -1, -1, -1, 0, 0, -1, -1, -1, 0 }
        };
    int d[SIZE];
    int v[SIZE];
    int temp, minindex, min;
    int begin_index = 0;
    int N = num.toInt();

    for (int i = 0; i<SIZE; i++)
    {
        for (int j = i + 1; j<SIZE; j++) {
            if (a[i][j] == -1) {
                temp = N * ((i + 1) * (i + 1) + (j + 1) * (j + 1)) + (i + 1) * (i + 1) + (j + 1) * (j + 1) + (i + 1) + (j + 1);
                temp %= 10;
                a[i][j] = temp;
                a[j][i] = temp;
            }
        }
    }
    for (int i = 0; i<SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin_index] = 0;
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i<SIZE; i++)
        {
          if ((v[i] == 1) && (d[i]<min))
          {
            min = d[i];
            minindex = i;
          }
        }
        // Добавляем найденный минимальный вес и сравниваем с текущим минимальным весом вершины
        if (minindex != 10000)
        {
          for (int i = 0; i<SIZE; i++)
          {
            if (a[minindex][i] > 0)
            {
              temp = min + a[minindex][i];
              if (temp < d[i])
              {
                d[i] = temp;
              }
            }
          }
          v[minindex] = 0;
        }
    } while (minindex < 10000);

    int ver[SIZE];
    int end = 4;
    ver[0] = end + 1;
    int k = 1;
    int weight = d[end];

    while (end != begin_index)
    {
    for (int i = 0; i<SIZE; i++)
      if (a[i][end] != 0)
      {
        int temp = weight - a[i][end]; // определяем вес пути из предыдущей вершины
        if (temp == d[i])
        {
          weight = temp;
          end = i;
          ver[k] = i + 1; // сохраняем новый вес, сохраняем предыдущую вершину и записываем ее в массив
          k++;
        }
      }
    }
    QString answer_to_string = "";
    for (int i = k - 1; i >= 0; i--) {
        answer_to_string += QString::number(ver[i]);
    }

    qDebug() << answer_to_string;

    return answer_to_string.toUtf8();
}
