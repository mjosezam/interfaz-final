#ifndef MAINMENU_H
#define MAINMENU_H
#include <QGraphicsScene>
#include <QGraphicsView>

class MainMenu: public QGraphicsView
{
  Q_OBJECT
public:
  QGraphicsScene *scene;
  MainMenu();
};

#endif // MAINMENU_H
