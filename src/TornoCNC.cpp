#include "../include/TornoCNC.h"

#include <string>
#include <iostream>

Torno::Torno(int id, const std::string& nombre): Maquina(id, nombre), husillo(8, false, 0)
{
this->segundos = 30;

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
    this->estadoFalla = true;
    Maquina::reportarFalla();
}

void Torno::realizarMantenimiento(){
    if(estadoFalla == true){
    husillo.mantenimiento();
    this->estadoFalla = false;
    }
}

bool Torno::procesarPieza(){
if(this-> Torno::puedeProcesar()){
if(this-> Torno::fallaDeTorno()){
this->estadoFalla = true;
this->apagar();
this->registrarMantenimiento();
this->realizarMantenimiento();
}
    this-> Torno::registrarPiezaTorno();
    this-> Torno::agregarTiempoTorno(this-> Torno::getSegundos());
}
 return 0;
}