#ifndef PLANTA_H
#define PLANTA_H

#include <vector>
#include "Maquina.h"

class Planta {
private:
    // Guarda referencias a maquinas creadas fuera de la planta.
    std::vector<Maquina*> maquinas;
    int totalPiezasTerminadas;
    int tiempoTotalTurno;

public:
    Planta();
    ~Planta() = default;

    void agregarMaquina(Maquina* maquina);
    void encenderLinea();
    void apagarLinea();
    void procesarLote(int numPiezas);
    void generarReporteTurno() const;
};

#endif