#include "mainmenu.h"
#include <QBrush>
#include <QImage>
MainMenu::MainMenu()
{
  QGraphicsScene* scene = new QGraphicsScene();
  QGraphicsView *view = new QGraphicsView(scene);

  scene->clear();
  scene->setBackgroundBrush(QBrush(QImage(":images/inicio.png")));

  view->show();
  view->setFixedSize(550,550);

  scene->setSceneRect(0,0,550,550);


  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
