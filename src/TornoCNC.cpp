#include "TornoCNC.h"

#include <string>
#include <iostream>

Torno::Torno(int id, const std::string& nombre, bool estadoFalla ,int const limiteHusillo, bool estadoHusilloFalla,  int contador): Maquina(id, nombre), 
estadoFalla(estadoFalla), husillo(limiteHusillo, estadoHusilloFalla, contador)
{
this->segundos = 20;

};

int Torno::getSegundos() const{
    return segundos;
}

bool Torno::fallaDeTorno(){
    return husillo.fallaHusillo();
}

void Torno::agregarTiempoTorno(int segundos){
    Maquina::agregarTiempo(segundos);
}

void Torno::registrarPiezaTorno(){
    Maquina::registrarPieza();
}

void Torno::reportarFallaTorno(){
    Maquina::reportarFalla();
}

void Torno::mantenimiento(){
    if(estadoFalla == true){
    husillo.mantenimiento();
    this->estadoFalla = false;
    }
}

void Torno::procesarPieza(Torno& torno){
 torno.encender();
 torno.estaEnFalla();
if(torno.fallaDeTorno()){
    torno.reportarFallaTorno();
    torno.mantenimiento();
}else if(torno.puedeProcesar()){
    torno.registrarPiezaTorno();
    torno.agregarTiempoTorno(torno.getSegundos());
}
}