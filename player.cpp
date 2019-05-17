#include "player.h"
#include <QKeyEvent>
#include <QtDebug>
void Player::KeyPressedEvent(QKeyEvent *event){
  qDebug()<<"lol";
  if (event->key() == Qt::Key_Left){
      setPos(x(),y()+10);
    }
  else if (event->key() == Qt::Key_Right){
      setPos(x(),y()-10);
    }
  else if (event->key() == Qt::Key_Up){
      setPos(x()-10,y());
    }
  else if (event->key() == Qt::Key_Down){
      setPos(x()+10,y());
    }
}
