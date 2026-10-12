#ifndef HUSILLO.H
#define HUSILLO.H

#include <string>

class Husillo{
private:
int limiteHusillo;
bool estadoHusilloFalla;
int contador;

public:

Husillo(int const limiteHusillo, bool estadoHusilloFalla, int contador );
bool limiteDeProduccion();
bool fallaHusillo();
void mantenimiento();
void estado();
void trabajo();
};




#endif