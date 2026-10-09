#include "Husillo.h"

#include <string>
#include <iostream>

Husillo::Husillo(int const limiteHusillo):limiteHusillo(limiteHusillo){
    this->limiteHusillo = 8;
}

bool Husillo::limiteDeProduccion(){
static int contador = 0;
contador++;
return (contador % limiteHusillo == 0);
}





