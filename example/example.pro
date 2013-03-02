QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = example
TEMPLATE = app
DESTDIR = $$PWD

SOURCES += main.cpp

OTHER_FILES += \
    example.png

include(../QxMesh.pri)
