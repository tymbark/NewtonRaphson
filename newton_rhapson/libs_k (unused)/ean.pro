#-------------------------------------------------
#
# Project created by QtCreator 2013-06-02T17:25:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ean
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cspl.cpp \
    IntervalArithmetic.cpp

HEADERS  += mainwindow.h \
    cspl.h \
    IntervalArithmetic.h

FORMS    += mainwindow.ui

RESOURCES += \
    ean.qrc

LIBS += -lquadmath
