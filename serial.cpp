#include "serial.h"

serial::serial()
{

}
void serial::deserializarIteracion3(string json,int arr[10][10], int* edad, int* edadBack, int* emocional, int* emocionalBack,
int* condicionFisica, int* condicionFisicaBack, int* resistencia, int* resistenciaBack, int* velocidad, int* velocidadBack, int* generacion,
int* generacionBack, int* id, int* idBack, int* vida, int* vidaBack, int* fitness, int* fitnessBack, int* probabilidad, int* probabilidadBack,
int* troncoSuperior, int* troncoSuperiorBack, int* troncoInferior, int* troncoInferiorBack, int* supervivenciaGen, int* supervivenciaGenBack, int aStar[30][2], int backTrack[30][2], int ubicacion[2]){
Document d;
d.Parse(json.c_str());
*edad = (d["edad"].GetArray()[0]).GetInt();
*edadBack =(d["edad"].GetArray()[1]).GetInt();
*emocional = (d["emocional"].GetArray()[0]).GetInt();
*emocionalBack = (d["emocional"].GetArray()[1]).GetInt();
*condicionFisica =(d["condicionFisica"].GetArray()[0]).GetInt();
*condicionFisicaBack =(d["condicionFisica"].GetArray()[1]).GetInt();
*resistencia =(d["resistencia"].GetArray()[0]).GetInt();
*resistenciaBack =(d["resistencia"].GetArray()[1]).GetInt();
*velocidad = (d["velocidad"].GetArray()[0]).GetInt();
*velocidadBack = (d["velocidad"].GetArray()[1]).GetInt();
*generacion = (d["generacion"].GetArray()[0]).GetInt();
*generacionBack = (d["generacion"].GetArray()[1]).GetInt();
*id = (d["id"].GetArray()[0]).GetInt();
*idBack = (d["id"].GetArray()[1]).GetInt();
*vida = (d["vida"].GetArray()[0]).GetInt();
*vidaBack = (d["vida"].GetArray()[1]).GetInt();
*fitness = (d["fitness"].GetArray()[0]).GetInt();
*fitnessBack = (d["fitness"].GetArray()[1]).GetInt();
*probabilidad = (d["probabilidad"].GetArray()[0]).GetInt();
*probabilidadBack = (d["probabilidad"].GetArray()[1]).GetInt();
*troncoSuperior = (d["troncoSuperior"].GetArray()[0]).GetInt();
*troncoSuperiorBack = (d["troncoSuperior"].GetArray()[1]).GetInt();
*troncoInferior = (d["troncoInferior"].GetArray()[0]).GetInt();
*troncoInferiorBack = (d["troncoInferior"].GetArray()[1]).GetInt();
*supervivenciaGen = (d["supervivenciaGen"].GetArray()[0]).GetInt();
*supervivenciaGenBack = (d["supervivenciaGen"].GetArray()[1]).GetInt();

for(int i=0; i<30;i++){
    if(d["aStar"].GetArray()[i][0] == 9 && d["aStar"].GetArray()[i][1] == 9){
        aStar[i][0] = (d["aStar"].GetArray()[i][0]).GetInt();
        aStar[i][1] = (d["aStar"].GetArray()[i][1]).GetInt();
        break;
    }
    else{
        aStar[i][0] = (d["aStar"].GetArray()[i][0]).GetInt();
        aStar[i][1] = (d["aStar"].GetArray()[i][1]).GetInt();
    }
}

for(int i=0; i<30;i++){
    if(d["backTrack"].GetArray()[i][0] == 9 && d["backTrack"].GetArray()[i][1] == 9){
        backTrack[i][0] = (d["backTrack"].GetArray()[i][0]).GetInt();
        backTrack[i][1] = (d["backTrack"].GetArray()[i][1]).GetInt();
        break;
    }
    else{
        backTrack[i][0] = (d["backTrack"].GetArray()[i][0]).GetInt();
        backTrack[i][1] = (d["backTrack"].GetArray()[i][1]).GetInt();
    }
}

for(int i =0 ;i <10; i++){
    for(int j =0; j<10 ; j++){
        arr[i][j] = (d["matrix"].GetArray()[i][j]).GetInt();
    }
}

    ubicacion[0] = (d["ubicacion"].GetArray()[0]).GetInt();
    ubicacion[1] = (d["ubicacion"].GetArray()[1]).GetInt();

}

void serial::deserealizarTableroGladiador(string json,int arr[10][10], int* edad, int* edadBack, int* emocional, int* emocionalBack,
    int* condicionFisica, int* condicionFisicaBack, int* resistencia, int* resistenciaBack, int* velocidad, int* velocidadBack, int* generacion,
    int* generacionBack, int* id, int* idBack, int* vida, int* vidaBack, int* fitness, int* fitnessBack, int* probabilidad, int* probabilidadBack,
    int* troncoSuperior, int* troncoSuperiorBack, int* troncoInferior, int* troncoInferiorBack, int* supervivenciaGen, int* supervivenciaGenBack, int aStar[30][2], int backTrack[30][2]){
    Document d;
    d.Parse(json.c_str());
    *edad = (d["edad"].GetArray()[0]).GetInt();
    *edadBack =(d["edad"].GetArray()[1]).GetInt();
    *emocional = (d["emocional"].GetArray()[0]).GetInt();
    *emocionalBack = (d["emocional"].GetArray()[1]).GetInt();
    *condicionFisica =(d["condicionFisica"].GetArray()[0]).GetInt();
    *condicionFisicaBack =(d["condicionFisica"].GetArray()[1]).GetInt();
    *resistencia =(d["resistencia"].GetArray()[0]).GetInt();
    *resistenciaBack =(d["resistencia"].GetArray()[1]).GetInt();
    *velocidad = (d["velocidad"].GetArray()[0]).GetInt();
    *velocidadBack = (d["velocidad"].GetArray()[1]).GetInt();
    *generacion = (d["generacion"].GetArray()[0]).GetInt();
    *generacionBack = (d["generacion"].GetArray()[1]).GetInt();
    *id = (d["id"].GetArray()[0]).GetInt();
    *idBack = (d["id"].GetArray()[1]).GetInt();
    *vida = (d["vida"].GetArray()[0]).GetInt();
    *vidaBack = (d["vida"].GetArray()[1]).GetInt();
    *fitness = (d["fitness"].GetArray()[0]).GetInt();
    *fitnessBack = (d["fitness"].GetArray()[1]).GetInt();
    *probabilidad = (d["probabilidad"].GetArray()[0]).GetInt();
    *probabilidadBack = (d["probabilidad"].GetArray()[1]).GetInt();
    *troncoSuperior = (d["troncoSuperior"].GetArray()[0]).GetInt();
    *troncoSuperiorBack = (d["troncoSuperior"].GetArray()[1]).GetInt();
    *troncoInferior = (d["troncoInferior"].GetArray()[0]).GetInt();
    *troncoInferiorBack = (d["troncoInferior"].GetArray()[1]).GetInt();
    *supervivenciaGen = (d["supervivenciaGen"].GetArray()[0]).GetInt();
    *supervivenciaGenBack = (d["supervivenciaGen"].GetArray()[1]).GetInt();

    for(int i=0; i<30;i++){
        if(d["aStar"].GetArray()[i][0] == 9 && d["aStar"].GetArray()[i][1] == 9){
            aStar[i][0] = (d["aStar"].GetArray()[i][0]).GetInt();
            aStar[i][1] = (d["aStar"].GetArray()[i][1]).GetInt();
            break;
        }
        else{
            aStar[i][0] = (d["aStar"].GetArray()[i][0]).GetInt();
            aStar[i][1] = (d["aStar"].GetArray()[i][1]).GetInt();
        }
    }

    for(int i=0; i<30;i++){
        if(d["backTrack"].GetArray()[i][0] == 9 && d["backTrack"].GetArray()[i][1] == 9){
            backTrack[i][0] = (d["backTrack"].GetArray()[i][0]).GetInt();
            backTrack[i][1] = (d["backTrack"].GetArray()[i][1]).GetInt();
            break;
        }
        else{
            backTrack[i][0] = (d["backTrack"].GetArray()[i][0]).GetInt();
            backTrack[i][1] = (d["backTrack"].GetArray()[i][1]).GetInt();
        }
    }

    for(int i =0 ;i <10; i++){
        for(int j =0; j<10 ; j++){
            arr[i][j] = (d["matrix"].GetArray()[i][j]).GetInt();
        }
    }




}
void serial::deserializarGrafico(string json, string *grafico1, string *grafico2){
    Document d;
    d.Parse(json.c_str());
    *grafico1 = d["grafico"].GetString();
    *grafico2 = d["grafico2"].GetString();

}
string serial::serializarTurno(bool play, int turno, bool mod3 )
{
    const char* json = "{\"play\":true,"
                       "\"mod3\":true,"
                       "\"turno\":0}";

    Document d;
    d.Parse(json);
    d["play"].SetBool(play);
    d["turno"].SetInt(turno);
    d["mod3"].SetBool(mod3);
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);
    qDebug()<<buffer.GetString()<<"JSON SERIALIZADO";
    return buffer.GetString();
}
