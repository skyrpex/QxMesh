#include "qxpsimpl.h"
#include "psimpl-7/psimpl.h"

QVector<qreal> fromPointVector(const QPolygonF& polygon)
{
  QVector<qreal> polyLine;
  foreach(const QPointF &point, polygon)
  {
    polyLine << point.x() << point.y();
  }
  return polyLine;
}

QPolygonF toPointVector(const QVector<qreal> &polyLine)
{
  QPolygonF polygon;
  for(int i = 0; i < polyLine.count(); i += 2)
  {
    polygon << QPointF(polyLine[i], polyLine[i+1]);
  }
  return polygon;
}


void QxPSimpl::simplifyNthPoint(QPolygonF &polygon, unsigned int n)
{
  QVector<qreal> polyLine = fromPointVector(polygon);

  QVector<qreal> simplified;
  QVector<qreal>::const_iterator begin = polyLine.constBegin();
  QVector<qreal>::const_iterator end = polyLine.constEnd();
  psimpl::simplify_nth_point<2>(begin, end, n,
                                std::back_inserter(simplified));

  polygon = toPointVector(simplified);
}

void QxPSimpl::simplifyRadialDistance(QPolygonF &polygon, qreal tolerance)
{
  QVector<qreal> polyLine = fromPointVector(polygon);

  QVector<qreal> simplified;
  QVector<qreal>::const_iterator begin = polyLine.constBegin();
  QVector<qreal>::const_iterator end = polyLine.constEnd();
  psimpl::simplify_radial_distance<2>(begin, end, tolerance,
                                      std::back_inserter(simplified));

  polygon = toPointVector(simplified);
}

void QxPSimpl::simplifyPerpendicularDistance(QPolygonF &polygon, qreal tolerance, unsigned int n)
{
  QVector<qreal> polyLine = fromPointVector(polygon);

  QVector<qreal> simplified;
  QVector<qreal>::const_iterator begin = polyLine.constBegin();
  QVector<qreal>::const_iterator end = polyLine.constEnd();
  psimpl::simplify_perpendicular_distance<2>(begin, end, tolerance, n,
                                             std::back_inserter(simplified));

  polygon = toPointVector(simplified);
}

void QxPSimpl::simplifyReumannWitkam(QPolygonF &polygon, qreal tolerance)
{
  QVector<qreal> polyLine = fromPointVector(polygon);

  QVector<qreal> simplified;
  QVector<qreal>::const_iterator begin = polyLine.constBegin();
  QVector<qreal>::const_iterator end = polyLine.constEnd();
  psimpl::simplify_reumann_witkam<2>(begin, end, tolerance,
                                     std::back_inserter(simplified));

  polygon = toPointVector(simplified);
}

void QxPSimpl::simplifyOpheim(QPolygonF &polygon, qreal minTolerance, qreal maxTolerance)
{
  QVector<qreal> polyLine = fromPointVector(polygon);

  QVector<qreal> simplified;
  QVector<qreal>::const_iterator begin = polyLine.constBegin();
  QVector<qreal>::const_iterator end = polyLine.constEnd();
  psimpl::simplify_opheim<2>(begin, end,
                             minTolerance, maxTolerance,
                             std::back_inserter(simplified));

  polygon = toPointVector(simplified);
}

void QxPSimpl::simplifyLang(QPolygonF &polygon, qreal tolerance, unsigned int lookAhead)
{
  QVector<qreal> polyLine = fromPointVector(polygon);

  QVector<qreal> simplified;
  QVector<qreal>::const_iterator begin = polyLine.constBegin();
  QVector<qreal>::const_iterator end = polyLine.constEnd();
  psimpl::simplify_lang<2>(begin, end, tolerance, lookAhead,
                           std::back_inserter(simplified));

  polygon = toPointVector(simplified);
}

void QxPSimpl::simplifyDouglasPeucker(QPolygonF &polygon, qreal tolerance)
{
  QVector<qreal> polyLine = fromPointVector(polygon);

  QVector<qreal> simplified;
  QVector<qreal>::const_iterator begin = polyLine.constBegin();
  QVector<qreal>::const_iterator end = polyLine.constEnd();
  psimpl::simplify_douglas_peucker<2>(begin, end, tolerance,
                                      std::back_inserter(simplified));

  polygon = toPointVector(simplified);
}

void QxPSimpl::simplifyDouglasPeuckerN(QPolygonF &polygon, unsigned int vertices)
{
  QVector<qreal> polyLine = fromPointVector(polygon);

  QVector<qreal> simplified;
  QVector<qreal>::const_iterator begin = polyLine.constBegin();
  QVector<qreal>::const_iterator end = polyLine.constEnd();
  psimpl::simplify_douglas_peucker_n<2>(begin, end, vertices,
                                        std::back_inserter(simplified));

  polygon = toPointVector(simplified);
}
