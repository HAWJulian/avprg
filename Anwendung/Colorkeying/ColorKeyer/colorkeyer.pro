#-------------------------------------------------
#
# Project created by QtCreator 2014-07-15T19:38:24
#
#-------------------------------------------------

QT       += core gui widgets



TARGET = ColorKeyer
TEMPLATE = app
INCLUDEPATH += ../Granularsynthesizer/
INCLUDEPATH += ../audioEngine/

SOURCES += main.cpp\
        videoplayer.cpp \
    colorkeyer.cpp \
    asdf.cpp

HEADERS  += videoplayer.h \
    colorkeyer.h \
    asdf.h


FORMS    += videoplayer.ui \
    asdf.ui

include(../videoengine/videoengine.pri)
include(../Granularsynthesizer/Granularsynthesizer.pro)
