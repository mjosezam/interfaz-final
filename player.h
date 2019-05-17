#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>


class Player:public QGraphicsRectItem
{
public:
 void KeyPressedEvent(QKeyEvent *event);
};

#endif // PLAYER_H
