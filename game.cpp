#include "game.h"
#include <QBrush>
#include <QImage>
#include "mainmenu.h"
#include "button.h"
#include <QDebug>
#include <tower.h>
#include <tower2.h>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <tower3.h>
#include <QPalette>
#include <stadistics.h>
#include <serial.h>
#include <QPushButton>
#include <stdlib.h>
#include <QProgressBar>
#include <sockets.h>
#include <iostream>
#include <QApplication>
using namespace std;
Game::Game()
{
  scene=new QGraphicsScene();
  qDebug()<<&scene<<"Escena inicial";
  view = new QGraphicsView(scene);

  scene->setBackgroundBrush(QBrush(QImage(":images/inicio.png")));
  view->show();
  view->setFixedSize(1050,700);


  scene->setSceneRect(0,0,1050,700);

  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void Game::mainButtons(){
    Button * buttonx = new Button(QString("Leave"));
      buttonx->setPos(600,500);

   QObject::connect(buttonx,SIGNAL(clicked()),this,SLOT(close()));
   scene->addItem(buttonx);

   Button * button = new Button(QString("Play"));
     button->setPos(300,500);
     connect(button,SIGNAL(clicked()),this,SLOT(start()));
   scene->addItem(button);

}

void Game::endgame(){
  scene->clear();
  scene->setBackgroundBrush(QBrush(QImage(":images/inicio.png")));
}
string Game::clear(string recibido, int ubicacion[2]){
    scene->clear();
    player = new MyPlayer();
    player1 = new MyPlayer();
    player2 = new MyPlayer();
    player1->setPixmap(QPixmap(":/images/try1.png"));
    player2->setPixmap(QPixmap(":/images/try.png"));

    scene->addItem(player1);
    scene->addItem(player2);
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setPos(64,64);
    player1->setFocus();
    player2->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setPos(64,64);
    player2->setFocus();
    serial::getInstance().deserializarIteracion3(recibido.c_str(), matriz, &player1->edad,&player2->edad,&player1->emocional,&player2->emocional,&player1->condicionFisica,&player2->condicionFisica
                                                 , &player1->resistencia,&player2->resistencia,&player1->velocidad,&player2->velocidad,&player1->generacion,&player2->generacion,&player1->id, &player2->id,
                                                   &player1->vida,&player2->vida,&player1->fitness,&player2->fitness,&player1->probabilidad,&player2->probabilidad,&player1->troncoSuperior, &player2->troncoSuperior,
                                                   &player1->troncoInferior,&player2->troncoInferior,
                                                 &player1->supervivenciaGen,&player2->supervivenciaGen,player1->arr,player2->arr, ubicacion);
    player->setPos(ubicacion[0],ubicacion[1]);
    player=player1;
    player->vida= Socket::getInstance().vida;
    qDebug()<<player->vida<<"edad it3";
    return recibido;
}

void Game::start()
{
    while(Socket::getInstance().play){
      scene->clear();
      player = new MyPlayer();
      player1 = new MyPlayer();
      player2 = new MyPlayer();
      player1->setPixmap(QPixmap(":/images/try1.png"));
      player2->setPixmap(QPixmap(":/images/try.png"));

      scene->addItem(player1);
      scene->addItem(player2);
      player1->setFlag(QGraphicsItem::ItemIsFocusable);
      player1->setPos(64,64);
      player1->setFocus();
      player2->setFlag(QGraphicsItem::ItemIsFocusable);
      player2->setPos(64,64);
      player2->setFocus();


      string json = "";
      string mensaje = serial::getInstance().serializarTurno(player->active,Socket::getInstance().turno,false);
      string recibido = Socket::getInstance().envioEscucho(mensaje, 8080, "192.168.0.111");
      qDebug()<<recibido.c_str();
      serial::getInstance().deserealizarTableroGladiador(recibido.c_str(), matriz, &player1->edad,&player2->edad,&player1->emocional,&player2->emocional,&player1->condicionFisica,&player2->condicionFisica
                                                                  , &player1->resistencia,&player2->resistencia,&player1->velocidad,&player2->velocidad,&player1->generacion,&player2->generacion,&player1->id, &player2->id,
                                                                    &player1->vida,&player2->vida,&player1->fitness,&player2->fitness,&player1->probabilidad,&player2->probabilidad,&player1->troncoSuperior, &player2->troncoSuperior,
                                                                    &player1->troncoInferior,&player2->troncoInferior,
                                                                  &player1->supervivenciaGen,&player2->supervivenciaGen,player1->arr,player2->arr);

      mode = new Stadistics();
      mode->set(0,850,11,25);
      mode->setPlainText(QString("Gladiador A*"));
      scene->addItem(mode);

      vida = new Stadistics();
      vida->set(player1->vida,850,180,20);
      //vida->setPlainText(QString("Vida: ")+QString(player1->vida));
      scene->addItem(vida);

      id = new Stadistics();
      id->set(player1->id,850,220,15);
      scene->addItem(id);

      edad = new Stadistics();
      edad->set(player1->edad,850,240,15);
      scene->addItem(edad);

      prob = new Stadistics();
      prob->set(player1->probabilidad,850,260,15);
      scene->addItem(prob);

      gen = new Stadistics();
      gen->set(player1->supervivenciaGen,850,280,15);
      scene->addItem(gen);

      emocion  = new Stadistics();
      emocion->set(player1->emocional,850,300,15);
      scene->addItem(emocion);

      superior = new Stadistics();
      superior->set(player1->troncoSuperior,850,320,15);
      scene->addItem(superior);

      inferior = new Stadistics();
      inferior->set(player1->troncoInferior,850,340,15);
      scene->addItem(inferior);

      resistencia = new Stadistics();
      resistencia->set(player1->resistencia,850,360,15);
      scene->addItem(resistencia);

      fisica = new Stadistics();
      fisica->set(player1->condicionFisica,850,380,15);
      scene->addItem(fisica);

      fitness = new Stadistics();
      fitness->set(player1->fitness,850,400,15);
      scene->addItem(fitness);

      time_in = new Stadistics();
      time_in->set(0,545,11,35);
      time_in->setPlainText(QString("0000"));
      scene->addItem(time_in);

      QProgressBar* GP = new QProgressBar();
      GP->setGeometry(870,450,100,20);
      GP->setAutoFillBackground(true);
      GP->setValue(20);
      scene->addWidget(GP);

      QProgressBar* GM = new QProgressBar();
      GM->setGeometry(870,480,100,20);
      GM->setValue(80);
      GM->setAutoFillBackground(true);
      scene->addWidget(GM);

      scene->setBackgroundBrush(QBrush(QImage(":images/game.png")));

      timer = new QTimer();
      QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
      timer->start();

      player=player1;
      Socket::getInstance().vida = player->vida;
      cout<<Socket::getInstance().vida<<"Vida inicial"<<endl;

      player1->moveArr(player1->arr);
      if (!Socket::getInstance().play){
          break;
      }
      player=player2;
      Socket::getInstance().vida= player->vida;
      cout<<Socket::getInstance().vida<<"Vida inicial backtracking"<<endl;
      player2->moveArr(player2->arr);
      Socket::getInstance().turno++;
      qDebug()<<Socket::getInstance().turno<<"TURNO";
    }
    qDebug()<<"Game Over";
    string mensaje = serial::getInstance().serializarTurno(false,1,false);
    string recibido = Socket::getInstance().envioEscucho(mensaje, 8080, "192.168.0.111");
    scene->clear();


}


void Game::close(){
  view->close();
}

void Game::spawn(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if (matriz[j][i]==1){
                Tower * tower = new Tower();
                tower->setPos((j+1)*60,(i+1)*60);
                listaTorres->Add(tower);
                cout<<"Se agrega torre";
                this->scene->addItem(tower);
            }
            else if (matriz[j][i]==2){
                Tower2 * tower = new Tower2();
                tower->setPos((j+1)*60,(i+1)*60);
                listaTorres2->Add(tower);
                cout<<"Se agrega torre";
                this->scene->addItem(tower);
            }
            else if (matriz[j][i]==3){
                Tower3 * tower = new Tower3();
                tower->setPos((j+1)*60,(i+1)*60);
                listaTorres3->Add(tower);
                cout<<"Se agrega torre";
                this->scene->addItem(tower);
            }
        }
    }timer->stop();
    cout << "timer stopped" << endl;
}


