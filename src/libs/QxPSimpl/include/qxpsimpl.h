#ifndef QXPSIMPL_H
#define QXPSIMPL_H

#include <qxpsimpl_global.h>
#include <QPolygonF>

class QXPSIMPL_EXPORT QxPSimpl
{
public:
  static void simplifyNthPoint(QPolygonF &polygon, unsigned int n);

  static void simplifyRadialDistance(QPolygonF &polygon,
                                     qreal tolerance);

  static void simplifyPerpendicularDistance(QPolygonF &polygon,
                                            qreal tolerance,
                                            unsigned int n = 0);

  static void simplifyReumannWitkam(QPolygonF &polygon,
                                    qreal tolerance);

  static void simplifyOpheim(QPolygonF &polygon,
                             qreal minTolerance,
                             qreal maxTolerance);

  static void simplifyLang(QPolygonF &polygon,
                           qreal tolerance,
                           unsigned int lookAhead);

  static void simplifyDouglasPeucker(QPolygonF &polygon,
                                     qreal tolerance);

  static void simplifyDouglasPeuckerN(QPolygonF &polygon,
                                      unsigned int vertices);
};

#endif // QXPSIMPL_H
