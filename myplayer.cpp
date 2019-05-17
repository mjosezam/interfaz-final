#include "myplayer.h"
#include <QDebug>
#include <QKeyEvent>
#include <QThread>
#include <tower.h>
#include <tower2.h>
#include <tower3.h>
#include "game.h"
#include <unistd.h>
#include <stdlib.h>
#include <QApplication>
#include <iostream>
#include "sockets.h"
#include "serial.h"
#include "node.h"
using namespace std;
extern Game *g;
MyPlayer::MyPlayer(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem ()
{

}

void MyPlayer::moveArr(int arr[30][2]){
    int ubicacion[2] = {0,0};
    string recibido;
    for (int i=0; i<30; i++){
        if (Game::getInstance().player->vida>0 && Socket::getInstance().vida>0){
            cout << arr[i][0]<<"  , "<<arr[i][1]<<endl;
            if (Socket::getInstance().turno%3==0 && Socket::getInstance().turno!=0){
                qDebug()<<"Iteracion 3";

                if (Game::getInstance().player==Game::getInstance().player1){
                    string enviar=serial::getInstance().serializarTurno(true,Socket::getInstance().turno,false);
                    recibido = Socket::getInstance().envioEscucho(enviar,8080,"192.168.0.111");
                    cout<<"A* jugando"<<endl;
                }else{
                    string enviar = serial::getInstance().serializarTurno(true,Socket::getInstance().turno,true);
                     recibido = Socket::getInstance().envioEscucho(enviar,8080,"192.168.0.111");
                     cout<<"BACK Jugando"<<endl;
                }
                recibido = Game::getInstance().clear(recibido, ubicacion);
                qDebug()<<recibido.c_str()<<"RECIBIDO DE ITERACION #3";

                Game::getInstance().player->setPos((ubicacion[0]+1)*60,(ubicacion[1]+1)*60);

//                if(arr[1][0]==9 && arr[1][1]==9 && Game::getInstance().player->vida>0){
//                    Socket::getInstance().play = false;
//                    qDebug()<<"GAME OVER";
//                    break;
//                }
                if (Game::getInstance().player->vida <= 0){
                    qDebug()<<"MURIO EL PLAYER";
                    string envio = serial::getInstance().serializarTurno(true,Socket::getInstance().turno,false);
                    Socket::getInstance().envioEscucho(envio,8080,"192.168.0.111");
                    return;
                }
                for(int i=0;i<10;i++){
                    for(int j=0;j<10;j++){
                        if (Game::getInstance().matriz[j][i]==1){
                            Tower * tower = new Tower();
                                tower->setPos((j+1)*60,(i+1)*60);
                                 Game::getInstance().listaTorres->Add(tower);
                            Game::getInstance().scene->addItem(tower);
                        }
                        else if (Game::getInstance().matriz[j][i]==2){
                            Tower2 * tower = new Tower2();
                            tower->setPos((j+1)*60,(i+1)*60);
                             Game::getInstance().listaTorres2->Add(tower);
                            Game::getInstance().scene->addItem(tower);
                        }
                        else if (Game::getInstance().matriz[j][i]==3){
                            Tower3 * tower = new Tower3();
                            tower->setPos((j+1)*60,(i+1)*60);
                             Game::getInstance().listaTorres3->Add(tower);
                            Game::getInstance().scene->addItem(tower);
                        }
                    }
                }
            }
            qApp->processEvents();
            if (arr[i][0]==0 && arr[i][1]==0 ){
                setPos(64,65);
            }
            if(arr[i][0]==9 && arr[i][1]==9 && Game::getInstance().player->vida>0 && Socket::getInstance().turno%3 != 0){
                Socket::getInstance().play = false;
                qDebug()<<"false";
                break;
            }
            else{
                int x = (arr[i][0]+1)*60;
                int y = (arr[i][1]+1)*60;
                setPos(x,y);
            }
        }
        else{
            return;
        }
      sleep(1);
    }
    delete this;
}

