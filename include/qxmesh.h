#ifndef QXMESH_H
#define QXMESH_H

#include <QPointF>
#include <QVector>
#include "qxmesh_global.h"

class QXMESH_API QxMesh
{
public:
  QxMesh();
  QxMesh(const QVector<QPointF> &vertices,
         const QVector<int> &indices);
  QxMesh(const QxMesh &other);

  QVector<QPointF> vertices;
  QVector<int> indices;
};

#endif // QXMESH_H
