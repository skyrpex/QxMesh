#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPolygonItem>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QDebug>
#include <QDir>
#include <QxMeshDef>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  // Create the view and the scene
  QGraphicsScene scene;
  QGraphicsView view(&scene);

  // Add the image
  QImage image("./example.png");
  if(image.isNull())
    return 1;
  QGraphicsPixmapItem *pixmapItem = scene.addPixmap(QPixmap::fromImage(image));
  pixmapItem->setOpacity(0.25);

  // Trace the image
  foreach(QxMeshDef def, QxMeshDef::fromImage(image))
  {
    // Transform our mesh def
    def.offset(3);
    def.simplifyByVertexCount(40);

    // Draw the triangles
    QxMesh mesh = def.mesh();
    for(int i = 2; i < mesh.indices.count(); i+=3)
    {
      int index0 = mesh.indices[i-2];
      int index1 = mesh.indices[i-1];
      int index2 = mesh.indices[i];

      QPolygonF triangle;
      triangle << mesh.vertices[index0]
               << mesh.vertices[index1]
               << mesh.vertices[index2];

      scene.addPolygon(triangle);
    }

//    scene.addPolygon(def.boundary, QPen(Qt::blue));
//    foreach(const QPolygonF &hole, def.holes)
//    {
//      scene.addPolygon(hole, QPen(Qt::red));
//    }
  }

  // Show the view
  view.scale(2, 2);
  view.show();

  return a.exec();
}
