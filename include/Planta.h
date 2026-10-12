#ifndef TornoCNC_H
#define TornoCNC_H

#include <string>
#include <vector>
#include <cstddef>

#include "Maquina.h"

class Planta {
private:
std::vector<Maquina*> maquina;
int repeticionesGlobales;

public: 

Planta(int const repeticionesGlobales);

bool agregarMaquina(Maquina* maquina);//funcion para agregar las maquinas a un vector y recibir una confirmacion

int cantidadMaquinas();

void mostrar();
};

#endif