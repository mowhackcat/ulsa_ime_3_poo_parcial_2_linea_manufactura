#pragma once
#include <iostream>

class Extrusor {
private:
    int usoActual;
    int limiteUso;

public:
    Extrusor (int limite);

    void desgastar();
    void restaurar();
    bool estaAgotado() const;
};