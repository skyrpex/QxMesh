#ifndef QXPSIMPL_GLOBAL_H
#define QXPSIMPL_GLOBAL_H

#include <QtGlobal>

#if defined(QXPSIMPL_LIBRARY)
#  define QXPSIMPL_EXPORT Q_DECL_EXPORT
#else
#  define QXPSIMPL_EXPORT Q_DECL_IMPORT
#endif

#endif // QXPSIMPL_GLOBAL_H