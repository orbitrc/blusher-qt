QT += gui

TEMPLATE = lib
DEFINES += BLUSHERQT_LIBRARY

CONFIG += c++14

INCLUDEPATH += ./include

TARGET = blusher

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/application-impl.cpp \
    src/application.cpp \
    src/surface.cpp \
    src/color.cpp \
    blusherqt.cpp \
    src/surface-impl.cpp

HEADERS += \
    include/blusher/application.h \
    include/blusher/surface.h \
    include/blusher/color.h \
    blusher-qt_global.h \
    blusherqt.h \
    src/application-impl.h \
    src/surface-impl.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
