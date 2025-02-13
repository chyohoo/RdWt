#-------------------------------------------------
#
# Project created by QtCreator 2019-03-03T12:50:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RdWt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    write_data.cpp

HEADERS += \
        widget.h \
    write_data.h \
    thread.h

FORMS += \
        widget.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



QMAKE_CXXFLAGS += -std=c++0x



unix:!macx: LIBS += -L$$PWD/../../../opt/qt5pi/sysroot/usr/lib/python2.7/config-arm-linux-gnueabihf/ -lpython2.7

INCLUDEPATH += $$PWD/../../../opt/qt5pi/sysroot/usr/include/python2.7
DEPENDPATH += $$PWD/../../../opt/qt5pi/sysroot/usr/include/python2.7

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../opt/qt5pi/sysroot/usr/lib/python2.7/config-arm-linux-gnueabihf/libpython2.7.a
