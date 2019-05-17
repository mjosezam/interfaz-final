#ifndef TOWER_H
#define TOWER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>
class Tower:public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Tower(QGraphicsItem * parent =0);
  void attack();

public slots:
  void kill();
private:
  QGraphicsPolygonItem *attack_area;QPointF attack_point;
  bool has_target;
  double distanceTo(QGraphicsItem *player);
  QList<QGraphicsItem *> collide_items;

};


#endif // TOWER_H
