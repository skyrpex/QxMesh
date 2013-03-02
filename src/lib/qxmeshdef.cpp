#include <QxMeshDef>
#include <QxPotrace>
#include <QxPSimpl>
#include <QxClipper>
#include <QxPoly2Tri>
#include <QDebug>

QxMeshDef::QxMeshDef()
{

}

QxMeshDef::QxMeshDef(const QPolygonF &boundary,
                     const QList<QPolygonF> &holes,
                     const QList<QPointF> &points) :
  boundary(boundary),
  holes(holes),
  points(points)
{

}

QxMeshDef::QxMeshDef(const QxMeshDef &other) :
  boundary(other.boundary),
  holes(other.holes),
  points(other.points)
{

}

QxMesh QxMeshDef::mesh() const
{
  QxPoly2Tri p2t;
  if(!p2t.triangulate(boundary, holes, points))
    return QxMesh();

  QxMesh mesh;
  mesh.indices = p2t.indices();
  mesh.vertices = p2t.points();
  return mesh;
}

void QxMeshDef::simplifyByVertexCount(uint vertexCount)
{
  QxPSimpl::simplifyDouglasPeuckerN(boundary, vertexCount);
  for(int i = 0; i < holes.count(); ++i)
    QxPSimpl::simplifyDouglasPeuckerN(holes[i], vertexCount);
}

void QxMeshDef::simplifyByTolerance(qreal tolerance)
{
  QxPSimpl::simplifyDouglasPeucker(boundary, tolerance);
  for(int i = 0; i < holes.count(); ++i)
    QxPSimpl::simplifyDouglasPeucker(holes[i], tolerance);
}

QxMeshDef QxMeshDef::simplified(qreal tolerance) const
{
  QxMeshDef def(*this);
  def.simplifyByTolerance(tolerance);
  return def;
}

void QxMeshDef::offset(qreal pixels)
{
//  boundary = QxClipper::offseted(boundary, pixels);
  QList<QPolygonF> polygons;
  polygons << boundary
           << holes;
  boundary.clear();
  holes.clear();

  polygons = QxClipper::offseted(polygons, pixels);
  foreach(const QPolygonF &poly, polygons)
  {
    if(QxClipper::orientation(poly) == Qx::Clockwise)
      boundary = poly;
    else
      holes << poly;
//    qDebug() << QxClipper::orientation(poly);
  }
}

QxMeshDef QxMeshDef::offseted(qreal pixels) const
{
  QxMeshDef def(*this);
  def.offset(pixels);
  return def;
}

QList<QxMeshDef> QxMeshDef::fromImage(const QImage &image)
{
  QxPotrace potrace;
  if(!potrace.trace(image))
    return QList<QxMeshDef>();

  QList<QxMeshDef> defs;
  foreach(const QxPotrace::Polygon &polygon, potrace.polygons())
  {
    defs << QxMeshDef(polygon.boundary, polygon.holes);
  }
  return defs;
}
