#include "TornoCNC.h"

#include <string>
#include <iostream>

Torno::Torno(int id, const std::string& nombre, bool estadoFalla ,int const limiteHusillo, bool estadoHusilloFalla,  int contador): Maquina(id, nombre), 
estadoFalla(estadoFalla), husillo(limiteHusillo, estadoHusilloFalla, contador)
{
this->segundos = 20;

};

bool Torno::fallaDeTorno(){
    return husillo.fallaHusillo();
}

void Torno::mantenimiento(){
    if(estadoFalla == true){
    husillo.mantenimiento();
    this->estadoFalla = false;
    }
}

void procesarPieza(Torno& torno){
 torno.encender();
 torno.estaEnFalla();
 torno.puedeProcesar();
if(torno.fallaDeTorno()){
    std::cout << "se llego al limite\n";
    torno.mantenimiento();
}
}