#ifndef TOWER3_H
#define TOWER3_H

#include "tower.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>
class Tower3:public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Tower3();
  void attack();

public slots:
  void kill();
private:
  QGraphicsPolygonItem *attack_area;QPointF attack_point;
  bool has_target;
  double distanceTo(QGraphicsItem *player);
  QList<QGraphicsItem *> collide_items;

};

#endif // TOWER3_H
