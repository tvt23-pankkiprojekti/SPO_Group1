QT += gui core serialport widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += network

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    env.cpp \
    main.cpp \
    mainwindow.cpp \
    transaction.cpp

HEADERS += \
    mainwindow.h \
    transaction.h \
    profilewindow.cpp

HEADERS += \
    mainwindow.h \
    env.h \
    profilewindow.h \
    transaction.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/../pincodeDLL/build/debug/ -lpincodeDLL

INCLUDEPATH += $$PWD/../pincodeDLL
DEPENDPATH += $$PWD/../pincodeDLL

DISTFILES += \
    myStyle.qss \
    styles/myStyle.qss \
    backG.jpg

RESOURCES += \
    Retest.qrc
