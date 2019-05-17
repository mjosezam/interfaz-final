#include <QApplication>
#include <mythread.h>
#include <game.h>
#include <myplayer.h>
#include <stdlib.h>
#include <QDebug>
#include <iostream>
#include <thread>
#include <unistd.h>
#include "sockets.h"
#include "serial.h"
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts>
#include <string>
#include <sstream>


using namespace std;
Game *g;
int gameStart(int argc, char *argv[]){
  QApplication a(argc,argv);
  //g=new Game();
  Game::getInstance().mainButtons();
  if (!Socket::getInstance().play){
      cout<<"GRAFICO";

  }

  return a.exec();
}



int main(int argc, char *argv[])
{


  srand(time(NULL));
  std::thread gameThread1 (gameStart,argc,argv);
  gameThread1.join();

  //g->player2->vida=vidaBack;
  return 0;
}

