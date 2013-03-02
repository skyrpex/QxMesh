#ifndef QXPOLY2TRI_H
#define QXPOLY2TRI_H

#include <qxpoly2tri_global.h>
#include <QPolygonF>
#include <QList>

class QXPOLY2TRI_EXPORT QxPoly2Tri
{
public:
  bool triangulate(const QPolygonF &boundary,
                   const QList<QPolygonF> &holes,
                   const QList<QPointF> &steinerPoints);

  QVector<QPointF> points() const;
  QVector<int> indices() const;
  bool isConstrained(int index) const;

private:
  QVector<QPointF> m_points;
  QVector<int> m_indices;
  QVector<bool> m_constrainedIndex;
};

#endif // QXPOLY2TRI_H
