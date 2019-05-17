#ifndef TOWER2_H
#define TOWER2_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>
class Tower2:public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Tower2();
  void attack();

public slots:
  void kill();
private:
  QGraphicsPolygonItem *attack_area;QPointF attack_point;
  bool has_target;
  double distanceTo(QGraphicsItem *player);
  QList<QGraphicsItem *> collide_items;

};

#endif // TOWER2_H
