QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = QxPSimpl
TEMPLATE = lib
DESTDIR = $$PWD/bin
DEFINES += QXPSIMPL_LIBRARY

SOURCES += \
    $$PWD/src/qxpsimpl.cpp

HEADERS  += \
    $$PWD/include/QxPSimpl \
    $$PWD/include/qxpsimpl.h

INCLUDEPATH += $$PWD/include