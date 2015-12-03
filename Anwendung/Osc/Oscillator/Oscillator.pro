#-------------------------------------------------
#
# Project created by QtCreator 2014-08-04T12:43:08
#
#-------------------------------------------------

QT       += core gui widgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Oscillator
TEMPLATE = app

INCLUDEPATH += ../audioEngine
SOURCES += main.cpp\
        mainwindow.cpp\
    envelope.cpp \
    granularsynthesis.cpp \
    qcustomplot/qcustomplot.cpp \
    grain.cpp


HEADERS  += mainwindow.h \
    envelope.h \
    granularsynthesis.h \
    qcustomplot/qcustomplot.h \
    grain.h


FORMS    += mainwindow.ui

include(../audioEngine/audioplayer.pri)
include(../midiEngine/midiengine.pro)
