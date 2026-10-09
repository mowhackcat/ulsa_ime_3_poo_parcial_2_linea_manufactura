#ifndef TornoCNC_H
#define TornoCNC_H

#include <string>
#include "Maquina.h"
#include "Husillo.h"


class Torno : public Maquina {
protected: 
int segundos;
Husillo husillo;

public:
Torno(int id, const std::string& nombre, int const segundos, int const limiteHusillo);
bool limiteDeProduccion();
void procesarPieza(Torno&);

};
#endif