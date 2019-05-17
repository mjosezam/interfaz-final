#include "mythread.h"
#include <QtDebug>
#include <game.h>
#include <QApplication>
void MyThread::run(int argc, char *argv[]){

  hello(argc,argv);

}
MyThread::MyThread(int argc, char *argv[])
{
 a=argc;

 run(argc,argv);

}

int MyThread::hello(int argc,char *argv[])
{
  QApplication a(argc,argv);
  //Game *g = new Game();
  Game::getInstance().mainButtons();
  return a.exec();
}
