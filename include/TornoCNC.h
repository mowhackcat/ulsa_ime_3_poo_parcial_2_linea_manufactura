#ifndef TornoCNC_H
#define TornoCNC_H

#include <string>
#include "Maquina.h"

class Torno : public Maquina {
private: 
int segundos;
int limite;

public:

Torno(int id, const std::string& nombre, int const limite, int const segundos);

bool limiteAlcanzado();

void trabajo();

};
#endif