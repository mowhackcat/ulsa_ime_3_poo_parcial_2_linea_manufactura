#include "Extrusor.h"

Extrusor::Extrusor(int limite) : usoActual(0), limiteUso(limite) 
{
     if (limite <= 0) {
        limiteUso = 10;   // valor seguro por defecto
    } else {
        limiteUso = limite;
    }
}

void Extrusor::desgastar() 
{
    if (usoActual < limiteUso) 
    {
        ++usoActual;
    }
}

void Extrusor::restaurar() 
{
    usoActual = 0;
}

bool Extrusor::estaAgotado() const 
{
    return usoActual >= limiteUso;
}
