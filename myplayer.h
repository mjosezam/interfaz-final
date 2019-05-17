#ifndef MYPLAYER_H
#define MYPLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include "linkedlist.h"
class MyPlayer:public QObject,public QGraphicsPixmapItem{
  Q_OBJECT
public:
  MyPlayer(QGraphicsItem * parent =0);
  void moveArr(int arr[30][2]);
  int arr[30][2];
  bool active=true;
  int edad=0;
  int emocional=0;
  int condicionFisica=0;
  int resistencia=0;
  int velocidad=0;
  int generacion=0;
  int id=0;
  int vida=0;
  int age=0;
  int probabilidad=0;
  int troncoSuperior=0;
  int troncoInferior=0;
  int supervivenciaGen=0;
  int fitness=0;
};

#endif // MYPLAYER_H
