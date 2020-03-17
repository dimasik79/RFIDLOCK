QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += \


SOURCES += \
    additionaly.cpp \
    card.cpp \
    comport.cpp \
    exitpass.cpp \
    main.cpp \
    mainwindow.cpp \
    settings.cpp

HEADERS += \
    additionaly.h \
    card.h \
    comport.h \
    exitpass.h \
    mainwindow.h \
    settings.h

FORMS += \
    additionaly.ui \
    card.ui \
    exitpass.ui \
    mainwindow.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    COPYING

RESOURCES += \
    res.qrc
