#ifndef FRESADORA_H
#define FRESADORA_H

#include "Maquina.h"
#include "HerramientaCorte.h"
#include <string>

class Fresadora : public Maquina {
private:
    HerramientaCorte herramienta;
    int tiempoPorPieza;
    int ranurasRealizadas;

public:
    Fresadora(int id, const std::string& nombre,
              int tiempo, int limiteDesgaste);

    bool ranurar();
    void realizarMantenimiento();
    void mostrarEstado() const;

    int getRanurasRealizadas() const;
    int getTiempoPorPieza() const;
};

#endif