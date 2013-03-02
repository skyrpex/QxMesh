include(src/libs/QxClipper/QxClipper.pri)
include(src/libs/QxPoly2Tri/QxPoly2Tri.pri)
include(src/libs/QxPotrace/QxPotrace.pri)
include(src/libs/QxPSimpl/QxPSimpl.pri)

INCLUDEPATH *= $$PWD/include
LIBS *= -L$$PWD/bin -lQxMesh
