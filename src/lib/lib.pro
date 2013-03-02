TARGET = QxMesh
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DESTDIR = $$PWD/../../bin
TEMPLATE = lib
DEFINES += QXMESH_LIBRARY

SOURCES += \
    qxmeshdef.cpp \
    qxmesh.cpp

HEADERS += \
    ../../include/qxmeshdef.h \
    ../../include/qxmesh.h \
    ../../include/QxMesh \
    ../../include/QxMeshDef

INCLUDEPATH += ../../include/

include(../libs/QxClipper/QxClipper.pri)
include(../libs/QxPoly2Tri/QxPoly2Tri.pri)
include(../libs/QxPotrace/QxPotrace.pri)
include(../libs/QxPSimpl/QxPSimpl.pri)
