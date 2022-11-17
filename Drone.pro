QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
 QT += network

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    network.cpp \
    pitch.cpp \
    roll.cpp \
    switch.cpp \
    throttle.cpp \
    widget.cpp \
    yaw.cpp

HEADERS += \
    mainwindow.h \
    network.h \
    pitch.h \
    roll.h \
    switch.h \
    throttle.h \
    widget.h \
    yaw.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Res/ClassPic.png \
    Res/Process.png

RESOURCES += \
    Res/Res.qrc
