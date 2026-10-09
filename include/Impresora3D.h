#pragma once
#include <string>
#include "Maquina.h"
#include "Extrusor.h"

class Impresora3D : public Maquina {
private: 
    int tiempoPorPieza;
    int temperaturaCelsius;
    Extrusor extrusor;

public:
Impresora3D(std::string id, std::string nombre, int tiempo, int limiteExtrusor);

bool procesarPieza();
void realizarMantenimiento();
void mostrarEstado();
void calibrarTemperatura(int temp);
};

