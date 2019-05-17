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
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts>

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
          string mensaje = serial::getInstance().serializarTurno(player->active,1,false);
          string recibido = Socket::getInstance().envioEscucho(mensaje, 8080, "192.168.0.111");
          qDebug()<<recibido.c_str();
          serial::getInstance().deserealizarTableroGladiador(recibido.c_str(), matriz, &player1->edad,&player2->edad,&player1->emocional,&player2->emocional,&player1->condicionFisica,&player2->condicionFisica
                                                                      , &player1->resistencia,&player2->resistencia,&player1->velocidad,&player2->velocidad,&player1->generacion,&player2->generacion,&player1->id, &player2->id,
                                                                        &player1->vida,&player2->vida,&player1->fitness,&player2->fitness,&player1->probabilidad,&player2->probabilidad,&player1->troncoSuperior, &player2->troncoSuperior,
                                                                        &player1->troncoInferior,&player2->troncoInferior,
                                                                      &player1->supervivenciaGen,&player2->supervivenciaGen,player1->arr,player2->arr);

          one = new Stadistics();
          one->set(0,800,180,15);
          one->setPlainText(QString("Vida: "));
          scene->addItem(one);

          two = new Stadistics();
          two->set(0,800,220,15);
          two->setPlainText(QString("ID: "));
          scene->addItem(two);

          three = new Stadistics();
          three->set(0,800,240,15);
          three->setPlainText(QString("Edad: "));
          scene->addItem(three);

          four = new Stadistics();
          four->set(0,800,260,15);
          four->setPlainText(QString("Probabilidad: "));
          scene->addItem(four);

          five = new Stadistics();
          five->set(0,800,280,10);
          five->setPlainText(QString("Supervivencia Gen: "));
          scene->addItem(five);

          six = new Stadistics();
          six->set(0,800,300,15);
          six->setPlainText(QString("Emocional: "));
          scene->addItem(six);

          seven = new Stadistics();
          seven->set(0,800,320,15);
         seven->setPlainText(QString("Tronco Sup: "));
          scene->addItem(seven);

          eight = new Stadistics();
          eight->set(0,800,340,15);
         eight->setPlainText(QString("Tronco Inf: "));
          scene->addItem(eight);

          nine =new Stadistics();
          nine->set(0,800,360,15);
          nine->setPlainText(QString("Resistencia: "));
          scene->addItem(nine);

          ten = new Stadistics();
          ten->set(0,800,380,15);
         ten->setPlainText(QString("Fisico: "));
          scene->addItem(ten);

          eleven = new Stadistics();
          eleven->set(0,800,400,15);
         eleven->setPlainText(QString("Fitness: "));
          scene->addItem(eleven);



          scene->setBackgroundBrush(QBrush(QImage(":images/game.png")));

          timer = new QTimer();
          QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
          timer->start();

          player=player1;

          vida = new Stadistics();
          vida->set(player->vida,950,180,20);
          scene->addItem(vida);

          id = new Stadistics();
          id->set(player->id,950,220,15);
          scene->addItem(id);

          edad = new Stadistics();
          edad->set(player->edad,950,240,15);
          scene->addItem(edad);

          prob = new Stadistics();
          prob->set(player->probabilidad,950,260,15);
          scene->addItem(prob);

          gen = new Stadistics();
          gen->set(player->supervivenciaGen,950,280,15);
          scene->addItem(gen);

          emocion  = new Stadistics();
          emocion->set(player->emocional,950,300,15);
          scene->addItem(emocion);

          superior = new Stadistics();
          superior->set(player->troncoSuperior,950,320,15);
          scene->addItem(superior);

          inferior = new Stadistics();
          inferior->set(player->troncoInferior,950,340,15);
          scene->addItem(inferior);

          resistencia = new Stadistics();
          resistencia->set(player->resistencia,950,360,15);
          scene->addItem(resistencia);

          fisica = new Stadistics();
          fisica->set(player->condicionFisica,950,380,15);
          scene->addItem(fisica);

          fitness = new Stadistics();
          fitness->set(player->fitness,950,400,15);
          scene->addItem(fitness);
          Socket::getInstance().vida = player->vida;
          cout<<Socket::getInstance().vida<<"Vida inicial"<<endl;

          player1->moveArr(player1->arr);
          if (!Socket::getInstance().play){
              break;
          }
          player=player2;

          vida->set(player->vida,950,180,20);

          id->set(player->id,950,220,15);

          edad->set(player->edad,950,240,15);

          prob->set(player->probabilidad,950,260,15);

          gen->set(player->supervivenciaGen,950,280,15);

          emocion->set(player->emocional,950,300,15);

          superior->set(player->troncoSuperior,950,320,15);

          inferior->set(player->troncoInferior,950,340,15);

          resistencia->set(player->resistencia,950,360,15);

          fisica->set(player->condicionFisica,950,380,15);

          fitness->set(player->fitness,950,400,15);


          Socket::getInstance().vida= player->vida;
          cout<<Socket::getInstance().vida<<"Vida inicial backtracking"<<endl;
          player2->moveArr(player2->arr);
          Socket::getInstance().turno++;
          qDebug()<<Socket::getInstance().turno<<"TURNO";
        }
        qDebug()<<"Game Over";
    string grafico1;
    string grafico2;
    string mensaje = serial::getInstance().serializarTurno(false,1,false);
    Socket::getInstance().envioEscucho(mensaje,8080,"192.168.0.111");
    sleep(1);
    string recibo = Socket::getInstance().envioEscucho(mensaje, 8080, "192.168.0.111");
    qDebug()<<recibo.c_str()<<"GRAFICO RECIBIDO";
    serial::getInstance().deserializarGrafico(recibo,&grafico1,&grafico2);
    QtCharts::QBarSet *set0 = new QtCharts::QBarSet("poblacion1");

    string numeros = "1,100,3,4";
    istringstream iss(numeros);
    string item;
    for (int i = 0;i<2;i++) {
        string numeros = grafico1;
        int numerosInt;
        istringstream iss(numeros);
        string item;
        while(getline(iss, item, ',')){
        numerosInt = stoi(item,nullptr, 10);
        *set0<< numerosInt;
        }
    }
    QtCharts::QBarSet *set1 = new QtCharts::QBarSet("poblacion2");

    for (int i = 0;i<2;i++) {
        string numeros = grafico2;
        int numerosInt;
        istringstream iss(numeros);
        string item;
        while(getline(iss, item, ',')){
        numerosInt = stoi(item,nullptr, 10);
        *set0<< numerosInt;
        }
    }
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
    series->append(set0);
    QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Avance de las generaciones");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
            categories << "gen";
            categories<< "gen";
            categories<< "gen" << "gen" << "gen" << "gen";
            QBarCategoryAxis *axisX = new QBarCategoryAxis();
            axisX->append(categories);
            chart->addAxis(axisX, Qt::AlignBottom);
            series->attachAxis(axisX);

            QValueAxis *axisY = new QValueAxis();
            axisY->setRange(0,100);
            chart->addAxis(axisY, Qt::AlignLeft);
            series->attachAxis(axisY);
            chart->legend()->setVisible(true);
                chart->legend()->setAlignment(Qt::AlignBottom);
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                scene->clear();
                scene->addItem(chart);



   // scene->clear();


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


