QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_task7_test.cpp \
    ../../server/task7.cpp

HEADERS += \
    ../../server/task7.h
