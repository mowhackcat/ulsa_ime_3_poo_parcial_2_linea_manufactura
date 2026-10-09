#pragma once
#include <iostream>

class Extrusor {
private:
    int horasUsoFilamento;
    int limiteHoras;

public:
    Extrusor (int limite);

    void acumularUso(int horas);
    void destaparBoquilla();
    bool estaObstruido();
    int obtenerHorasUso();
};