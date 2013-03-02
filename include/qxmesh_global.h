#ifndef QXMESH_GLOBAL_H
#define QXMESH_GLOBAL_H

#include <QtGlobal>

#if defined(QXMESH_LIBRARY)
#  define QXMESH_API Q_DECL_EXPORT
#else
#  define QXMESH_API Q_DECL_IMPORT
#endif


#endif // QXMESH_GLOBAL_H
