#include "Planta.h"
#include <iostream>

Planta::Planta (int const repeticionesGlobales): repeticionesGlobales(repeticionesGlobales) {}

bool Planta::agregarMaquina(Maquina* maquina){
    this->maquina.push_back(maquina);
    return true;
}

int Planta::cantidadMaquinas(){ //devuelve la cantidad de maquinas almacenadas en el vector
    return this->maquina.size();
}

void Planta::mostrar(){ //funcion para mostrar el estado de cada una de las maquinas en el vector
    for(size_t x=0; x <= maquina.size(); x++){
        this->maquina[x]->mostrarEstado();
    }
}