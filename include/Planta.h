#ifndef PLANTA_H
#define PLANTA_H

#include <vector>
#include "Maquina.h"

class Planta {
private:
    std::vector<Maquina*> maquinas;
    int repeticionesGlobales;
    int totalPiezasTerminadas;

public:
    Planta(int repeticionesGlobales = 20);

    bool agregarMaquina(Maquina* maquina);
    int cantidadMaquinas();

    void encenderMaquinas();
    void apagarMaquinas();
    void mostrar();
    int getRepeticionesGlobales() const;

    void encenderLinea();
    void apagarLinea();
    void procesarLote(int numPiezas);
    void generarReporteTurno() const;
};

#endif