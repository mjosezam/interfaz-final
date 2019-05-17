#ifndef STADISTICS_H
#define STADISTICS_H
#include <QGraphicsTextItem>

class Stadistics: public QGraphicsTextItem
{
public:
  Stadistics(QGraphicsItem *parent=0);
  void set(int player,int x, int y, int size);
};

#endif // STADISTICS_H
