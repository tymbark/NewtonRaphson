#-------------------------------------------------
#
# Project created by QtCreator 2014-06-08T12:56:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newton_rhapson
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    equation.cpp \
    IntervalArithmetic.cpp

HEADERS  += mainwindow.h \
    equation.h \
    IntervalArithmetic.h

FORMS    += mainwindow.ui

LIBS += -lmpfr

