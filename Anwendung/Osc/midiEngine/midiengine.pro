INCLUDEPATH += ../midiEngine

HEADERS += \
    ../midiEngine/midiinput.h \
    ../midiEngine/midioutput.h


win32 {
    SOURCES += \
        ../midiEngine/winmidiinput.cpp \
        ../midiEngine/winmidioutput.cpp
    LIBS += -lwinmm
}
macx {
    HEADERS += ../midiEngine/maccommon.h # macmidiinput.h macmidioutput.h
    SOURCES += \
        ../midiEngine/macmidiinput.cpp \
        ../midiEngine/macmidioutput.cpp \
        ../midiEngine/maccommon.cpp

    LIBS += -framework CoreMidi -framework CoreFoundation
}
