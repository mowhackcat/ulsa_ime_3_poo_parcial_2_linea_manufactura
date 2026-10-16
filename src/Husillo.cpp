#include "Husillo.h"

#include <string>
#include <iostream>

Husillo::Husillo(int const limiteHusillo,bool estadoHusilloFalla, int contador):limiteHusillo(limiteHusillo), estadoHusilloFalla(estadoHusilloFalla)
, contador(contador){
    this->limiteHusillo = 8;
    this->contador = 0;
}

bool Husillo::limiteDeProduccion(){
contador++;
return (contador % limiteHusillo == 0);
}

bool Husillo::fallaHusillo(){
if(limiteDeProduccion() == true){
    this->estadoHusilloFalla=true;
} else {
    this->estadoHusilloFalla = false;
}
return this->estadoHusilloFalla;
}

void Husillo::mantenimiento(){
    this-> contador = 0;
    this->estadoHusilloFalla = false;
}

void Husillo::estado(){
    std::cout << "husillo en falla:.. " << estadoHusilloFalla << "\n";
}





