#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <myplayer.h>
#include <QTimer>
#include "myplayer.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItemGroup>
#include <QObject>
#include <QWidget>
#include "linkedlist.h"
#include "stadistics.h"
#include<QKeyEvent>
class Game:public QGraphicsView, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Game();
  LinkedList* listaTorres = new LinkedList;
  LinkedList* listaTorres2 = new LinkedList;
  LinkedList* listaTorres3 = new LinkedList;
  static Game & getInstance(){
          static Game instance;
    return instance;}
  QGraphicsView *view;
  QGraphicsScene *scene;
  MyPlayer *player,*player1, *player2;
  Stadistics *mode,*time_in,*vida,*vida2,*id,*edad,*prob,*gen,*emocion,*superior,*inferior,*resistencia,*fisica,*fitness;
  QTimer *timer;
  Stadistics *one,*two,*three,*four,*five,*six,*seven,*eight,*nine,*ten,*eleven;
  int matriz[10][10];
  int i=0;
  void mainButtons();
  void endgame();

  string clear(string recibido, int ubicacion[2]);
public slots:
  void spawn();
  void start();
  void close();
};

#endif // GAME_H
