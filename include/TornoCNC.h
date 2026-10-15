#ifndef TORNO_CNC_H
#define TORNO_CNC_H

#include <string>
#include "Maquina.h"
#include "Husillo.h"


class Torno : public Maquina {
protected: 
int segundos;
bool estadoFalla;
Husillo husillo;

public:
Torno(int id, const std::string& nombre);
bool fallaDeTorno();
void mantenimiento();
void procesarPieza();
void registrarPiezaTorno();
void reportarFallaTorno();
void agregarTiempoTorno(int segundos);
int getSegundos() const;
};
#endif