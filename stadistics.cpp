  #include "stadistics.h"
#include <QFont>

Stadistics::Stadistics(QGraphicsItem *parent)
{
  setDefaultTextColor(Qt::black);
}
void Stadistics::set(int player,int x, int y, int size)
{
  this->setPlainText(QString::number(player));
  this->setPos(x,y);
  setFont(QFont("Arial",size));
}
