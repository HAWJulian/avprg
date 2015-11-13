
win32 {
#  für Windows muss die Umgebungsvariable OPENCV_DIR gesetzt sein 
#  auf den Pfad der OpenCV-Installation
#  Beispiel: C:\OPENCV\opencv-2.4.9\build\x86\vc12

    INCLUDEPATH += $$(OPENCV_DIR)\..\..\include
    LIBS += -L$$(OPENCV_DIR)\lib
    Release:LIBS +=  -lopencv_ts300 -lopencv_world300
    Debug:LIBS +=  -lopencv_ts300d -lopencv_world300d
}
macx {
    INCLUDEPATH += /usr/local/include
    LIBS += -L/usr/local/lib
    LIBS +=  -lopencv_core -lopencv_highgui -lopencv_imgproc
}
linux {
    INCLUDEPATH += /usr/local/include
    LIBS += -L/usr/local/lib
    LIBS +=  -lopencv_core -lopencv_highgui -lopencv_imgproc
}
