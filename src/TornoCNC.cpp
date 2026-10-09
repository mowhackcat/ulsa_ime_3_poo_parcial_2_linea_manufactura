#include "TornoCNC.h"

#include <string>
#include <iostream>

Torno::Torno(int id, const std::string& nombre, int const segundos, int const limiteHusillo): Maquina(id, nombre), 
segundos(segundos), husillo(limiteHusillo)
{
this->segundos = 20;

};

bool Torno::limiteDeProduccion(){
    return husillo.limiteDeProduccion();
}

void procesarPieza(Torno& torno){
while (true)
{
 torno.encender();
 torno.estaEnFalla();
 torno.puedeProcesar();
 torno.limiteDeProduccion();
if(torno.limiteDeProduccion()){
    std::cout << "se llego al limite\n";
    continue;
}

}
}