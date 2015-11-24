#-------------------------------------------------
#
# Project created by QtCreator 2014-07-15T19:38:24
#
#-------------------------------------------------

QT       += core gui widgets



TARGET = ColorKeyer
TEMPLATE = app


SOURCES += main.cpp\
        videoplayer.cpp \
    colorkeyer.cpp \
    _envelope.cpp \
    _mainwindow.cpp \
    _oscillator.cpp \
    _oscillatorsource.cpp \
    Neuer Ordner/envelope.cpp \
    Neuer Ordner/mainwindow.cpp \
    Neuer Ordner/oscillator.cpp \
    Neuer Ordner/oscillatorsource.cpp \
    envelope.cpp \
    mainwindow.cpp \
    oscillator.cpp \
    oscillatorsource.cpp

HEADERS  += videoplayer.h \
    colorkeyer.h \
    _envelope.h \
    _mainwindow.h \
    _oscillator.h \
    _oscillatorsource.h \
    Neuer Ordner/envelope.h \
    Neuer Ordner/mainwindow.h \
    Neuer Ordner/oscillator.h \
    Neuer Ordner/oscillatorsource.h \
    envelope.h \
    mainwindow.h \
    oscillator.h \
    oscillatorsource.h

FORMS    += videoplayer.ui \
    _mainwindow.ui \
    Neuer Ordner/mainwindow.ui \
    mainwindow.ui

include(../videoengine/videoengine.pri)
