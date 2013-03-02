#ifndef QXMESHDEF_H
#define QXMESHDEF_H

#include <QPolygonF>
#include <QList>
#include <QImage>
#include "qxmesh.h"
#include "qxmesh_global.h"

class QXMESH_API QxMeshDef
{
public:
  QxMeshDef();

  QxMeshDef(const QPolygonF &boundary,
            const QList<QPolygonF> &holes = QList<QPolygonF>(),
            const QList<QPointF> &points = QList<QPointF>());

  QxMeshDef(const QxMeshDef &other);

  QxMesh mesh() const;

  void simplifyByVertexCount(uint vertexCount);

  void simplifyByTolerance(qreal tolerance);

  QxMeshDef simplified(qreal tolerance) const;

  void offset(qreal pixels);

  QxMeshDef offseted(qreal pixels) const;

  static QList<QxMeshDef> fromImage(const QImage &image);

  QPolygonF boundary;
  QList<QPolygonF> holes;
  QList<QPointF> points;
};

#endif // QXMESHDEF_H
