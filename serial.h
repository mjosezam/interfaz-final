#ifndef SERIAL_H
#define SERIAL_H
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>
#include <QDebug>
using namespace std;
using namespace rapidjson;

class serial
{
public:
    serial();
    static serial &getInstance(){
        static serial instance;
        return instance;
    }
    bool active = true;
    void deserealizarTableroGladiador(string json, int arr[10][10], int *edad, int *edadBack, int *emocional, int *emocionalBack,
    int *condicionFisica, int *condicionFisicaBack, int *resistencia, int *resistenciaBack, int *velocidad, int *velocidadBack,
    int *generacion, int *generacionBack, int *id, int *idBack, int *vida, int *vidaBack, int *fitness, int *fitnessBack, int *probabilidad,
    int *probabilidadBack, int *troncoSuperior, int *troncoSuperiorBack, int *troncoInferior, int *troncoInferiorBack, int *supervivenciaGen,
    int *supervivenciaGenBack, int aStar[30][2], int backTrack[30][2]);
    string serializarTurno(bool play, int turno, bool mod3);
    void deserializarIteracion3(string json, int arr[10][10], int *edad, int *edadBack, int *emocional, int *emocionalBack, int *condicionFisica, int *condicionFisicaBack, int *resistencia, int *resistenciaBack, int *velocidad, int *velocidadBack, int *generacion, int *generacionBack, int *id, int *idBack, int *vida, int *vidaBack, int *fitness, int *fitnessBack, int *probabilidad, int *probabilidadBack, int *troncoSuperior, int *troncoSuperiorBack, int *troncoInferior, int *troncoInferiorBack, int *supervivenciaGen, int *supervivenciaGenBack, int aStar[30][2], int backTrack[30][2], int ubicacion[2]);
};

#endif // SERIAL_H
