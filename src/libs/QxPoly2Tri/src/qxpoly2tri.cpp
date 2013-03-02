#include <QxPoly2Tri>
#include "poly2tri/poly2tri.h"
#include <QDebug>

typedef std::vector<p2t::Triangle *> P2tTriangleVector;
typedef std::vector<p2t::Point *> P2tPointVector;

static void toPoly2Tri(const QVector<QPointF> &polygon,
                       std::vector<p2t::Point *> &p2tVector)
{
  Q_ASSERT(polygon.first() != polygon.last());
  foreach(const QPointF &point, polygon)
  {
    p2tVector.push_back(new p2t::Point(point.x(), point.y()));
  }
}

static int indexOf(const P2tPointVector &vector, p2t::Point *p)
{
  for(unsigned int i = 0; i < vector.size(); ++i)
  {
    if(vector[i] == p) return i;
  }
  return -1;
}

void p2tAppend(const P2tPointVector &vector, P2tPointVector &appended)
{
  for(unsigned int i = 0; i < vector.size(); ++i)
  {
    appended.push_back(vector[i]);
  }
}

bool QxPoly2Tri::triangulate(
    const QPolygonF &boundary,
    const QList<QPolygonF> &holes,
    const QList<QPointF> &steinerPoints)
{
  m_points.clear();
  m_indices.clear();
  m_constrainedIndex.clear();

  std::vector<p2t::Point *> p2tFullVector;

  // Add boundary
  std::vector<p2t::Point *> p2tBoundary;
  toPoly2Tri(boundary, p2tBoundary);
  p2t::CDT cdt(p2tBoundary);

  m_points << boundary;
  p2tAppend(p2tBoundary, p2tFullVector);


  // Add inner points
  foreach(const QPointF &point, steinerPoints)
  {
    p2t::Point *p2tPoint = new p2t::Point(point.x(), point.y());
    cdt.AddPoint(p2tPoint);

    m_points << point;
    p2tFullVector.push_back(p2tPoint);
  }

  // Add holes
  foreach(const QPolygonF &hole, holes)
  {
    if(hole.isEmpty()) continue;

    std::vector<p2t::Point *> p2tHole;
    toPoly2Tri(hole, p2tHole);
    cdt.AddHole(p2tHole);

    m_points << hole;
    p2tAppend(p2tHole, p2tFullVector);
  }

  // Triangulate
  cdt.Triangulate();


  // Get triangles
  P2tTriangleVector triangles = cdt.GetTriangles();
  for(P2tTriangleVector::const_iterator it = triangles.begin();
      it != triangles.end();
      ++it)
  {
    p2t::Triangle *p2tTri = *it;
    p2t::Point *p0 = p2tTri->GetPoint(0);
    p2t::Point *p1 = p2tTri->GetPoint(1);
    p2t::Point *p2 = p2tTri->GetPoint(2);

//    int edgeIndex0 = p2tTri->EdgeIndex(p0, p1);
//    int edgeIndex1 = p2tTri->EdgeIndex(p1, p2);
//    int edgeIndex2 = p2tTri->EdgeIndex(p2, p0);

    int i0 = indexOf(p2tFullVector, p0);
    int i1 = indexOf(p2tFullVector, p1);
    int i2 = indexOf(p2tFullVector, p2);
//    qDebug() << i0 << i1 << i2;
//    Q_ASSERT(i0 >= 0 && i1 >= 0 && i2 >= 0);
    if(i0 >= 0 && i1 >= 0 && i2 >= 0)
    {
      m_indices << i0
                << i1
                << i2;
      m_constrainedIndex << p2tTri->constrained_edge[2]
                         << p2tTri->constrained_edge[0]
                         << p2tTri->constrained_edge[1];
    }
    else
      return false;
  }
  return true;
}

QVector<QPointF> QxPoly2Tri::points() const
{
  return m_points;
}

QVector<int> QxPoly2Tri::indices() const
{
  return m_indices;
}

bool QxPoly2Tri::isConstrained(int index) const
{
  return m_constrainedIndex.at(index);
}
