QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_task3_test.cpp \
    ../../server/task3.cpp

HEADERS += \
    ../../server/task3.h
