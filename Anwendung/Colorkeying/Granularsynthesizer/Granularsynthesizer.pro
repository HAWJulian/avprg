#-------------------------------------------------
#
# Project created by QtCreator 2014-08-04T12:43:08
#
#-------------------------------------------------

QT       += core gui widgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

INCLUDEPATH += ../audioEngine
INCLUDEPATH += ../Granularsynthesizer
SOURCES += main.cpp\
        mainwindow.cpp\
    granularsynthesis.cpp \
    qcustomplot/qcustomplot.cpp \
    grain.cpp \
    filter.cpp


HEADERS  +=mainwindow.h \
    granularsynthesis.h \
    qcustomplot/qcustomplot.h \
    grain.h \
    filter.h


FORMS    += ../Granularsynthesizer/mainwindow.ui

include(../audioEngine/audioplayer.pri)
