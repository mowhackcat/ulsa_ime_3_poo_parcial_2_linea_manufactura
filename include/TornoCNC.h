#ifndef TornoCNC_H
#define TornoCNC_H

#include <string>
#include "Maquina.h"

class Torno : public Maquina {
private: 
int segundos;
int limiteHusillo;

public:

Torno(int id, const std::string& nombre, int const limiteHusillo, int const segundos);

bool LimiteDeProduccion();

void trabajo(Torno&);

};
#endif