#pragma once
#include <string>
#include "Maquina.h"
#include "Extrusor.h"

class Impresora3D : public Maquina {
private:
    int tiempoPorPieza = 120;
    Extrusor extrusor;

public:
    Impresora3D(int id, const std::string& nombre, int limiteExtrusor);

    bool procesarPieza();
    void realizarMantenimiento();
    void mostrarEstado() const;
};
