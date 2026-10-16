#ifndef CORTADORA_LASER_H
#define CORTADORA_LASER_H

#include "Maquina.h"
#include "Lente.h"

class CortadoraLaser : public Maquina {
private:
    int tiempoPorPieza;
    int potenciaWatts;
    Lente lente;

public:
    CortadoraLaser(int id, const std::string& nombre,
                   int tiempo, int limiteLente);

    bool procesarPieza() override;
    void realizarMantenimiento() override;
    void mostrarEstado() const override;
    void calibrarPotencia(int watts);
};

#endif