#include "tower3.h"
#include "game.h"
#include <sockets.h>
#include <iostream>
#include <QApplication>
#include "myplayer.h"
using namespace std;
extern Game * g;
Tower3::Tower3()
{
  setPixmap(QPixmap(":/images/TorreExplosiva.png"));

  QVector<QPoint> points;
  points << QPoint(-3,-2) << QPoint(-3,3) << QPoint(4,3) << QPoint(4,- 2);


  int SCALE_FACTORX = 44;
  int SCALE_FACTORY = 60;
  for (size_t i =0,n=points.size();i<n;i++){
      points[i].rx()*=SCALE_FACTORX;
      points[i].ry()*=SCALE_FACTORY;
    }
  attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
  collide_items=attack_area->collidingItems();
  attack_area->show();
  QTimer *timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(kill()));
  timer->start();
}



void Tower3::attack()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
      for(int i=0,n=colliding_items.size();i<n;i++){
          if(typeid(*(colliding_items[i]))==typeid (MyPlayer)){
             //Game::getInstance().vida->setPlainText(QString::number(Socket::getInstance().vida-4));
              Game::getInstance().player->vida=Game::getInstance().player->vida-4;
             Game::getInstance().player->vida;
             cout<<"SE RESTA VIDA";
              if (Game::getInstance().player->vida<=0){
                  cout << "Player dead T3" << endl;
                      delete Game::getInstance().player;
                  if (Game::getInstance().player==Game::getInstance().player2){
                      cout<<"Cambio de Turno"<<endl;
                     // Game::getInstance().start();
                                    }
                }
            }
        }
}

void Tower3::kill()
{
  collide_items=attack_area->collidingItems();
  if (collide_items.size()==1){
      has_target=false;
      return;
    }
      double closest=190;
      QPointF enemy=QPointF(0,0);
      for(size_t i =0,n = collide_items.size();i<n;i++){
          MyPlayer * player = dynamic_cast<MyPlayer *>(collide_items[i]);
          if (player){
              double this_dist = distanceTo(player);
              if (this_dist<closest){
                  closest=this_dist;
                  enemy=collide_items[i]->pos();
                  has_target=true;
                  attack_point= enemy;
                  attack();
                }
            }
        }
}

double Tower3::distanceTo(QGraphicsItem *player)
{
  QLineF ln(this->pos(),player->pos());
  return ln.length();
}
