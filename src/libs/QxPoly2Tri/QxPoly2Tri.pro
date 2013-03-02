QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = QxPoly2Tri
TEMPLATE = lib
DESTDIR = $$PWD/bin
DEFINES += QXPOLY2TRI_LIBRARY

SOURCES += \
  $$PWD/src/qxpoly2tri.cpp \
  $$PWD/src/poly2tri/common/shapes.cc \
  $$PWD/src/poly2tri/sweep/sweep_context.cc \
  $$PWD/src/poly2tri/sweep/sweep.cc \
  $$PWD/src/poly2tri/sweep/cdt.cc \
  $$PWD/src/poly2tri/sweep/advancing_front.cc

HEADERS  += \
  $$PWD/include/QxPoly2Tri \
  $$PWD/include/qxpoly2tri.h \
  $$PWD/include/qxpoly2tri_global.h \
  $$PWD/src/poly2tri/poly2tri.h \
  $$PWD/src/poly2tri/common/utils.h \
  $$PWD/src/poly2tri/common/shapes.h \
  $$PWD/src/poly2tri/sweep/sweep_context.h \
  $$PWD/src/poly2tri/sweep/sweep.h \
  $$PWD/src/poly2tri/sweep/cdt.h \
  $$PWD/src/poly2tri/sweep/advancing_front.h

    
INCLUDEPATH += $$PWD/include