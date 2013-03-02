#include <QxMesh>

QxMesh::QxMesh()
{

}

QxMesh::QxMesh(const QVector<QPointF> &points,
               const QVector<int> &indices) :
  vertices(points),
  indices(indices)
{

}

QxMesh::QxMesh(const QxMesh &other) :
  vertices(other.vertices),
  indices(other.indices)
{

}
