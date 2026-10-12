#ifndef TornoCNC_H
#define TornoCNC_H

#include <string>
#include "Maquina.h"
#include "Husillo.h"


class Torno : public Maquina {
protected: 
int segundos;
bool estadoFalla;
Husillo husillo;

public:
Torno(int id, const std::string& nombre, bool estadoFalla ,int const limiteHusillo, bool estadoHusilloFalla,  int contador);
bool fallaDeTorno();
void mantenimiento();
void procesarPieza(Torno&);
void registrarPiezaTorno();
void reportarFallaTorno();
void agregarTiempoTorno(int segundos);
int getSegundos() const;
};
#endif