#include "TornoCNC.h"

#include <string>
#include <iostream>

Torno::Torno(int id, const std::string& nombre, int const limiteHusillo, int const segundos):Maquina(id, nombre), 
segundos(segundos), limiteHusillo(limiteHusillo)
{
this->segundos = 20;
this->limiteHusillo = 8;
};

bool Torno::LimiteDeProduccion(){


}

void trabajo(){
while (true)
{
 void encender();
 bool estaEnFalla();
 bool puedeProcesar();
 

}
}